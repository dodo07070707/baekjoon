#include<iostream>
#include<string>
using namespace std;
int main(){
    int N=0, i, T;
    string L;
    cin >> T;
    
    while(T--){
        cin >> L;
        N = 0;
        
        for(i=0; i<L.length(); i++){
            if(L[i]=='(') N++;
            else N--;
            
            if(N < 0) break;
        }
        
        if(N==0) cout << "YES\n";
        else cout << "NO\n";
    }
}