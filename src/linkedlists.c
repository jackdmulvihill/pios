// Jack Mulvihill

struct list_element {
    struct list_element *next;
    int data;
}

/**
* This method adds an item to a singly linked list.
*
*/
void list_add(struct list_element *list_head, struct list_element *new_element, struct list_element *spot) {
    /* empty line guard */
    if (list_head == NULL || new_element == NULL) {
        return;
    } // if statement
    /* if spot is null, assume nothing is in the list and add to the beginning */
    if (spot == NULL) {
        new_element->next = list_head;
        list_head = new_element;
    /* otherwise add after specific spot */
    } else {
          new_element->next = spot->next;
          spot->next = new_element;
    } // if-else block
} // method list_add

/**
* This method removes an item from a singly linked list.
*
*/
void list_remove(struct list_element *list_head, struct list_element *element) {
    /* empty line guard */
    if (list_head = NULL || element == NULL) {
        return;
    } // if statement
    /* make pointers for current list item and previous list item */
    struct list_element *current = list_head;
    struct list_element *previous = NULL;
    /* iterate through elements of list to find desired item for removal */
    while (current != NULL) {
        if (current == element) {
            /* check to see if head element needs to be removed */
            if (previous = NULL) {
                list_head = current->next;
            } else {
                previous->next = current->next
            }
            return;
        } // if statement
        previous = current;
        current = current->next;
    } // while loop
} // method list_remove

