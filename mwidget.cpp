#include "mwidget.h"
#include <QGridLayout>
#include <QPushButton>

#include <iostream>
using namespace std;

MWidget::MWidget(QWidget *parent) : QWidget(parent)
{
    QGridLayout* layout = new QGridLayout;

    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++){
            uidata_[i][j] = new QLineEdit;
            uidata_[i][j]->setFixedSize(20,20);
            layout->addWidget(uidata_[i][j],i+1,j+1);
        }

    QHBoxLayout* layb = new QHBoxLayout;
    QPushButton* btn = new QPushButton("Count");
    layb->addWidget(btn);
    layout->addLayout(layb,10,1,1,9);
    setLayout(layout);

    connect(btn,SIGNAL(clicked(bool)),this,SLOT(count()));
}

void MWidget::count()
{

    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            if (!(uidata_[i][j]->text()).isEmpty())
                sudokuModel_.assignCeil(i,j,(uidata_[i][j]->text()).toInt());

    sudokuModel_.countSudoku();

    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            uidata_[i][j]->setText(QString::number(sudokuModel_.getData(i,j)));
}

