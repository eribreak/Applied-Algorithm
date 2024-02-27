#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int largestRectangleArea(vector<int> & heights) {
    stack<int> s;
    int maxArea = 0;
    int i = 0;
    while (i < heights.size()) {
        if (s.empty() || heights[i] >= heights[s.top()]) {
            s.push(i);
            i++;
        } else {
            int tp = s.top();
            s.pop();
            int width = s.empty() ? i : i - s.top() - 1;
            maxArea = max(maxArea, heights[tp] * width);
        }
    }
    while (!s.empty()) {
        int tp = s.top();
        s.pop();
        int width = s.empty() ? i : i - s.top() - 1;
        maxArea = max(maxArea, heights[tp] * width);
    }
    return maxArea;
}

int maximalRectangle(vector<vector<int> >& matrix) {
    if (matrix.empty() || matrix[0].empty()) {
        return 0;
    }
    
    int maxArea = 0;
    vector<int> histogram(matrix[0].size(), 0);
    
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            if (matrix[i][j] == 0) {
                histogram[j] = 0;
            } else {
                histogram[j] += matrix[i][j];
            }
        }
        maxArea = max(maxArea, largestRectangleArea(histogram));
    }
    
    return maxArea;
}

int main() {
    int m, n;
    cin >> m >> n;
    
    vector<vector<int> > matrix(m, vector<int>(n));
    
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }
    
    int result = maximalRectangle(matrix);
    cout << result << endl;
    
    return 0;
}
