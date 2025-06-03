#include "fs_node.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>

FSNode* create_node(const char* name, NodeType type, FSNode* parent) {
    FSNode* node = (FSNode*)malloc(sizeof(FSNode));
    strncpy(node->name, name, MAX_NAME);
    node->type = type;
    node->parent = parent;
    node->child_count = 0;
    memset(node->children, 0, sizeof(node->children));
    memset(node->content, 0, sizeof(node->content));
    time(&node->created_at);
    node->modified_at = node->created_at;
    strcpy(node->permissions, "rw");
    return node;
}

void add_child(FSNode* parent, FSNode* child) {
    if (parent->child_count < MAX_CHILDREN) {
        parent->children[parent->child_count++] = child;
    }
}

FSNode* find_child(FSNode* dir, const char* name) {
    for (int i = 0; i < dir->child_count; ++i) {
        if (strcmp(dir->children[i]->name, name) == 0)
            return dir->children[i];
    }
    return NULL;
}
