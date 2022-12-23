#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_0,SIGNAL(clicked()),this, SLOT(digitsNum()));
    connect(ui->pushButton_1,SIGNAL(clicked()),this, SLOT(digitsNum()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this, SLOT(digitsNum()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this, SLOT(digitsNum()));
    connect(ui->pushButton_4,SIGNAL(clicked()),this, SLOT(digitsNum()));
    connect(ui->pushButton_5,SIGNAL(clicked()),this, SLOT(digitsNum()));
    connect(ui->pushButton_6,SIGNAL(clicked()),this, SLOT(digitsNum()));
    connect(ui->pushButton_7,SIGNAL(clicked()),this, SLOT(digitsNum()));
    connect(ui->pushButton_8,SIGNAL(clicked()),this, SLOT(digitsNum()));
    connect(ui->pushButton_9,SIGNAL(clicked()),this, SLOT(digitsNum()));

    connect(ui->pushButton_divide,SIGNAL(clicked()),this, SLOT(mathOp()));
    connect(ui->pushButton_minus,SIGNAL(clicked()),this, SLOT(mathOp()));
    connect(ui->pushButton_plus,SIGNAL(clicked()),this, SLOT(mathOp()));
    connect(ui->pushButton_mult,SIGNAL(clicked()),this, SLOT(mathOp()));

    ui->pushButton_divide->setCheckable(true);
    ui->pushButton_mult->setCheckable(true);
    ui->pushButton_minus->setCheckable(true);
    ui->pushButton_plus->setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digitsNum()
{
    QPushButton *button = static_cast<QPushButton*>(sender());
      double numbers;
      QString new_label;
      if (ui->result_label->text().contains(".") && button->text() == "0")
      {
            ui->result_label->text() + button->text();
      }
      else
      {
          ui->result_label->setText("");
          numbers = (ui->result_label->text() + button->text()).toDouble();
          new_label = QString::number(numbers, 'g', 20);
      }

      ui->result_label->setText(new_label);
}

void MainWindow::on_pushButton_dot_clicked()
{
    if (!(ui->result_label->text().contains('.')))
        ui->result_label->setText(ui->result_label->text() + ".");
}

void MainWindow::mathOp()
{
    QPushButton *button = static_cast<QPushButton*>(sender());
    num_first = ui->result_label->text().toDouble();

    if(ui->pushButton_divide->isChecked())
    {
        ui->result_label->setText("");
        ui->result_label->setText("/");
    }
    else if(ui->pushButton_mult->isChecked())
    {
        ui->result_label->setText("");
        ui->result_label->setText("*");
    }
    else if(ui->pushButton_minus->isChecked())
    {
        ui->result_label->setText("");
        ui->result_label->setText("-");
    }
    else if(ui->pushButton_plus->isChecked())
    {
        ui->result_label->setText("");
        ui->result_label->setText("+");
    }
    button->setChecked(true);
}

void MainWindow::on_pushButton_clear_clicked()
{
    ui->pushButton_divide->setChecked(false);
    ui->pushButton_mult->setChecked(false);
    ui->pushButton_minus->setChecked(false);
    ui->pushButton_plus->setChecked(false);
    ui->result_label->setText("0");
}

void MainWindow::on_pushButton_equal_clicked()
{
    double labelNumber, num_second;
    QString new_label;
    num_second = ui->result_label->text().toDouble();
    if(ui->pushButton_divide->isChecked())
    {
        if(num_second==0)
        {
            ui->result_label->setText("0");
        }
        else
        {
            labelNumber = num_first / num_second;
            new_label = QString::number(labelNumber, 'g', 20);
            ui->result_label->setText(new_label);
        }
        ui->pushButton_divide->setChecked(false);
    }
    else if(ui->pushButton_mult->isChecked())
    {
        labelNumber = num_first * num_second;
        new_label = QString::number(labelNumber, 'g', 20);
        ui->result_label->setText(new_label);
        ui->pushButton_mult->setChecked(false);
    }
    else if(ui->pushButton_minus->isChecked())
    {
        labelNumber = num_first - num_second;
        new_label = QString::number(labelNumber, 'g', 20);
        ui->result_label->setText(new_label);
        ui->pushButton_minus->setChecked(false);
    }
    else if(ui->pushButton_plus->isChecked())
    {
        labelNumber = num_first + num_second;
        new_label = QString::number(labelNumber, 'g', 20);
        ui->result_label->setText(new_label);
        ui->pushButton_plus->setChecked(false);
    }

}

