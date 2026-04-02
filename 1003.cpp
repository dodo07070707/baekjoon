#include<iostream>
using namespace std;
int dp[41][2];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;

    dp[0][0] = 1; dp[0][1] = 0;
    dp[1][0] = 0; dp[1][1] = 1;

    for(int i = 2; i <= 40; i++){
        dp[i][0] = dp[i-1][0] + dp[i-2][0];
        dp[i][1] = dp[i-1][1] + dp[i-2][1];
    }

    while(n--){
        int k;
        cin >> k;
        cout << dp[k][0] << " " << dp[k][1] << "\n";
    }
}