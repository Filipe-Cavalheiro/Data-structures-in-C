#include "mAryTree.h"

struct _mAryTreeNode{
    int value;
    struct _mAryTreeNode* parent;
    linkedList children;
};

mAryTreeNode makeMAryTreeNode(int val, mAryTreeNode parent){
    mAryTreeNode tree = (mAryTreeNode)malloc(sizeof(struct _mAryTreeNode));
    if(tree == NULL){
        perror("mAryTreeNode created with value NULL\n");
        return NULL;
    }
    tree->value = val;
    tree->parent = parent;
    tree->children = makeLinkedList();
    return tree;
} 

mAryTreeNode makeInsert_mAry(mAryTreeNode parent, int elem){
    if(parent == NULL)
        return parent;
    mAryTreeNode node = makeMAryTreeNode(elem);
    append(parent->children, node);
    return node;
}

void insert_mAry(mAryTreeNode parent, mAryTreeNode child){
    append(parent->children, child);
}

int getElem_mAry(mAryTreeNode tree){
    return tree->value;
}

linkedList getChildren(mAryTreeNode tree){
    return tree->children;
}

mAryTreeNode getParent(mAryTreeNode tree){
    return tree->parent;
}

void printChilldren(mAryTreeNode parent){
    print_ll(parent->children); 
}
