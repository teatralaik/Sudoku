#ifndef SUDOKUMODEL_H
#define SUDOKUMODEL_H
#include <vector>
#include "sudokumatrix.h"
using namespace std;

class SudokuModel
{
    enum retCheck{FullID, ErrorID, NotFull};

    SudokuMatrix sudokuMatrix_;

    bool checkV(int n, int row);
    bool checkH(int n, int col);
    bool checkB(int n, int rowb, int colb);

    struct undefCell{
        vector<int> var_;
        int row_;
        int col_;

        void setData(int row, int col, vector<int>& n){
            if (row_ != row || col_ != col){
                var_.clear();
                row_ = row, col_ = col;
            }
            var_.clear();
            var_ = n;
        }
    };

    retCheck checkDefine(undefCell&);
public:
    SudokuModel();
    bool countSudoku();
    void assignCeil(int i, int j, int n);
    int getData(int i, int j);
    void clearAll();

};

#endif // SUDOKUMODEL_H
