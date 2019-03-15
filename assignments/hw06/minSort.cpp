/****************************************************************************
 *
 * Howemork.06: Implement a two recursive functions on a linked unsorted list.
 *
 * File Name:  minSort.cpp
 * Name:       Nicholas Morin
 * Course:     CPTR 242
 * Date:       5/21/18
 * Time Taken: longer than it should have
 *
 */
#include "ItemType.h"
#include "unsorted.h"

using namespace std;

NodeType* MinLoc(NodeType* list, NodeType*& minPtr) {
    
    if(list == NULL) return minPtr;
    
    else if(list->info.ComparedTo(minPtr->info) == EQUAL){
        return MinLoc(list->next, minPtr);
    }
    else if(list->info.ComparedTo(minPtr->info) == GREATER){
        return MinLoc(list->next,minPtr);
    }
    else if(list->info.ComparedTo(minPtr->info) == LESS){
        minPtr = list;
        return MinLoc(list, minPtr);
    }
    else return NULL;
}

void Sort(NodeType* list) {
    NodeType* minPtr;
    NodeType* temp;
    NodeType place;
    temp = &place;
    
    if(list == NULL) return;
    
    else {
        minPtr = list;
        minPtr = MinLoc(list, minPtr);
        
        if(list->info.ComparedTo(minPtr->info) == EQUAL){
            return Sort(list->next);
        }
        else if(list->info.ComparedTo(minPtr->info) == LESS){
            return Sort(list->next);
        }
        else if(list->info.ComparedTo(minPtr->info) == GREATER){
            temp->info = list->info;
            list->info = minPtr->info;
            minPtr->info = temp->info;
            return Sort(list->next); 
        }
    }
    
}
