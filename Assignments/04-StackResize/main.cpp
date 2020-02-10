/*
 
  /$$$$$$$   /$$$$$$    /$$                        
 | $$__  $$ /$$$_  $$ /$$$$                        
 | $$  \ $$| $$$$\ $$|_  $$                        
 | $$$$$$$/| $$ $$ $$  | $$                        
 | $$____/ | $$\ $$$$  | $$                        
 | $$      | $$ \ $$$  | $$                        
 | $$      |  $$$$$$/ /$$$$$$                      
 |__/       \______/ |______/                      
                                                   
                                                   
                                                   
   /$$$$$$   /$$$$$$    /$$    /$$$$$$             
  /$$__  $$ /$$$_  $$ /$$$$   /$$__  $$            
 |__/  \ $$| $$$$\ $$|_  $$  |__/  \ $$            
    /$$$$$/| $$ $$ $$  | $$     /$$$$$/            
   |___  $$| $$\ $$$$  | $$    |___  $$            
  /$$  \ $$| $$ \ $$$  | $$   /$$  \ $$            
 |  $$$$$$/|  $$$$$$/ /$$$$$$|  $$$$$$/            
  \______/  \______/ |______/ \______/             
                                                   
                                                   
                                                   
     /$$$$$                                        
    |__  $$                                        
       | $$  /$$$$$$  /$$$$$$$   /$$$$$$   /$$$$$$$
       | $$ /$$__  $$| $$__  $$ /$$__  $$ /$$_____/
  /$$  | $$| $$  \ $$| $$  \ $$| $$$$$$$$|  $$$$$$ 
 | $$  | $$| $$  | $$| $$  | $$| $$_____/ \____  $$
 |  $$$$$$/|  $$$$$$/| $$  | $$|  $$$$$$$ /$$$$$$$/
  \______/  \______/ |__/  |__/ \_______/|_______/ 
                                                   
                                                   
                                                   
 
*/
///////////////////////////////////////////////////////////////////////////////
//
// Author:           Landen Jones
// Email:            LandenSJones@yahoo.com
// Label:            P01
// Title:            Assignment 4 - Resizing the Stack
// Course:           3013
// Semester:         Spring 2020
//
// Description:
//       This program takes a dynamically allocated array which grows and shrinks
//       based upon how many values are in the array. 
//
// Usage:
//       
//
// Files:            
//                   main.cpp    : driver program
//                   nums.dat    : contains data in integer format of unspecified amount
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
using namespace std;

/**
 * ArrayStack
 *
 * Description:
 *      Array based stack
 *
 * Public Methods:
 *      ArrayStack(int s)               -parameterized constructor
 *      bool Empty()                    -checks if list has elements
 *      bool Full()                     -checks to see if list is full
 *      void Print(ofstream& outfile)   -prints list elements in order
 *      void Push(int x)                -pushes value onto the stack
 *      void Pop()                      -pops value from the stack
 *      void ContainerGrow()            -grows list if list is full when pushing
 *      void ContainerShrink()          -shrinks list if not empty and capacity is less than half
 *      int NumResized()                -returns number of times list was resized
 *      int PrintTop()                  -prints top value
 *      int PrintSize()                 -prints number of elements in list
 *
 * Usage:
 *      - See main program
 *
 */
class ArrayStack
{
private:
    int* A;   // pointer to array of int's
    int size; // current max stack size
    int top;  // top of stack
    int numResize; //used to keep track of how many times list is resized
    int maxStackSize; //used to keep track of the largest size 
public:
    /**
    * ArrayStack
    *
    * Description:
    *      Constructor no params
    *
    * Params:
    *     - None
    *
    * Returns:
    *     - NULL
    */
    ArrayStack()
    {
        size = 10;          //inital size 10 for default
        A = new int[size];  //allocate space for array
        top = -1;           //empty means top is -1
        numResize = 0;      //used to count number of times the stack is resized
        maxStackSize = size;//used to remember what maximum size of stack overall is
    }
    /**
    * ArrayStack
    *
    * Description:
    *      Constructor size param
    *
    * Params:
    *     - int size
    *
    * Returns:
    *     - NULL
    */
    ArrayStack(int s)
    {
        size = s;           //inital size is passed by param
        A = new int[s];     //allocate space for array
        top = -1;           //defualt is -1
        numResize = 0;      //initally hasn't been resized
        maxStackSize = size;//in case size never exceeds original size
    }
    /**
    * Public bool: Empty
    *
    * Description:
    *      Checks to see if stack is empty
    *
    * Params:
    *      NULL
    *
    * Returns:
    *      [bool] true = empty
    */
    bool Empty()
    {
        return (top <= -1);
    }
    /**
    * Public bool: Full
    *
    * Description:
    *      Checks to see if stack is full
    *
    * Params:
    *      NULL
    *
    * Returns:
    *      [bool] true = full
    */
    bool Full()
    {
        return (top >= size - 1);
    }
    /**
    * Public void: Print
    *
    * Description:
    *      Prints stack to standard output
    *
    * Params:
    *      ofstream: output file name
    *
    * Returns:
    *      NULL
    */
    void Print(ofstream& outfile)
    {
        for (int i = 0; i <= top; i++)
        {
            outfile << A[i] << " ";
        }
        outfile << endl;
    }
    /**
    * Public void: Push
    *
    * Description:
    *      Adds an item to top of stack
    *
    * Params:
    *      [int] : item to be added
    *
    * Returns:
    *      NULL
    */
    void Push(int x)
    {
        if (Full())
        {
            ContainerGrow();
        }
        if (!Full())
        {
            A[++top] = x;
        }
    }
    /**
    * Public int: Pop
    *
    * Description:
    *      Returns top value and removes it from stack
    *
    * Params:
    *      NULL
    *
    * Returns:
    *      [int] top value if any
    */
    int Pop()
    {
        if (Empty())
        {
            return -200; //sentinel value, don't really care about what is returned anyway
        }
        else
        {
            if (top < (size / 2) && (size >= 20))
                ContainerShrink(); //shrinks if capacity is half empty
            return top--;   //returns top
        }
    }
    /**
    * Public void: ContainerGrow
    *
    * Description:
    *      Resizes the container for the stack by multiplying its capacity by 1.75
    *
    * Params:
    *      NULL
    *
    * Returns:
    *      NULL
    */
    void ContainerGrow()
    {
        int newSize = size * 1.75; // 1.75size of original
        if (newSize > maxStackSize) //checks to see if max size needs to updated
            maxStackSize = newSize;
        int* B = new int[newSize]; // allocate new memory
        for (int i = 0; i < size; i++)
        { // copy values to new array
            B[i] = A[i];
        }
        delete[] A;     // delete old array
        size = newSize; // save new size
        A = B;          // reset array pointer
        numResize++;
    }
    /**
    * Public void: ContainerShrink
    *
    * Description:
    *      Resizes the container for the stack by multiplying its capacity by 0.50
    *
    * Params:
    *      NULL
    *
    * Returns:
    *      NULL
    */
    void ContainerShrink()
    {
        int newSize = (size * 0.5);  // half size of original
        int* B = new int[newSize]; // allocate new memory
        for (int i = 0; i < top; i++)
        { // copy values to new array
            B[i] = A[i];
        }
        delete[] A;     // delete old array
        size = newSize; // save new size
        A = B;          // reset array pointer
        numResize++;
    }
    /**
    * Public int: NumResized
    *
    * Description:
    *      getter for numresized
    *
    * Params:
    *      NULL
    *
    * Returns:
    *      int: numResize
    */
    int NumResized()
    {
        return numResize;
    }
    /**
    * Public int: PrintTop
    *
    * Description:
    *      Prints index of top
    *
    * Params:
    *      NULL
    *
    * Returns:
    *      [int]: Index of top
    */
    int PrintTop()
    {
        return top;
    }
    /**
    * Public int: PrintSize
    *
    * Description:
    *      returns number of times the stack was resized
    *
    * Params:
    *      NULL
    *
    * Returns:
    *      [int] Value of Size
    */
    int PrintSize()
    {
        return size;
    }
    /**
    * Public int: Max
    *
    * Description:
    *      returns maximum size that the stack has been
    *
    * Params:
    *      NULL
    *
    * Returns:
    *      NULL
    */
    int Max()
    {
        return maxStackSize;
    }
};

// MAIN DRIVER
int main()
{
    ArrayStack stack;       //object initialization
    int r = 0;              //int used to hold the read integer
    ifstream infile;        //infile stream
    infile.open("nums_test.dat");//hardcoded but can be removed if unknown before run
    ofstream outfile;            //output file
    outfile.open("output.dat");     //opening output file
    while (!infile.eof())
    {
        infile >> r;
        if (r % 2 == 0)   //if even, push
            stack.Push(r);
        else            //if odd, pop
            stack.Pop();
    }
    //Desired output
    outfile << "######################################################################\n";
    outfile << "\tAssignment 4 - Resizing the Stack\n\tCMPS 3013\n\tLanden Jones\n\n";
    outfile << "\tMax Stack Size: " << stack.Max() << '\n';
    outfile << "\tEnd Stack Size: " << stack.PrintSize() << '\n';
    outfile << "\tStack Resized: " << stack.NumResized() << "\n\n";
    outfile << "######################################################################\n";
    return 0;
}
