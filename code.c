#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

#define PATH_LENGTH_MAX 1024

typedef struct nodeForStack {
    char path[PATH_LENGTH_MAX];
    struct nodeForStack* next;
} nodeForStack;

nodeForStack* createNode(char* path) {
    nodeForStack* newNode = (nodeForStack*)malloc(sizeof(nodeForStack));
    strcpy(newNode->path, path);
    newNode->next = NULL;
    return newNode;
}

void push(nodeForStack** top, char* path) {
    nodeForStack* newNode = createNode(path);
    newNode->next = *top;
    *top = newNode;
}

char* pop(nodeForStack** top) {
    if (*top == NULL) {
        return NULL;
    }
    nodeForStack* temp = *top;
    char* path = (char*)malloc(PATH_LENGTH_MAX * sizeof(char));
    strcpy(path, temp->path);
    *top = temp->next;
    free(temp);
    return path;
}

int main(void) {
    int arraySize, choice;
    nodeForStack* stack = NULL;
    char* currentDir = (char*)malloc(PATH_LENGTH_MAX * sizeof(char));
    getcwd(currentDir, PATH_LENGTH_MAX);

    printf("Enter the maximum number of directories to store in the stack: ");
    scanf("%d", &arraySize);

    while (1) {
        printf("\nSelect an operation:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            char* newDir = (char*)malloc(PATH_LENGTH_MAX * sizeof(char));
            printf("Enter the directory path to push: ");
            scanf("%s", newDir);

            if (chdir(newDir) != 0) {
                printf("Error: Directory not found\n");
                continue;
            }

            push(&stack, currentDir);
            getcwd(currentDir, PATH_LENGTH_MAX);

            if (stack->next == NULL) {
                printf("Stack size: 1\n");
            } else {
                printf("Stack size: %d\n", arraySize - 1);
            }
        } else if (choice == 2) {
            if (stack == NULL) {
                printf("Error: No directory to pop\n");
                continue;
            }
            char* prevDir = pop(&stack);
            if (chdir(prevDir) != 0) {
                printf("Error: Directory not found\n");
                continue;
            }
            free(prevDir);

            if (stack == NULL) {
                printf("Stack size: 0\n");
            } else {
                printf("Stack size: %d\n", arraySize - 1);
            }
        } else if (choice == 3) {
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    free(currentDir);
    return 0;
}
