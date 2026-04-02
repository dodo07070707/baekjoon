#include <iostream>
#include<cmath>
#include <algorithm>
#include <numeric>
using namespace std;

long long pi(long long n) {
    long long dap = n;
    for (long long i=2;i*i<=n;i++) {
        if (n%i == 0) {
            while (n%i == 0) n = n / i;
            dap = dap - dap / i;
        }
    }
    if (n>1) dap  = dap - dap / n;
    return dap;
}

long long powpow(long long a, long long b, long long m) {
    long long result = 1 % m;
    a = a % m;
    while (b) {
        if (b & 1) result = result * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return result;
}

long long solve(long long a, long long m) {
    if (m == 1) return 0;

    long long p = pi(m);
    long long temp = solve(a, p);

    //if (std::gcd(a, m) != 1) { 왜 빨간줄 뜨지 ? 백준은 맞음
    //    temp += p;
    //}

    return powpow(a, temp, m);
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        long long a, m;
        cin >> a >> m;
        cout << solve(a, m) << endl;
    }
}