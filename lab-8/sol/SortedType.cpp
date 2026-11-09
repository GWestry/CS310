#ifndef SORTED_TYPE_CPP
#define SORTED_TYPE_CPP

#include "SortedType.h"
#include <new>

template <class ItemType>
void FindItem(NodeType<ItemType> *listData,
              ItemType item,
              NodeType<ItemType> *&location,
              NodeType<ItemType> *&predLoc,
              bool &found)
{
    bool moreToSearch = true;

    location = listData->next;
    predLoc = listData;
    found = false;

    while (moreToSearch && !found)
    {
        if (item < location->info)
            moreToSearch = false;
        else if (item == location->info)
            found = true;
        else
        {
            predLoc = location;
            location = location->next;
            moreToSearch = (location != listData->next);
        }
    }
}

template <class ItemType>
SortedType<ItemType>::SortedType()
{
    length = 0;
    listData = nullptr;
    currentPos = nullptr;
}

template <class ItemType>
SortedType<ItemType>::~SortedType()
{
    MakeEmpty();
}

template <class ItemType>
bool SortedType<ItemType>::IsFull() const
{
    try
    {
        NodeType<ItemType> *location = new NodeType<ItemType>;
        delete location;
        return false;
    }
    catch (const std::bad_alloc &)
    {
        return true;
    }
}

template <class ItemType>
int SortedType<ItemType>::GetLength() const
{
    return length;
}

template <class ItemType>
bool SortedType<ItemType>::isEmpty()
{
    return length == 0;
}

template <class ItemType>
void SortedType<ItemType>::MakeEmpty()
{
    if (listData == nullptr)
        return;

    NodeType<ItemType> *first = listData->next;
    NodeType<ItemType> *current = first;
    while (current != listData)
    {
        NodeType<ItemType> *next = current->next;
        delete current;
        current = next;
    }

    delete listData;
    listData = nullptr;
    currentPos = nullptr;
    length = 0;
}

template <class ItemType>
ItemType SortedType<ItemType>::GetItem(ItemType item, bool &found)
{
    found = false;
    if (listData == nullptr)
        return item;

    NodeType<ItemType> *location = listData->next;
    do
    {
        if (item == location->info)
        {
            item = location->info;
            found = true;
            return item;
        }
        if (item < location->info)
            return item;
        location = location->next;
    } while (location != listData->next);

    return item;
}

template <class ItemType>
void SortedType<ItemType>::ResetList()
{
    currentPos = listData == nullptr ? nullptr : listData->next;
}

template <class ItemType>
ItemType SortedType<ItemType>::GetNextItem()
{
    ItemType item = currentPos->info;
    currentPos = currentPos->next;
    return item;
}

template <class ItemType>
void SortedType<ItemType>::PutItem(ItemType item)
{
    NodeType<ItemType> *newNode;
    NodeType<ItemType> *predLoc;
    NodeType<ItemType> *location;
    bool found;

    newNode = new NodeType<ItemType>;
    newNode->info = item;
    if (listData != nullptr)
    {
        FindItem(listData, item, location, predLoc, found);
        newNode->next = predLoc->next;
        predLoc->next = newNode;
        if (listData->info < item)
            listData = newNode;
    }
    else
    {
        listData = newNode;
        newNode->next = newNode;
    }
    length++;
}

template <class ItemType>
void SortedType<ItemType>::Delete(ItemType item)
{
    NodeType<ItemType> *location;
    NodeType<ItemType> *predLoc;
    bool found;

    FindItem(listData, item, location, predLoc, found);
    if (predLoc == location)
        listData = nullptr;
    else
    {
        predLoc->next = location->next;
        if (location == listData)
            listData = predLoc;
    }
    delete location;
    length--;
}

template <class ItemType>
void PrintReverseHelper(NodeType<ItemType> *current,
                        NodeType<ItemType> *first)
{
    if (current->next != first)
        PrintReverseHelper(current->next, first);
    std::cout << current->info << ' ';
}

template <class ItemType>
void SortedType<ItemType>::PrintReverse() const
{
    if (listData == nullptr)
    {
        std::cout << "List is empty. No items to print." << std::endl;
        return;
    }

    NodeType<ItemType> *next = listData->next;
    PrintReverseHelper(next, next);
    std::cout << '\n';
}

#endif
