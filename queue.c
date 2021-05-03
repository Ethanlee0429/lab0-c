#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "harness.h"
#include "queue.h"

/*
 * Create empty queue.
 * Return NULL if could not allocate space.
 */
queue_t *q_new()
{
    queue_t *q = malloc(sizeof(queue_t));
    /* TODO: What if malloc returned NULL? */
    if (q != NULL) {
        q->head = NULL;
        q->end = NULL;
        q->size = 0;
        return q;
    } else {
        return NULL;
    }
}

/* Free all storage used by queue */
void q_free(queue_t *q)
{
    /* TODO: How about freeing the list elements and the strings? */
    /* Free queue structure */

    list_ele_t *current = q->head, *next;
    while (current != NULL) {
        next = current->next;
        free(current->value);
        free(current);
        current = next;
    }
    free(q);
}

/*
 * Attempt to insert element at head of queue.
 * Return true if successful.
 * Return false if q is NULL or could not allocate space.
 * Argument s points to the string to be stored.
 * The function must explicitly allocate space and copy the string into it.
 */
bool q_insert_head(queue_t *q, char *s)
{
    list_ele_t *newh;

    if (!q)
        return false;

    newh = malloc(sizeof(list_ele_t));
    if (!newh) {
        return false;
    } else {
        newh->next = q->head;
        if (!q->head) {
            q->head = q->end = newh;
        } else {
            q->head = newh;
        }
        char *temp = malloc(strlen(s) + 1);
        if (!temp) {
            free(newh);
            return false;
        }
        memset(temp, 0, strlen(s) + 1);
        memcpy(temp, s, strlen(s));
        newh->value = temp;
        q->size++;
        return true;
    }
}

/*
 * Attempt to insert element at tail of queue.
 * Return true if successful.
 * Return false if q is NULL or could not allocate space.
 * Argument s points to the string to be stored.
 * The function must explicitly allocate space and copy the string into it.
 */
bool q_insert_tail(queue_t *q, char *s)
{
    list_ele_t *newh;

    if (!q)
        return false;

    newh = malloc(sizeof(list_ele_t));
    if (!newh) {
        return false;
    } else {
        if (!q->end) {
            newh->next = NULL;
            q->end = q->head = newh;
        } else {
            newh->next = NULL;
            q->end->next = newh;
            q->end = newh;
        }
        char *temp = malloc(strlen(s) + 1);
        if (!temp) {
            free(newh);
            return false;
        }

        memset(temp, 0, strlen(s) + 1);
        memcpy(temp, s, strlen(s));
        newh->value = temp;
        q->size++;
        return true;
    }
}

/*
 * Attempt to remove element from head of queue.
 * Return true if successful.
 * Return false if queue is NULL or empty.
 * If sp is non-NULL and an element is removed, copy the removed string to *sp
 * (up to a maximum of bufsize-1 characters, plus a null terminator.)
 * The space used by the list element and the string should be freed.
 */
bool q_remove_head(queue_t *q, char *sp, size_t bufsize)
{
    list_ele_t *removeh;

    if (!q || !q->head)
        return false;
    removeh = q->head;
    if (removeh != q->end) {
        q->head = q->head->next;
    } else {
        q->head = q->end = NULL;
    }
    if (sp)
        memcpy(sp, removeh->value, strlen(removeh->value) + 1);
    free(removeh->value);
    free(removeh);
    return true;
}

/*
 * Return number of elements in queue.
 * Return 0 if q is NULL or empty
 */
int q_size(queue_t *q)
{
    /* TODO: You need to write the code for this function */
    /* Remember: It should operate in O(1) time */
    /* TODO: Remove the above comment when you are about to implement. */
    return q == NULL ? 0 : q->size;
}

/*
 * Reverse elements in queue
 * No effect if q is NULL or empty
 * This function should not allocate or free any list elements
 * (e.g., by calling q_insert_head, q_insert_tail, or q_remove_head).
 * It should rearrange the existing ones.
 */
void q_reverse(queue_t *q)
{
    if (!q) {
        return;
    }
    list_ele_t *tmp = q->head, *current = q->head, *previous = NULL,
               *next = q->head;

    while (next != NULL) {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    q->head = q->end;
    q->end = tmp;
}

/*
 * Sort elements of queue in ascending order
 * No effect if q is NULL or empty. In addition, if q has only one
 * element, do nothing.
 */
void q_sort(queue_t *q)
{
    /* TODO: You need to write the code for this function */
    /* TODO: Remove the above comment when you are about to implement. */
}
