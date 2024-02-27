#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

// Construct the segment tree
void buildTree(vector<int>& a, vector<int>& segTree, int i, int l, int r) {
    if (l == r) {
        segTree[i] = a[l];
        return;
    }

    int mid = (l + r) / 2;
    buildTree(a, segTree, 2*i, l, mid);
    buildTree(a, segTree, 2*i+1, mid+1, r);
    segTree[i] = min(segTree[2*i], segTree[2*i+1]);
}

// Query the segment tree to get the rmq for the given range
int query(vector<int>& segTree, int i, int l, int r, int ql, int qr) {
    if (ql > r || qr < l) return INT_MAX;  // Out of range
    if (ql <= l && qr >= r) return segTree[i];  // Complete overlap

    int mid = (l + r) / 2;
    return min(query(segTree, 2*i, l, mid, ql, qr),
               query(segTree, 2*i+1, mid+1, r, ql, qr));
}

int main() {
    int n, m;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Allocate memory for the segment tree
    int size = 2 * pow(2, ceil(log2(n)));
    vector<int> segTree(size, INT_MAX);

    buildTree(a, segTree, 1, 0, n-1);

    cin >> m;

    int result = 0;
    for (int i = 0; i < m; i++) {
        int ik, jk;
        cin >> ik >> jk;
        result += query(segTree, 1, 0, n-1, ik, jk);
    }

    cout << result << endl;

    return 0;
}
