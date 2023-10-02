class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int newsize=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=val)
            {
                nums[newsize]=nums[i];
                newsize++;
            }
        }
        return newsize;
    }
};