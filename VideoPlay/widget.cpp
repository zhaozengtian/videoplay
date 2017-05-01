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
    setWindowTitle(tr("С�ﲥ����"));

    mediaObject = new Phonon::MediaObject(this);    //ý�����ĳ�ʼ��(ָ�������Ϊ��ǰ����)
    videoWidget = new Phonon::VideoWidget(ui->frameVideo);    //��Ƶ��������ʼ��(ָ�����ĸ����Ϊ���ڲ���frameVideo)
    Phonon::createPath(mediaObject, videoWidget);   //��ý��������Ƶ�����������
    audioOutput = new Phonon::AudioOutput(Phonon::VideoCategory, this);//��Ƶ��������ʼ��(ָ�����ĸ����Ϊ��ǰ����)
    Phonon::createPath(mediaObject, audioOutput);   //ý��������Ƶ�����������

    slider = new Phonon::SeekSlider(mediaObject, ui->frameSeek);//��������ʼ��(ָ�����ĸ����ΪframeSeek)
    volumeSlider = new Phonon::VolumeSlider(audioOutput, ui->frameVolume);//�������ڶ����ʼ��(ָ�����ĸ����ΪframeVolume)
    audioOutput->setVolume(0.5);//����Ĭ�ϵ�����

    *i=0;
    file = new QString[MAXFILE];


    videoWidget->installEventFilter(this);//��װ�¼�������
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
    QString filename = QFileDialog::getOpenFileName(this, tr("���ļ�"), tr("F:\\music"), "*.mpg; *.avi; *.wmv; *.mp4; *.mp3;;*.*");
    file[j++] = filename;
    if(filename.isEmpty() || filename.isNull())
    {
        return;
    }
    if(j == 1)
    mediaObject->setCurrentSource(Phonon::MediaSource(file[0]));
}

//��������ͣ
void Widget::on_btnPlay_clicked(bool checked)
{
    if(checked)
    {
        ui->btnPlay->setText(tr("��ͣ"));
        mediaObject->play();
    }
    else
    {
        ui->btnPlay->setText(tr("����"));
        mediaObject->pause();
    }
}

void Widget::resizeEvent(QResizeEvent * event)
{
    videoWidget->setGeometry(ui->frameVideo->rect());
    slider->setGeometry(ui->frameSeek->rect());
    volumeSlider->setGeometry(ui->frameVolume->rect());
}

//��һ��
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
    ui->btnPlay->setText(tr("��ͣ"));
    mediaObject->play();
}
//��һ��
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
    ui->btnPlay->setText(tr("��ͣ"));
    mediaObject->play();
}

 //���� ����
void Widget::on_btnSet_clicked()
{
        /*QMenu *mymenu=new QMenu;
        QMenu *qing = mymenu->addMenu(tr("����"));
        //QActionGroup *biaoqingGroup = new QActionGroup(biaoqing);
        //connect(biaoqingGroup,SIGNAL(triggered(QAction*)),this,SLOT(on_btnSet_clicked(QAction*)));
        QAction *biaoqing = qing->addAction(tr("����"));
        QAction *gaoqing = qing->addAction(tr("����"));
        QAction *chaoqing = qing->addAction(tr("����"))
        ui->btnSet->setMenu(mymenu);
        */
}

bool Widget::eventFilter(QObject * watched, QEvent * event)
{
    if(watched == videoWidget)
    {
        if(event->type() == QEvent::MouseButtonDblClick)
        {//���˫��
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

