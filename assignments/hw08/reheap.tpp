/****************************************************************************
 *
 * Howemork.08: Implement ReheapDown and ReheapUp functions using iteratation.
 *
 * File Name:  reheap.tpp
 * Name:       Nicholas Morin
 * Course:     CPTR 242
 * Date:       6/3/18
 * Time Taken: As long as it takes for a whale to tap dance
 *
 */#include "Heap.h"

using namespace std;

template <class ItemType>
void HeapType<ItemType>::ReheapDownIterative(int root, int bottom)
{
int top, right, left;
bool heapComplete = false;

while(!heapComplete && (root*2 + 1 <= bottom)){

left = root * 2 + 1;
right = root * 2 + 2;

if(left == bottom)
{
top = left;
}
else
{
    if(elements[left] <= elements[right])
        top = right;
    else
        top = left;
}
if(elements[root] < elements[top])
    Swap(elements[root], elements[top]);
else
    heapComplete = true;
}
}

template <class ItemType>
void HeapType<ItemType>::ReheapUpIterative(int root, int bottom)
{
int head;
bool heapComplete = false;

while(!heapComplete && root < bottom){
head = (bottom - 1) / 2;
if(elements[head] < elements[bottom]){
    Swap(elements[head], elements[bottom]);
    bottom = head;
}
else
    heapComplete = true;
}
}
