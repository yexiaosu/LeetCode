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
    TreeNode* buildTreeHelper(vector<int>& inorder, vector<int>& postorder, unordered_map<int, int>& index, int inStart, int inEnd, int postStart, int postEnd) {
        if (inStart > inEnd || postStart > postEnd) {
            return nullptr;
        }
        // the last element in postorder is the root
        int rootVal = postorder[postEnd];
        TreeNode* root = new TreeNode(rootVal);
        // find index of root in inorder
        int inorderIdx = index[rootVal];
        int leftSubtreeSize = inorderIdx - inStart;
        root->left = buildTreeHelper(inorder, postorder, index, inStart, inorderIdx - 1, postStart, postStart + leftSubtreeSize - 1);
        root->right = buildTreeHelper(inorder, postorder, index, inorderIdx + 1, inEnd, postStart + leftSubtreeSize, postEnd - 1);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // use an unordered map to store the index of elements in inorder
        unordered_map<int, int> index;
        for (int i = 0; i < inorder.size(); i++) {
            index[inorder[i]] = i;
        }
        return buildTreeHelper(inorder, postorder, index, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }
};