#include "sudokumodel.h"
#include <iostream>
#include <vector>
#include <memory.h>
#include <algorithm>
using namespace std;

SudokuModel::retCheck SudokuModel::checkDefine(SudokuModel::undefCell& cell)
{
   vector<int> p;
   p.reserve(10);
   int minCount = 10;
   bool full = true;

   for(int i = 0; i < 9; i++)
       for(int j = 0; j < 9; j++){
           if (sudokuMatrix_[i][j] == 0){
               p.clear();
               for(int n = 1; n < 10; n++){
                   if (checkV(n,i) &&
                       checkH(n,j) &&
                       checkB(n,i - i%3, j - j%3))
                       p.push_back(n);
               }

               if(!p.empty()){
                    int sizeP = p.size();
                    if (sizeP == 1){
                        sudokuMatrix_.assignCeil(i, j, p.back());
                        i = 0, j = 0;
                        full = true;
                        minCount = 10;
                    }
                    else{
                        if (minCount > sizeP){
                            minCount = sizeP;
                            cell.setData(i,j,p);
                        }
                        full = false;
                    }
               }
               else return ErrorID;
           }
       }

   return (full ? FullID : NotFull);
}

bool SudokuModel::checkV( int n, int row)
{
    for(int i = 0; i<9; i++)
        if (sudokuMatrix_[row][i] == n)
            return false;
    return true;
}

bool SudokuModel::checkH(int n, int col)
{
    for(int i = 0; i<9; i++)
        if (sudokuMatrix_[i][col] == n)
            return false;
    return true;
}

bool SudokuModel::checkB(int n, int rowb, int colb)
{

    for(int i = rowb; i<rowb+3; i++)
        for(int j = colb; j<colb+3; j++)
            if (sudokuMatrix_[i][j] == n)
                return false;
    return true;
}

SudokuModel::SudokuModel()
{

}

bool SudokuModel::countSudoku()
{
    sudokuMatrix_.raiseLevel();
    undefCell cell;
    retCheck ret = checkDefine(cell);
    if (ret == ErrorID)
        return false;


    if (ret == NotFull){
        for(auto x: cell.var_){
            sudokuMatrix_.raiseLevel();
            sudokuMatrix_.assignCeil(cell.row_, cell.col_, x);
            if (countSudoku())
                return true;
            sudokuMatrix_.clearDataPerLevel();
        }
        sudokuMatrix_.reduceLevel();
        return false;
    }

    return true;
}

void SudokuModel::assignCeil(int i, int j, int n)
{
    sudokuMatrix_.assignCeil(i,j,n);
}

int SudokuModel::getData(int i, int j)
{
    return sudokuMatrix_[i][j];
}

void SudokuModel::clearAll()
{
    sudokuMatrix_.clearAll();
}

void SudokuModel::clearSol()
{
    sudokuMatrix_.clearSol();
}

bool SudokuModel::hintSudoku()
{
    return true;
}
