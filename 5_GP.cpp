#include <iostream>
#include <cmath>
using namespace std;

//iterative 
int SumGeoSeries1(int a, int r, int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += a;   
        a *= r;     
    }
    return sum;
}

//formula 
int SumGeoSeries2(int a, int r, int n) {
    if (r == 1) {
        return a * n; 
    }
    return a * (pow(r, n) - 1 ) / (r - 1);
}

int main() {
    int a1= 1, r1 = 2, n1 = 5;
    int a2= 1, r2 = 2, n2 = 6;

    cout << SumGeoSeries1(a1, r1, n1) << endl;
    cout << SumGeoSeries2(a2, r2, n2) << endl;

    return 0;
}
