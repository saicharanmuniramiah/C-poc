#include <stdio.h>
#include <string.h>
#include "fs_node.h"
#include "operations.h"
#include "navigation.h"

int main() {
    FSNode* root = create_node("root", DIR_NODE, NULL);
    FSNode* current = root;
    char command[100], arg1[100], arg2[1024];

    while (1) {
        printf("\n");
        mydir(current);
        printf("> ");
        scanf("%s", command);

        if (strcmp(command, "exit") == 0) break;

        if (strcmp(command, "listfiles") == 0) {
            listfiles(current);
        } else if (strcmp(command, "changedir") == 0) {
            scanf("%s", arg1);
            current = changedir(current, arg1);
        } else if (strcmp(command, "makedir") == 0) {
            scanf("%s", arg1);
            makedir(current, arg1);
        } else if (strcmp(command, "newfile") == 0) {
            scanf("%s", arg1);
            newfile(current, arg1);
        } else if (strcmp(command, "write") == 0) {
            scanf("%s", arg1);
            getchar();
            fgets(arg2, sizeof(arg2), stdin);
            arg2[strcspn(arg2, "\n")] = 0;
            write(current, arg1, arg2);
        } else if (strcmp(command, "read") == 0) {
            scanf("%s", arg1);
            read(current, arg1);
        } else if (strcmp(command, "access") == 0) {
            scanf("%s %s", arg1, arg2);
            access(current, arg1, arg2);
        } else if (strcmp(command, "mydir") == 0) {
            mydir(current);
            printf("\n");
        } else {
            printf("Unknown command.\n");
        }
    }

    return 0;
}
