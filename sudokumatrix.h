#ifndef SUDOKUMATRIX_H
#define SUDOKUMATRIX_H
#include <vector>
using namespace std;

class SudokuMatrix
{
    struct ceil{
        int data_;
        int level_;
    };
    vector< vector<ceil> > data_;

    struct proxy{
        vector<ceil>& data_;

        proxy(vector<ceil>& data):
            data_(data){}

        int operator [](int i){
            return data_[i].data_;
        }
    };

    int currentLevel_;
public:
    SudokuMatrix();

    proxy operator [](int i);
    void assignCeil(int i, int j, int n);
    void raiseLevel();
    void clearDataPerLevel();





};

#endif // SUDOKUMATRIX_H
