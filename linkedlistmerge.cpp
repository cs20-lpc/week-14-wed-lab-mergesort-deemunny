#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;

    Node(int val = 0, Node* n = nullptr) : data(val), next(n) {}
};

void insertEnd(Node*& head, int value)
{
    Node* newNode = new Node(value);
    
    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

void display(Node* head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* sortedMerge(Node* leftHead, Node* rightHead)
{
    // TODO:
    // Merge two sorted linked lists
    cout << "merge :";
    display(leftHead);
    cout << "merge :";
    display(rightHead);
    cout << endl;
    if (!leftHead) return rightHead;
    if (!rightHead) return leftHead;

    if (leftHead->data <= rightHead->data) {
        leftHead->next = sortedMerge(leftHead->next,rightHead);
        return leftHead;
    } else {
        rightHead->next = sortedMerge(leftHead,rightHead->next);
        return rightHead;
    }
}

void splitList(Node* source, Node*& front, Node*& back)
{
    // TODO:
    // Use slow/fast pointer method

    // check 1 or null lists first
    if (!source || !source->next) {
        front = source;
        back = nullptr;
        return;
    }

    Node* fast = source;
    Node* slow = source; 
    Node* prev;
    while (fast && fast->next) {
        // fast = fast->next;
        // if (fast->next) {
        //     fast = fast->next;
        // }
        fast = fast->next->next;
        prev = slow;
        slow = slow->next; // slow will point to start of new right side list when loop finishes
    }
    // Split list into two halves
    front = source;
    back = slow;
    // Node* temp(source);
    // while (temp->next != back) temp = temp->next;   // temp should be one before the RHS list after the loop
    // temp->next = nullptr;
    if (prev) prev->next = nullptr;
}

void mergeSort(Node*& head)
{
    if (head == NULL || head->next == NULL)
        return;

    Node* leftHead;
    Node* rightHead;

    // TODO:
    // Split list
    splitList(head,leftHead,rightHead);
    // Recursively sort both halves
    cout << "mergesort: ";
    display(leftHead);
    cout << "mergesort: ";
    display(rightHead);
    cout << endl;
    mergeSort(leftHead);
    mergeSort(rightHead);
    // Merge sorted lists
    head = sortedMerge(leftHead,rightHead);
}

int main()
{
    Node* head = NULL;

    int values[10] = {38, 27, 43, 3, 9, 82, 10, 5, 61, 14};

    for (int i = 0; i < 10; i++)
        insertEnd(head, values[i]);

    cout << "Before Sorting: ";
    display(head);

    mergeSort(head);

    cout << "After Sorting: ";
    display(head);

    return 0;
}
