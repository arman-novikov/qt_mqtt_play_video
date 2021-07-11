#include "mainwindow.h"
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QVideoWidget>
#include <QDir>

MainWindow::MainWindow(const QString& app_dir, QWidget *parent)
    : QMainWindow(parent), _app_dir(app_dir)
{

    const QString video_file{"mouse.mp4"};
    const QString mouse_file = this->_app_dir + QDir::separator() + video_file;

    auto player = new QMediaPlayer;

    auto videoWidget = new QVideoWidget;
    player->setVideoOutput(videoWidget);

    /* looping
    QMediaPlaylist *playlist = new QMediaPlaylist();
    playlist->addMedia(QUrl("qrc:/sounds/backgroundmusic.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    QMediaPlayer *music = new QMediaPlayer();
    music->setPlaylist(playlist);
    music->play();
     */

    this->setCentralWidget(videoWidget);
    player->setMedia(QUrl::fromLocalFile(mouse_file));
    player->play();
    videoWidget->setFullScreen(true);
}

MainWindow::~MainWindow()
{
}

