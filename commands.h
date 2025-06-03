#ifndef COMMANDS_H
#define COMMANDS_H

#include "fs_node.h"

void showall(FSNode* dir);
FSNode* stepin(FSNode* current, const char* name);
void makedir(FSNode* current, const char* name);
void newfile(FSNode* current, const char* name);
void pen(FSNode* current, const char* name, const char* content);
void show(FSNode* current, const char* name);
void access(FSNode* current, const char* name, const char* perms);
void mydir(FSNode* current);

#endif
