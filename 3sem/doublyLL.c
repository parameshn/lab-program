// #include <stdio.h>
// #include <stdlib.h>

// // Node structure for circular doubly linked list
// typedef struct Node {
//     int data;
//     struct Node* prev;
//     struct Node* next;
// } Node;

// // List structure
// typedef struct List {
//     int count;
//     Node* head;
// } List;

// // Function prototypes
// Node* createNode(int value);
// void insertFront(List* list, int value);
// void insertEnd(List* list, int value);
// void insertPosition(List* list, int value, int position);
// void deleteFront(List* list);
// void deleteEnd(List* list);
// void deletePosition(List* list, int position);
// void deleteByKey(List* list, int key);
// void searchByKey(List* list, int key);
// void createOrderedList(List* list, int value);
// void reverse(List* list);
// List* createCopyList(List* list);
// void display(List* list);

// int main() {
//     int choice, value, position, key;
//     List* list = (List*)malloc(sizeof(List));
//     list->count = 0;
//     list->head = NULL;

//     List* orderedList = (List*)malloc(sizeof(List));
//     orderedList->head = NULL;
//     orderedList->count = 0;

//     List* copy;

//     do {
//         printf("\n\n1. Insert at Front\n2. Insert at End\n3. Insert at Position\n");
//         printf("4. Delete Front\n5. Delete End\n6. Delete at Position\n");
//         printf("7. Delete by Key\n8. Search by Key\n9. Create Ordered List\n");
//         printf("10. Reverse the List\n11. Create a Copy\n12. Display\n13. Exit\n");
//         printf("Enter your choice: ");
//         scanf("%d", &choice);

//         switch (choice) {
//             case 1:
//                 printf("Enter the value to insert at front: ");
//                 scanf("%d", &value);
//                 insertFront(list, value);
//                 break;
//             case 2:
//                 printf("Enter the value to insert at end: ");
//                 scanf("%d", &value);
//                 insertEnd(list, value);
//                 break;
//             case 3:
//                 printf("Enter the value and position to be inserted: ");
//                 scanf("%d %d", &value, &position);
//                 insertPosition(list, value, position);
//                 break;
//             case 4:
//                 deleteFront(list);
//                 break;
//             case 5:
//                 deleteEnd(list);
//                 break;
//             case 6:
//                 printf("Enter the position to be deleted: ");
//                 scanf("%d", &position);
//                 deletePosition(list, position);
//                 break;
//             case 7:
//                 printf("Enter the key to be deleted: ");
//                 scanf("%d", &key);
//                 deleteByKey(list, key);
//                 break;
//             case 8:
//                 printf("Enter key to be searched: ");
//                 scanf("%d", &key);
//                 searchByKey(list, key);
//                 break;
//             case 9:
//                 printf("Creating an ordered list\n");
//                 while (1) {
//                     printf("\nEnter -1 to stop or enter value to continue: ");
//                     scanf("%d", &value);
//                     if (value == -1)
//                         break;
//                     createOrderedList(orderedList, value);
//                 }
//                 break;
//             case 10:
//                 reverse(list);
//                 break;
//             case 11:
//                 copy = createCopyList(list);
//                 if (copy != NULL) {
//                     printf("\nList copied successfully\n");
//                     display(copy);
//                 } else {
//                     printf("\nFailed to copy\n");
//                 }
//                 break;
//             case 12:
//                 display(list);
//                 break;
//             case 13:
//                 free(list);
//                 free(orderedList);
//                 printf("Exiting the program\n");
//                 exit(0);
//             default:
//                 printf("Invalid choice\n");
//                 break;
//         }
//     } while (choice != 13);

//     return 0;
// }

// // Create a new node
// Node* createNode(int value) {
//     Node* newNode = (Node*)malloc(sizeof(Node));
//     if (newNode == NULL) {
//         printf("Memory allocation failed\n");
//         return NULL;
//     }
//     newNode->data = value;
//     newNode->prev = NULL;
//     newNode->next = NULL;
//     return newNode;
// }

// // Insert a new node at the front of the list
// void insertFront(List* list, int value) {
//     Node* newNode = createNode(value);
//     if (list->head == NULL) {
//         list->head = newNode;
//         newNode->next = newNode;
//         newNode->prev = newNode;
//     } else {
//         Node* last = list->head->prev;
//         newNode->next = list->head;
//         newNode->prev = last;
//         last->next = newNode;
//         list->head->prev = newNode;
//         list->head = newNode;
//     }
//     list->count++;
//     printf("%d inserted at front\n", value);
//     printf("Count: %d\n", list->count);
// }

// // Insert a new node at the end of the list
// void insertEnd(List* list, int value) {
//     Node* newNode = createNode(value);
//     if (list->head == NULL) {
//         list->head = newNode;
//         newNode->next = newNode;
//         newNode->prev = newNode;
//     } else {
//         Node* last = list->head->prev;
//         last->next = newNode;
//         newNode->prev = last;
//         newNode->next = list->head;
//         list->head->prev = newNode;
//     }
//     list->count++;
//     printf("%d inserted at end\n", value);
//     printf("Count: %d\n", list->count);
// }

// // Insert a new node at a specified position
// void insertPosition(List* list, int value, int position) {
//     if (position < 1 || position > list->count + 1) {
//         printf("Invalid position\n");
//         return;
//     }

//     if (position == 1) {
//         insertFront(list, value);
//         return;
//     }

//     if (position == list->count + 1) {
//         insertEnd(list, value);
//         return;
//     }

//     Node* newNode = createNode(value);
//     Node* current = list->head;
//     for (int i = 1; i < position - 1; i++) {
//         current = current->next;
//     }
//     newNode->next = current->next;
//     newNode->prev = current;
//     current->next->prev = newNode;
//     current->next = newNode;
//     list->count++;
//     printf("%d inserted at position %d\n", value, position);
//     printf("Count: %d\n", list->count);
// }

// // Delete the node at the front of the list
// void deleteFront(List* list) {
//     if (list->head == NULL) {
//         printf("List is empty\n");
//         return;
//     }

//     Node* temp = list->head;
//     if (list->head == list->head->next) {
//         list->head = NULL;
//     } else {
//         list->head = temp->next;
//         temp->prev->next = list->head;
//         list->head->prev = temp->prev;
//     }
//     printf("%d deleted\n", temp->data);
//     free(temp);
//     list->count--;
//     printf("Count: %d\n", list->count);
// }

// // Delete the node at the end of the list
// void deleteEnd(List* list) {
//     if (list->head == NULL) {
//         printf("List is empty\n");
//         return;
//     }

//     Node* temp = list->head->prev;
//     if (list->head == list->head->next) {
//         list->head = NULL;
//     } else {
//         temp->prev->next = list->head;
//         list->head->prev = temp->prev;
//     }
//     printf("%d deleted\n", temp->data);
//     free(temp);
//     list->count--;
//     printf("Count: %d\n", list->count);
// }

// // Delete the node at a specified position
// void deletePosition(List* list, int position) {
//     if (list->head == NULL) {
//         printf("List is empty\n");
//         return;
//     }

//     if (position < 1 || position > list->count) {
//         printf("Invalid position\n");
//         return;
//     }

//     if (position == 1) {
//         deleteFront(list);
//         return;
//     }

//     Node* current = list->head;
//     for (int i = 1; i < position; i++) {
//         current = current->next;
//     }
//     current->prev->next = current->next;
//     current->next->prev = current->prev;
//     printf("%d deleted\n", current->data);
//     free(current);
//     list->count--;
//     printf("Count: %d\n", list->count);
// }

// // Delete the node with the specified key (data value)
// void deleteByKey(List* list, int key) {
//     if (list->head == NULL) {
//         printf("List is empty\n");
//         return;
//     }

//     Node* current = list->head;
//     if (current->data == key) {
//         deleteFront(list);
//         return;
//     }

//     do {
//         current = current->next;
//         if (current->data == key) {
//             current->prev->next = current->next;
//             current->next->prev = current->prev;
//             printf("%d deleted\n", current->data);
//             free(current);
//             list->count--;
//             printf("Count: %d\n", list->count);
//             return;
//         }
//     } while (current != list->head);

//     printf("%d is not found\n", key);
// }

// // Search for the node with the specified key (data value)
// void searchByKey(List* list, int key) {
//     if (list->head == NULL) {
//         printf("List is empty\n");
//         return;
//     }

//     Node* current = list->head;
//     int position = 1;
//     if (current->data == key) {
//         printf("%d found at position %d\n", key, position);
//         return;
//     }

//     do {
//         current = current->next;
//         position++;
//         if (current->data == key) {
//             printf("%d found at position %d\n", key, position);
//             return;
//         }
//     } while (current != list->head);

//     printf("%d is not found\n", key);
// }

// // Create an ordered list by inserting the value at the appropriate position
// void createOrderedList(List* list, int value) {
//     if (list->head == NULL || value <= list->head->data) {
//         insertFront(list, value);
//         return;
//     }

//     Node* newNode = createNode(value);
//     Node* current = list->head;
//     Node* prev = NULL;

//     do {
//         prev = current;
//         current = current->next;
//     } while (current != list->head && current->data < newNode->data);

//     newNode->next = current;
//     prev->next = newNode;
//     newNode->prev = prev;
//     current->prev = newNode;
//     list->count++;

//     printf("Ordered list: ");
//     display(list);
// }

// // Reverse the order of nodes in the list
// void reverse(List* list) {
//     if (list->head == NULL) {
//         printf("Nothing to reverse\n");
//         return;
//     }

//     Node* current = list->head;
//     Node* temp;

//     do {
//         temp = current->prev;
//         current->prev = current->next;
//         current->next = temp;
//         current = current->prev;
//     } while (current != list->head);

//     list->head = current->next;

//     printf("Reversed list: ");
//     display(list);
// }

// // Create a copy of the list
// List* createCopyList(List* list) {
//     if (list->head == NULL) {
//         printf("List is empty\n");
//         return NULL;
//     }

//     List* newList = (List*)malloc(sizeof(List));
//     newList->count = 0;
//     newList->head = NULL;

//     Node* current = list->head;

//     do {
//         insertEnd(newList, current->data);
//         current = current->next;
//     } while (current != list->head);

//     return newList;
// }

// // Display the nodes in the list
// void display(List* list) {
//     if (list->head == NULL) {
//         printf("List is empty\n");
//         return;
//     }

//     Node* current = list->head;

//     do {
//         printf("%d ", current->data);
//         current = current->next;
//     } while (current != list->head);

//     printf("\nCount: %d\n", list->count);
// }

#include <stdio.h>
#include <stdlib.h>

// Node structure for circular doubly linked list
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// List structure
typedef struct List {
    int count;
    Node* head;
} List;

// Function prototypes
Node* createNode(int value);
void insertFront(List* list, int value);
void insertEnd(List* list, int value);
void insertPosition(List* list, int value, int position);
void deleteFront(List* list);
void deleteEnd(List* list);
void deletePosition(List* list, int position);
void deleteByKey(List* list, int key);
void searchByKey(List* list, int key);
void searchByPosition(List* list, int position);
void createOrderedList(List* list, int value);
void reverse(List* list);
List* createCopyList(List* list);
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
        printf("\n\n1. Insert at Front\n2. Insert at End\n3. Insert at Position\n");
        printf("4. Delete Front\n5. Delete End\n6. Delete at Position\n");
        printf("7. Delete by Key\n8. Search by Key\n9. Search by Position\n10. Create Ordered List\n");
        printf("11. Reverse the List\n12. Create a Copy\n13. Display\n14. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert at front: ");
                scanf("%d", &value);
                insertFront(list, value);
                break;
            case 2:
                printf("Enter the value to insert at end: ");
                scanf("%d", &value);
                insertEnd(list, value);
                break;
            case 3:
                printf("Enter the value and position to be inserted: ");
                scanf("%d %d", &value, &position);
                insertPosition(list, value, position);
                break;
            case 4:
                deleteFront(list);
                break;
            case 5:
                deleteEnd(list);
                break;
            case 6:
                printf("Enter the position to be deleted: ");
                scanf("%d", &position);
                deletePosition(list, position);
                break;
            case 7:
                printf("Enter the key to be deleted: ");
                scanf("%d", &key);
                deleteByKey(list, key);
                break;
            case 8:
                printf("Enter key to be searched: ");
                scanf("%d", &key);
                searchByKey(list, key);
                break;
            case 9:
                printf("Enter position to search: ");
                scanf("%d", &position);
                searchByPosition(list, position);
                break;
            case 10:
                printf("Creating an ordered list\n");
                while (1) {
                    printf("\nEnter -1 to stop or enter value to continue: ");
                    scanf("%d", &value);
                    if (value == -1)
                        break;
                    createOrderedList(orderedList, value);
                }
                break;
            case 11:
                reverse(list);
                break;
            case 12:
                copy = createCopyList(list);
                if (copy != NULL) {
                    printf("\nList copied successfully\n");
                    display(copy);
                } else {
                    printf("\nFailed to copy\n");
                }
                break;
            case 13:
                display(list);
                break;
            case 14:
                free(list);
                free(orderedList);
                printf("Exiting the program\n");
                exit(0);
            default:
                printf("Invalid choice\n");
                break;
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
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Insert a new node at the front of the list
void insertFront(List* list, int value) {
    Node* newNode = createNode(value);
    if (list->head == NULL) {
        list->head = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
    } else {
        Node* last = list->head->prev;
        newNode->next = list->head;
        newNode->prev = last;
        last->next = newNode;
        list->head->prev = newNode;
        list->head = newNode;
    }
    list->count++;
    printf("%d inserted at front\n", value);
    printf("Count: %d\n", list->count);
}

// Insert a new node at the end of the list
void insertEnd(List* list, int value) {
    Node* newNode = createNode(value);
    if (list->head == NULL) {
        list->head = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
    } else {
        Node* last = list->head->prev;
        last->next = newNode;
        newNode->prev = last;
        newNode->next = list->head;
        list->head->prev = newNode;
    }
    list->count++;
    printf("%d inserted at end\n", value);
    printf("Count: %d\n", list->count);
}

// Insert a new node at a specified position
void insertPosition(List* list, int value, int position) {
    if (position < 1 || position > list->count + 1) {
        printf("Invalid position\n");
        return;
    }

    if (position == 1) {
        insertFront(list, value);
        return;
    }

    if (position == list->count + 1) {
        insertEnd(list, value);
        return;
    }

    Node* newNode = createNode(value);
    Node* current = list->head;
    for (int i = 1; i < position - 1; i++) {
        current = current->next;
    }
    newNode->next = current->next;
    newNode->prev = current;
    current->next->prev = newNode;
    current->next = newNode;
    list->count++;
    printf("%d inserted at position %d\n", value, position);
    printf("Count: %d\n", list->count);
}

// Delete the node at the front of the list
void deleteFront(List* list) {
    if (list->head == NULL) {
        printf("List is empty\n");
        return;
    }

    Node* temp = list->head;
    if (list->head == list->head->next) {
        list->head = NULL;
    } else {
        list->head = temp->next;
        temp->prev->next = list->head;
        list->head->prev = temp->prev;
    }
    printf("%d deleted\n", temp->data);
    free(temp);
    list->count--;
    printf("Count: %d\n", list->count);
}

// Delete the node at the end of the list
void deleteEnd(List* list) {
    if (list->head == NULL) {
        printf("List is empty\n");
        return;
    }

    Node* temp = list->head->prev;
    if (list->head == list->head->next) {
        list->head = NULL;
    } else {
        temp->prev->next = list->head;
        list->head->prev = temp->prev;
    }
    printf("%d deleted\n", temp->data);
    free(temp);
    list->count--;
    printf("Count: %d\n", list->count);
}

// Delete the node at a specified position
void deletePosition(List* list, int position) {
    if (list->head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (position < 1 || position > list->count) {
        printf("Invalid position\n");
        return;
    }

    if (position == 1) {
        deleteFront(list);
        return;
    }

    Node* current = list->head;
    for (int i = 1; i < position; i++) {
        current = current->next;
    }
    current->prev->next = current->next;
    current->next->prev = current->prev;
    printf("%d deleted\n", current->data);
    free(current);
    list->count--;
    printf("Count: %d\n", list->count);
}

// Delete the node with the specified key (data value)
void deleteByKey(List* list, int key) {
    if (list->head == NULL) {
        printf("List is empty\n");
        return;
    }

    Node* current = list->head;
    if (current->data == key) {
        deleteFront(list);
        return;
    }

    do {
        current = current->next;
        if (current->data == key) {
            current->prev->next = current->next;
            current->next->prev = current->prev;
            printf("%d deleted\n", current->data);
            free(current);
            list->count--;
            printf("Count: %d\n", list->count);
            return;
        }
    } while (current != list->head);

    printf("%d is not found\n", key);
}

// Search for the node with the specified key (data value)
void searchByKey(List* list, int key) {
    if (list->head == NULL) {
        printf("List is empty\n");
        return;
    }

    Node* current = list->head;
    int position = 1;

    // Check if the first node contains the key
    if (current->data == key) {
        printf("%d found at position %d\n", key, position);
        return;
    }

    // Traverse the list to find the node with the key
    do {
        current = current->next;
        position++;

        if (current->data == key) {
            printf("%d found at position %d\n", key, position);
            return;
        }
    } while (current != list->head);

    // If the key is not found, print a message
    printf("%d is not found\n", key);
}

// Search for the node at the specified position
void searchByPosition(List* list, int position) {
    if (list->head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (position < 1 || position > list->count) {
        printf("Invalid position\n");
        return;
    }

    Node* current = list->head;
    for (int i = 1; i < position; i++) {
        current = current->next;
    }

    printf("Data at position %d: %d\n", position, current->data);
}

// Create an ordered list by inserting the value at the appropriate position
void createOrderedList(List* list, int value) {
    if (list->head == NULL || value <= list->head->data) {
        insertFront(list, value);
        return;
    }

    Node* newNode = createNode(value);
    Node* current = list->head;
    Node* prev = NULL;

    do {
        prev = current;
        current = current->next;
    } while (current != list->head && current->data < newNode->data);

    newNode->next = current;
    prev->next = newNode;
    newNode->prev = prev;
    current->prev = newNode;
    list->count++;

    printf("Ordered list: ");
    display(list);
}

// Reverse the order of nodes in the list
void reverse(List* list) {
    if (list->head == NULL) {
        printf("Nothing to reverse\n");
        return;
    }

    Node* current = list->head;
    Node* temp;

    do {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    } while (current != list->head);

    list->head = current->next;

    printf("Reversed list: ");
    display(list);
}

// Create a copy of the list
List* createCopyList(List* list) {
    if (list->head == NULL) {
        printf("List is empty\n");
        return NULL;
    }

    List* newList = (List*)malloc(sizeof(List));
    newList->count = 0;
    newList->head = NULL;

    Node* current = list->head;

    do {
        insertEnd(newList, current->data);
        current = current->next;
    } while (current != list->head);

    return newList;
}

// Display the nodes in the list
void display(List* list) {
    if (list->head == NULL) {
        printf("List is empty\n");
        return;
    }

    Node* current = list->head;

    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != list->head);

    printf("\nCount: %d\n", list->count);
}