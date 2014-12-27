#include "header.hpp"

int size = 0;

typedef struct Btree
{
	int value;
	struct Btree *left, *right;
} btree;

btree *get_node(int data)
{
	size++;
	btree *temp = new btree;
	temp->value = data;
	temp->right = NULL;
	temp->left = NULL;
	return temp;
}

void insertt(btree **temp, int data)
{
	if(*temp == NULL)
		*temp = get_node(data);
	else if((*temp)->value >= data)
		insertt(&(*temp)->left, data);
	else
		insertt(&(*temp)->right, data);
}

bool search(btree *temp, int data)
{
	if(temp == NULL)
		return false;
	else if(temp->value == data)
		return true;
	else if(temp->value > data)
		return search(temp->left, data);
	else
		return search(temp->right, data);
}

btree *deletee(btree *temp, int data)
{
    int min;
	btree *tempo = temp;
	if(temp == NULL)
		printf("Invalid input. Element %d not present in btree.\n",data);
	else if(temp->value < data)
		temp->right = deletee(temp->right, data);
	else if(temp->value > data)
		temp->left = deletee(temp->left, data);
	else
	{
		if( temp->right && temp->left )
		{
			tempo = temp->right;
			while(tempo != NULL)
			{
				min = tempo->value;
				tempo = tempo->left;
			}
			temp->value = min;
			temp->right = deletee(temp->right, min);
		}
		else
		{
			tempo = temp;
			if(temp->left == NULL)
				temp = temp->right;
			else
				temp = temp->left;
			delete tempo;
			size--;
		}
	}
	return temp;
}

void preorder(btree *temp)
{
	if(temp != NULL)
	{
		printf("%d\t",temp->value);
		preorder(temp->left);
		preorder(temp->right);
	}
}

void inorder(btree *temp)
{
	if(temp != NULL)
	{
		inorder(temp->left);
		printf("%d\t",temp->value);
		inorder(temp->right);
	}
}

void postorder(btree *temp)
{
	if(temp != NULL)
	{
		postorder(temp->left);
		postorder(temp->right);
		printf("%d\t",temp->value);
	}
}

btree *decrease(btree *temp)
{
	int value, dec;
	printf("Enter the element you want to decrease.\n");
	if(search(temp, value))
	scanf("%d",&value);
	{
		temp = deletee(temp, value);
		printf("Decrement value.\n");
		scanf("%d",&dec);
		insertt(&temp, value - dec);
	}
	else
		temp = deletee(temp, value);

	return temp;
}

btree *increase(btree *temp)
{
	int value, inc;
	printf("Enter the element you want to increase.\n");
	scanf("%d",&value);
	if(search(temp, value))
	{
		temp = deletee(temp, value);
		printf("Increment value.\n");
		scanf("%d",&inc);
		insertt(&temp, value + inc);
	}
	else
		temp = deletee(temp, value);

	return temp;
}

int depth(btree *temp)
{
	int dep = 0;

	if(temp->left != NULL)
		dep = 1 + depth(temp->left);

	if(temp->right != NULL)
		if( (1 + depth(temp->right)) > dep)
			dep = 1 + depth(temp->right);

	return dep;
}

int main()
{
	btree *root = NULL;
	btree *temp;
	int input, insert;
	while(1)
	{
            print_bt();
            scanf("%d",&input);
			switch(input)
			{
				case 1:
					size = 0;
					printf("Enter the root value.\n");
					scanf("%d",&insert);
					root = get_node(insert);
					printf("Btree created with root value = %d\n",insert);
					break;
				case 2:
					if(root == NULL)
					{
						printf("First create btree.\n");
						break;
					}
					scanf("%d",&insert);
					insertt(&root, insert);
					printf("Element %d inserted in the Btree.\n",insert);
					break;
				case 3:
					if(root == NULL)
					{
						printf("First create btree and push some element.\n");
						break;
					}
					int min;
					temp = root;
					while(temp!= NULL)
					{
						min = temp->value;
						temp = temp->left;
					}
					printf("Min value = %d.\n",min);
					break;
				case 4:
					if(root == NULL)
						printf("First create btree and push some element.\n");
					else
					{
						int max;
						temp = root;
						while(temp!= NULL)
						{
							max = temp->value;
							temp = temp->right;
						}
						printf("Max value = %d.\n",max);
					}
					break;
				case 5:
					if(root == NULL)
						printf("First create btree and push some element.\n");
					else
					{
						printf("Enter the value you want to search for :\n");
						scanf("%d",&insert);
						if(search(root, insert))
							printf("Value %d is present in the Btree.\n",insert);
						else
							printf("Value %d isn't  present in the Btree.\n",insert);
					}
					break;
				case 6:
					if(root == NULL)
						printf("Btree not created.\n");
					else
					{
						printf("Preorder traversal :\n");
						preorder(root);
						printf("\n");
					}
					break;
				case 7:
					if(root == NULL)
						printf("First create btree and push some element.\n");
					else
					{
						printf("Inorder traversal :\n");
						inorder(root);
						printf("\n");
					}
					break;
				case 8:
					if(root == NULL)
						printf("First create btree and push some element.\n");
					else
					{
						printf("Postorder traversal :\n");
						postorder(root);
						printf("\n");
					}
					break;
				case 9:
					if(root == NULL)
						printf("Btree not created.\n");
					else
						root = decrease(root);
					break;
				case 10:
					if(root == NULL)
						printf("Btree not created.\n");
					else
						root = increase(root);
					break;
				case 11:
					if(root == NULL)
						printf("Btree not created.\n");
					else
					{
						printf("Enter the element you want to delete.\n");
						scanf("%d",&insert);
						root = deletee(root, insert);
						printf("Element deleted from btree.\n");
					}
					break;
				case 12:
					if(root == NULL)
						printf("Btree not created or is empty. Create it.\n");
					else
						printf("No. Btree is not empty.\n");
					break;
				case 13:
					if(root == NULL)
						printf("Btree not created or is empty. Create it.\n");
					else
						printf("Size = %d.\n",size);
					break;
				case 14:
					if(root == NULL)
						printf("Btree not created.\n");
					else
						printf("Max depth = %d.\n",depth(root));
					break;
				case 15:
					if(root == NULL)
						printf("Btree not even present to delete.\n");
					else
					{
						size = 0;
						root = NULL;
						printf("Btree deleted. Recreate it to use further.\n");
					}
					break;
				case 16:
					break;
			}
			if(input==16)
			{
				printf("EXITING");
				break;
			}
			printf("\n");
	}
	return 0;
}
