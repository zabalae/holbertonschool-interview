#include <stdlib.h>
#include "binary_trees.h"

/**
 * find_insertion_point - Finds the insertion point for a new node
 * @root: Pointer to the root of the heap
 *
 * Return: Pointer to the parent node where the new node should be inserted
 */
heap_t *find_insertion_point(heap_t *root)
{
heap_t *current;
heap_t *queue[1024]; /* Using an array as a queue for BFS */
int front = 0, rear = 0;

/* Initialize the queue */
queue[rear++] = root;

while (front < rear)
{
current = queue[front++];

/* Check if there's an empty spot on the left or right */
if (!current->left || !current->right)
return current;

/* Add the children to the queue */
queue[rear++] = current->left;
queue[rear++] = current->right;
}
return NULL;
}

/**
 * heapify_up - Restores the Max Heap property by bubbling up the node
 * @node: Pointer to the node to bubble up
 *
 * Return: Pointer to the node after heapifying
 */
heap_t *heapify_up(heap_t *node)
{
int temp;

while (node->parent && node->n > node->parent->n)
{
/* Swap values with the parent */
temp = node->n;
node->n = node->parent->n;
node->parent->n = temp;

/* Move up to the parent */
node = node->parent;
}
return node;
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to the root node of the Heap
 * @value: Value to store in the node to be inserted
 *
 * Return: Pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
heap_t *new_node;
heap_t *parent;

/* Create the new node */
if (!root)
return NULL;

if (*root == NULL)
{
/* If the heap is empty, the new node becomes the root */
*root = binary_tree_node(NULL, value);
return *root;
}

/* Find the insertion point */
parent = find_insertion_point(*root);

/* Insert the new node as a left or right child */
if (!parent->left)
parent->left = binary_tree_node(parent, value);
else
parent->right = binary_tree_node(parent, value);

new_node = parent->left ? parent->left : parent->right;

/* Restore the Max Heap property */
return heapify_up(new_node);
}
