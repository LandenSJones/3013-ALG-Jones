#include <iostream>

using namespace std;

/**
 * Class Heap
 *
 * @methods:
 *      constructors:
 *          Heap        : default constructor
 *          Heap(int)   : overload constructor with heap size
 *      private:
 *          BubbleUp    : This puts one value into its proper place in the heap
 *          Left        : Calculates index of left child.
 *          Right       : Calculates index of right child.
 *          Parent      : Calculates parent of a given index.
 *          OnHeap      : Checks if an index is on the array (past the end).
 *          Swap        : Swaps to values in the heap
 *          SinkDown    : you comment this
 *          PickChild   : If one child exists, return it. Otherwise, return the smaller of the two.
 *      public:
 *          Heapify     : Takes an unsorted array and places it in min heap order
 *          Insert      : Add a value to the heap.
 *          Print       : For test our heap !!! Prints data
 *          Remove      : Removes item from top of heap
 */
class Heap {
private:
    int size; // size of the array
    int* H;   // array pointer
    int end;  // 1 past last item in array

    /**
     * Left
     * @description:
     *      Calculates index of left child.
     *
     * @param  {int} index : index of parent
     * @return {int}       : index of left child
     */
    int Left(int index) {
        return 2 * index;
    }

    /**
     * Right
     * @description:
     *      Calculates index of right child.
     *
     * @param  {int} index : index of parent
     * @return {int}       : index of right child
     */
    int Right(int index) {
        return 2 * index + 1;
    }

    /**
     * Parent
     * @description:
     *      Calculates parent of a given index.
     *
     * @param  {int} index : index to check
     * @return {int}       : parent index
     */
    int Parent(int index) {
        return index / 2;
    }

    /**
     * OnHeap
     * @description:
     *      Checks if an index is on the array (past the end).
     *
     * @param  {int} index : index to check
     * @return {bool}      : 0 = off heap / 1 = on heap
     */
    bool OnHeap(int index) {
        return index < end;
    }

    /**
     * BubbleUp
     *
     * @description:
     *    This puts one value into its proper
     *    place in the heap.
     *
     * @param  {int} index : index to start bubbling at
     * @return             : void
     */
    void BubbleUp(int index) {
        // check parent is not of beginning of array
        if (Parent(index) >= 1) {
            // index is on array and value is less than parent
            while (index > 1 && H[index] < H[Parent(index)]) {
                // do a swap
                Swap(index, Parent(index));

                // update index to values new position
                index = Parent(index);
            }
        }
    }

    /**
     * Swap
     *
     * @description:
     *      Swaps to values in the heap
     *
     * @param  {int} i  : index in array
     * @param  {int} j  : index in array
     * @return          : void
     */
    void Swap(int i, int j) {
        int temp = H[i];
        H[i] = H[j];
        H[j] = temp;
    }

    ////////////////////////////
    //Fix These Methods
    ////////////////////////////

    /**
     *
     * @description:
     *      Takes an unsorted array and places it in min heap order
     *
     * @param  {int*} A   :  array pointer with unsorted values to make into a heap
     * @param  {int} size :  size of new heap
     */
    void Heapify(int *A, int size) {
        //assume swapped for the first iteration
        bool swapped = 1;
        while (swapped == 1)
        {
            swapped = 0;
            for (int i = 1; i < size / 2; i++)
            {
                SinkDown(i);
            }
        }
    }

    /**
     * SinkDown
     * @description:
     *      Places one heap item into its proper place in the heap
     *      by bubbling it down to it proper location.
     *
     * @param  {int} index  : index to start from in the array
     * @return              : void
     */
    void SinkDown(int index) {
        PickChild(index);
    }

    /**
     * PickChild
     * @description:
     *      If one child exists, return it. 
     *      Otherwise, return the smaller of the two.
     *
     * @param  {int} index  : index of parent in the array
     * @return              : index to child
     */
    int PickChild(int index) {
        if (end % 2 == 1) {
            // no right child
            return Left(index);
        }
        else {
            // got two children
            if (Right(index) < end) {
                if (H[Right(index)] > H[Left(index)]) {
                    return Left(index);
                }
                else {
                    return Right(index);
                }
            }
        }
    }

public:
    /**
     * Heap constructor
     */
    Heap() {
        size = 100;
        H = new int[size];
        end = 1;
    }

    /**
     * Heap constructor
     *
     * @param  {int} s : heap size
     */
    Heap(int s) {
        size = s;
        H = new int[s];
        end = 1;
    }

    /**
   * Insert
   *
   * @description:
   *        Add a value to the heap.
   *
   * @param  {int} x : value to Insert
   * @return         : void
   */
    void Insert(int x) {
        H[end] = x;
        BubbleUp(end);
        end++;
    }

    /**
    * Print
     * @description:
     *      For test our heap !!! Prints heap in nice format
     *
     *@return void
     */
    void Print() {
        for (int i = 1; i <= end - 1; i++) {
            cout << H[i];
            if (i < end - 1) {
                cout << "->";
            }
        }
    }

    /**
     * Remove
     * @description:
     *      Removes item from top of heap
     *
     * @return {int}  : top of heap
     */
    int Remove() {
        int temp = H[1];
        H[1] = H[end];
        --end;

        return temp;
    }
};

int main() {
    Heap H;

    H.Insert(17);
    H.Insert(11);

    for (int i = 2; i <= 10; i++) {
        H.Insert(i);
    }

    H.Print();
    cout << endl << H.Remove() << endl;
    H.Print();
    cout << endl << H.Remove() << endl;
}
