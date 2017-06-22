#include "ttplayerthread.h"
#include <QFileInfo>
#include <QFileInfoList>
#include <QDir>
#include <QStringList>

ttPlayerThread::ttPlayerThread(QObject *parent) :
    QThread(parent)
{
    threadInit();
}

void ttPlayerThread::threadInit()
{
    mPlayerConf = new stTtPlayerConf;
    //memset(mPlayerConf, 0, sizeof(stTtPlayerConf));

    av_register_all();
    avformat_network_init();
}

void ttPlayerThread::setFileName(QString fileName)
{
    mPlayerConf->fileName = fileName;
}

void ttPlayerThread::threadDestory()
{
    delete mPlayerConf;
}

void ttPlayerThread::run()
{
    AVFormatContext *pFormatCtx;
    int videoIndex = -1;
    int audioIndex = -1;
    AVCodecContext *pCodecCtx;
    AVCodec *pCodec;

    QByteArray byteFileName = mPlayerConf->fileName.toLatin1();
    char * filename = byteFileName.data();
    pFormatCtx = avformat_alloc_context();
    if (avformat_open_input(&pFormatCtx, filename, NULL, NULL) != 0)
    {
        printf("can't open the input stream.\n");
        return ;
    }

    if (avformat_find_stream_info(pFormatCtx, NULL) < 0)
    {
        printf("can't find stream information.\n");
        return ;
    }

    for (int i = 0; i < pFormatCtx->nb_streams; i++)
    {
        if (pFormatCtx->streams[i]->codecpar->codec_type == AVMEDIA_TYPE_VIDEO)
            videoIndex = i;
        else if (pFormatCtx->streams[i]->codecpar->codec_type == AVMEDIA_TYPE_AUDIO)
            audioIndex = i;
    }
    if (videoIndex == -1)
    {
        printf("Can't find a video stream.\n");
    }

    pCodecCtx = avcodec_alloc_context3(NULL);
    if (NULL == pCodecCtx)
    {
        printf("alloc AVCodecContext error.\n");
        return ;
    }
    avcodec_parameters_to_context(pCodecCtx, pFormatCtx->streams[videoIndex]->codecpar);

    pCodec = avcodec_find_decoder(pFormatCtx->streams[videoIndex]->codecpar->codec_id);
    if (NULL == pCodec)
    {
        printf("Codec Not Found!\n");
        return ;
    }

    if (avcodec_open2(pCodecCtx, pCodec, NULL) < 0)
    {
        printf("Can't open codec.\n");
        return ;
    }
    
    AVFrame *pFrame, *pFrameRGB;
    uint8_t *out_buffer_rgb;
    SwsContext *img_convert_ctx;
    AVPacket *packet = (AVPacket *)av_malloc(sizeof(AVPacket));
    int ret;

    pFrame = av_frame_alloc();
    pFrameRGB = av_frame_alloc();
    img_convert_ctx = sws_getContext(pCodecCtx->width, pCodecCtx->height, pCodecCtx->pix_fmt, pCodecCtx->width, pCodecCtx->height,
                                     AV_PIX_FMT_RGB32, SWS_BICUBIC, NULL, NULL, NULL);
    //int numBytes = avpicture_get_size(AV_PIX_FMT_RGB32, pCodecCtx->width, pCodecCtx->height);
    int numBytes = av_image_get_buffer_size(AV_PIX_FMT_RGB32, pCodecCtx->width, pCodecCtx->height, 1);
    out_buffer_rgb = (uint8_t *)av_malloc(numBytes * sizeof(uint8_t));
    //avpicture_fill((AVPicture *)pFrameRGB, out_buffer_rgb, AV_PIX_FMT_RGB32, pCodecCtx->width, pCodecCtx->height);
    av_image_fill_arrays(pFrameRGB->data, pFrameRGB->linesize, out_buffer_rgb, AV_PIX_FMT_RGB32, pCodecCtx->width, pCodecCtx->height, 1);

    while(1)
    {
        if (av_read_frame(pFormatCtx, packet) < 0)
            break;
        if (packet->stream_index != videoIndex)
            continue;

        avcodec_send_packet(pCodecCtx, packet);
        ret = avcodec_receive_frame(pCodecCtx, pFrame);
        if (0 == ret)
        {
            sws_scale(img_convert_ctx, (uint8_t const* const *) pFrame->data, pFrame->linesize,
                      0, pCodecCtx->height, pFrameRGB->data, pFrameRGB->linesize);
            QImage tmpImg((uchar *)out_buffer_rgb, pCodecCtx->width, pCodecCtx->height, QImage::Format_RGB32);
            QImage image = tmpImg.copy();
            emit changePic(image);
        }
        msleep(40);
    }

    av_free(pFrame);
    av_free(pFrameRGB);
    av_free(packet);
}

/*
void ttPlayerThread::run()
{
    QDir *rootDir = new QDir("D:\\jpg\\");
    QFileInfoList fileList;
    QStringList filterstr;
    //filterstr.insert(0, ".");
    //filterstr.insert(1, "..");
    fileList = rootDir->entryInfoList(filterstr);
    int currentIndex = 0;
    while (1)
    {
        currentIndex ++;
        if (currentIndex >= fileList.count())
            currentIndex = 0;
       QFileInfo cFile = fileList.at(currentIndex);
        if ((cFile.fileName() == ".") || (cFile.fileName() == ".."))
            continue;
        //cFile.filePath();
        emit changePic(QImage(cFile.filePath()));
        sleep(1);
    }
}
*/
