#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}    
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
vector<int> rightSideView(TreeNode* root) {
    if(!root) return {};
    vector<int>ans;
    queue<TreeNode*>bfs;
    TreeNode* sep = new TreeNode(-1000);
    bfs.push(sep);
    bfs.push(root);
    while(!bfs.empty()){
        TreeNode* top = bfs.front();
        bfs.pop();
        if(top->val==-1000){
            if(bfs.size()>0 && bfs.front()){
                ans.push_back(bfs.front()->val);
                bfs.push( sep );
            }
        }
        else{
            if(top->right) bfs.push( top->right );
            if(top->left) bfs.push( top->left );
        }
    }
    return ans;
}
int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);
    vector<int> bag = rightSideView(root);
    for(int i=0;i<bag.size();i++){
        cout<<bag[i]<<" ";
    }
    cout<<endl;
    return 0;
}