/*************************************************************************
 *
 * hw02: Implement IsThere() for Array and Linked implementations
 * 
 * File Name:   IsThereLinked.cpp
 * Name:        ?
 * Course:      CPTR 242
 * Date:        ?
 * Time Taken:  ?
 * 
 */
#include "ItemType.h"
#include "SortedLinked.h"

// Boolean IsThere(ItemType item)
//  Function:	    Determines if item is in the list.
//  Precondition:	List has been initialized.
// 	Postcondition:	Function value = there exist an item in the list whose key is the same as item's.	
bool SortedLinked::IsThere(ItemType item) const {
    
    bool moreToSearch;
    NodeType *location;
    
    location = listData;
    bool found = false;
    moreToSearch = (location != NULL);
    
    while (moreToSearch && !found) {
        switch (item.ComparedTo(location->info)) {
            case LESS:
                moreToSearch = false;
                break;
            case GREATER:
                location = location->next;
                moreToSearch = (location != NULL);
                break;
            case EQUAL:
                found = true;
                return true; 
           
        }
    }
    return found;
}
