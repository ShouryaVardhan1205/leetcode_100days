#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    int size;
} MyLinkedList;

/** Initialize your data structure here. */
MyLinkedList* myLinkedListCreate() {
    MyLinkedList* obj = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    obj->head = NULL;
    obj->size = 0;
    return obj;
}

/** Get the value of the index-th node in the linked list. */
int myLinkedListGet(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size)
        return -1;

    Node* temp = obj->head;
    for (int i = 0; i < index; i++)
        temp = temp->next;

    return temp->val;
}

/** Add a node of value val before the first element. */
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = obj->head;
    obj->head = newNode;
    obj->size++;
}

/** Append a node of value val to the last element. */
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = NULL;

    if (obj->head == NULL) {
        obj->head = newNode;
    } else {
        Node* temp = obj->head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }

    obj->size++;
}

/** Add a node before the index-th node. */
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if (index < 0 || index > obj->size)
        return;

    if (index == 0) {
        myLinkedListAddAtHead(obj, val);
        return;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;

    Node* temp = obj->head;
    for (int i = 0; i < index - 1; i++)
        temp = temp->next;

    newNode->next = temp->next;
    temp->next = newNode;

    obj->size++;
}

/** Delete the index-th node. */
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size)
        return;

    Node* temp;

    if (index == 0) {
        temp = obj->head;
        obj->head = obj->head->next;
        free(temp);
    } else {
        Node* prev = obj->head;
        for (int i = 0; i < index - 1; i++)
            prev = prev->next;

        temp = prev->next;
        prev->next = temp->next;
        free(temp);
    }

    obj->size--;
}

/** Free all nodes */
void myLinkedListFree(MyLinkedList* obj) {
    Node* current = obj->head;
    while (current != NULL) {
        Node* next = current->next;
        free(current);
        current = next;
    }
    free(obj);
}