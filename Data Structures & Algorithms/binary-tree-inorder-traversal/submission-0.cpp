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
    std::vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> result{};
        getInOrderTraversal(root, result);
        return result;
    }
    void getInOrderTraversal(TreeNode* root, std::vector<int>& result) {
        if (!root) return;

        if (!root->left && !root->right) {
            result.push_back(root->val);
            return;
        }
        getInOrderTraversal(root->left, result);
        result.push_back(root->val);
        getInOrderTraversal(root->right, result);
    }
};
