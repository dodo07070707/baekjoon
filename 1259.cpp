#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n;
    while(1){
        int arr[10] = {0,};
        cin >> n;
        if(n == 0) break;
        int cnt=0;
        while(n!=0){
            arr[cnt] = n % 10;
            n = n / 10;
            cnt++;
        }
        int flag=0;
        for(int i=0;i<cnt/2;i++){
            if(arr[i] != arr[cnt-i-1]) flag = 1;
        }
        if(flag == 1) cout << "no" << endl;
        else cout << "yes" << endl;
    }
}