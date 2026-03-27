#include<iostream>
#include<algorithm>
using namespace std;
int arr[1005];
int dp[1005];
int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
        dp[i] = 1;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[j] > arr[i]) dp[i] = max(dp[i],dp[j]+1);
        }
    }

    int dap = 0;
    for(int i=0;i<n;i++){
        dap = max(dap,dp[i]);
    }

    cout << dap;
}