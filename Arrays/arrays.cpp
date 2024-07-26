#include <iostream>
#include <string>
using std::cout;
using std::endl;
#include <vector>
using std::vector;

#define height 3
#define width 4

int main(){
    // Statically allocated
    int score[6];
    // must match number of elements and declaration.
    int score2[4] = {1,2,3,4}; 
    // cout << sizeof(score2)/sizeof(int) << endl;
    // can go beyond its range and compiler and runtime system will NOT detect these errors
    // cout << score[65]; // Returns 0
    // string a[3];
    // cout << a[5]; // string returns nothing

    // multidimensional arrays:
    int table[height][width] = {1,2,3,45,6,77,4,32,1,2,3,3};

    // using indexes
    for(int i = 0 ; i < height; i++){
        for(int j = 0; j < width; j++){
            cout << table[i][j]<<' ';
        }
    }
    cout<<endl;

    //using array to pointer decay
    for(int i = 0;i < height*width; i++){
        cout << *(*(table+0)+i) <<' ';
    }
    cout<<endl;
    for(int i = 0;i < height; i++){
        for(int j = 0; j < width; j++){
            cout << *(*(table+i)+j) <<' ';
        }
    }
    cout<<endl;

    cout <<*(*(table+1))<<endl;
    cout <<*(*(table+1)+7)<<endl;
    cout <<*(*(table+1)-8)<<endl;

    // more explainations in arrays.md
}