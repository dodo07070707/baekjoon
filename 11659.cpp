#include<iostream>
using namespace std;
int arr[100005];
int hap[100005] = {0,};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int temp=0;
    for(int i=0;i<n;i++){
        temp = arr[i] + temp;
        hap[i+1] = temp;
    }
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        cout << hap[b] - hap[a-1] << "\n";
    }
}