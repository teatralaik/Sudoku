#include "sudokumatrix.h"

SudokuMatrix::SudokuMatrix():
    currentLevel_(0)
{
    static ceil c = {0, 0};
    for (int i = 0; i < 9 ; i++){
        vector<ceil> vct;
        for (int j = 0; j < 9 ; j++)
            vct.push_back(c);
        data_.emplace_back(vct);
    }

}

SudokuMatrix::proxy SudokuMatrix::operator [](int i)
{
    return proxy(data_[i]);
}

void SudokuMatrix::assignCeil(int i, int j, int n)
{
    data_[i][j].data_   = n;
    data_[i][j].level_  = currentLevel_;
}

void SudokuMatrix::raiseLevel()
{
    currentLevel_++;
}

void SudokuMatrix::clearDataPerLevel()
{
    for (int i = 0; i < 9 ; i++){
        for (int j = 0; j < 9 ; j++){
            if (data_[i][j].level_ == currentLevel_){
                data_[i][j].data_   = 0;
                data_[i][j].level_  = 0;
            }
        }
    }
    currentLevel_--;
}
