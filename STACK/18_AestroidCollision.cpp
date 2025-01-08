#include <bits/stdc++.h>
using namespace std;

/* ABOUT QUESTION 
   Given a list of positive and negative integers (representing asteroids):
   - Positive values move to the right.
   - Negative values move to the left.
   - Collisions occur when a positive and negative asteroid meet:
       - The smaller asteroid is destroyed.
       - If both have the same absolute value, both are destroyed.
       - If they move in the same direction or do not meet, they remain intact.
   - The goal is to simulate the collisions and return the final state of the asteroids.
*/
vector<int> collision(vector<int>&nums){
    int n = nums.size();
    vector<int>list;
    for(int i = 0;i<n;i++){
        if(nums[i]>0){
             // Push all positive asteroids to the stack.
            list.push_back(nums[i]);
        }
        else{
             // Handle collisions for negative asteroids.
            while(!list.empty() && list.back()>0 && list.back()<abs(nums[i]) ){
             // Positive asteroid is smaller and destroyed
                list.pop_back();
            }
            if(!list.empty() && list.back()==abs(nums[i])){ 
            // Both asteroids have the same size and destroy each other.
                list.pop_back();
            // No collision or stack has only negative asteroids, add current negative asteroid
            }else if(list.empty() && list.back()<0){
                list.push_back(nums[i]);
            }
        }
    }
    return list;
}
int main()
{
     vector<int> nums = {4,7,1,1,-3,-7,17,15,-16}; // Example input
    vector<int> result = collision(nums);

    // Print the result
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}