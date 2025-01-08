#include <bits/stdc++.h>
using namespace std;
class  spanner{
    public:
    vector<int>nums;
    spanner(vector<int>arr){
        this->nums = arr;
    }
    int next(int val){
        nums.push_back(val);
        int cnt= 1;
        for(int i = nums.size()-2;i>=0;i--){
            if(nums[i]<=val){
                cnt++;
            }else{
                break;
            }
        }
        return cnt;
    }

};
int main()
{
    return 0;
}