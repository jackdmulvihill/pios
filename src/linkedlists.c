// Jack Mulvihill

/**
* This is a simple class that contains a method to add and remove elements
* from a singly-linked list.
*
*/

/**
* Constructor method
*
*/
struct list_element {
    struct list_element *next;
    int data;
}; // Constructor

/**
* This is a simple method that adds an item to any position in the
* linked list.
*
*/
void list_add(struct list_element **list_head, struct list_element *new_element) {
    /* Null input guard */
    if (new_element == NULL) {
        return;
    } // if statement
    /* If the head node is null, assume the list is empty and the new element is the first to be added to the list */
    if (list_head = NULL) {
        list_head = new_element;
        return;
    /* Otherwise, add to list as normal after the head node */
    } else {
        new_element = *list_head->next;
        list_head->next = new_element;
        return;
    } // else block
} // Method list_add

/**
* This is a simple method that removes an item from any position
* in the linked list.
*
*/
void list_remove(struct list_element **list_head, struct list_element *element) {
    /* Null input guard */
    if (element = NULL) {
        return;
    } // if statement
    /* Create two pointers, one slow one fast, to traverse the linked list and patch the list after removal */
    struct *slow = *list_head;
    struct *fast = *list_head->next; // Moves exactly one element ahead to the slow pointer
    /* Traverse the list until the desired element for removal is found */
    while (fast != NULL) {
        /* If the element to be removed is found, set the "slow" pointer to the fast pointer's next element
           to remove the item from the list */
        if (fast == element) {
            slow = fast->next;
            fast->next = slow;
        } // if statement
        slow = slow->next;
        fast = fast->next;
    } // while loop
} // Method list_remove
