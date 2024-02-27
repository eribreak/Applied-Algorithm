#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canPlaceCows(vector<int>& positions, int N, int C, int minDist) {
    int count = 1;
    int lastPosition = positions[0];
    for (int i = 1; i < N; i++) {
        if (positions[i] - lastPosition >= minDist) {
            count++;
            lastPosition = positions[i];
        }
    }
    return count >= C;
}

int findLargestMinDistance(vector<int>& positions, int N, int C) {
    sort(positions.begin(), positions.end());
    int left = 0;
    int right = positions[N - 1] - positions[0];
    int result = -1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (canPlaceCows(positions, N, C, mid)) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return result;
}

int main() {
    int T;
    cin >> T;
    
    for (int t = 0; t < T; t++) {
        int N, C;
        cin >> N >> C;
        
        vector<int> positions(N);
        for (int i = 0; i < N; i++) {
            cin >> positions[i];
        }
        
        int maxMinDistance = findLargestMinDistance(positions, N, C);
        cout << maxMinDistance << endl;
    }
    
    return 0;
}

