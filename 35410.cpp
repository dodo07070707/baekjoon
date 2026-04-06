#include<iostream>
#include<algorithm>
using namespace std;
int arr[1005];
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    int time = 0;
    for(int i = 0; i < n; i++){
        if(time < arr[i]){
            time = arr[i];
        }
        time += 1;
    }

    cout << time;
}