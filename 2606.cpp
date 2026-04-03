#include<iostream>
#include<algorithm>
#include<queue>
int arr[105][105] = {0,};
int visited[105] = {0,};
using namespace std;
queue <int> dp;
int main(){
    int com, n;
    cin >> com >> n;
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        arr[a][b] = 1; arr[b][a] = 1;
    }
    dp.push(1);
    visited[1] = 1;
    while(1){
        if(dp.empty() == true) break;
        for(int i=1;i<=com;i++){
            if(arr[dp.front()][i] == 1 && visited[i] == 0 && dp.front() != i){
                visited[i] = 1;
                dp.push(i);
            }
        }
        dp.pop();
    }
    int cnt = 0;
    for(int i=1;i<=com;i++){
        if(visited[i] == 1) cnt++;
        //cout << visited[i] << " ";
    }
    cout << cnt-1;
}