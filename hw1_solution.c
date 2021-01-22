/*
 * This section is dedicated to answering Question 1. The rest of the document includes the linked list code
 * QUESTION 1 ANSWERS
 * A. Tim
 * B. 6 semesters
 * C. I am taking CMPT 276, 354, and 361 besides this course
 * D. Masters
 * E. P(x) = ((lambda^x)*(e^-lambda))/(x!)
      lambda = 1.5*1 = 1.5, x = 4
      P(4) = ((1.5^4)*(e^-1.5))/(4!)
           = (5.0625*0.22313)/(24)
           ~= 0.0471
 * F. P(x>x) = e^(-lambda*x)
      lambda = 1/3.8 x = 6
      P(x>10) = e^(-(1/3.8)*6)
              = e^(-1.579)
              ~= 0.2062
 * END OF QUESTION 1 ANSWERS
*/
/* In the following code, you need to fill in body 
 * of each function
*/
#include "list-2.h"
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

/*
 * Allocate memory for a node of type struct ListNode and
 * initialize it with the item value.
 * Return a pointer to the new node.
 */
struct ListNode* CreateNode(int item) {
    struct ListNode* newNode = (struct ListNode*) malloc(sizeof(struct ListNode));
    newNode->item = item;
    newNode->next = NULL;
    return newNode;
}

/*
 * Insert node with specified item at the head of the list.
 */
void InsertAtHead (struct ListNode **head, int item) {
    struct ListNode* newNode = (struct ListNode*) malloc(sizeof(struct ListNode));
    newNode->item = item;
    newNode->next = *head;
    return;
}

/*
 * Create node and insert in the location specified by order
 * If order is larger than number of list element, insert at tail
 * For example, in the list 1, 5, 8, 3, 5
 * InsertAtOrder(head, 100, 3) changes list to 1, 5, 100, 8, 3, 5
 * InsertAtOrder(head, 200, 1) changes list to 200, 1, 5, 8, 3, 5
 * InsertAtOrder(head, 300, 9) changes list to 1, 5, 8, 3, 5, 300
 */
void InsertAtOrder (struct ListNode **head, int item, int order) {
    struct ListNode * newNode = CreateNode(item);
    struct ListNode * currentNode = *head;
    for(int i = 1; i <= order; i++){
        if(currentNode->next != NULL){
            currentNode = currentNode->next;
        } else{
            break;
        }
    }
    struct ListNode*tempPointer = currentNode->next;
    currentNode->next = newNode;
    newNode->next = tempPointer;
    return;
}

/*
 * Count number of nodes in the list.
 * Return 0 if the list is empty, i.e., head == NULL
 */
int CountNodes (struct ListNode *head) {
    if(head == NULL){
        return 0;
    }
    struct ListNode * currentNode = head;
    int i = 1;
    for(i = 1; i <= 2147483647; i++){
        if(currentNode->next != NULL){
            currentNode = currentNode->next;
        } else{
            break;
        }
    }
    return i;
}

/*
 * Return the first node holding the value item
 * return NULL if none found
 */
struct ListNode* FindNode(struct ListNode *head, int item) {
    printf("DEBUG:STARTING");
    if(CountNodes(head) == 0){
        return NULL;
    }
    struct ListNode * currentNode = head;
    while(currentNode != NULL){
        if(currentNode->item == item){
            printf("DEBUG: FOUND NODE");
            return currentNode;
        }else if(currentNode->next == NULL){
            printf("DEBUG: DID NOT FIND NODE, BREAKING");
            break;
        }else{
            printf("DEBUG: NOT FOUND NODE, LOOPING");
            currentNode = currentNode->next;
        }
    }
    return NULL;
}

/*
 * Return the value of the item at node number node_number
 * return -32768 if none found
 * For example, in the list 1, 5, 8, 3, 5
 * FindNodeValue(head, 3) returns 8
 */
int FindNodeValue(struct ListNode *head, int node_number) {
    struct ListNode currentNode = *head;
    int rv = -32768;
    for (int i = 1; i <= node_number; i++){
        rv = currentNode.item;
        if(currentNode.next == NULL && i == node_number){
            return -32768;
        }
        currentNode = *currentNode.next;
    }
    return rv;
}

/*
 * Return the order of first node holding the value item
 * return 0 if none found
 * For example, the list 1, 5, 8, 3, 5  
 * FindNodeOrder (head, 5) returns 2
 * FindNodeOrder (head, 3) returns 4
 * FindNodeOrder (head, 7) returns 0
 */
int FindNodeOrder(struct ListNode *head, int item) {
    struct ListNode currentNode = *head;
    int counter = 1;
    do{
        if(currentNode.item == item){
            return counter;
        }else{
            currentNode = *currentNode.next;
        }
        counter ++;
    }while(currentNode.next != NULL);
    return 0;
}

/*
 * Delete node from the list and free memory allocated to it.
 * This function assumes that node is valid
 */
void DeleteNode (struct ListNode **head, struct ListNode *node) {
    struct ListNode * currentNode = *head;
    while(currentNode != NULL){
        if(currentNode->next == node){
            currentNode->next = node->next;
            free(node);
            return;
        }
    }
}

/*
 * Return the first node containing the item with maximum value.
 * Return NULL if list is empty
 */
struct ListNode* FindMaxNode (struct ListNode *head) {
    if(head == NULL){
        return NULL;
    } else if (head->next == NULL){
        return head;
    }
    struct ListNode * currentNode = head;
    struct ListNode * ret = NULL;
    int compare = -2147483647;
    while(currentNode != NULL){
        if (currentNode->item >= compare){
            ret = currentNode;
            compare = currentNode->item;
        }
        currentNode = currentNode->next;
    }
    return ret;
}


