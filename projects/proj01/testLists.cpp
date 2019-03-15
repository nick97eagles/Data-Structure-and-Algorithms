#include "testLists.h"
<<<<<<< HEAD
=======
#include "ItemType.h"
#include "SortedType.h"

>>>>>>> upstream/master

bool testMergeLists(SortedType list1, SortedType list2) {
    
    SortedType result;
    mergeLists(list1, list2, result);
    result.ResetList();
    
    // Checks if length of new list is correct
    if((list1.GetLength() + list2.GetLength()) != result.GetLength()){
        return false;
        }
    
    // Checks that the result of the merged list is sorted
    ItemType temp1 = result.GetNextItem();
    ItemType temp2 = result.GetNextItem();
    
    for(int i=2; i<result.GetLength(); i++){
        if(temp1.ComparedTo(temp2)!=LESS){
            return false;
        }
        temp1 = temp2;
        temp2 = result.GetNextItem();
    }
    
    // Checks that all elements in list1 & list2 are in result
    result.ResetList();
    list1.ResetList();
    list2.ResetList();
    SortedType tempList;
    
    for(int i=0; i<result.GetLength(); i++){
        temp1 = result.GetNextItem();
        for(int i=0; i<list1.GetLength(); i++){
            if(temp1.ComparedTo(list1.GetNextItem())
               == EQUAL){
                tempList.PutItem(temp1);
            }
        }
        for(int i=0; i<list2.GetLength(); i++){
            if(temp1.ComparedTo(list2.GetNextItem())
               == EQUAL){
                tempList.PutItem(temp1);
            }
        }
    }
    
    if(tempList.GetLength() != result.GetLength()){
        return false;
    }
    
  // All the tests are passed then function will return true
    return true;
}


bool testSplitLists(SortedType list, ItemType item) {
<<<<<<< HEAD
   
    SortedType list1;
    SortedType list2;
    splitLists(list, item, list1, list2);
    list1.ResetList();
    list2.ResetList();
    
    // Checks to see if the list1 & list2 are the length of original list
    if((list1.GetLength() + list2.GetLength()) != list.GetLength())
        return false;
    
    //Checks to see if all elements in original list made it into list1 & list2
    ItemType test1;
    list1.ResetList();
    list2.ResetList();
    SortedType tempList;
    
    for(int i=0; i<list.GetLength(); i++){
        test1 = list.GetNextItem();
        for(int i=0; i<list1.GetLength(); i++){
            if(test1.ComparedTo(list1.GetNextItem())
               == EQUAL){
                tempList.PutItem(test1);
            }
        }
        for(int i=0; i<list2.GetLength(); i++){
            if(test1.ComparedTo(list2.GetNextItem())
               == EQUAL){
                tempList.PutItem(test1);
            }
        }
    }
    if(tempList.GetLength() != list.GetLength()){
        return false;
    }
     // If item is in list1 then return false because it should be in list2
    for(int i=0; i<list1.GetLength(); i++){
        if(item.ComparedTo(list1.GetNextItem())==EQUAL)
            return false;
        }
    
=======
    // TODO Write test for SplitLists
>>>>>>> upstream/master
    return true;
}
