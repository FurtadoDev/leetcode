//https://leetcode.com/problems/partition-to-k-equal-sum-subsets/description/

class Solution {

    public:
    bool dfs(int k, vector<int>& nums, vector<bool> explored, int current_sum, int target_sum, int start_indx) {

        if (k == 0) return true;

        if (current_sum > target_sum) {

            return false;

        }
        else if (current_sum == target_sum) {

            return dfs(k - 1, nums, explored, 0, target_sum, 0);

        }
        else {

            for (int i = start_indx; i < explored.size(); i++) {

                if (explored[i] == false) {
                    explored[i] = true;
                    if (dfs(k, nums, explored, current_sum + nums[i], target_sum, i) == false)
                        explored[i] = false;
                    else
                        return true;
                }

            }

            return false;
        }

    }
   
   
    bool canPartitionKSubsets(vector<int>& nums, int k) {
       
        int sum = 0;
        size_t dataset_size = nums.size();
        vector<bool> explored_nodes;
        for(size_t i = 0; i < dataset_size; i++){
            explored_nodes.push_back(false);
            sum += nums[i];
        }
       
        if(sum % k != 0){
           
            return false;
           
        }else{
           
            return dfs(k, nums, explored_nodes, 0, sum/k, 0);
           
        }
           
    }
   
   
   
};
