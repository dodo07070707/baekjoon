#include<iostream>
using namespace std;
long long fac(int n) {
    if (n <= 1)
        return 1;
    else
        return n * fac(n - 1);
}

int main(){
    int n,k;
    cin >> n >> k;
    cout << fac(n) / fac(n-k) / fac(k);
}