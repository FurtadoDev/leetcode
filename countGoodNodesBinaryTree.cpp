#include <limits>
/**
 *  https://leetcode.com/problems/count-good-nodes-in-binary-tree/
 */
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {

    public:
   
    int process_node(TreeNode* node, int current_max){
       
        if(node == NULL)
            return 0;
       
        if(node->val >= current_max){
           
            current_max = node->val;
            return 1 + process_node(node->left, current_max) + process_node(node->right, current_max);
       
        }  
        else{
           
            return 0 + process_node(node->left, current_max) + process_node(node->right, current_max);
           
        }
       
    }
   
    int goodNodes(TreeNode* root) {
       
        int answer = process_node(root, std::numeric_limits<int>::min());
       
        return answer;
    }
};
