#include <cstdlib>
#include <ctime>
#include <iostream>

#include "unsorted.h"

void PrintList(UnsortedType &list)
{
    list.ResetList();
    for (int count = 0; count < list.GetLength(); count++)
    {
        list.GetNextItem().Print(std::cout);
        std::cout << ' ';
    }
    std::cout << std::endl;
}

int main()
{
    srand(static_cast<unsigned>(time(nullptr)));

    UnsortedType list;
    ItemType item;
    int randomPoint = 1 + rand() % 50;

    std::cout << "Empty: ";
    PrintList(list);

    for (int count = 1; count <= 50; count++)
    {
        item.Initialize(1 + rand() % 100);
        list.PutItem(item);
        if (count == randomPoint)
        {
            std::cout << "Random point: ";
            PrintList(list);
            std::cout << "Head: ";
            list.Head().Print(std::cout);
            std::cout << std::endl
                      << "Tail: ";
            UnsortedType tail = list.Tail();
            PrintList(tail);
        }
    }

    std::cout << "Full: ";
    PrintList(list);
    std::cout << "Head: ";
    list.Head().Print(std::cout);
    std::cout << std::endl;
    std::cout << "Tail: ";
    UnsortedType tail = list.Tail();
    PrintList(tail);
}