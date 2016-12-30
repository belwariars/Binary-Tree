#include <bits/stdc++.h>
using namespace std;

struct nodel
{
	int data;
	struct nodel *next;	
	struct nodel *prev;
};

struct nodet
{
	int data;
	struct nodet *left;
	struct nodet *right;	
};

struct nodel* createnodel(int data)
{
	struct nodel* newnode = (struct nodel*)malloc(sizeof(struct nodel));
	newnode->data = data;
	newnode->next = NULL;
	newnode->prev = NULL;
	
	return newnode;
}

struct nodet* createnodet(int data)
{
	struct nodet* newnode = (struct nodet*)malloc(sizeof(struct nodet));
	newnode->data = data;
	newnode->left = NULL;
	newnode->right = NULL;
	
	return newnode;
}

void printlist(struct nodel *head1)
{
	while(head1 != NULL)
	{
		printf("%d ", head1->data);
		head1 = head1->next;
	}
}
struct nodel *head = NULL;
void push(int data)
{
	if(head==NULL)
	{
		head = createnodel(data);
		return;
	}
	struct nodel *temp = createnodel(data);
	temp->next = head;
	(head)->prev = temp;
	head = temp;
}

void treeToDLL(struct nodet *root)
{
	if(root == NULL)
	return ;
	
	treeToDLL(root->right);
	push(root->data);
	//printf("%d ", head->data);
	treeToDLL(root->left);
	
}

int main()
{
	struct nodet *root = createnodet(10);
    root->left        = createnodet(12);
    root->right       = createnodet(15);
    root->left->left  = createnodet(25);
    root->left->right = createnodet(30);
    root->right->left = createnodet(36);
    
    //printf("%d\n",head->data);
    treeToDLL(root);
    
    printlist(head);
    
	return 0;
}
