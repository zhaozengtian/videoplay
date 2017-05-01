#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <phonon>

namespace Ui {
    class Widget;
}

class Widget : public QWidget {
    Q_OBJECT
public:
    Widget(QWidget *parent = 0);
    ~Widget();

    bool eventFilter(QObject * watched, QEvent * event); //双击屏幕 全屏播放

protected:
    void changeEvent(QEvent *e);
    void resizeEvent(QResizeEvent * event);

private:
    Ui::Widget *ui;

    Phonon::MediaObject *mediaObject;   //媒体对象
    Phonon::VideoWidget *videoWidget;   //视频输出
    Phonon::AudioOutput *audioOutput;   //音频输出
    Phonon::SeekSlider *slider;         //播放进度条
    Phonon::VolumeSlider *volumeSlider; //音量调节

private slots:
    void on_btnStop_clicked();  //暂停
    void on_btnPlay_clicked(bool checked); //播放
    void on_btnMedia_clicked(); //
    void on_btnSet_clicked();

};

#endif // WIDGET_H
