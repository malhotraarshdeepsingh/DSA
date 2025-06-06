#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void TopView(TreeNode *root, int level, map<int, pair<int, int>> &m) {
        if (!root) return;

        if (m.find(level) == m.end()) {
            m[level] = {root->val, level}; // Store value and level
        }

        TopView(root->left, level + 1, m);
        TopView(root->right, level + 1, m);
    }
    vector<int> topView(TreeNode *root) {
        map<int, pair<int, int>> m; // Map to store value and level
        TopView(root, 0, m);

        vector<int> result;
        for (auto &it : m) {
            result.push_back(it.second.first); // Push only the value
        }
        return result;
    }
};