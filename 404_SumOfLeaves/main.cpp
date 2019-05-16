/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//遍历树，设置标志位，１:左子树  
void GetLeaves(TreeNode* root, vector<int>& leaves, int flag)
{
    if(root == nullptr)return ;
    if(root->left == nullptr && root->right == nullptr&& flag == 1) // 当前是左子树，且没有子节点(叶子)
	leaves.push_back(root->val);
    
     GetLeaves(root->left, leaves, 1);                

     GetLeaves(root->right, leaves, 0);
}


int sumOfLeftLeaves(TreeNode* root) 
{
    if(root == nullptr) return 0;
    vector<int> leaves;
    GetLeaves(root,  leaves, 0); //
    
    int sum = 0;
    for(vector<int>::iterator it = number.begin();  it!=number.end(); it++) //求和
    {
	sum += (*it);
    }
    
    return sum;
}
