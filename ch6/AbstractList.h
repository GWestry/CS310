// Abstract list class for linked list
#ifndef TEMPLATE_LIST_H
#define TEMPLATE_LIST_H

template <typename T>
class List
{
public:
    virtual ~List() = default;
    virtual void insert(const T &value) = 0;
    virtual void remove(const T &value) = 0;
    virtual bool contains(const T &value) = 0;
    virtual void print() = 0;
    virtual bool isEmpty() const = 0;
    virtual int size() const = 0;
    virtual void clear() = 0;
    // because objects arent fixed size you pass it with & and add const so it doesnt modify the object
    //  virtual T[] search(const std::string& key) const = 0;
};

#endif

template <typename T>
class LinkedList : public List<T>
{
    // Now instead of only ItemType we can do Person, Dog or any other object

private:
    struct Node
    {
        T data;
        Node *next;
        Node(const T &value) : data(value), next(nullptr) {}
    };

    Node *head;
    int listSize;

public:
    LinkedList() : head(nullptr), listSize(0)
    {
    }
    ~LinkedList()
    {
        clear();
    }

    void print() const override
    {
        Node *current = head;
        while (current == nullptr)
        {
            // while(current) also works because of nullptr/0 have a false truth value
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    void clear() override
    {
        Node *current = head;
        while (current != nullptr)
        {
            Node *temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        listSize = 0;
    }

    void insert(const T &value) override
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node *current = head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newNode;
        }
        listSize++;
    }

    void remove(const T &value) override
    {
        if (head == nullptr)
        {
            return;
        }

        if (head->data == value)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            listSize--;
            return;
        }

        Node *current = head;
        while (current->next != nullptr && current->next->data != value)
        {
            current = current->next;
        }

        if (current->next != nullptr)
        {
            Node *temp = current->next;
            current->next = current->next->next;
            delete temp;
            listSize--;
        }
    }
};

// double linked list
// for a test think about why this would be good for playing a music playlist in reverse
// if you cant use doubly linked list combine a linked list and a stack
template <typename T>
class DoublyLinkedList : public List<T>
{
private:
    struct Node
    {
        T data;
        Node *next;
        Node *prev;
        Node(const T &value) : data(value), next(nullptr), prev(nullptr) {}
    };

    Node *head;
    Node *tail;
    int listSize;

public:
    DoublyLinkedList() {}
    ~DoublyLinkedList()
    {
        clear();
    }

    void print() const override
    {
        Node *current = head;
        while (current != nullptr)
        {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    void printReverse() const
    {
        Node *current = tail;
        while (current != nullptr)
        {
            std::cout << current->data << " ";
            current = current->prev;
        }
        std::cout << std::endl;
    }

    void clear() override
    {
        Node *current = head;
        while (current != nullptr)
        {
            Node *temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
        listSize = 0;
    }

    void insert(const T &value) override
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        listSize++;
    }

    void remove(const T &value) override
    {
        if (head == nullptr)
        {
            return;
        }

        if (head->data == value)
        {
            Node *temp = head;
            head = head->next;
            if (head != nullptr)
            {
                head->prev = nullptr;
            }
            else
            {
                tail = nullptr;
            }
            delete temp;
            listSize--;
            return;
        }

        Node *current = head;
        while (current != nullptr && current->data != value)
        {
            current = current->next;
        }

        if (current != nullptr)
        {
            if (current->next != nullptr)
            {
                current->next->prev = current->prev;
            }
            else
            {
                tail = current->prev;
            }
            if (current->prev != nullptr)
            {
                current->prev->next = current->next;
            }
            delete current;
            listSize--;
        }
    }
    // think about how you could insert/retrieve an element at a specific position

    class Iterator
    {
    private:
        Node *current;

    public:
        Iterator(Node *start) : current(start) {}
        bool hasNext() const
        {
            return current != nullptr;
        }
        T &next()
        {
            if (!hasNext())
            {
                throw std::out_of_range("Iterator out of bounds");
            }
            T &value = current->data;
            current = current->next;
            return value;
        }
    };
    Iterator begin() const
    {
        return Iterator(head);
    }
    Iterator end() const
    {
        return Iterator(nullptr);
    }
};