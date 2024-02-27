#include <bits/stdc++.h>
using namespace std;

int iArray[100];
int res[100];
int n, target;
int sum = 0;
int cnt = 0;

void Try(int k, int start) {
    if (sum >= target) {
        cnt++;
    }

    for (int i = start; i < n; i++) {
        res[k] = iArray[i];
        sum += res[k];
        Try(k + 1, i + 1);
        sum -= res[k];
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> iArray[i];
    }
    cin >> target;
    Try(0, 0);
    cout << cnt << endl;
    return 0;
}
