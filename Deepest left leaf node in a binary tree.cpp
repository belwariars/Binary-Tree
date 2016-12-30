#include <bits/stdc++.h>
using namespace std;


struct node
{
	int data;
	struct node *left;
	struct node *right;	
};

struct node* createnode(int data)
{
	struct node *newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = data;
	newnode->left = NULL;
	newnode->right = NULL;
}

void inorder(struct node *root)
{
	if(root == NULL)
	return;
	
	inorder(root->left);
	printf("%d ", root->data);
	inorder(root->right);
}

int height(struct node *root)
{
	if(root == NULL)
	return 0;
	
	int lheight = height(root->left);
	int rheight = height(root->right);
	
	if(lheight > rheight)
	return lheight+1;
	else
	return rheight+1;
}
int deepleft = -1;
void BFS(struct node *root)
{
	if(root == NULL)
	return;
	
	list<struct node*> queue;
	struct node *temp = root;
	queue.push_back(temp);
	
	while(queue.size() > 0)
	{
		int count = queue.size();
		while(count--)
		{
			temp = queue.front();
			queue.pop_front();
			//printf("%d ", temp->data);
			
			if(temp->left != NULL)
			{
				queue.push_back(temp->left);
				deepleft = (temp->left)->data;
			}
			if(temp->right != NULL)
			{
				queue.push_back(temp->right);
			}
		}
	}
	
	if(deepleft == -1)
	{
		printf("No Left node\n");
	}
	else
	{
		printf("Deepest Left node=  %d\n", deepleft);
	}
}


int main()
{
	
	struct node* root = createnode(1);
    //root->left = createnode(2);
    root->right = createnode(3);
   // root->left->left = createnode(4);
 //   root->right->left = createnode(5);
    root->right->right = createnode(6);
    //root->right->left->right = createnode(7);
    root->right->right->right = createnode(8);
   // root->right->left->right->left = createnode(9);
    root->right->right->right->right = createnode(10);

	BFS(root);
	
  	
	return 0;
}
