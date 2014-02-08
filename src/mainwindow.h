#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    bool gridDrawn;
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void drawGrid();
    
private:
    Ui::MainWindow *ui;

    void configure();
    void initializeGraphics();
};

#endif // MAINWINDOW_H
