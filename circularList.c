//  James Sandoval 16July2016
//  CS 261 - Data Structures
//  Assignment 3 - Circular List Deque Implementation
//



#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "circularList.h"

// Double link
struct Link
{
	TYPE value;
	struct Link * next;
	struct Link * prev;
};

struct CircularList
{
	int size;
	struct Link* sentinel;
};

/**
 * Allocates the list's sentinel and sets the size to 0.
 * The sentinel's next and prev should point to the sentinel itself.
 */
static void init(struct CircularList* list)
{
	// FIXED
    
    assert(list != 0);
    
    list->size = 0;
    list->sentinel = (struct Link*)malloc(sizeof(struct Link));
    
    assert(list->sentinel != 0);
    
    list->sentinel->next = list->sentinel;
    list->sentinel->prev = list->sentinel;
    
    // FIXED
    
}

/**
 * Creates a link with the given value and NULL next and prev pointers.
 */
static struct Link* createLink(TYPE value)

{
    
     // FIXED
    
    struct Link* link = (struct Link*)malloc(sizeof(struct Link));
    
    assert(link != 0 );
    
    link->value = value;

    return link;
    
     // FIXED
}

/**
 * Adds a new link with the given value after the given link and
 * increments the list's size.
 */
static void addLinkAfter(struct CircularList* list, struct Link* link, TYPE value)
{
	// FIXED
    
    assert(list != 0);
    assert(link != 0);
    
    assert(link->next != 0 );
    assert(link->prev != 0 );
    
    struct Link* newLink = createLink(value);
    assert(newLink != 0);
    
    
    link->next->prev = newLink;
    newLink->next = link->next;
    
    link->next = newLink;
    newLink->prev = link;

    list->size++;
    
    // FIXED
}

/**
 * Removes the given link from the list and
 * decrements the list's size.
 */
static void removeLink(struct CircularList* list, struct Link* link)
{
	// FIXED
    
    assert(link != 0);
    assert(list->size != 0);
    assert(link != 0);
    
    link->prev->next = link->next;
    link->next->prev = link->prev;
    
    free(link);
    list->size--;
    
    
    // FIXED
}

/**
 * Allocates and initializes a list.
 */
struct CircularList* circularListCreate()
{
	struct CircularList* list = malloc(sizeof(struct CircularList));
	init(list);
	return list;
}

/**
 * Deallocates every link in the list and frees the list pointer.
 */
void circularListDestroy(struct CircularList* list)
{
	// FIXED
    
    while(list->size != 0){
        
        circularListRemoveBack(list);
        
    }
    
    free(list->sentinel);
    
    // FIXED
    
}

/**
 * Adds a new link with the given value to the front of the deque.
 */
void circularListAddFront(struct CircularList* list, TYPE value)
{
	// FIXED
    
    assert(list != 0);
    
    addLinkAfter(list, list->sentinel, value);
    
    // FIXED
}

/**
 * Adds a new link with the given value to the back of the deque.
 */
void circularListAddBack(struct CircularList* list, TYPE value)
{
	// FIXED
    
    assert(list != 0);
    
    addLinkAfter(list, list->sentinel->prev, value);
    
    // FIXED
}

/**
 * Returns the value of the link at the front of the deque.
 */
TYPE circularListFront(struct CircularList* list)
{
	// FIXED
    assert(list != 0);
    
    assert(list->size != 0);
    
    return list->sentinel->next->value;
    
    // FIXED
}

/**
 * Returns the value of the link at the back of the deque.
 */
TYPE circularListBack(struct CircularList* list)
{
	// FIXED
    
    assert(list != 0);
    
    assert(list->size != 0);
    
    return list->sentinel->prev->value;
    
    
    // FIXED
}

/**
 * Removes the link at the front of the deque.
 */
void circularListRemoveFront(struct CircularList* list)
{
	// FIXED
    
    assert(list != 0);
    assert(list->size != 0);
    
    removeLink(list, list->sentinel->next);

    // FIXED
    
}

/**
 * Removes the link at the back of the deque.
 */
void circularListRemoveBack(struct CircularList* list)
{
    // FIXED
    assert(list != 0);
    assert(list->size != 0);
    
    removeLink(list, list->sentinel->prev);

    // FIXED
}

/**
 * Returns 1 if the deque is empty and 0 otherwise.
 */
int circularListIsEmpty(struct CircularList* list)
{
    // FIXED
    
    assert(list != 0);
    
    if(list->size == 0){
        return 1;}
    
    return 0;
    // FIXED
}

/**
 * Prints the values of the links in the deque from front to back.
 */
void circularListPrint(struct CircularList* list)
{
	// FIXED
    
    assert(list != 0);
    assert(list->size != 0);
    
    printf("Here is the Deque Printout:\n");
    
    struct Link* link;
    link = list->sentinel->next;
    
    while (link != list->sentinel) {
        printf("%g\n", link->value);
        link = link->next;
    }
    
    // FIXED
}

/**
 * Reverses the deque.
 */
void circularListReverse(struct CircularList* list)
{
	// FIXED

    assert(list != 0);
    assert(list->size != 0);
    
    struct Link* link;
    struct Link* link2;
    
    link = list->sentinel->next;
    list->sentinel->prev = link;
    
    do{
        
        link2 = link->next;
        if (link2->next == list->sentinel)
            list->sentinel->next=link2;
       
        link->next = link->prev;
        link->prev = link2;
        link = link2;
        
        
    }while (link != list->sentinel);
    
    
    // FIXED
}
