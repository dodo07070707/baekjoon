#include<iostream>
#include<algorithm>
#include<utility>
using namespace std;
pair<int, int> arr[10];
int main(){
    for(int i=0;i<9;i++){
        cin >> arr[i].first;
        arr[i].second = i;
    }
    sort(arr, arr+9);
    cout << arr[8].first << endl << arr[8].second+1;
}