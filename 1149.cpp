#include<iostream>
#include<algorithm>
using namespace std;

int house[1005][3]={0,};
int cost[1005][3];
int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
    }
    for(int i=1;i<=n;i++){
        house[i][0] = min(house[i-1][1], house[i-1][2]) + cost[i-1][0];
        house[i][1] = min(house[i-1][0], house[i-1][2]) + cost[i-1][1];
        house[i][2] = min(house[i-1][0], house[i-1][1]) + cost[i-1][2];
    }

    cout << min(min(house[n][0], house[n][1]), house[n][2]) << "\n";
}

//g++ 1149.cpp -o main      // ./main