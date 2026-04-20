class Solution{
public:
    bool existsinTree(TreeNode*root,TreeNode*target){
        if(root==NULL) return false;
        if(root==target) return true;
        return existsinTree(root->left,target) || existsinTree(root->right,target);
    }
    TreeNode*lowestCommonAncestor(TreeNode*root,TreeNode*p,TreeNode*q){
        if(root ==p || root == q) return root;
        else if (existsinTree(root->left,p)&&existsinTree(root->right,q)) return root;
        else if (existsinTree(root->right,p)&& existsinTree(root->left,q)) return root;  // if we remove "!" by converting root->left in root->right & viceversa// 
        else if (existsinTree(root->left,p)&& existsinTree(root->left,q)) return lowestCommonAncestor(root->left,p,q);
        else return lowestCommonAncestor(root->right,p,q);
    }
};




///////////////////////////////////////////////////////////////////////////////
//  Solution 2: less complexity
///////////////////////////////////////////////////////////////////////////////

class Solution{
public:
    bool existsinTree(TreeNode*root,TreeNode*target){
        if(root==NULL) return false;
        if(root==target) return true;
        return existsinTree(root->left,target) || existsinTree(root->right,target);
    }
    TreeNode*lowestCommonAncestor(TreeNode*root,TreeNode*p,TreeNode*q){
        if (existsinTree(root->left,p)&& existsinTree(root->left,q)) return lowestCommonAncestor(root->left,p,q);
        else if (existsinTree(root->right,p)&& existsinTree(root->right,q)) return lowestCommonAncestor(root->right,p,q);
        return root;
    }
};