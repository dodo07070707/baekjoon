#include<iostream>
#include<queue>
using namespace std;
int arr[1005][1005] = {0,};
int visited[1005] = {0,};
queue<int> dfs;
int main(){
    int node, n;
    cin >> node >> n;
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        arr[a][b] = 1;
        arr[b][a] = 1;
    }
    int cnt=0;
    for(int i=1;i<=node;i++){
        if(visited[i] == 1)continue;
        else{
            cnt++;
            dfs.push(i);
            visited[i] = 1;
            while(1){
                if(dfs.empty() == true)break;
                for(int j=1;j<=node;j++){
                    if(arr[dfs.front()][j] == 1 && visited[j] == 0 && dfs.front() != j){
                        visited[j] = 1;
                        dfs.push(j);
                    }
                }
            dfs.pop();
            } 
        }
    }
    cout << cnt;
}