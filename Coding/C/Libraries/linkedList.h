#ifndef __LINKEDLIST_H
#define __LINKEDLIST_H

// Simplest implementation with no meta data
struct linkedList {
    int i;
    struct linkedList *next;
};

struct linkedList* createNode(int num);
int getElementAt(struct linkedList* head, int index);
int getIndexOf(struct linkedList* head, int element);
void appendElement(struct linkedList* head, int value);
struct linkedList* prependElement(struct linkedList* head, int value);
struct linkedList* deleteElementAt(struct linkedList* head, int index);
void printList(struct linkedList* head);
struct linkedList* interleave(struct linkedList* list1, struct linkedList* list2);

#endif