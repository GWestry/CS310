#include "itemType.h"
#include <iostream>

using namespace std;

struct NodeType
{
    ItemType data;
    NodeType *next = nullptr;
};

class SortedLinkedList
{
private:
    NodeType* head;
    int length;
    NodeType* currPos;

public:

    SortedLinkedList::SortedLinkedList()
        : head(nullptr), length(0), currPos(nullptr) {
          };
    
    SortedLinkedList()
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
        
        if(head == nullptr || head->data.CompareTo(item) > 0){
            newNode->next = head;
            head = newNode;
        }else{
            currPos = head;
            while(currPos->next != nullptr && currPos->next->data.CompareTo(item) < 0){
                currPos = currPos->next;
                currPos->next = newNode;
            }
            newNode->next = currPos->next;
            currPos->next = newNode;
        }
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

    ItemType GetItem(ItemType& item, bool& found){
        
        currPos = head;
        found = false;
        while(currPos != nullptr){
            switch (item.CompareTo(currPos->data)){
                case 0:
                    found = true;
                    item = currPos -> data;
                    return;
                case 1:
                    currPos = currPos->next;
                    break;
                case -1:
                    return;
            }
        }
    }

};
