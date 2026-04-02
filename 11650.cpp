#include <iostream>
#include <algorithm>
using namespace std;
pair<int, int>arr[100005];
bool cmp(pair<int,int> a, pair<int,int> b)
{
    if(a.first < b.first) return true;
    else if(a.first == b.first) return a.second < b.second;
    else return false;
}
int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr,arr + n,cmp);
    for(int i = 0; i < n; i++)
        cout << arr[i].first << ' ' << arr[i].second << '\n';
}