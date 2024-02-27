#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Structure to represent a cell in the maze
struct Cell {
    int row;
    int col;
    int distance;
};

// Function to check if a cell is valid (within the maze and not a wall)
bool isValidCell(int row, int col, int n, int m, vector<vector<int>>& maze) {
    return (row >= 0 && row < n && col >= 0 && col < m && maze[row][col] == 0);
}

// Function to find the shortest path in the maze
int findShortestPath(vector<vector<int>>& maze, int startRow, int startCol) {
    int n = maze.size();
    int m = maze[0].size();

    // Array to keep track of visited cells
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    // Define the four possible directions to move
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    // Create a queue for BFS
    queue<Cell> q;

    // Mark the starting cell as visited and enqueue it
    visited[startRow][startCol] = true;
    q.push({startRow, startCol, 0});

    // Perform BFS
    while (!q.empty()) {
        // Dequeue a cell from the queue
        Cell curr = q.front();
        q.pop();

        // Check if the current cell is the exit
        if (curr.row == 0 || curr.row == n - 1 || curr.col == 0 || curr.col == m - 1) {
            return curr.distance + 1;  // Add 1 to include the starting cell
        }

        // Explore the four neighboring cells
        for (int i = 0; i < 4; i++) {
            int newRow = curr.row + dx[i];
            int newCol = curr.col + dy[i];

            // Check if the neighboring cell is valid and not visited
            if (isValidCell(newRow, newCol, n, m, maze) && !visited[newRow][newCol]) {
                // Mark the neighboring cell as visited and enqueue it
                visited[newRow][newCol] = true;
                q.push({newRow, newCol, curr.distance + 1});
            }
        }
    }

    // If no path to the exit is found, return -1
    return -1;
}

int main() {
    int n, m, startRow, startCol;
    cin >> n >> m >> startRow >> startCol;

    // Read the maze matrix
    vector<vector<int>> maze(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> maze[i][j];
        }
    }

    // Find the shortest path in the maze
    int shortestPath = findShortestPath(maze, startRow - 1, startCol - 1);

    // Print the result
    cout << shortestPath << endl;

    return 0;
}
