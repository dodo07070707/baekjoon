#include<iostream>
#include<algorithm>
using namespace std;
int arr[1005];
int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    sort(arr, arr+n);
    int hap=0, dap=0;
    for(int i=0;i<n;i++){
        hap = hap + arr[i];
        dap = dap + hap;
    }
    cout << dap;
}