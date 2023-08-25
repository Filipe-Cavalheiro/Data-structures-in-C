#include "binaryTree.h"

typedef struct{
    int coords[2];
    int value;
} _dijkstraNode, *dijkstraNode;

int getElem(dijkstraNode elem){
    return elem->value;
}

int getElemGen(void* elem){
    return getElem((dijkstraNode)elem);
}

dijkstraNode makeDijkstraNode(int* coords, int value){
    dijkstraNode elem = (dijkstraNode)malloc(sizeof(_dijkstraNode));
    elem->coords[0] = coords[0];
    elem->coords[1] = coords[1];
    elem->value = value;
    return elem;
}

int main(){
    dijkstraNode node = makeDijkstraNode((int[2]){0,0}, 0);
    /*
    dijkstraNode node1 = makeDijkstraNode((int[2]){0,1}, 0);
    dijkstraNode node2 = makeDijkstraNode((int[2]){1,0}, 0);
    dijkstraNode node3 = makeDijkstraNode((int[2]){1,1}, 0);
    dijkstraNode node4 = makeDijkstraNode((int[2]){0,2}, 0);
    */
    binaryTree tree = makeBinaryTree(node);

    dijkstraNode currentNode = (dijkstraNode)getElem_bt(removeMinNode(&tree));
    printf("Removed a Node: {%d, %d}, %d\n", currentNode->coords[0], currentNode->coords[1], currentNode->value);
    if(tree == NULL)
        printf("tree is NULL\n");
    /*
    insert_bt(tree, node1, getElemGen);
    printf("created a Node: {%d, %d}, %d\n", node1->coords[0], node1->coords[1], node1->value);
    insert_bt(tree, node2, getElemGen);
    printf("created a Node: {%d, %d}, %d\n", node2->coords[0], node2->coords[1], node2->value);
    insert_bt(tree, node3, getElemGen);
    printf("created a Node: {%d, %d}, %d\n", node3->coords[0], node3->coords[1], node3->value);
    currentNode = (dijkstraNode)removeMinNode(tree);
    printf("Removed a Node: {%d, %d}, %d\n", currentNode->coords[0], currentNode->coords[1], currentNode->value);
    insert_bt(tree, node4, getElemGen);
    printf("created a Node: {%d, %d}, %d\n", node4->coords[0], node4->coords[1], node4->value);
    */

    /*
    dijkstraNode node1 = makeDijkstraNode(tmp, 25);
    insert_bt(tree, node, getElemGen);
    insert_bt(tree, node1, getElemGen);
    tree = removeNode_bt(tree, node, getElemGen);
    print_bt(tree, 0, getElemGen);
    printf("Min: %d\n", getElem(getElem_bt(findMin(tree))));
    printf("Max: %d\n", getElem(getElem_bt(findMax(tree))));
    insert_bt(tree, node, getElemGen);
    insert_bt(tree, node1, getElemGen);
    insert_bt(tree, node, getElemGen);
    insert_bt(tree, node1, getElemGen);
    print_bt(tree, 0, getElemGen);
    printf("Min: %d\n", getElem(getElem_bt(findMin(tree))));
    printf("Max: %d\n", getElem(getElem_bt(findMax(tree))));
    */
    freeTree(tree);
    return 0;
}
