#include<iostream>
#include<algorithm>
#include<string>
#include <utility>
using namespace std;
pair<int, string>arr[20005];
string flag = "";
int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i].second;
        arr[i].first = arr[i].second.length();
    }
    sort(arr, arr+ n);
    for(int i=0;i<n;i++){
        if(flag == arr[i].second) continue;
        cout << arr[i].second << endl;
        flag = arr[i].second;
    }
}