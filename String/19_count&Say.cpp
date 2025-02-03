/*- **Explanation:**
- **n = 1** → "1"
- **n = 2** → "11" (one '1')
- **n = 3** → "21" (two '1's)
- **n = 4** → "1211" (one '2', one '1')
- **n = 5** → "111221" (one '1', one '2', two '1's)

---

 **Why Use Recursion?**
- The sequence follows a **self-dependent pattern** where `n-th` term depends on `(n-1)-th` term.
- Recursion naturally expresses this dependency.

---

 **Approach:**
1. **Base Case:**  
 - If `n == 1`, return `"1"`.
 
2. **Recursive Step:**  
 - Get the previous sequence by calling `count_say(n-1)`.
 - **Count consecutive characters** and construct the new sequence.

3. **Constructing the New Term:**
 - Iterate through the previous term.
 - Count how many times a character appears consecutively.
 - Append `{count}{character}` to the result string.

4. **Return the generated sequence for `n`**.

---

🔹 **Time Complexity:** `O(2^n)` (exponential growth due to recursion)
🔹 **Space Complexity:** `O(n)` (recursive stack depth)

*/

#include <bits/stdc++.h>
using namespace std;

string count_say(int n) {
  if (n == 1) {
      return "1"; // Base case
  }
  
  string say = count_say(n - 1); // Get the previous sequence
  string ans = "";
  int m = say.length();
  
  for (int i = 0; i < m; i++) {
      char ch = say[i];
      int cnt = 1;
      
      // Count consecutive occurrences of the character
      while (i + 1 < m && say[i] == say[i + 1]) {
          cnt++;
          i++;
      }
      
      ans += to_string(cnt) + string(1, ch); // Append count and character
  }
  return ans;
}

int main() {
  int n;
  cout << "Enter the value of n: ";
  cin >> n;
  
  cout << "The " << n << "th term in the Count and Say sequence is: " << count_say(n) << endl;
  
  return 0;
}
