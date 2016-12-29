#include <bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	struct node *left;
	struct node *right;
	struct node *next;	
};

struct node* createnode(int data)
{
	struct node *newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = data;
	newnode->left = NULL;
	newnode->right = NULL;
	newnode->next = NULL;
}

struct node *nextin = NULL;

void reverseInorder(struct node *root)
{
	if(root == NULL)
	return;
	
	reverseInorder(root->right);
	
	root->next = nextin;
	nextin = root;
	
	reverseInorder(root->left);
}

int main()
{
	struct node *root = createnode(10);
    root->left        = createnode(8);
    root->right       = createnode(12);
    root->left->left  = createnode(3);
 
    // Populates nextRight pointer in all nodes
    reverseInorder(root);
 
    // Let us see the populated values
    struct node *ptr = root->left->left;
    while(ptr)
    {
        // -1 is printed if there is no successor
        printf("Next of %d is %d \n", ptr->data, ptr->next? ptr->next->data: -1);
        ptr = ptr->next;
    }
	return 0;
}
