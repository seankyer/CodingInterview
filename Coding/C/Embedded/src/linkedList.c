/***
 * TODO:
 * Implement a linked-list using C
 * 
 * All operations O(n)
*/
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <assert.h>
#include "test.h"

// Simplest implementation with no meta data
struct linkedList {
    int i;
    struct linkedList *next;
};

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
 
int main() {
    printTestName("Simply Linked Lists!");

    // Create tests
    printTestName("Create some lists:");
    struct linkedList* list1 = createNode(0);
    assertTrue((uintptr_t) list1);
    struct linkedList* list2 = createNode(1);
    assertTrue((uintptr_t) list2);

    // Create edge case
    printTestName("Create a NULL list:");
    struct linkedList* garbageList = createNode(999);
    garbageList = deleteElementAt(garbageList, 0);
    assertFalse((uintptr_t) garbageList);

    // List manipulation tests
    printTestName("Append Element");
    struct linkedList* list = createNode(42);
    appendElement(list, 5);
    appendElement(list, 7);
    assertEquals(getElementAt(list, 0), 42);
    assertEquals(getElementAt(list, 1), 5);
    assertEquals(getElementAt(list, 2), 7);

    printTestName("Prepend Element");
    list = prependElement(list, -1);
    assertEquals(getElementAt(list, 0), -1);

    printTestName("Delete at Index");
    assertEquals(getElementAt(list, 1), 42);
    list = deleteElementAt(list, 1);
    assertEquals(getElementAt(list, 1), 5);
    list = deleteElementAt(list, 5);
    assertTrue((uintptr_t) list);

    // Interleave test
    printTestName("Interleave Test!");
    appendElement(list1, 2);
    appendElement(list1, 4);
    appendElement(list1, 6);
    appendElement(list2, 3);
    appendElement(list2, 5);
    struct linkedList* new = interleave(list1, list2);
    for (int i = 0; i < 6; i++) {
        assertEquals(getElementAt(new, i), i);
    }

    printTestName("Get Element Of Test:");
    struct linkedList* hiddenNumber = createNode(0);
    for (int i = 1; i < 25; i++) {
        appendElement(hiddenNumber, i);
    }
    assertEquals(getElementAt(hiddenNumber, 14), 14);
    assertEquals(getElementAt(hiddenNumber, 0), 0);
    assertEquals(getElementAt(hiddenNumber, 24), 24);
    // assertEquals(getElementAt(hiddenNumber, 25), -1); // Generates assertion (good)
    // assertEquals(getElementAt(hiddenNumber, 27), -1); // Generates assertion (good)
    hiddenNumber = deleteElementAt(hiddenNumber, 10);
    assertEquals(getElementAt(hiddenNumber, 10), 11);

    printTestName("Get Index Of Test:");
    assertEquals(getIndexOf(hiddenNumber, 10), -1);
    assertEquals(getIndexOf(hiddenNumber, 11), 10);
}