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

unordered_map<int, int> container;
int count1 = 0;
int count2 = 0;
void storeParentChild(struct node *root, struct node *parent)
{
	if(root == NULL)
	return;
	
	if(parent == NULL)
	{
		container.insert(make_pair(root->data, -1));
	}
	else
	{
		container.insert(make_pair(root->data, parent->data));
	}
	count1++;
	storeParentChild(root->left, root);
	storeParentChild(root->right, root);
}
bool flag = true;
void isIsomorphic(struct node *root, struct node *parent)
{
	if(root == NULL)
	return;
	
	if(container.find(root->data) == container.end())
	{
		flag = false;
	}
	if(parent!= NULL && container.find(root->data) != container.end())
	{
		if((container.find(root->data))->second != parent->data)
		{
			flag = false;
		}
	}
	else if(parent== NULL && container.find(root->data) != container.end())
	{
		if((container.find(root->data))->second != -1)
		{
			flag = false;
		}
	}
	count2++;
	isIsomorphic(root->left, root);
	isIsomorphic(root->right, root);
}


int main()
{
	struct node *n1 = createnode(1);
    n1->left        = createnode(2);
    n1->right       = createnode(3);
    n1->left->left  = createnode(4);
    n1->left->right = createnode(5);
    n1->right->left  = createnode(6);
    n1->left->right->left = createnode(7);
    n1->left->right->right = createnode(8);
 
    struct node *n2 = createnode(1);
    n2->left         = createnode(3);
    n2->right        = createnode(2);
    n2->right->left   = createnode(4);
    n2->right->right   = createnode(5);
    n2->left->right   = createnode(6);
    n2->right->right->left = createnode(8);

	storeParentChild(n1, NULL);
	isIsomorphic(n2, NULL);
//	printf("%d %d\n", count1, count2);
	if(flag && count1 == count2)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
	
  	
	return 0;
}
