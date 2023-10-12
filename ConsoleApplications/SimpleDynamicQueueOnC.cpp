#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char* value;
    struct Node* next;
};

struct Queue {
    struct Node* begin;
    struct Node* end;
};

struct Queue queue;

char* Pop() {
    if (queue.begin == NULL && queue.end == NULL) {
        printf("Queue is empty!\n");
        return NULL;
    }
    char* value = queue.begin->value;
    struct Node* currentNode = queue.begin;
    if (queue.begin == queue.end) {
        queue.begin = NULL;
        queue.end = NULL;
        free(currentNode);
        return value;
    }
    else {
        queue.begin = queue.begin->next;
        free(currentNode);
        return value;
    }
}

void Push(char* value) {
    struct Node* currentNode = (struct Node*)malloc(sizeof(struct Node));
    if (currentNode == NULL) {
        printf("Memory is used at its full.\n");
        return;
    }

    currentNode->value = (char*)malloc(strlen(value));
    if (currentNode->value == NULL) {
        printf("Memory is used at its full.\n");
        free(currentNode);
        return;
    }

    strcpy(currentNode->value, value);

    currentNode->next = NULL;

    if (queue.end == NULL) {
        queue.end = currentNode;
        queue.begin = currentNode;
    }
    else {
        queue.end->next = currentNode;
        queue.end = currentNode;
    }
}

int main() {
    char words[100];

    scanf("%s", words);
    char quit[5] = "quit";
    while (strcmp(quit, words) != 0) {
        Push(words);
        scanf("%s", words);
    }

    char* poppedValue;
    poppedValue = Pop();
    while (poppedValue != NULL) {
        printf("%s ->", poppedValue);
        poppedValue = Pop();
    }
    return 0;
}
