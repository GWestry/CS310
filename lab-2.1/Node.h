#include "Card.h"

struct Node {
        Card data;
        Node* next;
        Node(Card c) : data(c), next(nullptr) {}
};
