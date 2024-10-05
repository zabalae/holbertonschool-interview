#include "lists.h"

/**
 * reverse_list - Reverses a linked list.
 * @head: Pointer to the head of the list to reverse.
 * Return: Pointer to the new head of the reversed list.
 */
listint_t *reverse_list(listint_t *head)
{
    listint_t *prev = NULL, *next = NULL;
    while (head != NULL)
    {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return (prev);
}

/**
 * is_palindrome - Checks if a singly linked list is a palindrome.
 * @head: Double pointer to the head of the list.
 * Return: 1 if it is a palindrome, 0 otherwise.
 */
int is_palindrome(listint_t **head)
{
    if (!head || !*head)
        return (1);

    listint_t *slow = *head, *fast = *head, *first_half = *head, *second_half = NULL;

    /* Find the middle of the list */
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    /* Reverse the second half of the list */
    second_half = reverse_list(slow);

    /* Compare the first and the second half */
    while (second_half)
    {
        if (first_half->n != second_half->n)
            return (0);

        first_half = first_half->next;
        second_half = second_half->next;
    }

    return (1);
}
