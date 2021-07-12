from PyQt5.QtCore import QUrl
from PyQt5.QtMultimedia import QMediaContent, QMediaPlayer
from PyQt5.QtMultimediaWidgets import QVideoWidget
from PyQt5.QtWidgets import QApplication, QMainWindow

filename = "/home/uba/mouse.mp4"


class VideoPlayer(QMainWindow):
    def __init__(self, parent=None):
        super(VideoPlayer, self).__init__(parent)
        self.mediaPlayer = QMediaPlayer(None, QMediaPlayer.VideoSurface)
        video_widget = QVideoWidget()
        self.setCentralWidget(video_widget)
        self.mediaPlayer.setVideoOutput(video_widget)
        self.mediaPlayer.setMedia(
            QMediaContent(QUrl.fromLocalFile(filename)))
        video_widget.setFullScreen(True)
        self.mediaPlayer.play()


if __name__ == '__main__':
    import sys
    app = QApplication(sys.argv)
    player = VideoPlayer()
    player.setWindowTitle("Player")
    player.resize(600, 400)
    player.show()
    sys.exit(app.exec_())