#include<iostream>
#include<algorithm>
using namespace std;

int arr[1000005];

int main(){
    int n;
    cin >> n;

    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    int lis[1000005];
    int len = 0;

    for(int i=0;i<n;i++){
        int pos = lower_bound(lis, lis+len, arr[i]) - lis;
        lis[pos] = arr[i];

        if(pos == len) len++;
    }

    cout << len;
}