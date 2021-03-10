#include "structs/TreeNode.h"
#include <vector>
#include <iostream>

using namespace std;

class Solution {
private:
    /**
     * 中序遍历的序列的[s,e)，以及前序遍历c是树根，构建一颗子树，返回树根
     * @param s 中序遍历开始点
     * @param e 中序遍历终止点
     * @param c 前序遍历中的树根
    */
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder, int s, int e, int c){
        cout << "(" << s << "," << e << "," << c << ")" << endl;
        if(e-s==1){//一个节点
            return new TreeNode(preorder[c]);
        }
        if(s>=e){
            return nullptr;
        }
        TreeNode *root = new TreeNode(preorder[c]);
        int i = 0;
        for(i=s;i<e;i++){
            if(inorder[i] == preorder[c]){
                break;
            }
        }
        root -> left = buildTree(preorder, inorder, s, i, c+1);//左子树
        root -> right = buildTree(preorder, inorder, i+1, e, c+(i-s)+1);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder, inorder, 0, preorder.size(), 0);
    }
};

int main(){
    Solution s;
    vector<int> preorder = {3,9,20,15,7}, inorder = {9,3,15,20,7};
    s.buildTree(preorder, inorder);
    return 0;
}