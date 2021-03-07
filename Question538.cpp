#include "structs/TreeNode.h"
#include <map>

using namespace std;

class Solution {
public:
    /**
     * 把二叉搜索树变成累加树，也就是每个节点的值变为原树中大于等于其的值之和
     * 二叉树的右子树节点值都大于根
    */
    TreeNode* convertBST(TreeNode* root) {
        if(root==nullptr)return nullptr;
        map<int, TreeNode* > record;
        transverse(root, &record);
        map<int, TreeNode*>::reverse_iterator it;
        int current_sum = 0;
        for(it = record.rbegin();it != record.rend();it++){
            current_sum += (*it).first;
            (*it).second->val = current_sum;
        }
        return root;
    }
private:
    void transverse(TreeNode *root, map<int,TreeNode*> *record){
        record->insert(make_pair(root->val, root));
        if(root->left!=nullptr){
            transverse(root->left, record);
        }
        if(root->right!=nullptr){
            transverse(root->right, record);
        }
    }
};
