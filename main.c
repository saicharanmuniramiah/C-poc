#include <stdio.h>
#include <string.h>
#include "fs_node.h"
#include "commands.h"

int main() {
    FSNode* root = create_node("root", DIR_NODE, NULL);
    FSNode* current = root;
    char command[100], arg1[100], arg2[1024];

    while (1) {
        printf("\n");
        mydir(current);
        printf("> ");
        scanf("%s", command);

        if (strcmp(command, "bye") == 0) break;

        if (strcmp(command, "showall") == 0) {
            showall(current);
        } else if (strcmp(command, "stepin") == 0) {
            scanf("%s", arg1);
            current = stepin(current, arg1);
        } else if (strcmp(command, "makedir") == 0) {
            scanf("%s", arg1);
            makedir(current, arg1);
        } else if (strcmp(command, "newfile") == 0) {
            scanf("%s", arg1);
            newfile(current, arg1);
        } else if (strcmp(command, "pen") == 0) {
            scanf("%s", arg1);
            getchar();
            fgets(arg2, sizeof(arg2), stdin);
            arg2[strcspn(arg2, "\n")] = 0;
            pen(current, arg1, arg2);
        } else if (strcmp(command, "show") == 0) {
            scanf("%s", arg1);
            show(current, arg1);
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
