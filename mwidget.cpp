#include "mwidget.h"
#include <QGridLayout>
#include <QPushButton>


#include <iostream>
using namespace std;

void MWidget::setResult(bool result)
{
    if (result){
        setData();
        label_->setStyleSheet("QLabel { color : green; }");
        label_->setText("Good!");

    }
    else{

        label_->setStyleSheet("QLabel { color : red; }");
        label_->setText("Bad!");
    }

}

void MWidget::setData()
{
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++){
            int d = sudokuModel_.getData(i,j);
            uidata_[i][j]->setText((d == 0 ? QString(""):QString::number(d)));
        }
}

MWidget::MWidget(QWidget *parent) : QWidget(parent)
{
    QGridLayout* layout = new QGridLayout;

    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++){
            uidata_[i][j] = new QLineEdit;
            uidata_[i][j]->setFixedSize(20,20);
            layout->addWidget(uidata_[i][j],i+1,j+1);
        }

    QGridLayout* layb = new QGridLayout;
    QPushButton* btnCount       = new QPushButton("Count");
    QPushButton* btnClear       = new QPushButton("Clear All");
    QPushButton* btnClearSol    = new QPushButton("Clear sol");
    QPushButton* btnHint        = new QPushButton("Hint");

    QHBoxLayout* layl = new QHBoxLayout;
    label_ = new QLabel;
    label_->setAlignment(Qt::AlignHCenter);

    layb->addWidget(btnCount, 1, 1);
    layb->addWidget(btnClear, 1, 2);
    layb->addWidget(btnClearSol, 2, 1);
    layb->addWidget(btnHint, 2, 2);
    layout->addLayout(layb,11,1,1,9);

    layl->addWidget(label_);
    layout->addLayout(layl,10,1,1,9);

    setLayout(layout);

    connect(btnCount,SIGNAL(clicked(bool)),this,SLOT(count()));
    connect(btnClear,SIGNAL(clicked(bool)),this,SLOT(clear()));
}

void MWidget::count()
{
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            if (!(uidata_[i][j]->text()).isEmpty())
                sudokuModel_.assignCeil(i,j,(uidata_[i][j]->text()).toInt());

    setResult(sudokuModel_.countSudoku());
}

void MWidget::clear()
{
    sudokuModel_.clearAll();
    setData();
    label_->clear();
}

