#include <bits/stdc++.h>
using namespace std;

vector<int> unionOfsortedArray(vector<int> &nums1, vector<int> nums2)
{
    int n = nums1.size();
    int m = nums2.size();
    set<int> st;
    for (int i = 0; i < n; i++)
    {
        st.insert(nums1[i]);
    }
    for (int i = 0; i < m; i++)
    {
        st.insert(nums2[i]);
    }
    vector<int> temp;
    for (auto it : st)
    {
        temp.push_back(it);
    }
    return temp; // tc nlog , mlog , o (n1+m)
}

vector<int> optimalUnion(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums1.size();
    int m = nums2.size();
    int i = 0;
    int j = 0;
    vector<int> UnionArray;
    while (i < n && j < m)
    {
        if (nums1[i] <= nums2[j])
        {
            if (UnionArray.size() == 0 || UnionArray.back() != nums1[i])
            {
                UnionArray.push_back(nums1[i]);
            }
            i++;
        }
        else
        {
            if (UnionArray.size() == 0 || UnionArray.back() != nums2[j])
            {
                UnionArray.push_back(nums2[j]);
            }
            j++;
        }
    }

    while (i < n)
    {
        if (UnionArray.size() == 0 || UnionArray.back() != nums1[i])
        {
            UnionArray.push_back(nums1[i]);
        }
        i++;
    }

    while (j < m)
    {
        if (UnionArray.size() == 0 || UnionArray.back() != nums2[j])
        {
            UnionArray.push_back(nums2[j]);
        }
        j++;
    }
}

int main()
{
    int t;
    cout << "Enter no of test case ";
    cin >> t;
    while (t--)
    {
        int n;
        cout << "Enter the size of array ";
        cin >> n;
        vector<int> nums(n);
        cout << "Enter the elements of array " << endl;
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }
    }
    return 0;
}