#include<stdio.h>
/*
50->20->15->4->10
         ^
         |______|
*/

/* Link list node */
struct Node {
    int data;
    struct Node* next;
};

/* This function detects loop in the list
  If loop was there in the list then it returns 1,
  otherwise returns 0 */
int detectLoop(struct Node* list){
    if (!list || !list->next)    {
        return 0;
    }
    
    struct Node *fast = list->next;
    struct Node *slow = list;
    
    while (fast && fast->next)    {
        if (fast == slow)   {
            return 1;
        }
        
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return 0;
    
}
 
 
/* Function to print linked list */
void printList(struct Node* node)
{
    // Print the list after loop removal
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}
 
struct Node* newNode(int key)
{
    struct Node* temp = new Node();
    temp->data = key;
    temp->next = NULL;
    return temp;
}
 
// Driver Code
int main()
{
    struct Node* head = newNode(50);
    head->next = newNode(20);
    head->next->next = newNode(15);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(10);
 
    /* Create a loop for testing */
    head->next->next->next->next->next = head->next->next;
 
    if (detectLoop(head))   {
        printf ("Loop exists\n");
    }
    else    {
        printf ("No Loop\n");
    }
 
    // printf("Linked List after removing loop \n");
    // printList(head);
    return 0;
}
