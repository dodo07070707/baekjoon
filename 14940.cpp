#include<iostream>
#include<queue>
using namespace std;

int arr[1005][1005];
int dist[1005][1005];
bool visited[1005][1005];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin >> n >> m;

    queue<pair<int,int>> q;
    int sx, sy;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> arr[i][j];

            if(arr[i][j] == 2){
                sx = i;
                sy = j;
            }
        }
    }

    q.push({sx, sy});
    visited[sx][sy] = true;
    dist[sx][sy] = 0;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx<0 || ny<0 || nx>=n || ny>=m) continue;
            if(visited[nx][ny]) continue;
            if(arr[nx][ny] == 0) continue;

            visited[nx][ny] = true;
            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j] == 0) cout << 0 << " ";
            else if(!visited[i][j]) cout << -1 << " ";
            else cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
}