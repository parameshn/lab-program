#include <stdio.h>
#include <stdlib.h>

// Node structure for circular linked list
typedef struct Node {
    int data;
    struct Node* link;
} Node;

// List structure
typedef struct List {
    int count;
    Node* head;
} List;

// Function prototypes
Node* createNode(int value);
Node* insertEnd(List* list, int value);
Node* insertFront(List* list, int value);
Node* insertPosition(List* list, int position, int value);
Node* deleteFront(List* list);
Node* deleteEnd(List* list);
Node* deletePosition(List* list, int position);
Node* deleteByKey(List* list, int key);
Node* searchByKey(List* list, int key);
Node* searchByPosition(List* list, int position);
void reverseList(List* list);
List* copyList(List* list);
void createOrdered(List* list, int value);
void display(List* list);

int main() {
    int choice, value, position, key;
    List* list = (List*)malloc(sizeof(List));
    list->count = 0;
    list->head = NULL;

    List* orderedList = (List*)malloc(sizeof(List));
    orderedList->head = NULL;
    orderedList->count = 0;

    List* copy;

    do {
        printf("\n1. Insert at Front\n2. Insert at End\n3. Insert at Position\n");
        printf("4. Delete Front\n5. Delete End\n6. Delete at Position\n");
        printf("7. Delete by Key\n8. Search by Key\n9. Search by Position\n10. Reverse List\n");
        printf("11. Copy List\n12. Create Ordered List\n13. Display\n14. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d", &value);
                list->head = insertFront(list, value);
                break;
            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                insertEnd(list, value);
                break;
            case 3:
                printf("\nEnter the position to insert: ");
                scanf("%d", &position);
                printf("Enter value to insert at position: ");
                scanf("%d", &value);
                insertPosition(list, position, value);
                break;
            case 4:
                list->head = deleteFront(list);
                break;
            case 5:
                deleteEnd(list);
                break;
            case 6:
                printf("\nEnter the position to delete: ");
                scanf("%d", &position);
                deletePosition(list, position);
                break;
            case 7:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                list->head = deleteByKey(list, key);
                break;
            case 8:
                printf("\nEnter the key to search: ");
                scanf("%d", &key);
                searchByKey(list, key);
                break;
            case 9:
                printf("\nEnter the position to search: ");
                scanf("%d", &position);
                searchByPosition(list, position);
                break;
            case 10:
                reverseList(list);
                break;
            case 11:
                copy = copyList(list);
                printf("\nCopied List: ");
                display(copy);
                break;
            case 12:
                printf("Creating an ordered list...\n");
                while (1) {
                    printf("\nEnter -1 to stop or enter value to continue: ");
                    scanf("%d", &value);
                    if (value == -1)
                        break;
                    createOrdered(orderedList, value);
                }
                break;
            case 13:
                display(list);
                break;
            case 14:
                printf("\nProgram exited\n");
                free(list);
                free(orderedList);
                return 0;
            default:
                printf("\nInvalid Choice\n");
        }
    } while (choice != 14);

    return 0;
}

// Create a new node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    newNode->data = value;
    newNode->link = NULL;
    return newNode;
}

// Insert a new node at the end of the list
Node* insertEnd(List* list, int value) {
    Node* newNode = createNode(value);

    if (list->head == NULL) {
        list->head = newNode;
        newNode->link = newNode; // Point to itself in a circular list
    } else {
        Node* last = list->head;
        while (last->link != list->head) {
            last = last->link;
        }
        last->link = newNode;
        newNode->link = list->head;
    }
    list->count++;
    printf("%d inserted at end\n", value);
    printf("Count: %d\n", list->count);
    return newNode;
}

// Insert a new node at the front of the list
Node* insertFront(List* list, int value) {
    Node* newNode = createNode(value);

    if (list->head == NULL) {
        list->head = newNode;
        newNode->link = newNode; // Point to itself in a circular list
    } else {
        Node* last = list->head;
        while (last->link != list->head) {
            last = last->link;
        }
        newNode->link = list->head;
        list->head = newNode;
        last->link = newNode;
    }
    list->count++;
    printf("%d inserted at front\n", value);
    printf("Count: %d\n", list->count);
    return newNode;
}

// Insert a new node at a specified position
Node* insertPosition(List* list, int position, int value) {
    if (position < 1 || position > list->count + 1) {
        printf("\nInvalid position\n");
        return NULL;
    }

    Node* newNode = createNode(value);
    list->count++;

    if (position == 1) {
        return insertFront(list, value);
    } else if (position == list->count) {
        return insertEnd(list, value);
    } else {
        Node* current = list->head;
        for (int i = 1; i < position - 1; i++) {
            current = current->link;
        }
        newNode->link = current->link;
        current->link = newNode;
    }
    printf("%d inserted at position %d\n", value, position);
    printf("Count: %d\n", list->count);
    return newNode;
}

// Delete the node at the front of the list
Node* deleteFront(List* list) {
    if (list->head == NULL) {
        printf("\nThe list is empty\n");
        return NULL;
    }

    Node* temp = list->head;
    if (list->count == 1) {
        printf("\nDeleted element=%d\n", temp->data);
        free(temp);
        list->head = NULL;
    } else {
        Node* last = list->head;
        while (last->link != list->head)
            last = last->link;

        list->head = list->head->link;
        last->link = list->head;
        printf("\nDeleted element=%d\n", temp->data);
        free(temp);
    }
    list->count--;
    printf("Count: %d\n", list->count);
    return list->head;
}

// Delete the node at the end of the list
Node* deleteEnd(List* list) {
    if (list->head == NULL) {
        printf("\nThe list is empty\n");
        return NULL;
    }

    Node* current = list->head;
    Node* previous = NULL;

    while (current->link != list->head) {
        previous = current;
        current = current->link;
    }

    if (previous != NULL) {
        previous->link = list->head; // Update the second-to-last node to point to the head
    } else {
        list->head = NULL; // If only one node is present
    }

    printf("\nDeleted element=%d\n", current->data);
    free(current);
    list->count--;
    printf("Count: %d\n", list->count);

    return list->head;
}

// Delete the node at a specified position
Node* deletePosition(List* list, int position) {
    if (list->head == NULL || position < 1 || position > list->count) {
        printf("\nInvalid position or empty list\n");
        return NULL;
    }

    if (position == 1) {
        return deleteFront(list);
    }

    Node* current = list->head;
    Node* previous = NULL;

    for (int i = 1; i < position; i++) {
        previous = current;
        current = current->link;
    }
    previous->link = current->link;
    printf("\nDeleted element=%d\n", current->data);
    free(current);
    list->count--;
    printf("Count: %d\n", list->count);

    return list->head;
}

// Delete the node with the specified key (data value)
Node* deleteByKey(List* list, int key) {
    if (list->head == NULL) {
        printf("\nThe list is empty\n");
        return NULL;
    }

    Node* current = list->head;
    Node* previous = NULL;

    do {
        if (current->data == key) {
            // Node with the key found, delete it
            if (previous == NULL) {
                // If the node to be deleted is the head
                if (current->link == list->head) {
                    // If it's the only node in the list
                    free(current);
                    list->head = NULL;
                    list->count = 0;
                    return NULL;
                } else {
                    // Update head and link last node to the new head
                    Node* last = list->head;
                    while (last->link != list->head) {
                        last = last->link;
                    }
                    list->head = current->link;
                    last->link = list->head;
                }
            } else {
                previous->link = current->link;
            }

            free(current);
            list->count--;

            printf("\nNode with key %d deleted\n", key);

            return list->head;
        }

        // Move to the next node
        previous = current;
        current = current->link;

    } while (current != list->head);

    // If the key is not found in the list
    printf("\nNode with key %d not found\n", key);

    return list->head;
}

// Search for the node with the specified key (data value)
Node* searchByKey(List* list, int key) {
    if (list->head == NULL) {
        // The list is empty, so there is nothing to search
        printf("\nThe list is empty\n");
        return NULL;
    }

    Node* current = list->head;

    do {
        if (current->data == key) {
            // Node with the key found, return the pointer to the node
            printf("\nNode with key %d found\n", key);
            return current;
        }

        // Move to the next node
        current = current->link;
    } while (current != list->head);

    // If the key is not found in the list
    printf("\nNode with key %d not found\n", key);
    return NULL;
}

// Search for the node at the specified position
Node* searchByPosition(List* list, int position) {
    if (list->head == NULL) {
        printf("\nThe list is empty\n");
        return NULL;
    }

    if (position < 1 || position > list->count) {
        printf("\nInvalid position\n");
        return NULL;
    }

    Node* current = list->head;
    for (int i = 1; i < position; i++) {
        current = current->link;
    }

    printf("\nData at position %d: %d\n", position, current->data);
    return current;
}

// Reverse the order of nodes in the list
void reverseList(List* list) {
    if (list->head == NULL || list->head->link == list->head) {
        // Empty list or only one node, no change needed
        return;
    }

    Node* prev = NULL;
    Node* current = list->head;
    Node* next = current->link;

    do {
        current->link = prev;
        prev = current;
        current = next;
        next = current->link;
    } while (current != list->head);

    // Update the head to the last node, which becomes the new head after reversal
    list->head->link = prev;
    list->head = prev;
    printf("\nCircular linked list reversed\n");
}

// Create a copy of the list
List* copyList(List* list) {
    if (list->head == NULL) {
        printf("\nThe original list is empty\n");
        return NULL;
    }

    List* newList = (List*)malloc(sizeof(List));
    newList->count = 0;
    newList->head = NULL;

    Node* current = list->head;

    do {
        insertEnd(newList, current->data);
        current = current->link;
    } while (current != list->head);

    return newList;
}

// Create an ordered list by inserting the value at the appropriate position
void createOrdered(List* list, int value) {
    Node* newNode = createNode(value);
    Node* current = list->head;

    if (list->head == NULL || value <= list->head->data) {
        list->head = insertFront(list, value);
    } else {
        Node* prev = NULL;

        do {
            prev = current;
            current = current->link;
        } while (current != list->head && current->data < value);

        newNode->link = current;
        prev->link = newNode;
        list->count++;
    }

    printf("\nOrdered Circular Linked List: \n");
    display(list);
}

// Display the nodes in the list
void display(List* list) {
    if (list->head == NULL) {
        printf("\nThe list is empty\n");
        return;
    }

    Node* current = list->head;

    printf("List elements: ");
    do {
        printf("%d -> ", current->data);
        current = current->link;
    } while (current != list->head);
    printf("\n");
}