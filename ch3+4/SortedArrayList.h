#include "itemType.h"
#include <iostream>
using namespace std;

const int MAX_ITEMS = 100;

class SortedArrayList{

    private:
        ItemType *data;
        int length;
        int currPos;
        int capacity;
    
    public:
        SortedArrayList(): length(0), currPos(-1)
        {
            capacity = MAX_ITEMS;
            data = new ItemType[capacity];
        }

        ~SortedArrayList(){
            delete[] data;
        }

        SortedArrayList(int c){
            capacity = c;
            data = new ItemType[capacity];
            length = 0;
            currPos = -1;
        }

        bool IsFull() const{
            return length == capacity;
        }

        int Length()const{
            return length;
        }

        void PutItem(ItemType item){
            if (IsFull()){
                return;
            }

            // find the position to insert the new item
            currPos = 0;
            while (currPos < length && data[currPos].CompareTo(item) < 0){
                currPos++;
            }
            // Shift elements to the right to make space for the new item
            for (int i = length; i > currPos; i--){
                data[i] = data[i-1];
            }
            // Insert the new item at the correct position
            data[currPos] = item;

            // Increment the length of the list
            length++;
        }

        void DeleteItem(ItemType item){
            if (Length() == 0){
                return;
            }

            currPos = 0;
            while (currPos < length && data[currPos].CompareTo(item) < 0){
                currPos++;
            }

            for (int i = currPos + 1; i < length; i++){
                data[i - 1] = data[i];
            }
            length--;
        }

        ItemType GetItem(ItemType item, bool& found){

            int low = 0;
            int high = length - 1;
            found = false;
            int midpoint;

            while( !found && low <= high){
                midpoint = (low + high) / 2;
                
                if(data[midpoint].CompareTo(item) == 0){
                    found = true;
                    item = data[midpoint];
                }
                else if(data[midpoint].CompareTo(item) == -1){
                    low = midpoint + 1;
                }
                else if(data[midpoint].CompareTo(item) == 1){
                    high = midpoint - 1;
                }


            }
            return item;

        }

        void Display(){
            for (int i = 0; i < length; i++){
            cout << "List["<<(i+1)<<"]: " << data[i].key << endl;
    }
        }
};