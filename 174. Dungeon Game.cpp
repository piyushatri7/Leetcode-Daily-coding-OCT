//https://leetcode.com/problems/dungeon-game/discuss/698376/C%2B%2B-or-Beginner-friendly-dp-%2B-Explanation-and-idea
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& a) {
        int m=a.size(),n=a[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,INT_MAX));
        dp[m-1][n] = dp[m][n-1] = 0;
        
        for(int i=m-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                dp[i][j] = min(dp[i+1][j], dp[i][j+1]) - a[i][j];
                dp[i][j] = max(0,dp[i][j]);
            }
        }
        
        return dp[0][0]+1;
    }
};
