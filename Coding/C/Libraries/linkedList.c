/***
 * Linked-list using C
 * 
 * All operations O(n)
*/
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "linkedList.h"

// Creates a node or begins a linked list
struct linkedList* createNode(int num) {
    struct linkedList* temp = malloc(sizeof(struct linkedList));
    temp->i = num;
    temp->next = NULL;
    return temp;
}

// Returns the integer element at the specified index
// index should be within range of list (assertion if otherwise)
int getElementAt(struct linkedList* head, int index) {
    assert(head);

    struct linkedList* temp = head;

    int i = 0;
    while (i < index) {
        if (temp == NULL) {
            assert(0);
        }

        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        assert(0);
    }

    return temp->i;
}

// Returns the first index of the element specified 
// If element not found, returns -1
int getIndexOf(struct linkedList* head, int element) {
    assert(head);

    struct linkedList* temp = head;
    int i = 0;

    if (head->i == element) {
        return i;
    }

    while (temp->next != NULL) {
        if (temp->i == element) {
            return i;
        }
        temp = temp->next;
        i++;
    }

    if (temp->i == element) {
        return i;
    }

    return -1;
}

// Add an element to the end of the list
void appendElement(struct linkedList* head, int value) {
    assert(head);
    struct linkedList* temp = head;

    // Find the end of the list
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = createNode(value);
}

// Add an element to the begining of the list
// Return the new start of the list
struct linkedList* prependElement(struct linkedList* head, int value) {
    assert(head);
    
    struct linkedList* temp = createNode(value);

    temp->next = head;
    return temp;
}

// Deletes and frees the element at the specified index
// If the index cannot be reached, do nothing instead
// Returns the updated list
struct linkedList* deleteElementAt(struct linkedList* head, int index) {
    assert(head);
    struct linkedList* temp = head;

    // If the index is 0, we just return the next value
    if (index == 0) {
        temp = head->next;
        free(head);
        head = NULL;
        return temp;
    }

    // Find the index, or the end of the list
    // Stop directly before the element to delete
    int i = 1;
    while (temp->next != NULL && i < index) {
        temp = temp->next;
        i++;
    }

    // Means index out of range
    if (i < index || temp->next == NULL) {
        return head;
    }
    // The next element is the one we will delete
    struct linkedList* delNode = temp->next;

    // Preserve order, unless we are already at the end of the list
    if (delNode->next != NULL) {
        struct linkedList* tail = delNode->next;
        temp->next = tail;
    } else {
        temp->next = NULL;
    }

    // Free the pointer and node
    free(delNode);
    delNode = NULL;

    return head;
}

// Iterate and print each element after the head
void printList(struct linkedList* head) {
    assert(head);

    struct linkedList* temp = head;

    int count = 0;
    while (temp->next != NULL) {
        printf("%d: %d\n", count, temp->i);
        temp = temp->next;
        count++;
    }
    printf("%d: %d\n\n", count, temp->i);
}

// Destructively interleaves the two list to become part of eachother
struct linkedList* interleave(struct linkedList* list1, struct linkedList* list2) {
    if (list1 == NULL) {
        return list2;
    } else if (list2 == NULL) {
        return list1;
    }

    struct linkedList* temp = list1->next;
    list1->next = list2;
    list2->next = interleave(temp, list2->next);
    
    return list1;
}
