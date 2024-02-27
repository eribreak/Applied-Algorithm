#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAX_N = 999;
const int MAX_M = 999;
const int INF = 1e9;

int n, m, r, c;
vector<vector<int> > A;
vector<vector<int> > dist;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool isValid(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < m && A[x][y] == 0);
}

int shortestPath() {
    dist.assign(n, vector<int>(m, INF));
    dist[r][c] = 0;
    queue<pair<int, int> > q;
    q.push({r, c});

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (isValid(nx, ny) && dist[nx][ny] == INF) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});

                if (nx == 0 || nx == n - 1 || ny == 0 || ny == m - 1) {
                    return dist[nx][ny] + 1;
                }
            }
        }
    }

    return -1;
}

int main() {
    cin >> n >> m >> r >> c;
    r--;  // Adjust to 0-based indexing
    c--;

    A.assign(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
        }
    }

    int result = shortestPath();
    cout << result << endl;

    return 0;
}
