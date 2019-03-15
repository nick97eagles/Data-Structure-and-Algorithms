/*************************************************************************
 *
 * hw02: Implement IsThere() for Array and Linked implementations
 *
 * File Name:   IsThereArray.cpp
 * Name:        Nicholas Morin
 * Course:      CPTR 242
 * Date:        4/16/18
 * Tine Taken:  ?
 *
 */
#include "ItemType.h"
#include "UnsortedArray.h"

// Boolean IsThere(ItemType item)
//  Function:        Determines if item is in the list.
//  Precondition:    List has been initialized.
//     Postcondition:    Function value = there exist an item in the list whose key is the same as item's.
bool UnsortedArray::IsThere(ItemType item) const {
    
    bool moreToSearch;
    int location = 0;
    bool found = false;
    
    moreToSearch = (location < length);
    
    while (moreToSearch && !found) {
        switch (item.ComparedTo(info[location])) {
            case LESS:
            case GREATER:
                location++;
                moreToSearch = (location < length);
                break;
            case EQUAL:
                found = true;
                item = info[location];
                return true;
        }
    }
    
    return false;
}
