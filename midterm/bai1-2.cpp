#include <bits/stdc++.h>
using namespace std;
#define MODULE 1000000007

int a[100000];
int n;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);

    long long cnt = 0;
    long long soLanLap = 1; 

    for (int i = 1; i < n; i++) {
        if (a[i] == a[i - 1]) {
            soLanLap++; 
        } else {
            cnt += soLanLap * (soLanLap - 1) / 2; 
            soLanLap = 1; 
        }
    }
    cnt += soLanLap * (soLanLap - 1) / 2;

    cout << cnt % MODULE << endl;
    return 0;
}
