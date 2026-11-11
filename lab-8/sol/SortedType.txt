#ifndef SORTED_TYPE_H
#define SORTED_TYPE_H

#include <iostream>


template <class ItemType>
struct NodeType
{
    ItemType info;
    NodeType *next;
};

template <class ItemType>
class SortedType
{

public:
    SortedType();
    ~SortedType();

    bool IsFull() const;
    int GetLength() const;
    bool isEmpty();
    void MakeEmpty();
    ItemType GetItem(ItemType item, bool &found);
    void ResetList();
    ItemType GetNextItem();
    void PutItem(ItemType item);
    void Delete(ItemType item);
    void PrintReverse() const;

private:
    NodeType<ItemType> *listData;
    int length;
    NodeType<ItemType> *currentPos;
};

#include "SortedType.cpp"

#endif