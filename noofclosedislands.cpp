/**
* https://leetcode.com/problems/number-of-closed-islands/
**/
class Solution {

    public:
    bool dfs_connected_found(vector<vector<int>>& grid, size_t r_idx, size_t c_idx){
        
        
        //return true if you've already seen it(2) or it is a water node(1) 
        if(grid[r_idx][c_idx] == 2 || grid[r_idx][c_idx] == 1) return true;
        
        //now the only option left is that it is a 0 node
        if(r_idx == 0 || r_idx == grid.size() - 1 || c_idx == 0 || c_idx == grid[0].size() - 1) return false;
        
        
        //mark it as explored and run dfs for each of it's neighbours
        grid[r_idx][c_idx] = 2;
        
        /** Doesn't work for some reason
        return (dfs_connected_found(grid, r_idx - 1, c_idx) &&
            dfs_connected_found(grid, r_idx + 1, c_idx) && 
            dfs_connected_found(grid, r_idx, c_idx - 1) && 
            dfs_connected_found(grid, r_idx, c_idx + 1);
        **/
                
        
        bool top = dfs_connected_found(grid, r_idx - 1, c_idx);
        bool bottom = dfs_connected_found(grid, r_idx + 1, c_idx);
        bool left = dfs_connected_found(grid, r_idx, c_idx - 1);
        bool right = dfs_connected_found(grid, r_idx, c_idx + 1);
        
        return top && right && bottom && left;
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        
        int num_rows = grid.size();
        int num_cols = grid[0].size();
        
        int num_connected_components = 0;
        for(size_t i = 1; i < grid.size() - 1; i++){
            for(size_t j = 1; j < grid[0].size() - 1; j++){
                if(grid[i][j] == 0 && dfs_connected_found(grid, i, j))
                    num_connected_components++;
            }
        }
        
        return num_connected_components; 
    }
};
