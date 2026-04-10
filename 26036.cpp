#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    long double low = powl(100.0L, N);
    long double high = powl(100.0L, N + 1);

    __int128 x = 3, y = 1;

    while (true) {
        __int128 A = y * y;

        long double val = (long double)A;

        if (val >= low && val < high) {
            cout << (long long)y << " " << 1 << "\n";
            cout << (long long)x << " " << 1 << "\n";
            return 0;
        }

        if (val >= high) break;

        __int128 nx = 3*x + 8*y;
        __int128 ny = x + 3*y;

        x = nx;
        y = ny;
    }

    cout << -1 << "\n";
}