#include <iostream>
#include <queue>
#include <string>
#include <fstream>
using namespace std;
void Input(queue<int>& left, queue<int>& right, ifstream& infile, bool* sideOrder, int* numberOrder, int* result);
bool StillData(queue<int> left, queue<int> right);
bool BoatNeedsToMove(queue<int> left, queue<int> right, int cTime);
bool Carry(queue<int> left, queue<int> right, int cTime, bool boatSide);
void CarryRight2Left(queue<int>& right, bool& boatSide, int cap, int& cTime, int tTime, bool* sideOrder, int* numberOrder, int* result);
void CarryLeft2Right(queue<int>& left, bool& boatSide, int cap, int& cTime, int tTime, bool* sideOrder, int* numberOrder, int* result);
void TravelEmpty(bool& boatSide);
int main() 
{
    ifstream infile;
    infile.open("input.txt");
    int iterations;
    infile >> iterations;
    while (iterations--)
    {
        bool boatSide = 0;                                                      //boatSide = 0; means left. = 1 means right.
        int cap, tripT, cTime = 0;                                              //int for the capacity of the boat and tripT for the time it takes for the ferry to deliver, cTime is currentTime
        infile >> cap >> tripT;                                                 
        queue<int> left, right;                                                 //queues to hold the waiting cars on both sides of the banks
        int* numberOrder, *result;                                               //used to hold the original order of the input, result will hold final times
        bool* sideOrder;
        Input(left, right, infile, sideOrder, numberOrder, result);
        while (StillData(left, right))
        {
            if (BoatNeedsToMove(left, right, cTime))
            {
                if(Carry(left, right, cTime, boatSide))
                {
                    if (boatSide)
                        CarryRight2Left(right, boatSide, cap, cTime, tripT, sideOrder, numberOrder, result);
                    else
                        CarryLeft2Right(left, boatSide, cap, cTime, tripT, sideOrder, numberOrder, result);
                }
                else
                {
                    TravelEmpty(boatSide);
                    cTime += tripT;                                             //Time to cross elapsed
                }
            }
            else
                cTime++;
        }
        cout << '\n';
    }
    return 0;
}

//Funtion will read all of the data and fill the sides up with the relevant data
void Input(queue<int>& left, queue<int>& right, ifstream& infile, bool* sideOrder, int* numberOrder, int* result)
{
    int temp, size;
    infile >> size;
    result = new int[size];
    for (int i = 0; i < size; i++)
    {
        result[i] = -1;
    }
    numberOrder = new int[size];
    sideOrder = new bool[size];
    string side;
    for (int i = 0; i < size; i++)
    {
        infile >> temp >> side;
        numberOrder[i] = temp;
        
        if (side == "left")
        {
            sideOrder[i] = 0;
            left.push(temp);
        }
        else
        {
            right.push(temp);
            sideOrder[i] = 1;
        }
    }
}

//Returns true if there is any more data to be processed
bool StillData(queue<int> left, queue<int> right)
{
    return (!left.empty() || !right.empty());
}

//Returns true if there is a car that is currently waiting for the boat. otherwise returns false
bool BoatNeedsToMove(queue<int> left, queue<int> right, int cTime)
{
    if (!left.empty())
    {
        if (left.front() <= cTime)
            return true;
    }    
    if (!right.empty())
    {
        if (right.front() <= cTime)
            return true;
    }
    return false;
}
//Returns true if there is a car waiting on the side that the boat is on
bool Carry(queue<int> left, queue<int> right, int cTime, bool boatSide)
{
    if(!boatSide)               //If boat is on left side
    {
        if (!left.empty())      //If left side has data
        {
            if (left.front() <= cTime)
            {
                return true;
            }
        }
    }
    else                        //If boat is on the right side
    {
        if (!right.empty())      //If right side has data
        {
            if (right.front() <= cTime)
            {
                return true;
            }
        }
    }
    return false;
}

//Moves the boat from one side to the other
void TravelEmpty(bool& boatSide)
{
    if (boatSide)
        boatSide = false;
    else
        boatSide = true;
}

void CarryLeft2Right(queue<int>& left, bool& boatSide, int cap, int& cTime, int tTime, bool* sideOrder, int* numberOrder, int* result)
{
    if (left.size() > cap)
    {
        for (int i = 0; i < cap; i++)
        {
            if (left.front() <= cTime)
            {
                //HAVE TO CHANGE THIS FROM THIS TO PLACING RESULT IN RESULT

                cout << left.front() + tTime << '\n';
                left.pop();
            }
        }
    }
    else
    {
        for (int i = 0; i < left.size(); i++)
        {
            if (left.front() <= cTime)
            {
                cout << left.front() + tTime << '\n';
                left.pop();
            }
        }
    }
    cTime += tTime;
    boatSide = true;                                                //Move boat to other side
}

void CarryRight2Left(queue<int>& right, bool& boatSide, int cap, int& cTime, int tTime, bool* sideOrder, int* numberOrder, int* result)
{
    if (right.size() > cap)
    {
        for (int i = 0; i < cap; i++)
        {
            if (right.front() <= cTime)
            {
                cout << right.front() + tTime << '\n';
                right.pop();
            }
        }
    }
    else
    {
        for (int i = 0; i < right.size(); i++)
        {
            if (right.front() <= cTime)
            {
                cout << right.front() + tTime << '\n';
                right.pop();
            }
        }
    }
    cTime += tTime;
    boatSide = false;                                                //Move boat to other side
}
