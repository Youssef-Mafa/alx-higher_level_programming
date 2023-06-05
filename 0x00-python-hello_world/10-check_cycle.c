#include "lists.h"
#include <stdlib.h>

/**
 * _realloc - Reallocates a memory block
 * @ptr: The pointer to the previous memory block
 * @old_size: The size of the old memory block
 * @new_size: The size of the new memory block
 *
 * Returns: The pointer to the new memory block, or NULL if unsuccessful
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size) {
    void *new_ptr;
    unsigned int min_size = old_size < new_size ? old_size : new_size;
    unsigned int i;

    if (new_size == old_size)
        return ptr;

    if (ptr != NULL) {
        if (new_size == 0) {
            free(ptr);
            return NULL;
        }

        new_ptr = malloc(new_size);
        if (new_ptr != NULL) {
            for (i = 0; i < min_size; i++)
                *((char *)new_ptr + i) = *((char *)ptr + i);
            free(ptr);
            return new_ptr;
        }

        free(ptr);
        return NULL;
    } else {
        new_ptr = malloc(new_size);
        return new_ptr;
    }
}

/**
 * check_cycle - Checks if a singly linked list has a cycle in it
 * @list: List head
 *
 * Returns: 0 if no cycle, 1 if there is a cycle
 */
int check_cycle(listint_t *list) {
    listint_t *fast, *slow = list;

    if (list == NULL)
        return 0;

    fast = list->next;
    while (slow != NULL && fast != NULL && fast->next != NULL) {
        if (slow == fast)
            return 1;
        fast = fast->next->next;
        slow = slow->next;
    }

    return 0;
}
