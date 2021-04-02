#include "structs/TreeNode.h"
#include <deque>

using namespace std;

class BSTIterator {
private:
    deque<TreeNode*> contents;// 通过中序遍历，把内容装进来
    void mid_order(TreeNode *root, deque<TreeNode*>& dq){
        if(root->left!=nullptr)mid_order(root->left, dq);
        dq.push_back(root);
        if(root->right!=nullptr)mid_order(root->right, dq);
    }   
public:
    BSTIterator(TreeNode* root) {
        contents = deque<TreeNode *>();
        if(root!=nullptr)mid_order(root, contents);
    }
    
    int next() {
        int result = contents.front()->val;
        contents.pop_front();
        return result;
    }
    
    bool hasNext() {
        return !contents.empty();
    }
};
