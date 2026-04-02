#include<iostream>
#include<algorithm>
#include<utility>
using namespace std;
int arr[10000005];
int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++) cin >> arr[i];
    sort(arr, arr+n);
    cout << arr[0] << " " << arr[n-1];
}