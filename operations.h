#ifndef NAVIGATION_H
#define NAVIGATION_H

#include "fs_node.h"

FSNode* changedir(FSNode* current, const char* name);
void mydir(FSNode* current);

#endif
