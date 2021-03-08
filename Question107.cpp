#include <vector>
#include "structs/TreeNode.h"
#include <deque>

using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int> >result;
        if(root==nullptr)return result;
        vector<int> *current = new vector<int>();
        deque<TreeNode*> queue;
        deque<int> level;
        int current_level = 0;
        queue.push_back(root);
        level.push_back(current_level);
        while(!queue.empty()){
            int this_level = level.front();
            level.pop_front();
            TreeNode* this_node = queue.front();
            queue.pop_front();
            if(this_level>current_level){
                current_level = this_level;
                result.push_back(*current);
                delete current;
                current = new vector<int>();
            }
            
            (*current).push_back(this_node->val);
            if(this_node->left!=nullptr){
                level.push_back(this_level+1);
                queue.push_back(this_node->left);
            }
            if(this_node->right!=nullptr){
                level.push_back(this_level+1);
                queue.push_back(this_node->right);
            }
        }
        result.push_back(*current);
        reverse(result.begin(), result.end());
        return result;
    }
};