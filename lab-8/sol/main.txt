#include "SortedType.h"

template <class ItemType>
void TestList(const char *name, ItemType first, ItemType second, ItemType third)
{
    SortedType<ItemType> list;
    list.PutItem(first);
    list.PutItem(second);
    list.PutItem(third);

    std::cout << name << ": ";
    list.PrintReverse();
}

int main()
{
    TestList<int>("int", 3, 1, 2);
    TestList<double>("double", 3.3, 1.1, 2.2);
    TestList<char>("char", 'C', 'A', 'B');
}