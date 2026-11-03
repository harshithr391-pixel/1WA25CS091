#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}


void insertAtFirst(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    newNode->next = *head;
    *head = newNode;
    printf("Inserted %d at the first position.\n", value);
}


void insertAtEnd(struct Node** head, int value) {
    struct Node* newNode = createNode(value);


    if (*head == NULL) {
        *head = newNode;
        printf("Inserted %d at the end (List was empty).\n", value);
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    printf("Inserted %d at the end.\n", value);
}

void insertAtPosition(struct Node** head, int value, int position) {
    if (position < 1) {
        printf("Invalid position! Position should be >= 1.\n");
        return;
    }

    if (position == 1) {
        insertAtFirst(head, value);
        return;
    }

    struct Node* newNode = createNode(value);
    struct Node* temp = *head;

    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }


    if (temp == NULL) {
        printf("Position %d out of bounds! Cannot insert.\n", position);
        free(newNode);
        return;
    }


    newNode->next = temp->next;
    temp->next = newNode;
    printf("Inserted %d at position %d.\n", value, position);
}

void displayList(struct Node* head) {
    if (head == NULL) {
        printf("The linked list is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


int main() {
    struct Node* head = NULL;


    displayList(head);
printf("name:HARSHITHA B,USN : 1WA25CS092, DATE:03:11:26");
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    displayList(head);


    insertAtFirst(&head, 5);
    displayList(head);


    insertAtPosition(&head, 15, 3);
    insertAtPosition(&head, 2, 1);
    insertAtPosition(&head, 25, 6);
    insertAtPosition(&head, 100, 9);


    displayList(head);

    return 0;
}
