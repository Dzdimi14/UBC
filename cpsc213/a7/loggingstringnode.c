#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "node.h"
#include "stringnode.h"
#include "loggingstringnode.h"

// TODO

struct LoggingStringNode_class LoggingStringNode_class_table = {
    &StringNode_class_table,
    StringNode_compareTo,
    StringNode_printNode,
    LoggingStringNode_insert,
    Node_print,
    Node_delete,
};

void LoggingStringNode_ctor(void* thisv, char* s) {
    struct LoggingStringNode* this = thisv;
    Node_ctor(this);
    this->s = s;
}

void LoggingStringNode_insert(void* thisv, void* nodev) {
    struct LoggingStringNode* this = thisv;
    struct LoggingStringNode* node = nodev;
    Node_insert(this, node);
    printf("insert %s\n", node->s);
}


void* new_LoggingStringNode(char* s) {
    struct LoggingStringNode* obj = malloc(sizeof(struct LoggingStringNode));
    obj->class = &LoggingStringNode_class_table;
    LoggingStringNode_ctor(obj, s);
    return obj;
}
