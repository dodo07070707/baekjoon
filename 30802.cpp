#include<iostream>
using namespace std;
int arr[10];
int main(){
    int n;
    cin >> n;
    for(int i=0;i<6;i++){
        cin >> arr[i];
    }
    int x,y;
    cin >> x >> y;
    int cnt = 0;
    for(int i=0;i<6;i++){
        if(arr[i]%x == 0) cnt = cnt + arr[i]/x;
        else cnt = cnt + (arr[i]/x)+1;
    }
    cout << cnt << endl << n/y << " " << n%y;
}