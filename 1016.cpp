#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main(){
    long long min, max;
    cin >> min >> max;

    vector<bool> check(max - min + 1, false);

    for(long long i = 2; i * i <= max; i++){
        long long square = i * i;

        long long start = (min + square - 1) / square * square;

        for(long long j = start; j <= max; j += square){
            check[j - min] = true;
        }
    }

    int cnt = 0;
    for(int i = 0; i < check.size(); i++){
        if(!check[i]) cnt++;
    }

    cout << cnt;
}