/*************************************************************************
 *
 * hw02: Implement IsThere() for Array and Linked implementations
 * 
 * File Name:   IsThereArray.cpp
 * Name:        Nicholas Morin
 * Course:      CPTR 242
 * Date:        4/22/18
 * Time Taken:  ?
 * 
 */
#include "ItemType.h"
#include "SortedArray.h"

// Boolean IsThere(ItemType item)
//  Function:	    Determines if item is in the list.
//  Precondition:	List has been initialized.
// 	Postcondition:	Function value = there exist an item in the list whose key is the same as item's.	
bool SortedArray::IsThere(ItemType item) const {
    
    int midPoint;
    int first = 0;
    int last = length - 1;
    bool found;
    bool moreToSearch = first <= last;
    found = false;
   
    while (moreToSearch && !found) {
        midPoint = (first + last) / 2;
        switch (item.ComparedTo(info[midPoint])) {
            case LESS:
                last = midPoint - 1;
                moreToSearch = first <= last;
                break;
            case GREATER:
                first = midPoint + 1;
                moreToSearch = first <= last;
                break;
            case EQUAL:
                found = true;
                return true;
        }
    }
    return found;
}
