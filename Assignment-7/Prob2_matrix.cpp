#include<iostream>
#include<vector>

class matrix{
private:
    std::vector<std::vector<int>> matr;
    friend std::ostream &operator<<(std::ostream&, const matrix&);
public:
    matrix(){
        matr.resize(0);
    };
    matrix(std::vector<std::vector<int>> input): matr(input){};
    matrix operator+(matrix const&);
    matrix operator-(matrix const&);
    matrix operator*(matrix const&);
    matrix operator!();

};

matrix matrix::operator+(matrix const& a){
    if(matr.size() != a.matr.size() || matr[0].size() != a.matr[0].size()){
        throw std::invalid_argument("Matrices must have the same dimensions for addition!");
    }
    std::vector<std::vector<int>> result(matr.size(), std::vector<int>(matr.size(),0));
    for (size_t i = 0; i < matr.size(); ++i) {
        for (size_t j = 0; j < matr[0].size(); ++j) {
            result[i][j] = matr[i][j] + a.matr[i][j];
        }
    }
    return matrix(result);
}
matrix matrix::operator-(matrix const& a){
    if(matr.size() != a.matr.size() || matr[0].size() != a.matr[0].size()){
        throw std::invalid_argument("Matrices must have the same dimensions for substruction!");
    }
    std::vector<std::vector<int>> result(matr.size(), std::vector<int>(matr.size(),0));
    for (size_t i = 0; i < matr.size(); ++i) {
        for (size_t j = 0; j < matr[0].size(); ++j) {
            result[i][j] = matr[i][j] - a.matr[i][j];
        }
    }
    return matrix(result);
}
matrix matrix::operator*(matrix const& a){
    if(a.matr.size() != matr[0].size()){
        throw std::invalid_argument("Matrices cannot be multiplied. Invalid dimensions!");
    }
    std::vector<std::vector<int>> result(matr.size(), std::vector<int>(a.matr.size(),0));
    for (size_t i = 0; i < matr.size(); ++i) {
        for (size_t j = 0; j < a.matr[0].size(); ++j) {
            for (size_t k = 0; k < matr[0].size(); ++k) {
                result[i][j] += matr[i][k] * a.matr[k][j];
            }
        }
    }
    return matrix(result);
}
matrix matrix::operator!(){
    std::vector<std::vector<int>> result(matr[0].size(), std::vector<int>(matr.size(),0));
    for (size_t i = 0; i < matr.size(); ++i) {
        for (size_t j = 0; j < matr[0].size(); ++j) {
            result[j][i] = matr[i][j];
        }
    }
    return matrix(result);
}

std::ostream &operator<<(std::ostream &os, const matrix &x){
    for(auto it1: x.matr){
        for(auto it2: it1){
            os<< it2 << "\t";
        }
        os<<std::endl;
    }
    os<<"\v";
    return os;
}

int main(){
    matrix x({ {1, 2, 3}, {4, 5, 6}, {7, 8, 9} });
    matrix y({ {3, 2, 0}, {2, 4, 1}, {5, 2, 7} });

    std::cout<<x+y;
    std::cout<<x-y;
    std::cout<<x*y;
    std::cout<<!x;
    return 0;
}
