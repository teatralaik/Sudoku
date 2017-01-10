#include "sudokumodel.h"
#include <iostream>
#include <vector>
#include <memory.h>
#include <algorithm>
using namespace std;

SudokuModel::undefCell SudokuModel::checkDefine(int (&mas)[9][9])
{
   vector<int> p;
   undefCell ret;
   int minCount = 10;
   p.reserve(10);
   for(int i = 0; i < 9; i++)
       for(int j = 0; j < 9; j++){
           if (mas[i][j] == 0){
               p.clear();
               for(int n = 1; n < 10; n++){
                   if (checkV(mas,n,i) &&
                       checkH(mas,n,j) &&
                       checkB(mas,n,i - i%3, j - j%3))
                       p.push_back(n);
               }

               if(!p.empty()){
                    int sizeP = p.size();
                    if (sizeP == 1){
                        mas[i][j] = p.back();
                        i = 0, j = 0;
                    }
                    else{
                        if (minCount > sizeP){
                            minCount = sizeP;
                            ret.setData(i,j,p);
                        }
                    }
               }
               else
                   throw std::runtime_error("BAD SUDOKU");
           }
       }

   return ret;
}

bool SudokuModel::checkV(int (&mas)[9][9], int n, int row)
{
    for(int i = 0; i<9; i++)
        if (mas[row][i] == n)
            return false;
    return true;
}

bool SudokuModel::checkH(int (&mas)[9][9], int n, int col)
{
    for(int i = 0; i<9; i++)
        if (mas[i][col] == n)
            return false;
    return true;
}

bool SudokuModel::checkB(int (&mas)[9][9], int n, int colb, int rowb)
{

    for(int i = rowb; i<rowb+3; i++)
        for(int j = colb; j<colb+3; j++)
            if (mas[i][j] == n)
                return false;
    return true;
}

SudokuModel::SudokuModel()
{

}

bool SudokuModel::countSudoku(int (&mas)[9][9])
{
    undefCell cell;
    try{
        cell = checkDefine(mas);}
    catch(...){
        return false;
    }

    if (!cell.isEmpty()){
        vector<int>::iterator it;

        int masPr[9][9];
        for(it = cell.var_.begin(); it != cell.var_.end(); ++it){
            memcpy(masPr,mas,sizeof(masPr));

            masPr[cell.row_][cell.col_] = *it;
            if (countSudoku(masPr)){
                memcpy(mas,masPr,sizeof(masPr));
                return true;
            }
        }

        mas[cell.row_][cell.col_] = 0;
        return false;
    }
}
