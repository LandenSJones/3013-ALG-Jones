///////////////////////////////////////////////////////////////////////////////
//                   
// Author:           Landen Jones
// Email:            landensjones@yahoo.com
// Label:            AO2
// Title:            Commenting Assignment
// Course:           CMPS-3013
// Semester:         Spring 2020
//
// Description:
//       This program creates two linked lists and sets the values to integer values. This program uses basic operations
//       like addition and grabbing the value from a designated node in the list. This programs main focus is to practice good commenting
//       practice.
//
// Usage:
//       
//
// Files:            
//                   main.cpp    : driver program
/////////////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

int A[100];                     //Declaration of an array of 100 integers


/**
 * Node
 * 
 * Description:
 *      This is a node that contains an integer value and a pointer to another node
 * 
 * Public Methods:
 *                      Node()
 *                      Node(int n)
 * 
 * Private Methods:
 * 
 * Usage: 
 * 
 *      node1 Node();           //Creates an instance of your node
 *      
 */
struct Node {               
    int x;                  
    Node *next;
    /**
     * Public : Node()
     * 
     * Description:
     *      Default constructor for a Node structure
     * 
     * Params: 
     *      NONE
     * 
     * Returns:
     *      Created a node with value -1 and pointer to Null
     */
    Node() {                
        x = -1;
        next = NULL;
    }
    /**
     * Public : Node(int n)
     * 
     * Description:
     *      Parameterized constructor for Node
     * 
     * Params:
     *      int     : value to be stored in node
     * 
     * Returns:
     *      Node    : Created a node with a value inside of it and pointer Null
     */
    Node(int n) {
        x = n;
        next = NULL;
    }
};

/**
 * List
 * 
 * Description:
 *      This is a list that contains any amount of nodes linked together 
 * 
 * Public Methods:
 *                  List()
 *      void        Push(int val)
 *      void        Insert(int val)
 *      void        PrintTail()
 *      string      Print()
 *      int         Pop()
 *      List        operator+(const List &Rhs)
 *      int         operator[](int index)
 *      friend ostream &operator<<(ostream &os, List L)      
 *
 * Private Methods:
 * 
 * Usage: 
 * 
 *      L1 List();          //Creates an Instance of List class
 *      L1.Push(19);        //Pushes the value 19 to the end of the list
 *      L1.Insert(20);      //Creates a new node with the value 20 and places it at the beginning of the list
 *      L1.PrintTail();     //Prints the last value in the linked list
 *      L1.Print();         //Creates a string with all of the values of the list and prints them out like "1->2->3->2"
 *      L1.Pop();           //Reduces size by one 
 *      L1 = L1 + L2;       //Adds the values of both lists node by node and returns a new list with the combined values
 *      int x = L1[15];     //Takes the nth value of the list and stores in an integer value like x will be set the the value in the 15th node
 *      cout << L1;         //Prints values of the list in a nice fashion
 */
class List {                //List class
private:
    Node *Head;             //Contains a pointer to the beginning of the list
    Node *Tail;             //                        and the end of the list
    int Size;

public:
    /**
     * Public : List()
     * 
     * Description:
     *      Creates an empty list
     * 
     * Params:
     *      NONE
     * 
     * Returns:
     *      List   : Empty List with size 0 and head/tail pointers set to NULL
     */
    List() {
        Head = Tail = NULL; //Sets head and tail pointer to null
        Size = 0;           //sets size equal to 0
    }
    
    /**
     * Public : Push(int val)
     * 
     * Description:
     *      Creates a new node with a value and places it on the end of the list and increments size
     * 
     * Params:
     *      int     :  value to be stored in the node
     * 
     * Returns:
     *      NONE
     */
    void Push(int val) {
        Node *Temp = new Node(val);                 // allocate new memory and init node

        if (!Head && !Tail) {       //if head and tail are set to null then set head and tail to the new node
            Head = Tail = Temp;
        } else {
            Tail->next = Temp;      //the list is not empty then add the new node to the new node
            Tail = Temp;            //increments the size of the list
        }
        Size++;
    }
        /**
     * Public : Insert(int val)
     * 
     * Description:
     *      Creates a new node with a value and places it at the beginning of the list and increments the size
     * 
     * Params:
     *      int     :  value to be stored in the node
     * 
     * Returns:
     *      NONE
     */
    void Insert(int val) {
        // allocate new memory and init node
        Node *Temp = new Node(val);

        // figure out where it goes in the list

        Temp->next = Head;     //places new node at the head of the list and changes new node to point to the old head node
        Head = Temp;
        if (!Tail) {           //if list is empty then set head and tail to the new node
            Tail = Head;
        }
        Size++;                 //increments size of the list
    }

     /**
     * Public : PrintTail()
     * 
     * Description:
     *      Prints the last value of the list to the screen
     * 
     * Params:
     *      None
     * 
     * Returns:
     *             : last value of the linked list
     */
    void PrintTail() {
        cout << Tail->x << endl;        //prints last int value in the list
    }
    
     /**
     * Public : Print()
     * 
     * Description:
     *      takes all the values in the linked list and puts them into a string
     * 
     * Params:
     *      NONE
     * 
     * Returns:
     *              : prints the list of all the values in the linked list
     */
    string Print() {
        Node *Temp = Head;      //temporary node to be used as an index
        string list;            //string to hold the desired printable string

        while (Temp != NULL) {                  //while list isn't empty
            list += to_string(Temp->x) + "->";  //add the value to the string    
            Temp = Temp->next;                  //progress through the list to next value
        }

        return list;     //returns list of values in string format
    }

    
    /**
    * Public : Pop()
    * 
    * Description:
    *      Not implemented, reduces size by 1
    * 
    * Params:
    *      None
    * 
    * Returns:
    *      int   : 0 (in the future will return value of item popped)
    */
    // not implemented
    int Pop() {
        Size--; //decrements size
        return 0; //returns 0, function isn't complete
    }
    
    /**
    * Public : operator+
    * 
    * Description:
    *      Adds the second list in order after the first list in a new list
    * 
    * Params:
    *      List :   (List)
    * 
    * Returns:
    *      List  : Combined values of both lists in a new list(but not adding individual values)
    */
    
    List operator+(const List &Rhs) {  
        // Create a new list that will contain both when done
        List NewList;   //initialize new empty list for the return

        // Get a reference to beginning of local list
        Node *Temp = Head;  //new node to start at the beginning of the list

        // Loop through local list and Push values onto new list
        while (Temp != NULL) {  //if the has something in it
            NewList.Push(Temp->x);      //this code copies the first list into the new list
            Temp = Temp->next;          //next node in list
        }

        // Get a reference to head of Rhs
        Temp = Rhs.Head;    //now use temp node we used in first list to do the same thing in second list

        // Same as above, loop and push
        while (Temp != NULL) {      //while list has something in it
            NewList.Push(Temp->x);  //push the value of the second list nodes on the the new list, which already has the first list in
            Temp = Temp->next;      //next node in the list
        }

        // Return new concatenated version of lists
        return NewList;
    }

    /**
    * Public : operator[]
    * 
    * Description:
    *      Gets the value of an integer from one of the nodes in the list
    * 
    * Params:
    *      int value to specify which node you want the value of
    * 
    * Returns:
    *      int:     value in the node you want
    */


    // Implementation of [] operator.  This function returns an
    // int value as if the list were an array.
    int operator[](int index) {
        Node *Temp = Head;      //new node to use for getting values from list

        if (index >= Size) {    //checks to see if it is out of bounds
            cout << "Index out of bounds, exiting";
            exit(0);
        } else {   
            //Traverses list to the desired index
            for (int i = 0; i < index; i++) {
                Temp = Temp->next; //gets value of the node
            }
            return Temp->x; //retuns desired value
        }
    }

    friend ostream &operator<<(ostream &os, List L) {
        os << L.Print(); //calls print member function to get the string
        return os;       //outputs string of the values
    }
};

int main(int argc, char **argv) {
    List L1;    //Used for list 1
    List L2;    //Used for list 2
    
    //creates 25 values in list 1 of values 0-24
    for (int i = 0; i < 25; i++) {
        L1.Push(i);
    }

    //creates 50 values in list 2 of values 50-99
    for (int i = 50; i < 100; i++) {
        L2.Push(i);
    }

    //cout << L1 << endl;
    L1.PrintTail(); //prints last value in L1  
    L2.PrintTail(); //prints last value in L2

    List L3 = L1 + L2; //concatinates L1 and L2
    cout << L3 << endl;//prints new concatinated list

    cout << L3[5] << endl;  //prints the 5th index of the L3    
    return 0;
}
