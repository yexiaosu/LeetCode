/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        stringstream ss;
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            if (curr == NULL) {
                ss << "null" << " ";
            } else {
                ss << curr->val << " ";
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        string res = ss.str();
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss;
        ss << data;
        string node;
        TreeNode* curr, *re, *child;
        queue<TreeNode*> q;
        ss >> node;
        if (node == "null") {
            return NULL;
        } else {
            re = new TreeNode(stoi(node));
            q.push(re);
        }
        while (!q.empty()) {
            curr = q.front();
            q.pop();
            ss >> node;
            if (node == "null") {
                child = NULL;
            } else {
                child = new TreeNode(stoi(node));
                q.push(child);
            }
            curr->left = child;
            ss >> node;
            if (node == "null") {
                child = NULL;
            } else {
                child = new TreeNode(stoi(node));
                q.push(child);
            }
            curr->right = child;
        }
        return re;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));