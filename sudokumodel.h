#ifndef SUDOKUMODEL_H
#define SUDOKUMODEL_H
#include <vector>
using namespace std;

class SudokuModel
{

    bool checkV(int (&mas)[9][9], int n, int row);
    bool checkH(int (&mas)[9][9], int n, int col);
    bool checkB(int (&mas)[9][9], int n, int colb, int rowb);

    struct undefCell{
        vector<int> var_;
        int row_;
        int col_;
        bool enable_;

        undefCell():
            enable_(false){}

        bool isEmpty(){
            return !enable_;
        }

        void setData(int row, int col, vector<int>& n){
            enable_ = true;
            if (row_ != row || col_ != col){
                var_.clear();
                row_ = row, col_ = col;
            }
            var_.insert(var_.end(),n.begin(),n.end());
        }
    };

    undefCell checkDefine(int (&mas)[9][9]);
public:
    SudokuModel();
    bool countSudoku(int (&mas)[9][9]);
};

#endif // SUDOKUMODEL_H
