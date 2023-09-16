/***
 * TODO:
 * Implement a queue using a simply linked list
*/
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include "test.h"
#include "linkedList.h"

struct queue {
    struct linkedList* head;
    struct linkedList* tail;
    int numElements;
};

// Initialize the queue
struct queue* createQueue() {
    struct queue* temp = malloc(sizeof(struct queue));
    temp->head = NULL;
    temp->tail = NULL;
    temp->numElements = 0;

    return temp;
}

// Add element to the end of the linkedList
// O(1)
void enqueue(struct queue* que, int val) {
    assert(que);

    if (que->numElements == 0) {
        que->head = createNode(val);
        que->tail = que->head;
        que->numElements++;
    } else {
        appendElement(que->tail, val);
        que->tail = que->tail->next;
        que->numElements++;
    }
}

// Pop the first element off the queue
// O(1)
int dequeue(struct queue* que) {
    assert(que);

    if (que->numElements <= 0) {
        assert(0);
    }

    int value = getElementAt(que->head, 0);
    que->head = deleteElementAt(que->head, 0);
    que->numElements--;
    return value;
}

// Pop each element off the queue and free the queue
// O(n)
struct queue* destroyQueue(struct queue* que) {
    assert(que);

    for (int i = 0; i < que->numElements; i++) {
        dequeue(que);
    }
    free(que);
    que = NULL;
    return que;
}

int main() {
    printTestName("Simply Linked Lists!");

    printTestName("Create Queue Test:");
    struct queue* que = createQueue();
    assertTrue((uintptr_t) que);

    printTestName("Enqueue Test:");
    enqueue(que, 0);
    assertEquals(1, que->numElements);
    enqueue(que, 1);
    assertEquals(2, que->numElements);
    enqueue(que, 2);
    assertEquals(3, que->numElements);
    enqueue(que, 3);
    assertEquals(4, que->numElements);
    enqueue(que, 4);
    assertEquals(5, que->numElements);
    struct linkedList* temp = que->head;
    for (int i = 0; i < 4; i++) {
        assertEquals(i, temp->i);
        temp = temp->next;
    }
    assertEquals((uintptr_t) temp, (uintptr_t) que->tail);

    printTestName("Dequeue Test:");
    assertEquals(dequeue(que), 0);
    assertEquals(4, que->numElements);
    assertEquals(dequeue(que), 1);
    assertEquals(3, que->numElements);
    assertEquals(dequeue(que), 2);
    assertEquals(2, que->numElements);
    assertEquals(dequeue(que), 3);
    assertEquals(1, que->numElements);
    assertEquals(dequeue(que), 4);
    assertEquals(0, que->numElements);

    // assertFalse(dequeue(que)); // Creates an assertion because we dequeue off end of the list

    que = destroyQueue(que);
    assertFalse((uintptr_t) que);
}