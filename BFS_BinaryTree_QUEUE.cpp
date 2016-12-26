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
	
	return newnode;
}

void inorder(struct node* root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}	
}

void BFStraversal(struct node *root)
{
	struct node *temp = root;
	list<struct node *> queue; // Because list and queue have same  implementation....
	queue.push_back(temp);
	bool flag = true;
	while(queue.size() > 0)
	{
		temp = queue.front();
		queue.pop_front();
		
		printf("%d ", temp->data);
		if(temp->left != NULL)
		{
			queue.push_back((temp->left));
		}
		if(temp->right != NULL)
		{
			queue.push_back((temp->right));
		}
	}
}

int main()
{
	struct node *root = createnode(10);
	root->left = createnode(20);
	root->left->left = createnode(40);
	root->left->left->left = createnode(50);
	root->left->left->left->left = createnode(60);
	root->left->left->left->left->left = createnode(70);
	root->left->right = createnode(50);
	
	printf("Level Order (BFS):  ");
	BFStraversal(root);
	printf("\n");
	
	printf("inorder:  ");
	inorder(root);
	printf("\n");
	
	return 0;
}
