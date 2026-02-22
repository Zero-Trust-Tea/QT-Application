#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

    // вывод диалогового окна - QMessageBox::about(this, "Header", "Text inside");
    // QMessageBox::aboutQt(this, "Header");
    // диалоговое окно об ошибке - QMessageBox::critical(this, "Header", "Text inside");

    // диалоговое окно с информацией - QMessageBox::information(this, "Header", "Text inside");
    // предупреждение - QMessageBox::warning(this, "Header", "Text inside");
    // вопрос (да/нет) - QMessageBox::question(this, "Header", "Text inside");
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Header", "Do you want to exit ?",
                                        QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        QApplication::quit();
    } else {
        qDebug() << "Кнопка нет была нажата";
        ui->label->setText("Кнопка нет была нажата.");
    }
}

