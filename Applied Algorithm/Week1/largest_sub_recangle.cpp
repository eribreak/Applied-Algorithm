#include <iostream>
#include <stack>
using namespace std;

int largestRectangleArea(int heights[], int n) {
    stack<int> s;
    int maxArea = 0;
    int area = 0;
    int i = 0;

    while (i < n) {
        if (s.empty() || heights[s.top()] <= heights[i]) {
            s.push(i++);
        } else {
            int top = s.top();
            s.pop();
            area = heights[top] * (s.empty() ? i : i - s.top() - 1);
            maxArea = max(maxArea, area);
        }
    }

    while (!s.empty()) {
        int top = s.top();
        s.pop();
        area = heights[top] * (s.empty() ? i : i - s.top() - 1);
        maxArea = max(maxArea, area);
    }

    return maxArea;
}

int main() {
    int n, m;
    cin >> n >> m;

    int A[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
        }
    }

    int maxArea = 0;
    int height[m] = {0};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (A[i][j] == 0) {
                height[j] = 0;
            } else {
                height[j]++;
            }
        }
        maxArea = max(maxArea, largestRectangleArea(height, m));
    }

    cout << maxArea << endl;

    return 0;
}
