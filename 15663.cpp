#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[10];
int input[10];
bool visited[10];

void dfs(int depth) {
    if (depth == m) {
        for (int i = 0; i < m; i++) {
            cout << arr[i] << " ";
        }
        cout << '\n';
        return;
    }

    int prev = -1;

    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;
        if (prev == input[i]) continue;

        visited[i] = true;
        arr[depth] = input[i];
        prev = input[i];

        dfs(depth + 1);

        visited[i] = false;
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }

    sort(input, input + n);

    dfs(0);
}