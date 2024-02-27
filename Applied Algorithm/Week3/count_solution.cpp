#include <iostream>
#include <vector>

using namespace std;

vector<int> a;
int n, M;

int countSolutions(int idx, int sum) {
    if (idx == n) {
        return sum == M;
    }

    int count = 0;
    for (int x = 1; x <= (M - sum) / a[idx]; ++x) {
        count += countSolutions(idx + 1, sum + a[idx] * x);
    }

    return count;
}

int main() {
    cin >> n >> M;

    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    cout << countSolutions(0, 0) << endl;

    return 0;
}
