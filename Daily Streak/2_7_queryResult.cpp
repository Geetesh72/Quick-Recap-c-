#include <bits/stdc++.h>
using namespace std;

/*
   Problem Explanation:
   - You have a certain number of balls, each identified by an index.
   - You perform a series of queries where each query specifies:
     - A ball index.
     - A color to assign to that ball.
   - If a ball already has a color, it should be updated with the new color.
   - We need to track how many distinct colors are currently present after each query.

   Example:
   Input:
   limit = 5, queries = {{1, 3}, {2, 4}, {1, 4}, {3, 3}}
   Output:
   [1, 2, 2, 2]
   
   Explanation:
   - (1,3): Ball 1 -> Color 3, distinct colors = {3} → 1
   - (2,4): Ball 2 -> Color 4, distinct colors = {3, 4} → 2
   - (1,4): Ball 1 changes from 3 -> 4, distinct colors = {4} → 2
   - (3,3): Ball 3 -> Color 3, distinct colors = {3, 4} → 2
*/

/*
   Approach 1: Using a vector for ball tracking (MLE issue)
   - We use a `vector<int> ballArr(limit+1, -1)` to store the color assigned to each ball.
   - We use `unordered_map<int, int> colCnt` to store color frequencies.
   - If a ball already has a color, we decrease its previous color count.
   - After updating, we store the count of distinct colors.

   Problem: 
   - Using a vector `ballArr` of size (limit + 1) causes Memory Limit Exceeded (MLE) if `limit` is large.
*/

vector<int> queryResult(int limit, vector<vector<int>> &queries) {
    int n = queries.size();
    vector<int> ans(n); // Output array to store results for each query
    unordered_map<int, int> colCnt; // Stores frequency of each color
    vector<int> ballArr(limit + 1, -1); // MLE Issue: Large array initialization

    for (int i = 0; i < n; i++) {
        int ithBall = queries[i][0]; // Ball index
        int ballCol = queries[i][1]; // Color assigned

        // If the ball already has a color, decrease its count
        if (ballArr[ithBall] != -1) {
            int prevCol = ballArr[ithBall];
            colCnt[prevCol]--;
            if (colCnt[prevCol] == 0) {
                colCnt.erase(prevCol); // Remove from map if count reaches 0
            }
        }

        // Assign new color to the ball
        ballArr[ithBall] = ballCol;
        colCnt[ballCol]++;

        // Store the current count of distinct colors
        ans[i] = colCnt.size();
    }
    return ans;
}

/*
   Optimized Approach 2: Using Two HashMaps (Avoids MLE)
   - Instead of using a large vector, we use two hash maps:
     - `unordered_map<int, int> ballmp`: Stores the color assigned to each ball.
     - `unordered_map<int, int> colorMap`: Stores the frequency of each color.
   - This avoids unnecessary memory allocation and prevents MLE.
*/

vector<int> queryResult_2(int limit, vector<vector<int>> &queries) {
    int n = queries.size();
    vector<int> ans(n); // Output array to store results for each query
    unordered_map<int, int> colorMap; // Tracks color frequency
    unordered_map<int, int> ballmp;   // Tracks which color is assigned to each ball

    for (int i = 0; i < n; i++) {
        int ithBall = queries[i][0]; // Ball index
        int ballCol = queries[i][1]; // Color assigned

        // If the ball already has a color, decrease its previous color count
        if (ballmp.count(ithBall)) { // Fix: `ballmp.count()` → `ballmp.count(ithBall)`
            int prev = ballmp[ithBall];
            colorMap[prev]--;
            if (colorMap[prev] == 0) {
                colorMap.erase(prev); // Remove from map if count reaches 0
            }
        }

        // Assign new color to the ball
        ballmp[ithBall] = ballCol;
        colorMap[ballCol]++;

        // Store the current count of distinct colors
        ans[i] = colorMap.size();
    }
    return ans;
}

int main() {
    vector<vector<int>> queries = {{1, 3}, {2, 4}, {1, 4}, {3, 3}};
    int limit = 5;

    vector<int> result = queryResult_2(limit, queries);

    cout << "Number of distinct colors after each query: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
