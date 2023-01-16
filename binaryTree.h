#ifndef LINKED_TREE_H
#define LINKED_TREE_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * @author: Madusha Sandaruwan
 * @date: 2023-01-13
 * @brief: This header file contains the Binary Tree implementation and the functions.
 */

/**
 * @brief A new type name for tree elements
 */
typedef char treeType;

/**
 * @brief A node in a binary tree
 * Contains a value and pointers to the left and right children
 */
typedef struct tNode
{
    treeType value;
    struct tNode *leftChild;
    struct tNode *rightChild;
} TreeNode;

/**
 * @brief normal member taking value to create a treeNode initializing the value
 * and return the address of the created treeNode memory.
 * @param value value to be initialized as the value of the TreeNode.
 * @return Address of the created treeNode memory.
 */
TreeNode *createNode(treeType value)
{
    TreeNode *newTreeNode = (TreeNode *)malloc(sizeof(TreeNode));
    newTreeNode->value = value;
    newTreeNode->leftChild = NULL;
    newTreeNode->rightChild = NULL;
    return newTreeNode;
}

/**
 * @brief checks if the given character is an operator or not. character is an operator if it is one of the following: +,-,*,/,^
 * @param val value to be checked if it is an operator or not.
 * @return true if the given character is an operator, false otherwise.
 */
bool isOperator(char val)
{
    return (val == '+' || val == '-' || val == '*' || val == '/' || val == '^');
}

/**
 * @brief Prints the value of the given node
 *
 * @param node Pointer to the node to print
 */
void NodeValueToString(const TreeNode *node)
{
    printf("%c", node->value);
}

/**
 * @brief Clears a tree by freeing all nodes
 * @param node Pointer to the root of the tree to clear
 */
void cleartree(TreeNode *node)
{
    if (node)
    {
        cleartree(node->leftChild);
        cleartree(node->rightChild);
        free(node);
    }
}

/**
 * @brief Traverse a tree in postorder and perform an action on each node
 * @param node  Pointer to the root of the tree to traverse
 * @param action Pointer to the function to perform on each node
 */
void postOrder(const TreeNode *node, void (*action)(const TreeNode *))
{
    if (node)
    {
        postOrder(node->leftChild, action);
        postOrder(node->rightChild, action);
        printf("%c", node->value);
    }
}

/**
 * @brief Traverse a tree in inorder and perform an action on each node
 * @param node Pointer to the root of the tree to traverse
 * @param action Pointer to the function to perform on each node
 */
void inOrder(const TreeNode *node, void (*action)(const TreeNode *))
{
    if (node)
    {
        inOrder(node->leftChild, action);
        printf("%c", node->value);
        inOrder(node->rightChild, action);
    }
}

/**
 * @brief Traverse a tree in preorder and perform an action on each node
 * @param node Pointer to the root of the tree to traverse
 * @param action Pointer to the function to perform on each node
 */
void preOrder(const TreeNode *node, void (*action)(const TreeNode *))
{
    if (node)
    {
        printf("%c", node->value);
        preOrder(node->leftChild, action);
        preOrder(node->rightChild, action);
    }
}

#endif