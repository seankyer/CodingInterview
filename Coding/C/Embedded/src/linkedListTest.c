#include <stdint.h>
#include "test.h"
#include "linkedList.h"

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