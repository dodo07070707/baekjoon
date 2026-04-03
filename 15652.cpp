#include<iostream>
using namespace std;
int n, m;
int arr[10];
bool visited[10];

void dfs(int depth, int start) {
    if (depth == m) {
        for (int i = 0; i < m; i++) {
            cout << arr[i] << " ";
        }
        cout << '\n';
        return;
    }

    for (int i = start; i <= n; i++) {
        //if (!visited[i]) {
            visited[i] = true;
            arr[depth] = i;

            dfs(depth + 1,i);

            visited[i] = false;
        //}
    }
}

int main() {
    cin >> n >> m;
    dfs(0,1);
}