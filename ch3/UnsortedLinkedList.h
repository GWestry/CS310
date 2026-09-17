#include "itemType.h"
#include <iostream>

using namespace std;

struct NodeType
{
    ItemType data;
    NodeType *next = nullptr;
};

class UnsortedLinkedList
{
private:
    NodeType* head;
    int length;
    NodeType* currPos;

public:

    UnsortedLinkedList::UnsortedLinkedList()
        : head(nullptr), length(0), currPos(nullptr) {
          };
    
    ~UnsortedLinkedList()
    {
        NodeType* temp;
        while(head != nullptr){
            temp = head;
            head = head->next;
            delete temp;
        }
    }
    void PutItem(ItemType item)
    {
        NodeType *newNode = new NodeType;
        newNode->data = item;
        newNode->next = head;
        head = newNode;
        length++;
    }

    void DeleteItem(ItemType item){
        //search/find the items location

        NodeType* targetNode = head;
        NodeType* tempLocation;
        //if we are deleting first node
        if(targetNode != nullptr && targetNode->data.CompareTo(item) == 0){
            tempLocation = targetNode;
            head = head->next;
        }else{
            //if we are deleting a node in the middle/end
            while(targetNode!=nullptr && 
                targetNode->next != nullptr
                && targetNode->next->data.CompareTo(item) != 0){
                    targetNode = targetNode->next;
                }
            
            if(targetNode!=nullptr && targetNode->next!= nullptr){
                tempLocation = targetNode->next;
                targetNode->next = tempLocation->next;
            }else{
                return;
            }

            delete tempLocation;
            return;

        }
        //remove from the list
    }
};
