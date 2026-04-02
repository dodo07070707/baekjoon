#include<iostream>
#include <queue>
#include <utility>
using namespace std;

int arr[1005][1005];
queue <pair<int, int>> q;

int main(){
    //input
    int n,m, day=0, flag=0, daymovecheck;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j] == 1) q.push({i,j});
        }
    }
    //logic
    while(1){
        int size = q.size();
        daymovecheck = 0;

        for(int i=0;i<size;i++){
            int y = q.front().first; 
            int x = q.front().second;
            q.pop();

            if(x-1 >= 0 && arr[y][x-1] == 0){
                arr[y][x-1] = 1;
                q.push({y, x-1});
                daymovecheck = 1;
            }

            if(x+1 < n && arr[y][x+1] == 0){
                arr[y][x+1] = 1;
                q.push({y, x+1});
                daymovecheck = 1;
            }

            if(y+1 < m && arr[y+1][x] == 0){
                arr[y+1][x] = 1;
                q.push({y+1, x});
                daymovecheck = 1;
            }

            if(y-1 >= 0 && arr[y-1][x] == 0){
                arr[y-1][x] = 1;
                q.push({y-1, x});
                daymovecheck = 1;
            }
        }
        if(daymovecheck == 0) break;
        else day++;
    }

    //exception check
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j] == 0) flag = 1;
        }
    }

    //output
    if (flag == 1){
        cout << "-1";
    }
    else {
        cout << day;
    }
}