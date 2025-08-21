#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <unordered_set>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}    
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
bool isCousins(TreeNode* root, int x, int y) {
    unordered_set<int>check;
    check.insert(x);
    check.insert(y);
    TreeNode*sep = NULL;
    queue<TreeNode*>bfs;
    bfs.push(root);
    bfs.push(sep);
    while(!bfs.empty()){
        TreeNode* top = bfs.front();
        bfs.pop();
        if(!top){
            if(check.size()==1) return false;
            if(check.empty()) return true;
            if(bfs.size()>0) bfs.push(top);
        }
        else{
            bool x_present = (top->left && top->left->val==x) || (top->right && top->right->val==x);
            bool y_present = (top->right && top->right->val==y) || (top->left && top->left->val==y);
            if(x_present&&y_present) return false;
            if(top->left ){
                bfs.push(top->left);
                if(check.find(top->left->val)!=check.end()) check.erase(top->left->val);
            }
            if(top->right ){
                bfs.push(top->right);
                if( check.find(top->right->val)!=check.end() )check.erase(top->right->val);
            }
            
        }

    }
    return false;
}
int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(5);
    cout << isCousins(root, 4, 5) << endl; // Output: 0 (false)
    cout << isCousins(root, 2, 3) << endl; // Output: 1 (true)
    return 0;
}
// Time Complexity: O(n)
// Space Complexity: O(n)
// Did this code successfully run on Leetcode : Yes
// Any problem you faced while coding this : No
//Your code here along with comments explaining your approach in three sentences only
//Performed BFS and while adding nodes to the queue checking if the current node has its both children as x and y. If it has
// both children, then it means that x and y are siblings, not just cousins and so it will return false. Else I am maintaining a hashset containing x and y
// and removing them from hashset if a parent node's child node's value is either x or y. At the end of iterating through each level in BFS,
// I am checking the count of this hashset. If hashset size is 2, it means we will continue the BFS, if the size is 1 it means x and y are not in the same level and we will
// return false and if the size is 0, it means x and y are in the same level and with different parents, so return true.
// We will continue till the end and return false.