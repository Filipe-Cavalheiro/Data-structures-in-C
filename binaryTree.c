#include "binaryTree.h"

// Define the binary tree node structure
struct _binaryTree {
    void* data;
    struct _binaryTree* left;
    struct _binaryTree* right;
} ;

// Function to create a new node
binaryTree makeBinaryTree(void* data) {
    binaryTree newNode = (binaryTree)malloc(sizeof(struct _binaryTree));
    if (newNode == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void* getElem_bt(binaryTree tree){
    return tree->data;
}

// Function to insert a new node into the tree
binaryTree insert_bt(binaryTree root, void* data, int (*getData)(void *)) {
    if (root == NULL) {
        return makeBinaryTree(data);
    }
    if (getData(data) <= getData(root->data)) {
        root->left = insert_bt(root->left, data, getData);
    } else if (getData(data) > getData(root->data)) {
        root->right = insert_bt(root->right, data, getData);
    }

    return root;
}

// Function to find the minimum value node in a tree
binaryTree findMin(binaryTree node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

// Function to find the maximum value node in a tree
binaryTree findMax(binaryTree node) {
    while (node->right != NULL) {
        node = node->right;
    }
    return node;
}

// Function to remove a node from the tree
binaryTree removeNode_bt(binaryTree root, void* data, int (*getData)(void *)) {
    if (root == NULL) {
        return root;
    }

    if (getData(data) < getData(root->data)) {
        root->left = removeNode_bt(root->left, data, getData);
    } else if (getData(data) > getData(root->data)) {
        root->right = removeNode_bt(root->right, data, getData);
    } else {
        // binaryTree with only one child or no child
        if (root->left == NULL) {
            binaryTree temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            binaryTree temp = root->left;
            free(root);
            return temp;
        }

        // binaryTree with two children: Get the inorder successor (smallest in the right subtree)
        binaryTree temp = findMin(root->right);

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = removeNode_bt(root->right, temp->data, getData);
    }

    return root;
}

binaryTree removeMinNode(binaryTree root) {
    if (root == NULL) {
        return NULL;
    }

    if (root->left == NULL) {
        binaryTree rightChild = root->right;
        free(root);
        return rightChild;
    }

    root->left = removeMinNode(root->left);
    return root;
}

// Function to deallocate memory of the tree
void freeTree(binaryTree root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

void print_bt(binaryTree root, int level, int (*getData)(void *)) {
    if (root == NULL){
        return;
    }

    print_bt(root->right, level + 1, getData);

    printf("%d\n", getData(root->data));
    
    print_bt(root->left, level + 1, getData);
}

