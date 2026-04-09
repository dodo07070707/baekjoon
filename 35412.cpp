#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;
const ll MOD = 1000000007;
const ll BASE = 31;

vector<char> v;
vector<ll> h, rh, pw;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string st;
    cin >> n >> st;

    pw.resize(n + 1);
    pw[0] = 1;
    for (int i = 1; i <= n; i++) pw[i] = pw[i-1] * BASE % MOD;

    for (int i = 0; i < n; i++) {
        v.push_back(st[i]);
        int c = st[i] - 'a' + 1;
        if (h.empty()) {
            h.push_back(c);
            rh.push_back(c);
        } else {
            h.push_back((h.back() * BASE + c) % MOD);
            rh.push_back((c * pw[rh.size()] + rh.back()) % MOD);
        }
        while (true) {
            bool removed = false;
            int sz = v.size();

            for (int len = sz; len >= 2; len--) {
                int l = sz - len;
                int r = sz - 1;
                ll hash1 = h[r];
                if (l > 0) hash1 = (hash1 - h[l-1] * pw[len] % MOD + MOD) % MOD;
                ll hash2 = rh[l];
                if (r < sz-1) hash2 = (hash2 - rh[r+1] * pw[len] % MOD + MOD) % MOD;
                if (hash1 == hash2) {
                    for (int k = 0; k < len; k++) {
                        v.pop_back();
                        h.pop_back();
                        rh.pop_back();
                    }
                    removed = true;
                    break;
                }
            }
            if (!removed) break;
        }
    }
    if (v.empty()) cout << -1;
    else {
        for (char c : v) cout << c;
    }

    return 0;
}