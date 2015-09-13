/*
https://www.hackerrank.com/challenges/print-the-elements-of-a-linked-list-in-reverse

*/

#include <iostream>
using namespace std;

static struct Node
{
    int data;
    struct Node *next;
};

void ReversePrint(Node *head)
{
    // This is a "method-only" submission. 
    // You only need to complete this method. 
    if (head == nullptr)
        return;
    ReversePrint(head->next);
    cout << head->data << std::endl;
}