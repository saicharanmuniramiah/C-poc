#include "commands.h"
#include <stdio.h>
#include <string.h>
#include <time.h>

void showall(FSNode* dir) {
    for (int i = 0; i < dir->child_count; ++i) {
        FSNode* child = dir->children[i];
        char created[20], modified[20];
        strftime(created, sizeof(created), "%Y-%m-%d %H:%M", localtime(&child->created_at));
        strftime(modified, sizeof(modified), "%Y-%m-%d %H:%M", localtime(&child->modified_at));
        printf("%s\t[%s] (%s)\tCreated: %s\tModified: %s\n",
               child->name,
               child->type == DIR_NODE ? "DIR" : "FILE",
               child->permissions,
               created,
               modified);
    }
}

FSNode* stepin(FSNode* current, const char* name) {
    if (strcmp(name, "..") == 0 && current->parent)
        return current->parent;

    FSNode* target = find_child(current, name);
    if (target && target->type == DIR_NODE)
        return target;

    printf("Directory not found.\n");
    return current;
}

void makedir(FSNode* current, const char* name) {
    if (find_child(current, name)) {
        printf("Already exists.\n");
        return;
    }
    FSNode* dir = create_node(name, DIR_NODE, current);
    add_child(current, dir);
}

void newfile(FSNode* current, const char* name) {
    if (find_child(current, name)) {
        printf("File already exists.\n");
        return;
    }
    FSNode* file = create_node(name, FILE_NODE, current);
    add_child(current, file);
}

void pen(FSNode* current, const char* name, const char* content) {
    FSNode* file = find_child(current, name);
    if (file && file->type == FILE_NODE) {
        if (strchr(file->permissions, 'w')) {
            strncpy(file->content, content, MAX_CONTENT);
            time(&file->modified_at);
        } else {
            printf("Write permission denied.\n");
        }
    } else {
        printf("File not found.\n");
    }
}

void show(FSNode* current, const char* name) {
    FSNode* file = find_child(current, name);
    if (file && file->type == FILE_NODE) {
        printf("Content: %s\n", file->content);
    } else {
        printf("File not found.\n");
    }
}

void access(FSNode* current, const char* name, const char* perms) {
    FSNode* node = find_child(current, name);
    if (node) {
        strncpy(node->permissions, perms, MAX_PERM);
        printf("Permissions updated.\n");
    } else {
        printf("Node not found.\n");
    }
}

void mydir(FSNode* current) {
    if (!current) return;
    if (current->parent)
        mydir(current->parent);
    printf("/%s", current->name);
}
