/*

Given a Binary Search Tree ,Calculate its Inorder ,Postorder and PreOrder

Input : A BST
Output : Copy Inorder/Postorder/Preorder into the array specified .

Note : Memory for the Array is already allocated ,Dont allocate it again using malloc
->Take help of helper functions which are actually solving the problem .
->Dont Process Invalid Inputs

Bonus Task : 
->Go to the BSTTransversals Spec File ,We have left a custom test case for you ,Try to fill
it and understand how testing works .
*/

#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};

void inorder(struct node *root, int *arr){
	static int k = 0;   //NULL case
	if (root == NULL||arr==NULL)
		return;
	else
	{
		inorder(root->left, arr); //Traverse left subtree
		arr[k++] = root->data;  //Store data in array
		inorder(root->right, arr); //Traverse right subtree
	}
}

void preorder(struct node *root, int *arr){
	static int k = 0;
	if (root == NULL || arr == NULL)
		return;
	else
	{
		arr[k++] = root->data; //Store data in array
		preorder(root->left, arr); //Traverse left subtree
		preorder(root->right, arr); //Traverse right subtree
	}
}
void postorder(struct node *root, int *arr){
	static int k = 0;
	if (root == NULL || arr == NULL)
		return;
	else
	{
		postorder(root->left, arr); //Traverse left subtree
		postorder(root->right, arr); //Traverse right subtree
		arr[k++] = root->data; //Store data in array
	}
}

