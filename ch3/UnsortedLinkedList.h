#include "itemType.h"
#include <iostream>
using namespace std;

const int MAX_ITEMS = 100;

class UnsortedList{

    private:
        ItemType *data;
        int length;
        int currPos;
        int capacity;
    
    public:
        UnsortedList(): length(0), currPos(-1){
             capacity = MAX_ITEMS;
             data = new ItemType[capacity];
        }

        ~UnsortedList(){
            delete[] data;
        }

        UnsortedList(int c){
            capacity = c;
            length = 0;
            currPos = -1;
            data = new ItemType[capacity];
        }

        bool IsFull() const{
            return length == MAX_ITEMS;
        }

        int Length()const{
            return length;
        }

        void PutItem(ItemType item){
            if (!IsFull()){
                //data[length++] = item;
                //expanded version below
                data[length] = item;
                length++;
            }
        }

        void DeleteItem(ItemType item){
            for (int i = 0; i < length; i++){
                if(data[i].CompareTo(item) == 0){
                    data[i] = data[--length];
                    return;
                }
            }
        }

        void Display(){
            for (int i = 0; i < length; i++){
            cout << "List["<<(i+1)<<"]: " << data[i].key << endl;
    }
        }
};