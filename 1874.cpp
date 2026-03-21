#include <iostream>
#include <string>

using namespace std;

int arr[100005];
int stack_arr[100005];
char res[200005];

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int now_num = 1;
    int pos = 0;
    int res_cnt = 0;

    for (int i = 0; i < n; i++) {
        int target = arr[i];

        while (now_num <= target) {
            stack_arr[pos++] = now_num++;
            res[res_cnt++] = '+';
        }

        if (pos > 0 && stack_arr[pos - 1] == target) {
            pos--; // pop (-)
            res[res_cnt++] = '-';
        } 
        else {
            cout << "NO" << "\n";
            return 0;
        }
    }

    for (int i = 0; i < res_cnt; i++) {
        cout << res[i] << "\n";
    }

    return 0;
}