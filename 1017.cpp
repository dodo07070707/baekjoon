#include <iostream>
#include <algorithm>
using namespace std;
int n;
int arr[55];
bool sosu[2005];
int adj[55][55];
int adjsize[55];
int match[55];
bool visited[55];

bool dfs(int x) {
    for (int i = 0; i < adjsize[x]; i++) {
        int next = adj[x][i];
        if (visited[next]) continue;
        visited[next] = true;
        if (match[next] == -1 || dfs(match[next])) {
            match[next] = x;
            return true;
        }
    }
    return false;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    fill(sosu, sosu + 2005, true);
    sosu[0] = sosu[1] = false;
    for (int i = 2; i * i < 2005; i++) {
        if (sosu[i]) {
            for (int j = i * i; j < 2005; j += i)
                sosu[j] = false;
        }
    }
    int answer[55];
    int ansSize = 0;

    for (int i = 1; i < n; i++) {
        if (!sosu[arr[0] + arr[i]]) continue;
        for (int j = 0; j < 55; j++) adjsize[j] = 0;
        for (int j = 1; j < n; j++) {
            if (j == i) continue;

            for (int k = 1; k < n; k++) {
                if (k == i || j == k) continue;

                if ((arr[j] + arr[k]) % 2 == 1 && sosu[arr[j] + arr[k]]) {
                    adj[j][adjsize[j]++] = k;
                }
            }
        }

        fill(match, match + 55, -1);

        int cnt = 0;
        for (int j = 1; j < n; j++) {
            if (j == i) continue;

            fill(visited, visited + 55, false);
            if (dfs(j)) cnt++;
        }

        if (cnt == n - 2) {
            answer[ansSize++] = arr[i];
        }
    }

    if (ansSize == 0) {
        cout << -1;
    } else {
        sort(answer, answer + ansSize);
        for (int i = 0; i < ansSize; i++) {
            cout << answer[i] << " ";
        }
    }
}