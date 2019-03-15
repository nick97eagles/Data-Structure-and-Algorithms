/*************************************************************************
 *
 * hw02: Implement IsThere() for Array and Linked implementations
 *
 * File Name:   IsThereLinked.cpp
 * Name:        Nicholas Morin
 * Course:      CPTR 242
 * Date:        4/17/18
 * Tine Taken:  ?
 *
 */
#include "ItemType.h"
#include "UnsortedLinked.h"

// Boolean IsThere(ItemType item)
//  Function:        Determines if item is in the list.
//  Precondition:    List has been initialized.
//     Postcondition:    Function value = there exist an item in the list whose key is the same as item's.
bool UnsortedLinked::IsThere(ItemType item) const {
    
    
    bool moreToSearch;
    NodeType* location;
    
    location = listData;
    bool found = false;
    moreToSearch = (location != NULL);
    
    while (moreToSearch && !found) {
        switch (item.ComparedTo(location->info)) {
            case LESS:
            case GREATER:
                location = location->next;
                moreToSearch = (location != NULL);
                break;
            case EQUAL:
                found = true;
                item = location->info;
                return true;
        }
    }
    
    return false;
}

