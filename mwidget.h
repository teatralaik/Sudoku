#ifndef MWIDGET_H
#define MWIDGET_H

#include <QObject>
#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include "sudokumodel.h"

class MWidget : public QWidget
{
    Q_OBJECT
    SudokuModel sudokuModel_;
    QLineEdit* uidata_[9][9];
    QLabel * label_;

    void setResult(bool result);
    void setData();
public:
    explicit MWidget(QWidget *parent = 0);

signals:

public slots:
    void count();
    void clear();
    void clearSol();
};

#endif // MWIDGET_H
