#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int dap;
void tkqnsgkf(int y,int x,int n, int start, int end){
    //cout << y << " " << x << " " << n << " " << start << " " << end << endl;
    if(n==1){
        if(y==1 && x==1) dap = start;
        else if(y==1 && x==2) dap = start+1;
        else if(y==2 && x==1) dap = start+2;
        else dap = start+3;
        return;
    }
    int number = pow(2, 2*n);   
    int depth = pow(2, n);
    int mid = depth / 2;
    if(x > mid && y > mid){
        tkqnsgkf(y - mid, x - mid, n-1, start + number/4*3, 0);
    }
    else if(x <= mid && y > mid){
        tkqnsgkf(y - mid, x, n-1, start + number/4*2, 0);
    }
    else if(x > mid && y <= mid){
        tkqnsgkf(y, x - mid, n-1, start + number/4*1, 0);
    }
    else{
        tkqnsgkf(y, x, n-1, start, 0);
    }
}

int main(){
    int n, x,y;
    cin >> n >> y >> x;
    x++; y++;
    tkqnsgkf(y,x,n, 0 ,pow(2,2*n)-1);
    cout << dap;
    return 0;
}

//n == 1   ->   0~3 / 1~4 2^2 / 2x2
//n==2     ->   0~15 / 1~16 2^4 / 4x4
//n==3     ->   0~63 / 1~64 2^6 / 8x8


//마지막에 하나 빼기