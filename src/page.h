// Jack Mulvihill

#ifndef __PAGE_H__
#define __PAGE_H__

// structure for physical pages
struct ppage {
    struct ppage *next; // pointer to next page in list
    struct ppage *prev; // pointer to previous page in list
    void *physical_addr; // page physcial address
};

void init_pfa_list(void); // initializes list of free physical page structures
struct ppage *allocate_physical_pages(unsigned int npages); // allocate free physical pages
void free_physical_pages(struct ppage *ppage_list); // allocate free physical pages

#endif
