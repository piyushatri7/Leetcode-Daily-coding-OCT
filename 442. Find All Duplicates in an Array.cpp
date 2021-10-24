class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        nums.push_back(1);
        
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[abs(nums[i])] < 0)
                res.push_back(abs(nums[i]));
            
            nums[abs(nums[i])] = -abs(nums[abs(nums[i])]);
        }
        
        return res;
    }
};
