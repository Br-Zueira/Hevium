#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct node {
    struct node *previous;
    struct node *next;
    char *value;
};

struct doubleNode {
    struct node *first;
    struct node *last;
};

void insertVal(const char *value, struct doubleNode *list);
bool findVal(const char *value, struct doubleNode *list);
void deleteVal(const char *value, struct doubleNode *list);

int main() {
    struct doubleNode list = {NULL, NULL};
    insertVal("a", &list);
    insertVal("bb", &list);
    insertVal("ccc", &list);
    insertVal("dddd", &list);
    insertVal("eeeee", &list);
    printf("a (on list): %d\n", findVal("a", &list));
    printf("bb (on list): %d\n", findVal("bb", &list));
    printf("ccc (on list): %d\n", findVal("ccc", &list));
    printf("ghj (never added): %d\n", findVal("ghj", &list));
    deleteVal("ccc", &list);
    printf("ccc (removed): %d\n", findVal("ccc", &list));
    deleteVal("a", &list);
    printf("a (removed, list head): %d\n", findVal("a", &list));
    deleteVal("eeeee", &list);
    printf("eeeee (removed, list tail): %d\n", findVal("eeeee", &list));
    return 0;
};

void insertVal(const char *value, struct doubleNode *list) {
    // If list is invalid, stop execution
    if (list == NULL) { return; }

    // Node to be added
    struct node *newNode = malloc(sizeof(struct node));
    newNode->value = strdup(value);
    newNode->previous = NULL;
    newNode->next = NULL;

    // Tracks which node we're in right now
    struct node *currentNode = list->first;
    
    // If there's not a first node, sets it as our current node
    if (currentNode == NULL) {
        list->first = newNode; 
    } else {
        newNode->previous = list->last;
        (list->last)->next = newNode;
    }

    // Puts the new node at the end of the list
    list->last = newNode;
}

bool findVal(const char *value, struct doubleNode *list) {
    // If list is empty or invalid, return false
    if (list == NULL || list->first == NULL) {
        return false;
    }

    // Tracks the current node we're in
    struct node *currentNode = list->first;

    // While we're in a valid node, goes to the next and return true if the value was found
    while (currentNode != NULL) {
        if (strcmp(currentNode->value, value) == 0) {
            return true;
        }
        currentNode = currentNode->next;
    }

    // If code reaches here, value was not found
    return false;
}

void deleteVal(const char *value, struct doubleNode *list) {
    // If list is empty or invalid, stop execution
    if (list == NULL || list->first == NULL) {
        return;
    }

    // Tracks the current node we're in
    struct node *currentNode = list->first;

    // While we're in a valid node, iterates through the nodes and change pointers if value found
    while (currentNode != NULL) {
        if (strcmp(currentNode->value, value) == 0) {
            // Gets the immediate neighbour nodes
            struct node *previousNode = currentNode->previous;
            struct node *nextNode = currentNode->next;

            // If first or last of list, update list directly
            // Else, updates nodes
            if (currentNode == list->first) {
                list->first = nextNode;
            } else {                
                previousNode->next = nextNode;
            }

            if (currentNode == list->last) {
                list->last = previousNode;
            } else {   
                nextNode->previous = previousNode;
            }

            // Memory safety always :)
            free(currentNode->value);
            free(currentNode);
            return;
        }
        currentNode = currentNode->next;
    }
}