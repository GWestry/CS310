#include "UnsortedList.h"
#include <iostream>
using namespace std;

int main(){
    UnsortedList list;
    list.PutItem(ItemType(6));
    list.PutItem(ItemType(16));
    list.PutItem(ItemType(2));

    list.Display();
    list.DeleteItem(16);

    list.Display();
    list.DeleteItem(7);

    list.Display();
    list.DeleteItem(2);

    list.Display();
}