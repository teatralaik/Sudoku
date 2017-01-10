#ifndef MWIDGET_H
#define MWIDGET_H

#include <QObject>
#include <QWidget>
#include <QLineEdit>
#include "sudokumodel.h"

class MWidget : public QWidget
{
    Q_OBJECT
    SudokuModel sudokuModel_;
    QLineEdit* uidata_[9][9];
public:
    explicit MWidget(QWidget *parent = 0);

signals:

public slots:
    void count();
};

#endif // MWIDGET_H
