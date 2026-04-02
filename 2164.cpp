#include<iostream>
#include<queue>
using namespace std;
queue<int> q;
int main(){
    int n;
    cin >> n;
    int last;
    for(int i=1;i<=n;i++) q.push(i);
    while(1){
        if(q.empty() == true){
            cout << last;
            return 0;
        }
        last = q.front();
        q.pop();
        if(q.empty() == true){
            cout << last;
            return 0;
        }
        last = q.front();
        q.pop();
        q.push(last);
    }
}