/****************************************************************************
 *
 * Howemork.06: Implement a three functions for printing tree ancestors.
 *
 * File Name:  ancestors.cpp
 * Name:       Nicholas Morin
 * Course:     CPTR 242
 * Date:       6/1/18
 * Time Taken: Four Score and Seven Years 
 *
 */
#include "TreeType.h"
#include <iostream>

void TreeType::AncestorsIterative(ItemType value, std::ofstream& outFile) {
    TreeNode* tree = root; // create new pointer to reference tree
    // will loop until value equals tree or reaches end of tree
    while(value != tree->info && tree != NULL){
        if(value < tree->info){ // if value is less branch left
            outFile << tree->info;
            tree = tree->left;
        }
        else if (value > tree->info){ // if value is greater branch right
            outFile << tree->info;
            tree = tree->right;
        }
    }
}

void PrintAncestorsRecursive(TreeNode* tree, ItemType value, std::ofstream& outFile) {
    
    if(value == tree->info){ // if value equals node then return
        return;
    }
    else if(value > tree->info){ // if value is greater than root then branch right
        outFile << tree->info;
        PrintAncestorsRecursive(tree->right, value, outFile);
    }
    else if(value < tree->info){ // if value is less than root then branch left
        outFile << tree->info;
        PrintAncestorsRecursive(tree->left, value, outFile);
    }
}

void PrintAncestorsReverse(TreeNode* tree, ItemType value, std::ofstream& outFile) {
    // This function will be the same as Recursion except it will traverse down the list and then print up 
    if(value > tree->info){
        PrintAncestorsReverse(tree->right,value, outFile);
        outFile << tree->info;
    }
    else if(value < tree->info){
        PrintAncestorsReverse(tree->left,value, outFile);
        outFile << tree->info;
    }
    else if(value == tree->info){
        return;
    }
}
