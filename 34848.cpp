#include<iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    while(T--){
        long long n;
        cin >> n;

        int cnt = 0;

        while(n > 1){
            if(n % 2 == 1) cnt++;
            n = (n + 1) / 2;
        }

        cout << cnt << "\n";
    }
}