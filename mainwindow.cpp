#include "mainwindow.h"
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QVideoWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    const QString video_file{"mouse.mp4"};
    auto player = new QMediaPlayer;

    auto videoWidget = new QVideoWidget;
    player->setVideoOutput(videoWidget);

    this->setCentralWidget(videoWidget);
    player->setMedia(QUrl::fromLocalFile(video_file));
    player->play();
    videoWidget->setFullScreen(true);
}

MainWindow::~MainWindow()
{
}

