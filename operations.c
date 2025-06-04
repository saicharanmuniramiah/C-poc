#include "navigation.h"
#include <stdio.h>
#include <string.h>

FSNode* changedir(FSNode* current, const char* name) {
    if (strcmp(name, "..") == 0 && current->parent)
        return current->parent;

    FSNode* target = find_child(current, name);
    if (target && target->type == DIR_NODE)
        return target;

    printf("Directory not found.\n");
    return current;
}

void mydir(FSNode* current) {
    if (!current) return;
    if (current->parent)
        mydir(current->parent);
    printf("/%s", current->name);
}
