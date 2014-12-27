#include<stdio.h>
#include<vector>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

TreeNode *conversion(int *A, int left, int right) {
    if(left>right)
        return NULL;
    else
    {
        int mid = (left + right)/2;
        TreeNode *head = new TreeNode(A[mid]);
        if(left != right)
        {
            head->left = conversion(A, left, mid);
            head->right = conversion(A, mid+1, right);
        }
        return head;
    }
}

TreeNode *sortedArrayToBST(vector<int> &num) {
    vector<int> *input = &num;
    int *A = new int[input->size()];
    for(int i=0; i<input->size(); i++)
        A[i] = input->at(i);
    return conversion(A, 0, input->size()-1);
}

int main()
{
    vector<int> input;
    input.push_back(3);
    TreeNode *temp = sortedArrayToBST(input);
    printf("%d\n", temp->val);
    return 0;
}
