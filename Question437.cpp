#include "structs/TreeNode.h"
#include <unordered_map>
#include <deque>

using namespace std;

class Solution {
private:
    void calculateRootDist(TreeNode *root, unordered_map<TreeNode *, int>&dist, int cur_dist, deque<TreeNode*> &path, int target, int &result){
        dist[root] = cur_dist + root->val;
        for(TreeNode* t:path){
            if(cur_dist + root->val - dist[t] + t->val == target){
                result++;
            }
        }
        if(root->val==target)result++;
        if(root->left!=nullptr){
            path.push_back(root);
            calculateRootDist(root->left, dist, cur_dist+root->val, path, target, result);
            path.pop_back();
        }
        if(root->right!=nullptr){
            path.push_back(root);
            calculateRootDist(root->right, dist, cur_dist+root->val, path, target, result);
            path.pop_back();
        }
        dist.erase(root);
    }
public:
    int pathSum(TreeNode* root, int sum) {
        if(root==nullptr)return 0;
        unordered_map<TreeNode*, int>dist;
        deque<TreeNode*> path;
        int result;
        calculateRootDist(root, dist, 0, path, sum, result);
        return result;
    }
};