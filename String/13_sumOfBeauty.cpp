#include<bits/stdc++.h>
using namespace std;

int getMaxCnt(vector<int>&nums){
    int n = nums.size();
    int maxi = INT_MIN;
    for(int i = 0; i < n; i++){
        maxi = max(maxi, nums[i]);
    }
    return maxi;
}

int getMini(vector<int>&nums){
    int n = nums.size();
    int mini = INT_MAX;
    for(int i = 0; i < n; i++){
        mini = min(mini, nums[i]);
    }
    return mini;
}

int beautyOfString(string &s){
    int n = s.length();
    int sum = 0;

    // For each starting position of the substring
    for(int i = 0; i < n; i++){
        vector<int> hashArray(26, 0);
        
        // For each ending position of the substring
        for(int j = i; j < n; j++){
            hashArray[s[j] - 'a']++;
            
            // Compute max and min frequencies
            
            int maxiF = getMaxCnt(hashArray);
            int miniF = getMini(hashArray);
            
            sum += maxiF - miniF;
        }
    }

    return sum;
}


int beautyOfString(string &s) {
    int n = s.length();
    int sum = 0;

    // Prefix frequency array for each character ('a' to 'z')
    vector<vector<int>> freq(n + 1, vector<int>(26, 0));

    // Build the prefix frequency array
    for (int i = 0; i < n; i++) {
        freq[i + 1] = freq[i];
        freq[i + 1][s[i] - 'a']++;
    }

    // Iterate over all possible starting positions of the substring
    for (int i = 0; i < n; i++) {
        // Variables to keep track of the max and min frequencies in the current substring
        int maxiF = 0, miniF = INT_MAX;

        // Iterate over all possible ending positions of the substring
        for (int j = i; j < n; j++) {
            // Update frequencies of the current substring (s[i...j])
            int currentFreq = freq[j + 1][s[j] - 'a'] - freq[i][s[j] - 'a'];

            // Update max and min frequencies based on the current frequency
            maxiF = max(maxiF, currentFreq);
            miniF = min(miniF, currentFreq);

            // Add the beauty of the current substring
            sum += (maxiF - miniF);
        }
    }

    return sum;
}

int main() {
    // Example string
    string s = "abcabc";

    // Call beautyOfString function and display the result
    cout << "Beauty of string: " << beautyOfString(s) << endl;

    return 0;
}

/*
Achieving an O(n) solution for the "beauty of a string" problem, as defined in the current context (which involves calculating the difference between the maximum and minimum frequencies of characters in all possible substrings), is a non-trivial task due to the nature of the problem.

The reason it’s challenging to reduce the time complexity to O(n) lies in the fact that we are considering all possible substrings and comparing the frequencies of characters within each substring. This inherently requires processing multiple substrings and calculating their frequency characteristics, which naturally leads to a quadratic time complexity O(n^2) in the brute-force approach.

Why Can't We Achieve O(n)?
Comparing All Substrings:
 The problem inherently involves calculating the beauty of the string over all substrings,
  and substrings grow in size as you move from left to right in the string.
   To calculate the beauty for each substring, we need to compare the frequency of characters 
over potentially many different positions. This involves iterating over the string multiple times.

Character Frequencies: Even with advanced techniques like prefix sums or segment trees,
 tracking character frequencies across different substring ranges will still require more than
  linear time. We could precompute certain values, but we would still need to combine them in a way that
   doesn’t reduce the problem to O(n) directly.

What Could Be Done in O(n)?
Some specific problems involving frequencies or substring calculations can be solved in O(n) if:

We are only interested in a limited range of values (e.g., fixed-length substrings, or substrings with a limited number of characters).
We can use sliding windows or two-pointer techniques that maintain state without recalculating values for every possible combination.
But the case you’re dealing with here involves calculating a difference between maximum and minimum frequencies for all substrings, and that fundamentally requires O(n^2) complexity in most general cases.*/



