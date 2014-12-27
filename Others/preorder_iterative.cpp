#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

/* A binary tree node has data, left child and right child */
struct node
{
    int val;
    struct node* left;
    struct node* right;
};

/* Helper function that allocates a new node with the given data and
   NULL left and right  pointers.*/
struct node* newNode(int data)
{
    struct node* node = new struct node;
    node->val = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}

typedef struct Stack
{
	node *value;
	struct Stack *next;
} stackk;

class store
{
    public:
		int current_size;
		stackk *head;

		store()
		{
			current_size = 0;
			head = new stackk;
			head->next = NULL;
		}

		void push(node *a)
		{
		    current_size++;
		    stackk *temp = new stackk;
		    temp->value = a;
		    temp->next = head->next;
		    head->next = temp;
		}

		node *pop()
		{
            current_size--;
            node *top = head->next->value;
            head->next = head->next->next;
            return top;
		}

		bool isEmpty()
		{
		    if(this->current_size == 0)
		        return true;
		    else
		        return false;
		}
};

class Solution {
public:
    vector<int> preorderTraversal(node *root) {
        vector<int> output;
        store arrayy;
        if(root == NULL)
            return output;
        else
        {
            arrayy.push(root);
            while(!arrayy.isEmpty())
            {
                node *temp = arrayy.pop();
                output.push_back(temp->val);
                if(temp->right != NULL)
                    arrayy.push((temp->right));
                if(temp->left != NULL)
                    arrayy.push((temp->left));
            }
            return output;
        }
    }
};

int main()
{
    /* Constructed binary tree is
            10
          /   \
        8      2
      /  \    /
    3     5  2
  */
  struct node *root = newNode(10);
  root->left        = newNode(8);
  root->right       = newNode(2);
  root->left->left  = newNode(3);
  root->left->right = newNode(5);
  root->right->left = newNode(2);
  Solution temp;
  vector<int> output = temp.preorderTraversal(root);
  vector<int>::iterator it;
  for(it = output.begin(); it != output.end(); it++)
    printf("%d\n", *it);
  return 0;
}
