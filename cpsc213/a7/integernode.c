#include <stdlib.h>
#include <stdio.h>
#include "node.h"
#include "integernode.h"

// TODO

struct IntegerNode_class IntegerNode_class_table = {
    &Node_class_table,
    IntegerNode_compareTo,
    IntegerNode_printNode,
    Node_insert,
    Node_print,
    Node_delete,
    sum,
};



void IntegerNode_ctor(void* thisv, char* i) {
    struct IntegerNode* this = thisv;
    Node_ctor(this);
    this->i = i;
}

int IntegerNode_compareTo(void* thisv, void* nodev) {
    struct IntegerNode* this = thisv;
    struct IntegerNode* node = nodev;
    char* a = this->i;
    char* b = node->i;
    int i = atoi(a);
    int n = atoi(b);
    if (i > n)
        return 1;
    else if (i < n)
        return -1;
    else
        return 0;
}

void IntegerNode_printNode(void* thisv) {
    struct IntegerNode* this = thisv;
    printf("%s\n", this->i);
}



int sum(void* thisv) {

    struct IntegerNode* this = thisv;
    char* s = this->i;
    int m = atoi(s);

    if (this->left != NULL)
        m += (this->left->class->sum(this->left));
    if (this->right != NULL)
        m += (this->right->class->sum(this->right));
    return m;
}

void* new_IntegerNode(char* i) {
    struct IntegerNode* obj = malloc(sizeof(struct IntegerNode));
    obj->class = &IntegerNode_class_table;
    IntegerNode_ctor(obj, i);
    return obj;
}
