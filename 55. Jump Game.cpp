class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size(), maxjump=0;
        for(int i=0;i<n-1;i++)
        {
            maxjump = max(maxjump, i+nums[i]);
            if(i>=maxjump)
                return false;
        }
        return true;
    }
};
