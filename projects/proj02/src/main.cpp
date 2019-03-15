#include <iostream>
#include <cstdlib>
#include "Applicant.h"
#include "QueType.h"

using namespace std;

//Prototypes for functions 
Applicant createNew();                              // creates new application
void sortPriority(Applicant,QueType&,QueType&);     // Places application in either priority queue or base queue
Applicant pullNext(QueType&,QueType&);              // Pulls the specified application and deletes it from the queue
void printList(QueType,QueType);                    // Prints the list of specified list
void printApplicant(Applicant);                     // Prints applications
void editApplicant(Applicant&);                     // Allows changes to specific applications
void printMenu();                                   // Prints menu

int main(){
    QueType priorityQueue;                                              //Queue for holding priority applications
    QueType baseQueue;                                                  //Queue for holding non-priority applications
    int menuChoice = 0;                                                 //Variable handling choice of menu options (main)
    int switchChoice = 0;                                               //Variable handling choice of menu options (switch)
    bool menuRun = true;                                                //Bool handling run state of menu
    bool switchRun = true;                                              //Bool handling run state of switch case
    string temp;                                                        //Temp string used for various user input
    Applicant* edit;                                                    //Applicant pointer used in edit function
    
    while(menuRun) {
        printMenu();                                                    // Prints menu
        cin >> menuChoice;                                              //Input integer choice
        cin.ignore();                                                   //This ignores the carriage return in the stream from previous in

        switch (menuChoice) {                                           //Switch case handling menu options
            case 1: {                                                   //Input condition
                while (switchRun) {
                    sortPriority(createNew(),priorityQueue,baseQueue);                  //This calls for creation of an application and sorts/stores it
                    cout << "\nApplication recorded.\n\n";
                    cout << "Add another application? y or n ";
                    getline(cin,temp);
                    while(temp != "y" && temp != "Y" && temp != "n" && temp != "N"){    //Verifies user input to be the expected response
                        cout << "Invalid input, please enter y or n : ";
                        getline(cin,temp);
                    }
                    switchRun = temp == "y" || temp == "Y";                             //Shorthand if/else to set switchRun based on user input
                }
                switchRun = true;                                       //Always set switchRun to true after use for next case handle
                break;
            }
            case 2: {
                if(priorityQueue.IsEmpty() == true && baseQueue.IsEmpty() == true){ // If queues are empty will return to menu
                    cout << "There are no applications to delete at this time\n\n\n";
                    break;
                }
                                                                        //Pull application condition
                int apps = 0;                                           //Holds user input for number of applications to pull
                int count = 1;                                          //Holds count for clean output of applications
                cout << "How many applications would you like to delete?\n";
                cout << "This cannot be undone once completed\n";
                cin >> apps;                                            //Input integer choice
                cin.ignore();                                           //This ignore the carriage return in the stream from previous cin
                while(apps > priorityQueue.GetLength() + baseQueue.GetLength() || apps < 1){    //Verifies input as to not allow too many/too few pulls
                    cout << "Enter a valid number of applications. Between 1 and " <<
                         priorityQueue.GetLength() + baseQueue.GetLength() << ":\n";
                    cin >> apps;
                    cin.ignore();
                }
                for(apps;apps > 0;apps--){                              //Iterates and prints application information in pull order
                    cout << "Applicant " << count << endl;
                    printApplicant(pullNext(priorityQueue,baseQueue));
                    count++;
                }
                break;
            }
            case 3: {                                                   //Edit condition
                while (switchRun) {
                    if(priorityQueue.IsEmpty() == true && baseQueue.IsEmpty() == true){  // if there is no list to print then it will return to menu
                        cout << "There are no lists to edit at this time\n" << endl;
                        break;
                    }
                    
                    cout << "Printing the list...\n";
                    printList(priorityQueue,baseQueue);                 //Prints applicants from eah queue
                    cout << "Enter '1' to edit from the priority list, or '0' to edit from the list without priority:\n";
                    cin >> switchChoice;
                    
                    while(switchChoice != 0 && switchChoice != 1){      //Verifies a 0 or 1 input in switchChoice
                        cout << "Invalid choice. Please enter a '0' or '1':\n";
                        cin >> switchChoice;
                    }
                    if(switchChoice == 1){                              //Selects priority queue to be edited
                        if(priorityQueue.IsEmpty() == true){            //Will return to menu if priority queue is empty
                            cout << "There are no applicants to edit in this list\n";
                            break;
                        }
                        cout << "Enter the number of the applicant you wish to edit:\n";
                        cin >> switchChoice;
                        while(switchChoice < 1 || switchChoice > priorityQueue.getPos()){       //Verifies a valid applicant number choice
                            cout << "Invalid choice. Please enter an applicant number from the printed list above:\n";
                            cin >> switchChoice;
                        }
                        edit = priorityQueue.GetApplicant(switchChoice);                    //Pulls requested applicant and returns it to edit
                        cout << "Editing Applicant " << switchChoice << "..." << endl;
                        printApplicant(*edit);                                              //Prints specific applicant to be edited
                        editApplicant(*edit);                                               //Opens edit menu for specific applicant
                    }
                    else {                                              //Selects non-priority queue to be edited
                        if(baseQueue.IsEmpty() == true){                //Will return to menu if base queue is empty
                            cout << "There are no applicants to edit in this list\n";
                            break;
                        }
                        cout << "Enter the number of the applicant you wish to edit:\n";
                        cin >> switchChoice;
                        while(switchChoice < 1 || switchChoice > baseQueue.getPos()){           //Verifies a valid applicant number choice
                            cout << "Invalid choice. Please enter an applicant number from the printed list above:\n";
                            cin >> switchChoice;
                        }
                        edit = baseQueue.GetApplicant(switchChoice);                        //Pulls requested applicant and returns it to edit
                        cout << "Editing Applicant " << switchChoice << "..." << endl;
                        printApplicant(*edit);                                              //Prints specific applicant to be edited
                        editApplicant(*edit);                                               //Opens edit menu for specific applicant
                    }
                    cout << "Edit another application? [y/n]\n";
                    getline(cin,temp);
                    while(temp != "y" && temp != "Y" && temp != "n" && temp != "N"){        //Verifies input to be what is expected
                        cout << "Invalid input, please enter [y/n]:\n";
                        getline(cin,temp);
                    }
                    switchRun = temp == "y" || temp == "Y";             //Shorthand if/else to set switchRun based on user input
                }
                switchRun = true;                                       //Always set switchRun to true after use for next case handle
                break;
            }
            case 4: {
                
                if(priorityQueue.IsEmpty() == true && baseQueue.IsEmpty() == true){ // If the queues are empty then it will return to the menu
                    cout << "There are no lists to print at this time\n" << endl;
                    break;
                }                                                        //Print condition
                printList(priorityQueue,baseQueue);                     //Prints all applicants to console
                break;
            }
            case 5: {                                                   //Exit condition
                cout << "Goodbye...\n";
                menuRun = false;
                break;
            }
            default: {                                                  //Default case informs user of invalid input
                cout << "Invalid menu choice. Enter a valid number from 1 to 5\n";
            }
        }
    }
}
// Prints the list of specified list
void printList(QueType priorityPrint, QueType basePrint){
    
    if(!priorityPrint.IsEmpty()){
        cout << "-------------------------\n"
                "Applicants with priority:\n"
                "-------------------------\n";
        priorityPrint.PrintQueue();
    }
    if(!basePrint.IsEmpty()){
        cout << "----------------------------\n"
                "Applicants without priority:\n"
                "----------------------------\n";
        basePrint.PrintQueue();
    }
}

// Prints applications
void printApplicant(Applicant toPrint){
    string temp;
    cout << "Name: " << toPrint.getName() << endl;
    cout << "Age: " << toPrint.getAge() << endl;
    cout << "Phone: " << toPrint.getPhone() << endl;
    toPrint.getChildren() ? temp="Yes" : temp="No";
    cout << "Children " << temp << endl;
    toPrint.getMarried() ? temp="Yes" : temp="No";
    cout << "Married " << temp << endl << endl;
}

// Allows changes to specific applications
int editChoice = 0;
void editApplicant(Applicant& toEdit){
    bool editRun = true;
    string strEdit;
    int intEdit;
    bool boolEdit;

    while(editRun){
        cout << "1) Edit Name\n"
                "2) Edit Age\n"
                "3) Edit Phone Number\n"
                "4) Edit Status of Children\n"
                "5) Edit Marriage Status\n"
                "6) Exit and Save\n\n\n"
                "Choice: ";
        cin >> editChoice;
        cin.ignore();
        switch (editChoice) {
            case 1:{
                cout << "Enter new applicant name: ";
                getline(cin,strEdit);
                toEdit.setName(strEdit);
                cout << "Changes saved.\n\n";
                break;
            }
            case 2:{
                cout << "Enter new applicant age: ";
                cin >> intEdit;
                cin.ignore();
                toEdit.setAge(intEdit);
                cout << "Changes saved.\n\n";
                break;
            }
            case 3:{
                cout << "Enter new applicant phone number: ";
                getline(cin,strEdit);
                toEdit.setPhone(strEdit);
                cout << "Changes saved.\n\n";
                break;
            }
            case 4:{
                cout << "Does the applicant have children? y or n : ";
                getline(cin,strEdit);
                while(strEdit != "y" && strEdit != "Y" && strEdit != "n" && strEdit != "N"){
                    cout << "Invalid input, please enter y or n : ";
                    getline(cin,strEdit);
                }
                boolEdit = strEdit == "y" ||  strEdit == "Y";
                toEdit.setChildren(boolEdit);
                cout << "Changes saved.\n\n";
                break;
            }
            case 5:{
                cout << "Is the applicant married? y or n : ";
                getline(cin,strEdit);
                while(strEdit != "y" && strEdit != "Y" && strEdit != "n" && strEdit != "N"){
                    cout << "Invalid input, please enter y or n : ";
                    getline(cin,strEdit);
                }
                boolEdit = strEdit == "y" || strEdit == "Y";
                toEdit.setMarried(boolEdit);
                cout << "Changes saved.\n\n";
                break;
            }
            case 6:{
                cout << "Saving...\n";
                editRun = false;
                break;
            }
            default:{
                cout << "Invalid menu choice. Enter a valid number from 1 to 6\n";
            }
        }
    }
}

// Places application in either priority queue or base queue
void sortPriority(Applicant in, QueType& priorityQueue, QueType& baseQueue){
    if(in.getPriority()){
        priorityQueue.Enqueue(in);
    }
    else{
        baseQueue.Enqueue(in);
    }
}

// Pulls the specified application and deletes it from the queue
Applicant pullNext(QueType& priorityQueue, QueType& baseQueue){
    Applicant toReturn;
    if(priorityQueue.IsEmpty()){
        if(baseQueue.IsEmpty()){
            throw EmptyQueue();
        }
        else{
            baseQueue.Dequeue(toReturn);
            return toReturn;
        }
    }
    else{
        priorityQueue.Dequeue(toReturn);
        return toReturn;
    }
}

// creates new application
Applicant createNew(){
    bool c;
    bool m;
    int a = 0;
    string n;
    string ph;
    string temp;

    cout << "Enter applicant name: ";
    getline(cin,n);

    cout << "Enter applicant age: ";
    cin >> a;
    cin.ignore();

    cout << "Enter applicant phone number: ";
    getline(cin,ph);

    cout << "Does the applicant have children? y or n : ";
    getline(cin,temp);
    while(temp != "y" && temp != "Y" && temp != "n" && temp != "N"){
        cout << "Invalid input, please enter y or n : ";
        getline(cin,temp);
    }
    c = temp == "y" ||  temp == "Y";

    cout << "Is the applicant married? y or n : ";
    getline(cin,temp);
    while(temp != "y" && temp != "Y" && temp != "n" && temp != "N"){
        cout << "Invalid input, please enter y or n : ";
        getline(cin,temp);
    }
    m = temp == "y" || temp == "Y";

    return Applicant(c,m,a,n,ph);
}

// Prints menu
void printMenu(){
    cout << "----------------------------------------------\n"
            "      Village Housing Application Menu\n"
            "----------------------------------------------\n"
            "1) Add application(s)\n"
            "2) Delete application(s)\n"
            "3) Edit applications\n"
            "4) Print list\n"
            "5) Exit\n\n"
            "Choice: ";
}
