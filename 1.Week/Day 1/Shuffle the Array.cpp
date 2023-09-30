#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) 
    {
        vector<int> x;
        for (int i = 0; i < n; i++) 
        {
            x.push_back(nums[i]);
            x.push_back(nums[i + n]);
        }
        return x;
    }
};
int main() 
{
    Solution solution;
    int n;
    cin >> n;
    vector<int> nums(2 * n);
    for (int i = 0; i < 2 * n; i++) cin >> nums[i];
    vector<int> shuffled = solution.shuffle(nums, n);
    for (int num : shuffled) cout << num << " ";
    cout << endl;
    return 0;
}
