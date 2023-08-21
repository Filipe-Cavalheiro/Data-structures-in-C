#include "binaryTree.h"

typedef struct _dijkstraNode{
    int coords[2];
    int value;
}*dijkstraNode ;

int getElem(dijkstraNode elem){
    return elem->value;
}

int getElemGen(void* elem){
    return getElem((dijkstraNode)elem);
}

dijkstraNode makeDijkstraNode(int* coords, int value){
    dijkstraNode elem = (dijkstraNode)malloc(sizeof(struct _dijkstraNode));
    elem->coords[0] = coords[0];
    elem->coords[1] = coords[1];
    elem->value = value;
    return elem;
}

int main(){
    int tmp[] = {2,2};
    dijkstraNode node = makeDijkstraNode(tmp, 5);
    dijkstraNode node1 = makeDijkstraNode(tmp, 25);
    binaryTree root = makeBinaryTree(node);
    insert_bt(root, node, getElemGen);
    insert_bt(root, node1, getElemGen);
    root = removeNode_bt(root, node, getElemGen);
    print_bt(root, 0, getElemGen);
    printf("Min: %d\n", getElem(getElem_bt(findMin(root))));
    printf("Max: %d\n", getElem(getElem_bt(findMax(root))));
    insert_bt(root, node, getElemGen);
    insert_bt(root, node1, getElemGen);
    insert_bt(root, node, getElemGen);
    insert_bt(root, node1, getElemGen);
    removeMinNode(root);    
    print_bt(root, 0, getElemGen);
    printf("Min: %d\n", getElem(getElem_bt(findMin(root))));
    printf("Max: %d\n", getElem(getElem_bt(findMax(root))));
    freeTree(root);
    return 0;
}
