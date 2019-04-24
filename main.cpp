#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//struct of a table, which contains the table number, maximum size of customers that it could support and its availability
struct table{
    int number;
    int size;
    bool availability;
    table *next;
};

//print user menu and ask for user input
void printMenu(int *userInput){
    cout << endl;
    cout << "Restaurent Table Management Menu"<<endl;
    cout << "--------------------------------"<< endl;
    cout << "1) Check Table Availability"<<endl;
    cout << "2) Occupy a table"<<endl;
    cout << "3) Release a table"<<endl;
    cout << "4) Print table status"<<endl;
    cout << endl;
    cout << "-1) Exit" << endl;
    cout << endl;
    cout << "Please enter your choice: ";
    cin >> *userInput;
    cout << "--------------------------------"<<endl;
    cout << endl;
}

//to get the table information contained in the file and get the number of 6, 4 and 2-person table, return true if file input excist, false elsewise
bool generateTable(string tableInfo, int *numOfSix, int *numOfFour, int *numOfTwo){
    int sixT, fourT;
    ifstream inpFile(tableInfo);
    if(inpFile.is_open()){
        cin >> sixT; //number of 6-person table
        cin >> fourT; //number of 4-person table
        inpFile.close();
        if((50-sixT*6-fourT*4)<0){ //check if the input exceeds the maximum number of seats in restaurant
            cout << "Table arragement cannot be fulfilled! Please input again!"<<endl;
            return false;
        }else{
            *numOfSix = sixT;
            *numOfFour = fourT;
            *numOfTwo = (50-sixT-fourT)/2; //calculate the number of 2-person table
            return true;
        }
    }
    else{
        cout << "File not exist!"<<endl;
        return false;
    }
}


//to initialize table information using linked list
void appendTable(table *&head, int tableNum, int numOfPeople){
    table *new_table = new table;
    table *current = head;

    //if the list is empty, create a head and initialize it
    if (head == NULL){
        head = new_table;
        new_table->number = tableNum;
        new_table->size = numOfPeople;
        new_table->availability = false;
        new_table->next = NULL;
    }
    else{
        //if the list is not empty, search for its end and insert a new table information
        while (current != NULL){
            if (current->next == NULL){
                current->next = new_table;
                new_table->next= NULL;
                new_table->number = tableNum;
                new_table->size = numOfPeople;
                new_table->availability = false;
            }
            current = current->next;
        }
    }
    
    delete new_table;
}


//to check if the table user inputted is occupied or not
void checkAvab(table *&head, int numOfTwo, int numOfFour,int numOfSix){
    int tableNum;
    bool availability = false;
    table *current = head;
    
    //print out the range of table numbers of the 3 different sizes of tables
    cout << "Table number of 2-person table: 1-" << numOfTwo <<endl;
    cout << "Table number of 4-person table: " << numOfTwo+1 << "-"<< numOfTwo+numOfFour <<endl;
    cout << "Table number of 6-person table: " << numOfTwo+numOfFour+1 << "-"<<numOfTwo+numOfFour+numOfSix << endl;
    
    //ask for a input table number from user
    cout << "Please input a valid table number: ";
    cin >> tableNum;
    cout << endl;
    //check if the inputted data is out of range, if so, ask for another input
    while ((tableNum < 0) || (tableNum > (numOfFour+numOfSix+numOfTwo))){
        cout << "Invalid table number, please input again: ";
        cin >> tableNum;
        cout << endl;
    }
    
    //search from the head of the linked list until the table is found, and extract its availability into a variable
    while (current != NULL){
        if(current->number == tableNum){
            availability = current->availability;
            break;
        }else
        {
            current = current->next;
        }
    }
    
    //output the table availability using the variable to check whether its true or false
    if (availability == 0){
        cout << "Table " << tableNum << " is unoccupied!" <<endl;
    }else{
        cout << "Table " << tableNum << " is occupied"<<endl;
    }
    
}


//to occupy a table by changing it availability
void occupyTable(table *& head){
    table *current = head;
    int numOfCustomers, tableNum = -1;
    
    //ask for the number of customers
    cout << "Please input the number of customers: ";
    cin >> numOfCustomers;
    cout << endl;
    //if the number of customers is more than the capacity of the biggest table, than ask for the user to split them in groups
    while (numOfCustomers > 6){
        cout << "Sorry! We could not provide a table for more than 6 people! Please separate into 2 tables! Thanks!" << endl;
        cout << "Please input the number of customers again: ";
        cin >> numOfCustomers;
        cout << endl;
    }
    
    //search from the head, until a table which is unoccupied and big enough to handle all customers is found. Return the table numbers to a variable
    while (current != NULL) {
        if ((current->size >=numOfCustomers) && (current->availability == 0)){
            current -> availability = true;
            tableNum = current->number;
            break;
        }else
        {
            current = current->next;
        }
    }
    
    //if the table number does not change, it means there are no available table. Else, output the table number to the user
    if (tableNum == -1){
        cout << "Sorry! All our tables are occupied at this moment! Please wait!"<<endl;
    }else{
        cout << "Thank you! Your table number is " << tableNum << "." <<endl;
    }
}


//to release a table by changing its table availability
void releaseTable(table *&head, int tableSum){
    table *current = head;
    int tableNum;
    
    //ask for a table number which the user want to release
    cout << "Please input a table number of the table you want to release: ";
    cin >> tableNum;
    cout << endl;
    //check if the input is out of range. If so, ask for another input
    while ((tableNum > tableSum) || (tableNum<1)){
        cout << "Invalid table number. Please input a valid table number (from 1-" << tableSum <<"): ";
        cin >> tableNum;
        cout << endl;
    }
    
    //check frome the head, until the table number is found. Change its availability to false, which means unoccupied
    while (current != NULL){
        if (current -> number == tableNum){
            current -> availability = false;
            break;
        }else{
            current = current -> next;
        }
    }
    
    //output the table number of the released table to confirm that it's released.
    cout << "Table " << tableNum << " is released!" << endl;
}


//output all the data of tables
void tableStatus(table *&head, int tableSum){
    table *current = head;
    int tableNum;
    
    //ask for a input of table number which the user want to check the table status of. 0 symbolize to output the information of all tables
    cout << "Please input a table number to show its table information (0 = all tables): ";
    cin >> tableNum;
    cout << endl;
    //check if the input is out of range
    while ((tableNum<0) || (tableNum > tableSum)){
        cout << "Invalid table number. Please input a valid table number (from 0-"<<tableSum << "): ";
        cin >> tableNum;
        cout <<endl;
    }
    
    if (tableNum == 0){
        //start from the head and output all table information until NULL
        while (current != NULL){
            cout << "Table Number: " << current->number<<endl;
            cout << "Table Size: "<< current->size<<endl;
            if (current->availability == false){
                cout << "Table availability: Unoccupied" << endl;
            }else{
                cout << "Table availability: Occupied" << endl;
            }
            current = current->next;
        }
    }else{
        //search for the table number from head and output its table information
        while (current != NULL){
            if (current->number == tableNum){
                cout << "Table Number: " << current->number<<endl;
                cout << "Table Size: "<< current->size<<endl;
                if (current->availability == false){
                    cout << "Table availability: Unoccupied" << endl;
                }else{
                    cout << "Table availability: Occupied" << endl;
                }
                break;
            }else{
                current = current -> next;
            }
        }
    }
}

//the main program
int main(){
    int userInput, numOfSix = 0, numOfFour = 0, numOfTwo = 0, tableSum = 0;
    string tableInfo;
    bool flag = false;
    
    //Ask for the file that stores the table information which indicates the number of 6-person table and 4-person the owner wants to have
    cout << "Input your table information file name: ";
    cin >> tableInfo;
    cout << endl;
    
    //To get the number of tables of 6, 4 and 2-person table, loop until the inputted file exist
    while (flag == false){
        flag = generateTable(tableInfo,&numOfSix,&numOfFour,&numOfTwo);
        if (flag == false){
            cout << "Please input a existing file name: ";
            cin >> tableInfo;
            cout << endl;
        }
    }
    
    tableSum = numOfTwo + numOfSix + numOfFour;
    
    //initialize the table information
    table *head = NULL;
    
    for(int k = 1; k <=numOfTwo; k++){
        appendTable(head, k, 2);
    }
    
    for(int j = numOfTwo+1; j <= numOfTwo+numOfFour; j++){
        appendTable(head, j, 4);
    }
    
    for (int i = numOfTwo+numOfFour+1; i <= numOfSix + numOfTwo + numOfFour; i++){
        appendTable(head, i, 6);
    }


    
    //ask for user input to choose the program functions. Exit the whole program if -1 is inputted
    printMenu(&userInput);
    while (userInput != -1){
        if (userInput == 1){
            checkAvab(head, numOfTwo,numOfFour,numOfSix);
        }else if (userInput == 2){
            occupyTable(head);
        }else if (userInput == 3){
            releaseTable(head, tableSum);
        }else if (userInput == 4){
            tableStatus(head, tableSum);
        }
        printMenu(&userInput);
    }
}

