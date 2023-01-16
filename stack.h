#ifndef LINKED_STACK_H
#define LINKED_STACK_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "binaryTree.h"

/**
 * @author: Madusha Sandaruwan
 * @date: 2023-01-13
 * @brief: This header file contains the stack implementation and the functions.
 */

/**
 * @brief A new type name for stack elements based on TreeNode*
 */
typedef TreeNode *stacktype;

/**
 * @brief A node in a stack
 * Contains a value and a pointer to the next node *
 */
typedef struct node
{
    stacktype value;
    struct node *next;
} Node;

/**
 * @brief A stack
 * Contains a pointer to the top node and a count of the number of elements in the stack
 */
typedef struct
{
    int count;
    Node *top;
} Stack;

/**
 * @brief Initialize a stack
 * @param stack Pointer to the stack to initialize
 */
void stackInit(Stack *stack)
{
    stack->count = 0;
    stack->top = NULL;
}

/**
 * @brief Check if a stack is empty
 * @param stack Pointer to the stack to check
 * @return true if the stack is empty, false otherwise
 */
bool isEmpty(const Stack *stack)
{
    return (stack->top == NULL);
}

/**
 * @brief Push an element onto a stack
 * @param stack Pointer to the stack to push onto
 * @param data The element to push
 */
void push(Stack *stack, stacktype data)
{
    Node *newStack = (Node *)malloc(sizeof(Node));
    if (newStack)
    {
        newStack->value = data;
        newStack->next = stack->top;
        stack->top = newStack;
        stack->count++;
    }
    else
    {
        printf("Action failed. Memory not allocated.\n");
    }
}

/**
 * @brief Pop an element from a stack
 * @param stack Pointer to the stack to pop from
 * @param saveAt Pointer to a variable to store the popped element
 */
void pop(Stack *stack, stacktype *saveAt)
{
    if (isEmpty(stack))
    {
        printf("Action failed. Stack is empty.\n");
    }
    else
    {
        Node *temp = stack->top;
        stack->top = temp->next;
        *saveAt = temp->value;
        stack->count--;
        free(temp);
    }
}

/**
 * @brief remove all elements from a stack
 * @param stack Pointer to the stack to clear
 */
void clearStack(Stack *stack)
{
    stacktype temp;
    while (!isEmpty(stack))
    {
        pop(stack, &temp);
    }
}
#endif