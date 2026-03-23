#include<iostream>
using namespace std;
int n,m,start;
int arr[1005][1005]={0,};
int visited[1005] = {0,};
int bfs_array[1005] = {0,};
void dfs(int now){
    for(int i=1;i<=n;i++){
        if(arr[now][i] == 1 && now != i && visited[i] == 0){
            visited[i] = 1;
            cout << i << " ";
            dfs(i);
        }
    }
}

void bfs(int start){
    int queue[1005]={0,};
    int front = 0,rear = 0;

    queue[rear++] = start;
    visited[start] = 1;

    while(front < rear){
        int now = queue[front++];
        cout << now << " ";

        for(int i=1;i<=n;i++){
            if(arr[now][i] == 1 && visited[i] == 0){
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

int main(){
    cin >> n >> m >> start;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        arr[a][b] = 1;
        arr[b][a] = 1;
    }
    visited[start] = 1;


    //DFS
    cout << start << " ";
    dfs(start);
    cout << endl;

    //reset
    for(int i=1;i<=n;i++) visited[i] = 0;
    visited[start] = 1;

    //BFS
    bfs(start);
    return 0;
}