/*
Given a Sorted Array of integers .Create a new Balanced Binary Search Tree from the Array
and return the head of the new BST .

Ex : Input : [1,6,10]
Output : A new BST which structure is as follows 
  6
 / \
1  10

A BST is said to be balanced ,when it satisifes the following property 

Every node's Difference of Left subtree height and right-subtree height is not more than 1 .

Below Tree is Not a Balanced BST ,as 1's left subtree has height of 0 ,but 
right subtree height is 2 
(Diff >1)

  1
   \
    3
   / \
  10  5

Note : Return head of newly created BST
Note : Return Null for invalid Inputs
Note : Donot create a new BST .
*/
#include <stdlib.h>

struct node *convertToBalBST(int *, int, int);
struct node *createNode(int);

struct node{
	struct node * left;
	int data;
	struct node *right;
};


struct node * convert_array_to_bst(int *arr, int len){
	if (arr==NULL || len<=0)
	return NULL;
	
	struct node *root = convertToBalBST(arr,0,len-1);
	return root;
}

//Function to convert the elements of sorted array to balanced BST
struct node *convertToBalBST(int *arr, int start, int end)
{
	if (start > end)
		return NULL;
	int mid = (start + end) / 2;
	struct node *root = createNode(arr[mid]); //Recursively take the middle element of the array
	                                          //and form the bst
	root->left = convertToBalBST(arr, start, mid - 1); //Traverse through left sub array
	
	root->right = convertToBalBST(arr, mid + 1, end); //Traverse through right sub array

	return root;
}

//Function to create the balanced BST
struct node *createNode(int num)
{
	struct node *new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = num;
	new_node->left = NULL;
	new_node->right = NULL;

	return new_node;
}