// Jack Mulvihill

#include "page.h"

struct ppage *free_physical_pages; // make a linked list to track each physical page in memory

const int PAGES = 128; // 128 pages, each 2 mb in length covers 256 megs of memory

struct ppage physical_page_array[PAGES];

void init_pfa_list(void) {
    /* pointer to the head of the new linked list */
    struct ppage *list_head = NULL;
    for (int i = 0; i < PAGES; i++) {
        /* initialize the physical address of the page that i points to */
        physical_page_array[i].physical_addr = (i * PAGES);
        /* append the page to the linked list */
        list_add(&list_head, &physical_page_array[i]);
    } // for loop
} // method physical_page_array

struct ppage *allocate_physical_pages(unsigned int npages) {
    /* pointer to the head of the new linked list */
    struct ppage *list_head = NULL;
    /* pointer to current node in linked list */
    struct ppage *current_page = NULL;
    /* check to see if there are pages to allocate */
    if (npages == 0 || free_physical_pages == NULL) {
        return NULL;
    } // if statement
    while (free_physical_pages != NULL) {
    /* remove page from current list */
    current_page = list_head;
    list_remove(&list_head, current_page);
    /* add removed page to new linked list */
    current_page.next = list_head;
    list_head = current_page;
    } // while loop
    /* return head of new linked list */
    return list_head;
} // method allocate_physical_pages

void free_physical_pages(struct ppage *ppage_list) {
    /* pointer to current page in linked list */
    struct ppage *current_page = ppage_list;
    while (current_page != NULL) {
        /* add current page back to the free list */
        list_add(&free_physical_pages, current_page);
        /* move to next page */
        current_page = current_page.next;
    } // while loop
} // method free_physical_pages
