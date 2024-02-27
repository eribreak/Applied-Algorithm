#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 21;
const int INF = 1e9;
int n, dist[MAXN][MAXN];
int dp[1 << MAXN][MAXN];  // dp[mask][i] means minimum distance to visit all cities in mask, ending at city i

int tsp(int mask, int pos) {
    if(mask == (1 << (n + 1)) - 2) {  // if all cities are visited
        return dist[pos][1];
    }

    if(dp[mask][pos] != -1) {
        return dp[mask][pos];
    }

    int ans = INF;
    for(int city = 2; city <= n; city++) {
        if((mask & (1 << city)) == 0) {  // if city not visited yet
            ans = min(ans, dist[pos][city] + tsp(mask | (1 << city), city));
        }
    }

    return dp[mask][pos] = ans;
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> dist[i][j];
        }
    }

    for(int i = 0; i < (1 << (n + 1)); i++) {
        for(int j = 0; j < MAXN; j++) {
            dp[i][j] = -1;
        }
    }

    cout << tsp(2, 1) << endl;  // starting with city 1 visited, at position 1
    return 0;
}
