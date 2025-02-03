#include<bits/stdc++.h>
using namespace std;
// left rotate by one place 
void leftRotate(vector<int>&nums){
    int n = nums.size();
    int temp = nums[0];
    for(int i = 1;i<n;i++){
        nums[i-1] = nums[i];
    }
    nums[n-1] = temp;
}


// now by d places burte force
void leftRotate1 (vector<int>&nums,int d){
    int n = nums.size();
    d = d%n;
    vector<int>temp(nums.begin(),nums.begin()+d);
    for(int i = d  ;i<n;i++){
        nums[i-d]  = nums[i];

    }
    for(int i = 0;i<temp.size();i++){
        nums[n-d+i] = temp[i];
    }

 
}
// reversal game 

void optimalLeftRotate(vector<int>&nums,int d){
    int n = nums.size();
    d = d%n;
    reverse(nums.begin(),nums.begin()+d);
    reverse(nums.begin()+d,nums.end());
    reverse(nums.begin(),nums.end());

}

int main() {
    int t;
    cout << "Enter the number of test cases: ";
    cin >> t;

    while (t--) {
        int n, d;
        cout << "Enter the size of the array: ";
        cin >> n;
        cout << "Enter the number of places to rotate: ";
        cin >> d;

        vector<int> nums(n);
        cout << "Enter the elements of the array:\n";
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        // Test leftRotate (One-place rotation)
        vector<int> nums1 = nums;
        leftRotate(nums1);
        cout << "Array after left rotation by one place: ";
        for (int num : nums1) {
            cout << num << " ";
        }
        cout << "\n";

        // Test leftRotate1 (Brute force d-place rotation)
        vector<int> nums2 = nums;
        leftRotate1(nums2, d);
        cout << "Array after brute force left rotation by " << d << " places: ";
        for (int num : nums2) {
            cout << num << " ";
        }
        cout << "\n";

        // Test optimalLeftRotate (Reversal method)
        vector<int> nums3 = nums;
        optimalLeftRotate(nums3, d);
        cout << "Array after optimal left rotation by " << d << " places: ";
        for (int num : nums3) {
            cout << num << " ";
        }
        cout << "\n";
    }

    return 0;
}
