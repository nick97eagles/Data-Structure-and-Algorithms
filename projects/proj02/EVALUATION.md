# Project 2 Village Housing Waiting List 

## Data Structure #1
### Class w/ objects

* This structure will allow an applicant to input their information
    - Name
    - Class Standing 
    - Age / must be over 25 for priority 
    - Whether or not they are married 
    
## Data Structure #2
### Queue #1 

* This structure will be for the qualified people in the waiting list (those that are over 25 or married or have kids)
*  This structure will have member functions like push, pop, getlength, and showList. 
* Queue will contain the objects created dynamically in structure #1 

## Datat Structure #3 
### Queue #2

* This structure will be the same as the first queue except it is for those that are not fully qualified(those that are not over 25, don't have kids, and are not married)
* This structure will also have member functions the same as Queue #1
* This queue will also be filled with objects created in structure #1
* This queue will only be emptied if queue #1 is empty 

## Big-O Notation 

### Data structure #1
* This structure is mostly based off of the user. They are entering information and the program will be converting them into objects to be stored in the queues. 

### Data structure #2 
* The big-o notation for this structure is mostly dependant on what type of queue will be used. (Array vs Linked) 
* If Array is to be used then the big-o notation would be O(1) for all functions. 
* If Linked is to be used then the big-o notation would be O(1) for all functions except for MakeEmpty() and the Destructor. 

### Data structure #3 
* Since this is the same structure as #2 the big-o notation would be the same 

## Strenghts and Weaknessess 
### Structure #1 

* Strengths:
    - a clean way to get user info  
    - easy to store user input 
* Weaknesses: 
    - could be strenuous running through tests
    - information could get lost and not processed correctly 
    
    ### Structure #2 & #3 

* Strengths: 
    - Easy way to implement a FIFO implementation. 
    - Better than just a sorted List 
* Weaknesses: 
    - If member functions aren't implemented correctly then queue won't function correctly 
    - Possibly confusion between structures and the wrong applicant could get pulled. 
    

                     



