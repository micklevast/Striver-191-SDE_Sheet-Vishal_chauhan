
#include <bits/stdc++.h> 
/*   
    template <typename T = int>
	class TreeNode
	{
		public:
		T data;
		TreeNode<T> *left;
		TreeNode<T> *right;

		TreeNode(T data)
		{
			this->data = data;
			left = NULL;
			right = NULL;
		}

		~TreeNode()
		{
			if (left != NULL)
			{
		  		delete left;
			}
			if (right != NULL)
			{
			 	delete right;
			}
		}
	};
*/
bool find(TreeNode<int> *root,int nd,vector<int> &ans){
	if(root==NULL)return false;
	if(root->data==nd){
		ans.push_back(root->data);
		return true;
	}
	bool l=find(root->left,nd,ans);
	bool r=find(root->right,nd,ans);
	if(l || r){
		ans.push_back(root->data);
		return true;
	}
	else
	return false;
}

vector<int> pathInATree(TreeNode<int> *root, int x)
{
    // Write your code here.
	vector<int> ans;
	bool s=find(root,x,ans);
	reverse(ans.begin(),ans.end());
	return ans;
}
