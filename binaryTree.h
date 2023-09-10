#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <stdio.h>
#include <stdlib.h>
#include "binaryTree.c"

binaryTree makeBinaryTree(void* data);

void* getElem_bt(binaryTree tree);

void putItNULL(binaryTree *root);

// Function to insert a new node into the tree
binaryTree insert_bt(binaryTree root, void* data, float (*getData)(void *));

// Function to find the minimum value node in a tree
binaryTree findMin(binaryTree node);

// Function to find the maximum value node in a tree
binaryTree findMax(binaryTree node);

// Function to remove a node from the tree
binaryTree removeNode_bt(binaryTree root, void* data, int (*getData)(void *));

binaryTree removeMinNode(binaryTree *root);

// Function to deallocate memory of the tree
void freeTree(binaryTree root);

void print_bt(binaryTree root, int level, int(*getData)(void *));
#endif /* HASHTABLE_H */
