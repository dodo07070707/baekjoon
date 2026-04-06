#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[501];
int match[501];
bool visited[501];

bool dfs(int x) {
    for (int y : adj[x]) {
        if (visited[y]) continue;
        visited[y] = true;

        if (match[y] == 0 || dfs(match[y])) {
            match[y] = x;
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }

    int matching = 0;

    for (int x = 1; x <= 500; x++) {
        fill(visited, visited + 501, false);
        if (dfs(x)) matching++;
    }

    if (matching % 2 == 1)
        cout << "Mirko";
    else
        cout << "Slavko";

    return 0;
}