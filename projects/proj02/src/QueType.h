#ifndef PROJ02_QUETYPE_H
#define PROJ02_QUETYPE_H

// Header file for Queue ADT.
#include <cstddef>
#include <new>
#include "Applicant.h"

class FullQueue {};

class EmptyQueue {};

struct NodeType;

class QueType {
public:
    QueType();
    // Class constructor.
    // Because there is a default constructor, the precondition
    // that the queue has been initialized is omitted.
    QueType(int max);
    // Parameterized class constructor.
    ~QueType();
    // Class destructor.
    QueType(const QueType& anotherQue);
    // Copy constructor
    void MakeEmpty();
    // Function: Initializes the queue to an empty state.
    // Post: Queue is empty.
    bool IsEmpty() const;
    // Function: Determines whether the queue is empty.
    // Post: Function value = (queue is empty)
    bool IsFull() const;
    // Function: Determines whether the queue is full.
    // Post: Function value = (queue is full)
    void Enqueue(Applicant newItem);
    // Function: Adds newItem to the rear of the queue.
    // Post: If (queue is full) FullQueue exception is thrown
    //       else newItem is at rear of queue.
    void Dequeue(Applicant& item);
    // Function: Removes front item from the queue and returns it in item.
    // Post: If (queue is empty) EmptyQueue exception is thrown
    //       and item is undefined
    //       else front element has been removed from queue and
    //       item is a copy of removed element.
    int GetLength(); // Returns the length of the queue
    void PrintQueue(); // Prints the contents of the queue
    Applicant* GetApplicant(int p); // Returns specified application object
    int getPos(); // returns postion in queue 

private:
    NodeType* front;
    NodeType* rear;
    int pos;
};

#endif //PROJ02_QUETYPE_H
