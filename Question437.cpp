#include "structs/TreeNode.h"
#include <unordered_map>
#include <deque>

using namespace std;

class Solution {
private:
    void calculateRootDist(TreeNode *root, unordered_map<TreeNode *, int>&dist, int cur_dist, deque<TreeNode*> &path, int &result){
        dist[root] = cur_dist + root->val;
        if(root->left!=nullptr){
            path.push_back(root);
            calculateRootDist(root->left, dist, cur_dist+root->val, path, result);
            path.pop_back();
        }
        if(root->right!=nullptr){
            path.push_back(root);
            calculateRootDist(root->right, dist, cur_dist+root->val, path, result);
            path.pop_back();
        }
    }
public:
    int pathSum(TreeNode* root, int sum) {
        
    }  
};