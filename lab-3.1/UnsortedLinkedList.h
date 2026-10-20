#include <iostream>

template <typename T>
struct NodeType
{
    T data;
    NodeType *next;

    NodeType(const T &value) : data(value), next(nullptr) {}
};

template <typename T>
class UnsortedLinkedList
{
protected:
    NodeType<T> *head;
    int length;
    NodeType<T> *currPos;

public:
    UnsortedLinkedList()
        : head(nullptr), length(0), currPos(nullptr)
    {
    }

    virtual ~UnsortedLinkedList()
    {
        NodeType<T> *temp;
        while (head != nullptr)
        {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
    void PutItem(const T &item)
    {
        NodeType<T> *newNode = new NodeType<T>(item);
        newNode->next = head;
        head = newNode;
        length++;
    }

    void DeleteItem(const T &item)
    {
        // search/find the items location

        NodeType<T> *targetNode = head;
        NodeType<T> *tempLocation;
        // if we are deleting first node
        if (targetNode != nullptr && targetNode->data.CompareTo(item) == 0)
        {
            tempLocation = targetNode;
            head = head->next;
        }
        else
        {
            // if we are deleting a node in the middle/end
            while (targetNode != nullptr &&
                   targetNode->next != nullptr && targetNode->next->data.CompareTo(item) != 0)
            {
                targetNode = targetNode->next;
            }

            if (targetNode != nullptr && targetNode->next != nullptr)
            {
                tempLocation = targetNode->next;
                targetNode->next = tempLocation->next;
            }
            else
            {
                return;
            }

            delete tempLocation;
            length--;
            return;
        }
        delete tempLocation;
        length--;
    }

    int Length() const
    {
        return length;
    }

    void ResetList()
    {
        currPos = nullptr;
    }

    T *GetNextItem()
    {
        if (currPos == nullptr)
            currPos = head;
        else
            currPos = currPos->next;

        if (currPos == nullptr)
            return nullptr;

        return &currPos->data;
    }
};
