#-------------------------------------------------
#
# Project created by QtCreator 2017-01-10T11:06:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Sudoku
TEMPLATE = app


SOURCES += main.cpp \
    sudokumodel.cpp \
    mwidget.cpp \
    sudokumatrix.cpp

HEADERS  += \
    sudokumodel.h \
    mwidget.h \
    sudokumatrix.h

QMAKE_CXXFLAGS=-std=c++11
CONFIG += c++11
