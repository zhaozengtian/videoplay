#include "widget.h"
#include "ui_widget.h"
#include <QTextCodec>
#include <QFileDialog>
#include <QKeyEvent>

#include <QMenu>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));
    setWindowTitle(tr("小田播放器"));

    mediaObject = new Phonon::MediaObject(this);    //媒体对象的初始化(指定父组件为当前窗体)
    videoWidget = new Phonon::VideoWidget(ui->frameVideo);    //视频输出对象初始化(指定它的父组件为窗口部件frameVideo)
    Phonon::createPath(mediaObject, videoWidget);   //将媒体对象和视频输出对象连接
    audioOutput = new Phonon::AudioOutput(Phonon::VideoCategory, this);//音频输出对象初始化(指定它的父组件为当前窗体)
    Phonon::createPath(mediaObject, audioOutput);   //媒体对象和音频输出对象连接

    slider = new Phonon::SeekSlider(mediaObject, ui->frameSeek);//进度条初始化(指定它的父组件为frameSeek)
    volumeSlider = new Phonon::VolumeSlider(audioOutput, ui->frameVolume);//音量调节对象初始化(指定它的父组件为frameVolume)
    audioOutput->setVolume(0.5);//设置默认的音量

    *i=0;
    file = new QString[MAXFILE];


    videoWidget->installEventFilter(this);//安装事件过滤器
}

Widget::~Widget()
{
    delete[] file;
    delete ui;
}

void Widget::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void Widget::on_btnMedia_clicked()
{
    static int j=0;
     if(j == MAXFILE)
         return;
    QString filename = QFileDialog::getOpenFileName(this, tr("打开文件"), tr("F:\\music"), "*.mpg; *.avi; *.wmv; *.mp4; *.mp3;;*.*");
    file[j++] = filename;
    if(filename.isEmpty() || filename.isNull())
    {
        return;
    }
    if(j == 1)
    mediaObject->setCurrentSource(Phonon::MediaSource(file[0]));
}

//播放与暂停
void Widget::on_btnPlay_clicked(bool checked)
{
    if(checked)
    {
        ui->btnPlay->setText(tr("暂停"));
        mediaObject->play();
    }
    else
    {
        ui->btnPlay->setText(tr("播放"));
        mediaObject->pause();
    }
}

void Widget::resizeEvent(QResizeEvent * event)
{
    videoWidget->setGeometry(ui->frameVideo->rect());
    slider->setGeometry(ui->frameSeek->rect());
    volumeSlider->setGeometry(ui->frameVolume->rect());
}

//上一曲
void Widget::on_btnShang_clicked()
{  

    *(this->i)--;
    if(*(this->i)<0 || *(this->i)>MAXFILE-1)
    {
        *(this->i)++;
        return;
    }
    mediaObject->stop();
    mediaObject->setCurrentSource(Phonon::MediaSource(file[*(this->i)]));
    ui->btnPlay->setText(tr("暂停"));
    mediaObject->play();
}
//下一曲
void Widget::on_btnXia_clicked()
{

    *(this->i)++;
    if(*(this->i)<0 || *(this->i)>MAXFILE-1)
    {
        *(this->i)--;
       return;
    }
    mediaObject->stop();
    mediaObject->setCurrentSource(Phonon::MediaSource(file[*(this->i)]));
    ui->btnPlay->setText(tr("暂停"));
    mediaObject->play();
}

 //标清 高清
void Widget::on_btnSet_clicked()
{
        /*QMenu *mymenu=new QMenu;
        QMenu *qing = mymenu->addMenu(tr("标清"));
        //QActionGroup *biaoqingGroup = new QActionGroup(biaoqing);
        //connect(biaoqingGroup,SIGNAL(triggered(QAction*)),this,SLOT(on_btnSet_clicked(QAction*)));
        QAction *biaoqing = qing->addAction(tr("标清"));
        QAction *gaoqing = qing->addAction(tr("高清"));
        QAction *chaoqing = qing->addAction(tr("超清"))
        ui->btnSet->setMenu(mymenu);
        */
}

bool Widget::eventFilter(QObject * watched, QEvent * event)
{
    if(watched == videoWidget)
    {
        if(event->type() == QEvent::MouseButtonDblClick)
        {//鼠标双击
            if(videoWidget->isFullScreen())
            {
                videoWidget->exitFullScreen();
                resizeEvent(NULL);
            }else
            videoWidget->enterFullScreen();
            return true;
        }

        if(videoWidget->isFullScreen())
        {
            if(event->type() == QEvent::KeyPress)
            {
                if(((QKeyEvent*)event)->key() == Qt::Key_Escape)
                {
                    videoWidget->exitFullScreen();
                    resizeEvent(NULL);
                    return true;
                }
            }
        }
        return false;
    }

    return false;
}

