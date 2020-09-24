#include <iostream>
#include "./permutation.cpp"
using namespace std;

int main() {

    Determinant det;

    int a[] = {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };
    cout << det.calculate(a, 3) << endl;
    
    int b[] = {
        71, 12, 3, 5,
        4, 25, 9, 6,
        7, -7, 1, 7,
        3, 2, 1, 4
    };
    cout << det.calculate(b, 4);
}