#include <stdio.h>
#include "list-2.h"
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

/*
 * Custom testing framework
 */

void dumpList(struct ListNode *head);


/*
 * Main()
 */
int main(int argc, char** argv)
{
     struct ListNode *head = NULL;  // start with empty list
     head = CreateNode (100);  // list = 100
     InsertAtHead (&head, 50);  // list = 50, 100
     InsertAtOrder (&head, 25, 1); // list = 25, 50, 100
     InsertAtOrder (&head, 75, 3); // list = 25, 50, 75, 100
     InsertAtOrder (&head, 125, 5); // list = 25, 50, 75, 100, 125
     dumpList(head);
     printf("Node Count = %5d\n", CountNodes(head));
     printf("Third element = %5d\n", FindNodeValue(head, 3));
     printf("100 is element number %5d\n", FindNodeOrder(head, 100));
     printf("Max Value is = %5d\n", FindMaxNode(head)->item);
     struct ListNode *element = FindNode(head, 100);
    printf ("DEBUG: DONE FindNode");
     DeleteNode (&head, element); // list = 25, 50, 75, 125
    printf("DEBUG:DONE Deleting");
     dumpList(head);

     // free list
     struct ListNode *ptr = head;
	while (ptr) {
		head = ptr->next;
		free (ptr);
		ptr = head;
     }
     return 0;
}

/*
 * Helper Functions
 */
void dumpList(struct ListNode *head)
{
	struct ListNode *current = head;
	while (current != NULL) {
		printf("%5d", current->item);
		current = current->next;
	}
	printf("\n");
}


