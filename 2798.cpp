#include<iostream>
#include <algorithm>
using namespace std;
int arr[105];
int main(){
    int n, bound, dap=0;
    cin >> n >> bound;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            for(int k=j;k<n;k++){
                if(i != j && j!=k && arr[i] + arr[j] + arr[k] <= bound){
                    dap = max(dap, arr[i] + arr[j] + arr[k]);
                }
            }
        }
    }
    cout << dap;
}