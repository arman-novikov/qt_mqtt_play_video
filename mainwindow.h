#pragma once

#include <QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(const QString& app_dir, QWidget *parent = nullptr);
    ~MainWindow();
private:
    QString _app_dir;
};
