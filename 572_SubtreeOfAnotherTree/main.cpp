#include <iostream>
#include <stack>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


void FindRoot(TreeNode* s, int value, stack<TreeNode*>& result)//在s中遍历所有结点，找到所有和val= value的结点，保存到stack中
{
    if(s == nullptr) return;
    if(s->val == value) 
	result.push(s);
     FindRoot(s->left, value, result);           
     FindRoot(s->right, value, result); 
   
}

bool CompareTwoTree(TreeNode* tree1, TreeNode* tree2) //比较两个树是否相同
{
    // if(tree1 == nullptr && tree2 == nullptr) return true;
    // if(tree1 == nullptr && tree2 != nullptr) return false;
    // if(tree1 != nullptr && tree2 == nullptr)return false;

    // if(tree1->val == tree2->val)
    // {
    //     return CompareTwoTree(tree1->left, tree2->left)&&CompareTwoTree(tree1->right, tree2->right);
    // }
    // else
    // {
    //     return false;
    // }
    
    // leetcode 优化写法
    if(tree1 == nullptr && tree2 == nullptr) return true;
    if(tree1 == nullptr || tree2 == nullptr) return false;
    return (tree1->val == tree2->val) && CompareTwoTree(tree1->left, tree2->left) && CompareTwoTree(tree1->right, tree2->right);


}   



bool isSubtree(TreeNode* s, TreeNode* t) 
{
     if(s==nullptr || t == nullptr)return false;

     stack<TreeNode*> result;
     FindRoot(s, t->val, result);   

     TreeNode* tmp_root = nullptr;
     bool finalresult = false;

     while(finalresult != true) //从栈顶逐一取出，进行比较，只要符合要求则返回true
     {
	 if(result.size()!=0)
	 {
	     tmp_root = result.top();
	     result.pop();
	 }
	 else // 只要stack为空，证明没有结点和value值一样，返回false
	 {
	     break;
	 }

	 if(tmp_root != nullptr);
	    finalresult = CompareTwoTree(t, tmp_root);

     }
          return finalresult;
}




int main(void)
{

    TreeNode node1(1);
    TreeNode node2(1);
    TreeNode node3(1);
    TreeNode node4(1);
    TreeNode node5(2);

    TreeNode node6(1);
    TreeNode node7(1);
    TreeNode node8(2);

    node1.right= &node2;
    node2.right= &node3;
    node3.right= &node4;
    node4.right= &node5;

    node6.right = &node7;
    node7.right = &node8;

    bool result = isSubtree(&node1, &node6);
    cout <<result<< endl;

    return 0;
}





