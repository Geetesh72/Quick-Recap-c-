#include <bits/stdc++.h>
using namespace std;

void reverseWordsInString(string &s) {
    // Step 1: Split the string by spaces and store words
    stringstream ss(s);  // Create a stringstream from the input string
    string word;
    vector<string> words;
    
    // Extract each word and store it in a vector
    while (ss >> word) {
        // Reverse each word
        reverse(word.begin(), word.end());
        words.push_back(word);
    }
    
    // Step 2: Reassemble the string by joining the words
    s = "";
    for (int i = 0; i < words.size(); i++) {
        s += words[i];
        if (i != words.size() - 1) {
            s += " ";  // Add space between words
        }
    }
}

int main() {
    string s = "Hello World from C++";
    cout << "Original string: " << s << endl;
    
    reverseWordsInString(s);
    
    cout << "String with reversed words: " << s << endl;
    
    return 0;
}
