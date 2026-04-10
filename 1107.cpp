#include <iostream>
#include <cmath>
using namespace std;
bool broken[10];
bool canMake(int num) {
    if (num == 0) {
        return !broken[0];
    }
    while (num > 0) {
        if (broken[num % 10]) return false;
        num /= 10;
    }
    return true;
}
int getLength(int num) {
    if (num == 0) return 1;
    int len = 0;
    while (num > 0) {
        len++;
        num /= 10;
    }
    return len;
}
int main() {
    int target;
    cin >> target;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        broken[x] = true;
    }
    int ans = abs(target - 100);
    for (int i = 0; i <= 999999; i++) {
        if (canMake(i)) {
            int press = getLength(i) + abs(target - i);
            ans = min(ans, press);
        }
    }
    cout << ans;
}