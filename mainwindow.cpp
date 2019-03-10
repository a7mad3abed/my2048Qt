#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "board.h"
#include <QKeyEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    myBoard{new Board()}
{
    setFocusPolicy(Qt::FocusPolicy::StrongFocus);
    ui->setupUi(this);
    myBoard->initBoard();
    drawBoard();
    connect(ui->newGameButton, &QPushButton::clicked, this, &MainWindow::newGame);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete myBoard;
}

void MainWindow::setLabCol(QLabel *lab, int val)
{
    switch (val) {
    case 0:
        lab->setStyleSheet("background-color: rgb(205, 193, 180);");
        lab->setText("");
        break;
    case 2:
        lab->setStyleSheet("background-color: rgb(238, 228, 218);");
        lab->setText("2");
        break;
    case 4:
        lab->setStyleSheet("background-color: rgb(237, 224, 200);");
        lab->setText("4");
        break;
    case 8:
        lab->setStyleSheet("background-color: rgb(242, 177, 121);");
        lab->setText("8");
        break;
    case 16:
        lab->setStyleSheet("background-color: rgb(245, 149, 99);");
        lab->setText("16");
        break;
    case 32:
        lab->setStyleSheet("background-color: rgb(246, 124, 95);");
        lab->setText("32");
        break;
    case 64:
        lab->setStyleSheet("background-color: rgb(246, 94, 59);");
        lab->setText("64");
        break;
    case 128:
        lab->setStyleSheet("background-color: rgb(237, 207, 114);");
        lab->setText("128");
        break;
    case 256:
        lab->setStyleSheet("background-color: rgb(237, 204, 97);");
        lab->setText("256");
        break;
    case 512:
        lab->setStyleSheet("background-color: darkRed");
        lab->setText("512");
        break;
    case 1024:
        lab->setStyleSheet("background-color: darkGreen");
        lab->setText("1024");
        break;
    case 2048:
        lab->setStyleSheet("background-color: black");
        lab->setText("2048");
        break;
    case 4096:
        lab->setStyleSheet("background-color: darkblue");
        lab->setText("4096");
        break;
    case 8192:
        lab->setStyleSheet("background-color: darkYellow");
        lab->setText("8192");

    }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Right:
        myBoard->right();
        drawBoard();
        break;
    case Qt::Key_Left:
        myBoard->left();
        drawBoard();
        break;
    case Qt::Key_Up:
        myBoard->up();
        drawBoard();
        break;
    case Qt::Key_Down:
        myBoard->down();
        drawBoard();
    }
}

void MainWindow::drawBoard()
{
    std::vector<int> values;
    std::vector<Cell> tempBoard = myBoard->exportBorad();

    for (int i = 0; i<16; i++)
    {
        values.push_back(tempBoard[i].value());
    }

    QString labelVal = QString::number(values[0]);
    setLabCol(ui->label_1, values[0]);
    labelVal = QString::number(values[1]);
    setLabCol(ui->label_2, values[1]);
    labelVal = QString::number(values[2]);
    setLabCol(ui->label_3, values[2]);
    labelVal = QString::number(values[3]);
    setLabCol(ui->label_4, values[3]);
    labelVal = QString::number(values[4]);
    setLabCol(ui->label_5, values[4]);
    labelVal = QString::number(values[5]);
    setLabCol(ui->label_6, values[5]);
    labelVal = QString::number(values[6]);
    setLabCol(ui->label_7, values[6]);
    labelVal = QString::number(values[7]);
    setLabCol(ui->label_8, values[7]);
    labelVal = QString::number(values[8]);
    setLabCol(ui->label_9, values[8]);
    labelVal = QString::number(values[9]);
    setLabCol(ui->label_10, values[9]);
    labelVal = QString::number(values[10]);
    setLabCol(ui->label_11, values[10]);
    labelVal = QString::number(values[11]);
    setLabCol(ui->label_12, values[11]);
    labelVal = QString::number(values[12]);
    setLabCol(ui->label_13, values[12]);
    labelVal = QString::number(values[13]);
    setLabCol(ui->label_14, values[13]);
    labelVal = QString::number(values[14]);
    setLabCol(ui->label_15, values[14]);
    labelVal = QString::number(values[15]);
    setLabCol(ui->label_16, values[15]);

    if(myBoard->gameIsOver){
        ui->label_17->setText(tr("Game Over!"));
    } else ui->label_17->setText("");
    ui->label->setText(QString("Score: ") + QString::number(myBoard->score));
}

void MainWindow::newGame()
{
    setFocusPolicy(Qt::StrongFocus);
    myBoard = new Board();
    myBoard->initBoard();
    myBoard->score = 0;
    myBoard->gameIsOver = false;
    drawBoard();
}
