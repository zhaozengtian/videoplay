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

    bool eventFilter(QObject * watched, QEvent * event); //˫����Ļ ȫ������

protected:
    void changeEvent(QEvent *e);
    void resizeEvent(QResizeEvent * event);

private:
    Ui::Widget *ui;

    Phonon::MediaObject *mediaObject;   //ý�����
    Phonon::VideoWidget *videoWidget;   //��Ƶ���
    Phonon::AudioOutput *audioOutput;   //��Ƶ���
    Phonon::SeekSlider *slider;         //���Ž�����
    Phonon::VolumeSlider *volumeSlider; //��������

private slots:
    void on_btnStop_clicked();  //��ͣ
    void on_btnPlay_clicked(bool checked); //����
    void on_btnMedia_clicked(); //
    void on_btnSet_clicked();

};

#endif // WIDGET_H