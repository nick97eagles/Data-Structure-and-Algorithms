#include <iostream>
// will return false if applicant was not successfully added to queue
// will return true if applicant is successfully added to queue
bool testAddApplic(){
    Applicant test1; // Creates an empty object to test
    Applicant test2; // Creates an empty object to test
    test1.setPriority(true); // Sets the priority of the first object to true
    test2.setPriority(false);// Sets the priority of the second object to false
    test3.setPriority(false); // Sets the priority of the second object to false
    Place(test1); // Places the object according to its priority in either Queue1(priority queue) or Queue2
    Place(test2); // Places the object according to its priority in either Queue1(priority queue) or Queue2
    Place(test3); // Places the object according to its priority in either Queue1(priority queue) or Queue2
    
    // For the test to succeed then both test2 and test3's objects will be added to Queue2 and test1's object will be added to Queue1
    if((Queue1.GetLength() == 1) && (Queue2.GetLength() == 2)){
        return true;
    }
    
    else
    return false;
}
// Function will test the Enqueue and Dequeue functions
bool testIn&Out(){
   
    Applicant test1; // creates an empty object for the sake of the test
    test1.setPriority(true); // true will place it Queue1 (Priority Queue)
    Place(test1); // sorts the object to the correct queue
    
    if(Queue1.GetLength() == 1){ // if the object was successfully added to the queue
                                 // then dequeue the object
    Queue1.Dequeue();
    
    if(Queue1.GetLength() == 0){ // If the queue is empty it means that the object was
        return true;             // successfully taken out
    }
}
    else return false;
}
// Function will test the isEmpty() and MakeEmpty() functions
bool testEmpty(){
    // Creates three test objects
    Applicant t1;
    Applicant t2;
    Applicant t3;
    
    // Adds the three objects to the queue
    Queue1.Enqueue(t1);
    Queue1.Enqueue(t2);
    Queue1.Enqueue(t3);
    
    if(!Queue1.isEmpty()){ // if the queue is not empty then run the following code
        Queue1.MakeEmpty(); // will empty the queue
        if(Queue1.isEmpty() == true){
            return true;
        }
        else return false;
    }
    else
    return false;
}

// Function will test the GetLenght() function
bool testGetLength(){
    // creates three test objects
    Applicant t1, t2, t3;
    
    // adds the three objects to queue2
    Queue2.Enqueue(t1);
    Queue2.Enqueue(t2);
    Queue2.Enqueue(t3);
    
    if(Queue2.GetLength() == 3){ // if the length of the queue is 3 run the following code
        Queue2.Dequeue(); // take 1 object out of the queue
        if(Queue2.GetLength() == 2){ // if the length returns 2 then return true
        return true;
        }
        else return false;
    }
    else
    return false;
}
