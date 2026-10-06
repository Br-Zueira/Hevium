#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct node {
    struct node *previous;
    struct node *next;
    int value;
};

struct doubleNode {
    struct node *first;
    struct node *last;
};

void insertVal(int value, struct doubleNode *list);
bool findVal(int value, struct doubleNode *list);
void deleteVal(int value, struct doubleNode *list);

int main() {
    struct doubleNode list = {NULL, NULL};
    insertVal(1, &list);
    insertVal(2, &list);
    insertVal(3, &list);
    insertVal(4, &list);
    insertVal(5, &list);
    printf("1 (on list): %d\n", findVal(1, &list));
    printf("2 (on list): %d\n", findVal(2, &list));
    printf("4 (on list): %d\n", findVal(4, &list));
    printf("7 (never added): %d\n", findVal(7, &list));
    deleteVal(4, &list);
    printf("4 (removed): %d\n", findVal(4, &list));
    return 0;
};

void insertVal(int value, struct doubleNode *list) {
    // If list is invalid, stop execution
    if (list == NULL) { return; }

    // Node to be added
    struct node *newNode = malloc(sizeof(struct node));
    newNode->value = value;
    newNode->previous = NULL;
    newNode->next = NULL;

    // Tracks which node we're in right now
    struct node *currentNode = list->first;
    
    // If there's not a first node, sets it as our current node
    if (currentNode == NULL) {
        list->first = newNode; 
    } else {
        // Finds the previous node to be set
        while (currentNode != NULL) {
            newNode->previous = currentNode;
            currentNode = currentNode->next;
        }
    }

    // Puts the new node at the end of the list
    list->last = newNode;

    printf("[VALUE: %d] [NEWNODE: %X] [PREVIOUS: %X] [NEXT: %X]\n", value, newNode, newNode->previous, newNode->next);
}

bool findVal(int value, struct doubleNode *list) {
    // If list is empty or invalid, return false
    if (list == NULL || list->first == NULL) {
        return false;
    }

    // Tracks the current node we're in
    struct node *currentNode = list->first;

    // While we're in a valid node, goes to the next and return true if the value was found
    while (currentNode != NULL) {
        if (currentNode->value && currentNode->value == value) {
            return true;
        }
        currentNode = currentNode->next;
    }

    // If code reaches here, value was not found
    return false;
}

void deleteVal(int value, struct doubleNode *list) {
    // If list is empty or invalid, stop execution
    if (list == NULL || list->first == NULL) {
        return;
    }

    // Tracks the current node we're in
    struct node *currentNode = list->first;

    // While we're in a valid node, iterates through the nodes and change pointers if value found
    while (currentNode != NULL) {
        if (currentNode->value == value) {
            struct node *previousNode = currentNode->previous;
            struct node *nextNode = currentNode->next;

            previousNode->next = nextNode;
            nextNode->previous = previousNode;

            return;
        }
        currentNode = currentNode->next;
    }
}