#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "binaryTree.h"
#include "stack.h"

/**
 * @author: Madusha Sandaruwan
 * @date: 2023-01-13
 * @brief: This program converts a given postfix expression to prefix expression.
 * @details: This program builds an expression tree from a given postfix expression.
 * The expression tree is then traversed in preorder and prints the prefix expression.
 */

TreeNode *buildTreeFromString(const char *);

int main()
{
    char simpleExpressionString[15];
    TreeNode *expressionTree;

    printf("----------------------------------------\n");
    printf("|Postfix to Prefix Expression Converter|\n");
    printf("----------------------------------------\n");

    printf("Enter the expression (in postfix): ");

    // only reads the first 14 characters
    scanf("%14s", simpleExpressionString);
    // build the expression tree and store the root in expressionTree
    expressionTree = buildTreeFromString(simpleExpressionString);
    printf("\nThe prefix expression is: ");
    // print the prefix expression by traversing the expression tree in preorder
    preOrder(expressionTree, NodeValueToString);

    // free the memory allocated for the expression tree
    cleartree(expressionTree);
    return 0;
}

/**
 * @brief This function builds an expression tree from a given postfix expression.
 * @details This function builds an expression tree from a given postfix expression.
 * @param simpleExpressionString postfix expression as String
 * @return root of the expression tree as TreeNode*
 */
TreeNode *buildTreeFromString(const char simpleExpressionString[15])
{
    Stack stackHelper;
    stackInit(&stackHelper);
    TreeNode *treeRoot = NULL;

    // build the expression tree by looping through the expression string
    for (int i = 0; simpleExpressionString[i] != '\0'; i++)
    {
        treeRoot = createNode(simpleExpressionString[i]);
        if (isOperator(simpleExpressionString[i]))
        {
            TreeNode *right = NULL;
            TreeNode *left = NULL;
            pop(&stackHelper, &right);
            pop(&stackHelper, &left);
            treeRoot->rightChild = right;
            treeRoot->leftChild = left;
        }
        push(&stackHelper, treeRoot);
    }

    // The last element in the stack is the root of the expression tree
    // Reason for this is in case of a invalid/ incomplete expression String
    // will leave the root of the tree at the end of the stack
    // and all other unprocessed leaf nodes will be on top of the stack
    // we are processing the stack from top to bottom to filter out the invalid nodes
    // and the last valid node will be the root of the expression tree
    while (!isEmpty(&stackHelper))
    {
        pop(&stackHelper, &treeRoot);
    }

    return treeRoot;
}