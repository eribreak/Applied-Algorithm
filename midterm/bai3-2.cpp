#include <bits/stdc++.h>
using namespace std;

int a[1000][1000];
int minMarked[1000][1000];
int n, m;
int minCost = INT_MAX;

bool check(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < m && a[x][y] != 0;
}

void Try(int x, int y, int curCost){
    if (curCost >= minCost || curCost >= minMarked[x][y]) return; 
    if (x == n - 1 && y == m - 1){
        minCost = min(minCost, curCost);
        return;
    }

    minMarked[x][y] = curCost; 

    if (check(x, y + 1)){
        Try(x, y + 1, curCost + a[x][y + 1]);
    }

    if (check(x + 1, y)){
        Try(x + 1, y, curCost + a[x + 1][y]);
    }

    if (check(x + 1, y + 1)){
        Try(x + 1, y + 1, curCost + a[x + 1][y + 1]);
    }
}

int main(){
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> a[i][j];
            minMarked[i][j] = INT_MAX;
        }
    }

    Try(0, 0, a[0][0]);
    if (minCost == INT_MAX){
        cout << "-1";
    }
    else{
        cout << minCost;
    }
    return 0;
}
