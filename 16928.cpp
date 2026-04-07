#include<iostream>
#include<queue>
#include<memory.h>
using namespace std;
int tp[105] = {0,};
int bfs[105];
queue <int> q;
int main(){
    memset(bfs, -1, sizeof(bfs));
    int ladder, snake;
    cin >> ladder >> snake;
    for(int i=0;i<ladder+snake;i++){
        int a,b;
        cin >> a >> b;
        tp[a] = b;
    }
    q.push(1);
    bfs[1] = 0;
    while(q.empty() == 0){
        int now = q.front();
        q.pop();
        for(int i=1;i<=6;i++){
            int next = now + i;
            if(next>100) continue;
            if(tp[next] != 0){
                next = tp[next];
            }
            if(bfs[next] == -1){
                bfs[next] = bfs[now] + 1;
                q.push(next);
            }
        }
    }
    cout << bfs[100];
}