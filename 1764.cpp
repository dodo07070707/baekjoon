#include<iostream>
#include<string>
#include <vector>
#include<algorithm>
using namespace std;
vector <string> arr;
vector <string> dap;
int main(){
    int n,m; string st;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin>> st;
        arr.push_back(st);
    }
    sort(arr.begin(), arr.end());
    for(int i=0;i<m;i++){
        cin >> st;
        if(binary_search(arr.begin(), arr.end(), st) != 0){
            dap.push_back(st);
        }
    }
    int size = dap.size();
    sort(dap.begin(), dap.end());
    //output
    cout << size << "\n";
    for(int i=0;i<size;i++){
       cout << dap[i] << "\n";
    }
}