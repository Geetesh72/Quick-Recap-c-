#include <iostream>
#include <vector>
using namespace std;

// Function to print the 2D grid (matrix)
void printGrid(vector<vector<int>> &matrix) {
    for (const auto &row : matrix) {
        for (int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}
/*
You are given a 2D grid (or matrix) representing a canvas, where each cell has a specific color value (an integer).
You are also given a starting cell (row, col) and a new color to fill.
The task is to replace the color of the starting cell and all adjacent cells that have the same color as the starting cell with the new color.

Adjacent cells are connected either 4-directionally (up, down, left, right) or 8-directionally (including diagonals).
*/

// DFS function for flood fill
void floodFillDFS(int i, int j, vector<vector<int>> &image, vector<vector<int>> &ans, int newColor, int initialColor) {
    int n = image.size();
    int m = image[0].size();
    ans[i][j] = newColor;

    // Direction vectors for 4-directional movement
    vector<int> dRow = {-1, 1, 0, 0};
    vector<int> dCol = {0, 0, -1, 1};

    for (int k = 0; k < 4; k++) {
        int nRow = i + dRow[k];
        int nCol = j + dCol[k];

        if (nRow >= 0 && nCol >= 0 && nRow < n && nCol < m && image[nRow][nCol] == initialColor && ans[nRow][nCol] != newColor) {
            floodFillDFS(nRow, nCol, image, ans, newColor, initialColor);
        }
    }
}

// Wrapper function for flood fill
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor) {
    int initialColor = image[sr][sc];
    if (initialColor == newColor) {
        return image; // No need to process if the new color is the same as the initial color
    }

    vector<vector<int>> ans = image;
    floodFillDFS(sr, sc, image, ans, newColor, initialColor);
    return ans;
}

int main() {
    int t;
    cout << "Enter the number of test cases: ";
    cin >> t;

    while (t--) {
        int n, m;
        cout << "Enter the dimensions of the grid (n m): ";
        cin >> n >> m;

        vector<vector<int>> grid(n, vector<int>(m));
        cout << "Enter the grid values:" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        int sr, sc, newColor;
        cout << "Enter the starting row, column, and new color: ";
        cin >> sr >> sc >> newColor;

        vector<vector<int>> result = floodFill(grid, sr, sc, newColor);

        cout << "Flood-filled Grid:" << endl;
        printGrid(result);
    }

    return 0;
}
