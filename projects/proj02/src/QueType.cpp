/****************************************************************************
 *
 * File Name:  QueType.cpp
 * Course:     CPTR 242
 * Source:     Book Provided Code
 *
 */
#include "QueType.h"
#include <cstddef>  // For NULL
#include <new>      // For bad_alloc

struct NodeType {
    Applicant info;
    NodeType* next;
};

QueType::QueType()  // Class constructor.
// Post:  front and rear are set to NULL.
{
    front = NULL;
    rear = NULL;
    pos = 1;
}

void QueType::MakeEmpty()
// Post: Queue is empty; all elements have been deallocated.
{
    NodeType* tempPtr;

    while (front != NULL) {
        tempPtr = front;
        front = front->next;
        delete tempPtr;
    }
    rear = NULL;
    pos = 1;
}

// Class destructor.
QueType::~QueType() {
    MakeEmpty();
}

bool QueType::IsFull() const
// Returns true if there is no room for another ItemType
//  on the free store; false otherwise.
{
    NodeType* location;
    try {
        location = new NodeType;
        delete location;
        return false;
    } catch (std::bad_alloc) {
        return true;
    }
}

bool QueType::IsEmpty() const
// Returns true if there are no elements on the queue; false otherwise.
{
    return (front == NULL);
}

void QueType::Enqueue(Applicant newItem)
// Adds newItem to the rear of the queue.
// Pre:  Queue has been initialized.
// Post: If (queue is not full) newItem is at the rear of the queue;
//       otherwise a FullQueue exception is thrown.

{
    if (IsFull())
        throw FullQueue();
    else {
        NodeType* newNode;
        newItem.setPosition(pos);
        pos++;

        newNode = new NodeType;
        newNode->info = newItem;
        newNode->next = NULL;
        if (rear == NULL) {
            front = newNode;
        }
        else {
            rear->next = newNode;
        }
        rear = newNode;
    }
}

void QueType::Dequeue(Applicant& item)
// Removes front item from the queue and returns it in item.
// Pre:  Queue has been initialized and is not empty.
// Post: If (queue is not empty) the front of the queue has been
//       removed and a copy returned in item;
//       othersiwe a EmptyQueue exception has been thrown.
{
    if (IsEmpty())
        throw EmptyQueue();
    else {
        NodeType* tempPtr;

        tempPtr = front;
        item = front->info;
        front = front->next;
        if (front == NULL)
            rear = NULL;
        delete tempPtr;
        pos--;
    }
}

// Will return the length of the queue
int QueType::GetLength() {
    int length = 0;
    NodeType* tempPtr = front;
    while(front != NULL){
        length++;
        front = front->next;
    }
    front = tempPtr;
    return length;
}

// Prints the entire Queue for the user to see 
void QueType::PrintQueue() {
    int current = 1;
    string temp;
    NodeType* tempPtr = front;
    while(front != NULL){
        cout << "Applicant " << current << ":\n";
        cout << "Name: " << front->info.getName() << endl;
        cout << "Age: " << front->info.getAge() << endl;
        cout << "Phone: " << front->info.getPhone() << endl;
        front->info.getChildren() ? temp="Yes" : temp="No";
        cout << "Children? " << temp << endl;
        front->info.getMarried() ? temp="Yes" : temp="No";
        cout << "Married? " << temp << endl << endl;
        current++;
        front = front->next;
    }
    front = tempPtr;
}

// Returns specified application object
Applicant* QueType::GetApplicant(int p) {
    NodeType* tempPtr = front;
    NodeType* result;
    while(front != NULL && front->info.getPosition() != p){
        front = front->next;
    }
    result = front;
    front = tempPtr;
    if(result->info.getPosition() == p){
        Applicant* toReturn = &result->info;
        return toReturn;
    }
    else
        return 0;
}

// returns postion in queue 
int QueType::getPos() {
    return pos;
}

QueType::QueType(const QueType& anotherQue) {
    NodeType* ptr1;
    NodeType* ptr2;

    if (anotherQue.front == NULL)
        front = NULL;
    else {
        front = new NodeType;
        front->info = anotherQue.front->info;
        ptr1 = anotherQue.front->next;
        ptr2 = front;
        while (ptr1 != NULL) {
            ptr2->next = new NodeType;
            ptr2 = ptr2->next;
            ptr2->info = ptr1->info;
            ptr1 = ptr1->next;
        }
        ptr2->next = NULL;
        rear = ptr2;
    }
}
