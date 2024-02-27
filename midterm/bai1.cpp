#include <bits/stdc++.h>
using namespace std;
#define MODULE 1000000007

int a[100000];
int cnt = 0;
int n;

int main(){
    cin >> n;
    for (int i = 0; i <n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < n; i++){
        for (int j = i+1; j <n; j++){
            if (a[i] == a[j]) cnt++;
        }
    }
    cout << cnt%MODULE << endl;
}