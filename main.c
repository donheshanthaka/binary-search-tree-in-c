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
    struct bstNode *newNode = (struct bstNode*)malloc(sizeof(struct bstNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
};

// A recursive function to insert data into the tree
struct bstNode *insert(struct bstNode *root, int data){
    if(root == NULL){ // if the tree is empty
        root = getNewNode(data);

    }else if( data < root->data){ // if the data is less than the data in the current node, insert to the left subtree
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


// A recursive implementation to find the height of the tree
int height(struct bstNode *root){
    if(root == NULL){
        return -1;
    }
    return max(height(root->left), height(root->right)) + 1;
}

// function to find the max value of two int
int max(int left, int right){
    if (left > right){
        return left;
    }else{
        return right;
    }
}

// Pre-order traversal of tree using recursion
void preOrder(struct bstNode *root){
    if(root == NULL) return;
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

// In-order traversal of tree using recursion
void inOrder(struct bstNode *root){
    if(root == NULL) return;
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

// Post-order traversal of tree using recursion
void postOrder(struct bstNode *root){
    if(root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}

// Function deletes a node given its data value as input
struct bstNode *deleteNode(struct bstNode *root, int data){
    if (root == NULL) return root;
    else if (data < root->data){
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->data){
        root->right = deleteNode(root->right, data);
    }
    else{ // when data == the root->data

        // case 1: No child
        if (root->left == NULL && root->right == NULL){
            free(root);
            root = NULL;
            return root;
        }
        // case 2: One child
        else if (root->left == NULL){
            struct bstNode *temp = root;
            root = root->right;
            free(temp);
            temp = NULL;
            return root;
        }
        // case 3: 2 Children
        else{
            struct bstNode *temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
};

int main()
{
    struct BstNode *root = NULL;  // Creating an empty tree

    printf("The max value: %d\n", findMax(root));

	root = insert(root,27);
	root = insert(root,14);
	root = insert(root,35);
	root = insert(root,10);
	root = insert(root,19);
	root = insert(root,31);
	root = insert(root,42 );

	int number = 20;
	if(search(root,number) == true){
        printf("Found!\n");
	}
	else{
        printf("Not found!\n");
	}

	printf("The min value: %d\n", findMin(root));
	printf("The max value: %d\n", findMax(root));

	printf("The height of the tree: %d\n", height(root));



	printf("\nPre-order: ");
	preOrder(root);
	printf("\n");

    printf("\nIn-order: ");
	inOrder(root);
	printf("\n");

    printf("\nPost-order: ");
	postOrder(root);
	printf("\n");

	deleteNode(root, 31);

    printf("\nIn-order: ");
	inOrder(root);
	printf("\n");

    return 0;
}
