#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1000000;
int mu[MAX + 5];
bool is_prime[MAX + 5];
vector<int> primes;

void mobius() {
    fill(is_prime, is_prime + MAX + 1, true);
    mu[1] = 1;

    for (int i = 2; i <= MAX; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            mu[i] = -1;
        }

        for (int p : primes) {
            if (i * p > MAX) break;
            is_prime[i * p] = false;

            if (i % p == 0) {
                mu[i * p] = 0;
                break;
            } else {
                mu[i * p] = -mu[i];
            }
        }
    }
}

int undersquarefree(long long int n){
    long long int cnt = 0;
    for(int i=1;i*i<=n;i++){
        cnt = cnt + mu[i] * (n/ (i*i));
    }
    return cnt;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie();
    long long int n;
    cin >> n;
    mobius();
    undersquarefree(n);
    long long int left = 1, right = 2 * n;
    long long int dap = right;

    while (left <= right) {
        long long int mid = (left + right) / 2;

        if(undersquarefree(mid) >= n) {
            dap = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << dap;
}