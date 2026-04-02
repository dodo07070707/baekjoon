#include<iostream>
using namespace std;
double arr[10005];
int main(){
    int n,max=0;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
        if (max < arr[i]) max = arr[i];
    }
    double hap = 0;
    for(int i=0;i<n;i++){
        arr[i] = arr[i] / max *100;
        hap = hap + arr[i];
    }
    cout << (double)hap / n;
}