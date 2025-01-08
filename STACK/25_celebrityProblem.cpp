#include <bits/stdc++.h>
using namespace std;

// Brute force approach
int celebrity(vector<vector<int>>& nums) {
    int n = nums.size();
    vector<int> iKnow(n, 0);  // Count of how many people a person knows
    vector<int> KnowMe(n, 0);  // Count of how many people know a person

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (nums[i][j] == 1) {
                KnowMe[j]++;
                iKnow[i]++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        // A celebrity is someone known by everyone else and knows no one
        if (KnowMe[i] == n - 1 && iKnow[i] == 0) {
            return i;
        }
    }
    return -1;
}

// Optimal approach using two pointers
int celebrityProblem(vector<vector<int>>& nums) {
    int n = nums.size();
    int down = n - 1, top = 0;

    // Narrow down to one potential celebrity
    while (top < down) {
        if (nums[top][down] == 1) {
            top++;  // `top` can't be a celebrity
        }else if(nums[down][top]==1){
            down--;
        }
         else {
            down--;  // `down` can't be a celebrity
        }
    }

    int candidate = top;

    // Verify if the candidate is indeed a celebrity
    for (int i = 0; i < n; i++) {
        if (i == candidate) continue;
        if (nums[candidate][i] == 1 || nums[i][candidate] == 0) {
            return -1;  // Not a celebrity
        }
    }

    return candidate;
}

int main() {
    // Example test case
    vector<vector<int>> nums = {
        {0, 1, 1},
        {0, 0, 0},
        {1, 1, 0}
    };

    // Test brute force method
    int celeb1 = celebrity(nums);
    cout << "Celebrity (Brute Force): " << (celeb1 == -1 ? "None" : to_string(celeb1)) << endl;

    // Test optimal method
    int celeb2 = celebrityProblem(nums);
    cout << "Celebrity (Optimal): " << (celeb2 == -1 ? "None" : to_string(celeb2)) << endl;

    return 0;
}
