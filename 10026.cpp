#include <iostream>
using namespace std;

int n;
char arr[101][101];
bool visited1[101][101];
bool visited2[101][101];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void dfs1(int x, int y) {
    visited1[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
        if (!visited1[nx][ny] && arr[nx][ny] == arr[x][y]) {
            dfs1(nx, ny);
        }
    }
}
void dfs2(int x, int y) {
    visited2[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
        if (visited2[nx][ny]) continue;
        if (arr[x][y] == 'B') {
            if (arr[nx][ny] == 'B') dfs2(nx, ny);
        } else {
            if (arr[nx][ny] == 'R' || arr[nx][ny] == 'G') {
                dfs2(nx, ny);
            }
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int normal = 0;
    int blind = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited1[i][j]) {
                dfs1(i, j);
                normal++;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited2[i][j]) {
                dfs2(i, j);
                blind++;
            }
        }
    }

    cout << normal << " " << blind << '\n';
}