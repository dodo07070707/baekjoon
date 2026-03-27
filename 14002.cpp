#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int arr[1000005];
int dp[1000005];
vector<int> lis;

int main(){
    int n;
    cin >> n;

    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    for(int i=0;i<n;i++){
        int pos = lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin();

        if(pos == lis.size()) lis.push_back(arr[i]);
        else lis[pos] = arr[i];

        dp[i] = pos;
    }

    int len = lis.size();
    cout << len << '\n';

    vector<int> ans;
    int cur = len - 1;

    for(int i=n-1;i>=0;i--){
        if(dp[i] == cur){
            ans.push_back(arr[i]);
            cur--;
        }
    }   
    for(int i=len-1;i>=0;i--){
        cout << ans[i] << " ";
    }
}