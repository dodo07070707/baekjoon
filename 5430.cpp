#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        //input
        string st; int m; string temp; int flag=0; bool rflag = false;
        int arr[100005] = {0,};
        cin >> st >> m >> temp;
        if(m!=0){
            int j=1, tempnum=0, cnt=0;
            while(1){
                if(temp[j] == ']'){
                    arr[cnt] = tempnum;
                    cnt++;
                    break;
                }
                else if(temp[j] >= '0' && temp[j] <= '9'){
                    if(tempnum == 0) tempnum = temp[j] - '0';
                    else{
                        tempnum = tempnum*10;
                        tempnum = tempnum + temp[j] - '0';
                    }
                }
                else if(temp[j] == ','){
                    arr[cnt] = tempnum;
                    tempnum = 0;
                    cnt++;
                }
                j++;
            }
        }
        int start = 0, end = m;
        //logic
        for(int j=0;j<st.length();j++){
            if(st[j] == 'R') rflag = !rflag;
            else if(st[j] == 'D'){
                if(start >= end){
                    cout << "error" << endl;
                    flag = 1;
                    break;
                }
                else{
                    if(rflag == false) start++;
                    else end--;
                }
            }
        }
        //output
        if(flag == 1) continue;
        else{
            if(start >= end){
                cout << "[]" << endl;
                continue;
            }
            else if(rflag == true){
                cout << '[';
                for(int j=end-1;j>start;j--){
                    cout << arr[j] << ',';
                }
                cout << arr[start] << ']';
                cout << endl;
            }

            else{
                cout << '[';
                for(int j=start;j<end-1;j++){
                    cout << arr[j] << ',';
                }
                cout << arr[end-1] << ']';
                cout << endl;
            }
        }
    }
}