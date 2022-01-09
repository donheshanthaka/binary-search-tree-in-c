#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct bstNode{
    int data;
    struct bstNode *left;
    struct bstNode *right;
};

// function creates a new node in the heap
struct bstNode *getNewNode(int data){
    struct bstNode *newNode = malloc(sizeof(struct bstNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
};

// A recursive function to insert data into the tree
struct bstNode *insert(struct bstNode *root, int data){
    if(root == NULL){ // if the tree is empty
        root = getNewNode(data);

    }else if( data <= root->data){ // if the data is less than the data in the current node, insert to the left subtree
        root->left = insert(root->left, data);

    }else{ // if the data is greater than the data in the current node, insert to the right subtree
        root->right = insert(root->right, data);
    }
    return root;

};

bool search(struct bstNode *root, int data){
    if(root == NULL){
        return false;
    }
    else if(root->data == data){
        return true;
    }
    else if(data <= root->data){
        return search(root->left, data);
    }
    else{
        return search(root->right, data);
    }
}

// iterative solution to find the min value
int findMin(struct bstNode *root){
    if (root == NULL){
        printf("Error: The tree is empty!\n");
        return -1;
    }
    struct bstNode *current = root;
    while(current->left != NULL){
        current = current->left;
    }
    return current->data;
}

// recursive solution to find the max value
int findMax(struct bstNode *root){
    if (root == NULL){
        printf("Error: The tree is empty!\n");
        return -1;
    }
    else if (root->right == NULL){
        return root->data;
    }
    // search in right sub tree
    return findMax(root->right);
}

int main()
{

    struct BstNode *root = NULL;  // Creating an empty tree

    printf("The max value: %d\n", findMax(root));

	root = insert(root,15);
	root = insert(root,10);
	root = insert(root,20);
	root = insert(root,25);
	root = insert(root,8);
	root = insert(root,12);

	int number = 20;
	if(search(root,number) == true){
        printf("Found!\n");
	}
	else{
        printf("Not found!\n");
	}

	printf("The min value: %d\n", findMin(root));
	printf("The max value: %d\n", findMax(root));

    return 0;
}
