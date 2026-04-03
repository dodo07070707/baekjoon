#include <iostream>
#include<algorithm>
using namespace std;
int n, m;
int arr[10];
bool visited[10];
int given[10];

void dfs(int depth) {
    if (depth == m) {
        for (int i = 0; i < m; i++) {
            cout << arr[i] << " ";
        }
        cout << '\n';
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            arr[depth] = given[i];

            dfs(depth + 1);

            visited[i] = false;
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> given[i];
    }
    sort(given, given+n);
    dfs(0);
}