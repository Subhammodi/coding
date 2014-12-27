#include<stdio.h>
#include<stack>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

void flatten(TreeNode *root) {
    if(root == NULL)
        return;
    else
    {
        stack<TreeNode *> array;
        array.push(root);
        while(!array.empty())
        {
            TreeNode *temp = array.top();
            array.pop();
            if(temp->right != NULL)
                array.push((temp->right));
            if(temp->left != NULL)
                array.push((temp->left));

            if(temp->left!= NULL)
                temp->right = temp->left;
            else if(temp->left == NULL && temp->right != NULL)
                continue;
            else if(temp->left == NULL && temp->right == NULL && !array.empty())
            {
                TreeNode *temp1 = array.top();
                temp->right = temp1;
            }
            else
                temp->right = NULL;
        }
        return;
    }
}

int main()
{
    TreeNode *root = new TreeNode(1);
    TreeNode *temp = new TreeNode(5);
    root->right = temp;
    flatten(root);
    temp = root;
    while(temp != NULL)
    {
        printf("%d\t", root->val);
        temp = temp->right;
    }
    printf("\n");
    return 0;
}
