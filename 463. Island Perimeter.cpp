class Solution {
public:
    
    int dfs(vector<vector<int>>& grid,int i, int j)
    {
        if(i>=0 and j>=0 and i<grid.size() and j<grid[0].size())
        {
            if(grid[i][j]==1)
            {
                int ret = 0;

                grid[i][j]=-1;   

                ret += dfs(grid,i+1,j);
                ret += dfs(grid,i,j+1);
                ret += dfs(grid,i-1,j);
                ret += dfs(grid,i,j-1);

                return ret;
            }
            else if(grid[i][j]==-1)
                return 0;
        }
        
        return 1;
    }
    
    //https://leetcode.com/problems/island-perimeter/discuss/95001/clear-and-easy-java-solution
    int islandPerimeter(vector<vector<int>>& grid) {
        int cells=0,neigh=0,m=grid.size(),n=grid[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    cells++;
                    if(i+1<m and grid[i+1][j])
                        neigh++;
                    if(j+1<n and grid[i][j+1])
                        neigh++;                    
                }
            }
        }
        /*
        each cell  has 4 sides and each neighbour removes 2 sides from 
        perimeter (one from itself and one from neighbor)
        */
        
        return 4*cells - 2*neigh;
    }
};
