#include <iostream>
using namespace std;

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

void printList(node *n)
{
    while (n != NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

void createList(node **head, node **tail)
{
    node *first = new node();
    node *mid = new node();
    node *last = new node();
 
    first->data = 12;
    first->prev = last;
    first->next = mid;
    mid->data = 20;
    mid->prev = first;
    mid->next = last;
    last->data = 35;
    last->prev = mid;
    last->next = first;

    (*head) = first;
    (*tail) = last;
    printList(first);
}

void insertFirst(node **head, node **tail, int temp)
{
    node *newNode = new node();
    node *first = *head;
    node *last = *tail;
    newNode->data = temp;
    newNode->next = (*head);
    newNode->prev = (*tail);
    last->next = newNode;
    first->prev = newNode;
    (*head) = newNode;
}

void insertAfter(node *prevNode, int temp)
{
    node *newNode = new node();
    newNode->data = temp;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
    newNode->prev = prevNode;
    newNode->next->prev = newNode;
}

void insertLast(node **head, node **tail, int temp)
{
    node *newNode = new node();
    node *first = *head;
    node *last = *tail;
    newNode->data = temp;
    newNode->next = (*head);
    newNode->prev = (*tail);
    last->next = newNode;
    first->prev = newNode;
    (*tail) = newNode;
}

void insertBefore(node **head, node *nextNode, int temp)
{
    node *current = *head;
    while (current->data != nextNode->data)
        current = current->next;
    node *newNode = new node();
    newNode->data = temp;
    newNode->next = nextNode;
    newNode->prev = nextNode->prev;
    nextNode->prev->next = newNode;
    nextNode->prev = newNode;
}

void deleteFirst(node **head)
{
    node *temp = *head;
    (*head) = temp->next;
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    temp->next = NULL;
    temp->prev = NULL;
}

void deleteLast(node **tail)
{
    node *temp = *tail;
    (*tail) = temp->prev;
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    temp->next = NULL;
    temp->prev = NULL;
}

void deleteAfter(node *prevNode)
{
    node *temp = prevNode->next;
    prevNode->next = prevNode->next->next;
    prevNode->next->prev = prevNode;
    temp->next = NULL;
    temp->prev = NULL;
}

void deleteBefore(node *nextNode)
{
    node *temp = nextNode->prev;
    nextNode->prev = nextNode->prev->prev;
    nextNode->prev->next = nextNode;
    temp->next = NULL;
    temp->prev = NULL;
}

void searchNode(node **head, int id)
{
    int currentID = 1;
    node *temp = *head;
    while (temp->next != 0 && currentID != id)
    {
        temp = temp->next;
        currentID++;
    }
    cout << temp->data << " is Found at " << currentID;
}

int main()
{
    node *head = NULL, *tail = NULL;
    createList(&head, &tail);
    cout << "Insertion : ";
    insertFirst(&head, &tail, 10);
    insertAfter(head->next->next, 25);
    insertBefore(&head, head->next->next, 18);
    insertLast(&head, &tail, 40);
    printList(head);
    cout << "Deletion  : ";
    deleteFirst(&head);
    deleteLast(&tail);
    deleteAfter(head->next);
    printList(head);
    searchNode(&head, 3);
}
