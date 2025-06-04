#ifndef FS_NODE_H
#define FS_NODE_H

#include <time.h>

#define MAX_NAME 100
#define MAX_CHILDREN 10
#define MAX_CONTENT 1024
#define MAX_PERM 4

typedef enum { FILE_NODE, DIR_NODE } NodeType;

typedef struct FSNode {
    char name[MAX_NAME];
    NodeType type;
    char content[MAX_CONTENT];
    struct FSNode* parent;
    struct FSNode* children[MAX_CHILDREN];
    int child_count;
    time_t created_at;
    time_t modified_at;
    char permissions[MAX_PERM];
} FSNode;

FSNode* create_node(const char* name, NodeType type, FSNode* parent);
void add_child(FSNode* parent, FSNode* child);
FSNode* find_child(FSNode* dir, const char* name);

#endif

