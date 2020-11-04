#ifndef __INTEGERNODE_H__
#define __INTEGERNODE_H__

// TODO

struct IntegerNode_class {
    struct Node_class* super;
    int (*compareTo) (void*, void*);
    void (*printNode) (void*);
    void (*insert) (void*, void*);
    void (*print) (void*);
    void (*delete) (void*);
    int (*sum) (void*);
};

extern struct IntegerNode_class IntegerNode_class_table;

struct IntegerNode;
struct IntegerNode {
    struct IntegerNode_class* class;
    struct IntegerNode* left;
    struct IntegerNode* right;

    char* i;
};

void IntegerNode_ctor(void*, char*);
int IntegerNode_compareTo(void*, void*);
void IntegerNode_printNode(void*);
int sum(void*);

void* new_IntegerNode(char*);



#endif /*__INTEGERNODE_H__*/
