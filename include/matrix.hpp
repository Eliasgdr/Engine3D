#ifndef ENGINE3D_MATRIX_HPP
#define ENGINE3D_MATRIX_HPP

#include<iostream>

using namespace std;

template <typename T>
class Matrix{
public:
    int height;
    int width;
    T** grid;

    Matrix(int h, int w){
        if(h<=0 || w<=0){
            cout<<"Matrix: Invalid value\n";
            exit(1);
        }
        height = h;
        width = w;
        grid = new T*[height];
        for (int i = 0; i < height; ++i) {
            grid[i] = new T[width];
        }
    }

    T getVal(int y, int x){
        if(y<0 || x<0 || y>=height || x>=width ){
            cout<<"getVal: Invalid value\n";
            exit(1);
        }
        return grid[y][x];
    }

    void setVal(int y, int x, T val){
        if(y<0 || x<0 || y>=height || x>=width ){
            cout<<"setVal: Invalid value\n";
            exit(1);
        }
        grid[y][x]=val;
    }

    void fill(T val){
        for (int i=0; i<height;i++){
            for(int j=0; j<width;j++){
                setVal(i,j,val);
            }
        }
    }

    void display(){
        for (int i=0;i<height;i++){
            cout<<"| ";
            for(int j=0;j<width;j++){
                cout<<grid[i][j]<<" ";
            }
            cout<<"|\n";
        }
    }

    Matrix operator + (const Matrix& m){
        if(height!=m.height || width!=m.width){
            cout<<"operator +: Incompatible matrices\n";
            exit(1);
        }
        Matrix temp = Matrix(height, width);
        for (int y=0;y<height;y++){
            for(int x=0;x<width;x++){
                temp.grid[y][x] = grid[y][x] + m.grid[y][x];
            }
        }
        return temp;
    }

    Matrix operator * (const Matrix& m){
        if(m.height != width){
            cout<<"operator *: Incompatible matrices\n";
            exit(1);
        }
        Matrix temp = Matrix(height, m.width);
        for (int y=0;y<height;y++){
            for(int x=0;x<m.width;x++){
                T val = 0;
                for(int i=0;i<width;i++){
                    val += grid[y][i] * m.grid[i][x];
                }
                temp.grid[y][x]=val;
            }
        }
        return temp;
    }
};

typedef Matrix<int> iMatrix;
typedef Matrix<float> fMatrix;
typedef Matrix<double> dMatrix;

iMatrix identity(int size){
    if(size<=0){
        cout<<"fill: Invalid value\n";
        exit(1);
    }
    iMatrix m = iMatrix(size, size);
    m.fill(0);
    for (int i=0;i<size;i++){
        m.setVal(i,i,1);
    }
    return m;
}

#endif //ENGINE3D_MATRIX_HPP