//  James Sandoval 16July2016
//  CS 261 - Data Structures
//  Assignment 3 - Linked List Deque and Bag Implementation
//

#include "linkedList.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

// Double link
struct Link
{
	TYPE value;
	struct Link* next;
	struct Link* prev;
};

// Double linked list with front and back sentinels
struct LinkedList
{
	int size;
	struct Link* frontSentinel;
	struct Link* backSentinel;
};

/**
 * Allocates the list's sentinel and sets the size to 0.
 * The sentinels' next and prev should point to eachother or NULL
 * as appropriate.
 */
static void init(struct LinkedList* list) {
	// FIXED
    
    assert(list != NULL);
    list->size = 0;
    
    list->frontSentinel = (struct Link*)malloc(sizeof(struct Link));
    
    list->backSentinel = (struct Link*)malloc(sizeof(struct Link));
    
    assert(list->backSentinel != 0);
    assert(list->frontSentinel != 0);
    
    list->frontSentinel->next = list->backSentinel;
    list->backSentinel->prev = list->frontSentinel;
    
    
    // FIXED
}

/**
 * Adds a new link with the given value before the given link and
 * increments the list's size.
 */
static void addLinkBefore(struct LinkedList* list, struct Link* link, TYPE value)
{
	// FIXED
    
    assert(list != 0);
    assert(link != 0);
    
    struct Link* newLink;
    newLink = (struct Link*)malloc(sizeof(struct Link));
    
    assert(newLink != 0);
    newLink->value = value;
    newLink->next = link;
    newLink->prev = link->prev;
    
    link->prev->next = newLink;
    link->prev = newLink;
    list->size++;
    
    // FIXED
}

/**
 * Removes the given link from the list and
 * decrements the list's size.
 */
static void removeLink(struct LinkedList* list, struct Link* link)
{
	// FIXED
    
    assert(list != 0);
    assert(link != 0);
    

    
    link->prev->next = link->next;
    link->next->prev = link->prev;
    
    list -> size--;
    free(link);
    
    // FIXED
}

/**
 * Allocates and initializes a list.
 */
struct LinkedList* linkedListCreate()
{
	struct LinkedList* newDeque = malloc(sizeof(struct LinkedList));
	init(newDeque);
	return newDeque;
}

/**
 * Deallocates every link in the list including the sentinels,
 * and frees the list itself.
 */
void linkedListDestroy(struct LinkedList* list)
{
    
	free(list->frontSentinel);
	free(list->backSentinel);
	free(list);
}

/**
 * Adds a new link with the given value to the front of the deque.
 */
void linkedListAddFront(struct LinkedList* list, TYPE value)
{
	// FIXED
    
    assert(list != 0);
    addLinkBefore(list, list->frontSentinel->next, value);
    
    // FIXED
    
}

/**
 * Adds a new link with the given value to the back of the deque.
 */
void linkedListAddBack(struct LinkedList* list, TYPE value)
{
	// FIXED
    
    assert(list != 0);
    addLinkBefore(list, list->backSentinel, value);
    
    // FIXED
}

/**
 * Returns the value of the link at the front of the deque.
 */
TYPE linkedListFront(struct LinkedList* list)
{
    // FIXED
    
    assert(list != 0);
    assert(list->size != 0);
    
    return (list->frontSentinel->next->value);
    
    // FIXED
}

/**
 * Returns the value of the link at the back of the deque.
 */
TYPE linkedListBack(struct LinkedList* list)
{
    // FIXED
    assert(list != 0);
    assert(list->size != 0);
    
    return (list->frontSentinel->prev->value);
    // FIXED
}

/**
 * Removes the link at the front of the deque.
 */
void linkedListRemoveFront(struct LinkedList* list)
{
    // FIXED
    
    assert(list != 0);
    
    assert(list->size != 0);
    
    removeLink(list, list->frontSentinel->next);
    
    //FIXED
}

/**
 * Removes the link at the back of the deque.
 */
void linkedListRemoveBack(struct LinkedList* list)
{
	// FIXED
    
    assert(list != 0);
    
    assert(list->size != 0);
    
    removeLink(list, list->backSentinel->prev);
    
    
    // FIXED
}

/**
 * Returns 1 if the deque is empty and 0 otherwise.
 */
int linkedListIsEmpty(struct LinkedList* list)
{
	// FIXED
    
    assert(list != 0);
    
    if (list->size == 0) {
        return 1;
    }
    
    return 0;
    
    
    // FIXED
}

/**
 * Prints the values of the links in the deque from front to back.
 */
void linkedListPrint(struct LinkedList* list)
{
	// FIXED
    
    assert(list != 0);
    
    struct Link* link;
    link = (struct Link*)malloc(sizeof(struct Link));
    
    link = list->frontSentinel;
    
    while(link->next != list -> backSentinel)
    {
        link = link->next;
        printf("%d\n", link->value);
    }
    
    free(link);
    
    // FIXED
}

/**
 * Adds a link with the given value to the bag.
 */
void linkedListAdd(struct LinkedList* list, TYPE value)
{
	// FIXED
    
    assert(list != 0);
    
    addLinkBefore(list, list->frontSentinel->next, value);
    
    // FIXED
}

/**
 * Returns 1 if a link with the value is in the bag and 0 otherwise.
 */
int linkedListContains(struct LinkedList* list, TYPE value)
{
	// FIXED
    
    assert(list != 0);
    
    assert(list->size != 0);
    
    struct Link* link;
    link = (struct Link*)malloc(sizeof(struct Link));
    
    link = list->frontSentinel;
    
    while(link->next != list->backSentinel)
    {
        link = link->next;
        
        if(link->value == value)
        {
            free(link);
            return 1;
        }
    }
    
    free(link);
    
    return 0;
    
    
    // FIXED
}

/**
 * Removes the first occurrence of a link with the given value.
 */
void linkedListRemove(struct LinkedList* list, TYPE value)
{
    // FIXED
    
    assert(list != 0);
    
    assert(list->size != 0);
    
    struct Link* link;
    link = (struct Link*)malloc(sizeof(struct Link));
    
    link = list->frontSentinel;
    
    while(link->next != list->backSentinel)
    {
        link = link->next;
        
        if(link ->value == value)
        {
            removeLink(list, link);
            free(link);
        }
    }
    
    free(link);
    
    // FIXED
}
