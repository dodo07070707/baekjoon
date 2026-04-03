#include<iostream>
#include<string>
using namespace std;
int arr[25] = {0,};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        string comm; int temp;
        cin >> comm;
        if(comm == "add"){
            cin >> temp;
            arr[temp] = 1;
        }
        else if(comm == "remove"){
            cin >> temp;
            arr[temp] = 0;
        }
        else if(comm == "check"){
            cin >> temp;
            if(arr[temp] == 1) cout << 1 << "\n";
            else cout << 0 << "\n";
        }
        else if(comm == "toggle"){
            cin >> temp;
            if(arr[temp] == 1) arr[temp] = 0;
            else arr[temp] = 1;
        }
        else if(comm == "all"){
            for(int j=1;j<=20;j++) arr[j] = 1;
        }
        else if(comm == "empty"){
            for(int j=1;j<=20;j++) arr[j] = 0;
        }
        /*debug
        cout << "deboug :";
        for(int j=1;j<=20;j++){
            cout << arr[j] << " ";
        }
        cout << endl;*/
    }
}