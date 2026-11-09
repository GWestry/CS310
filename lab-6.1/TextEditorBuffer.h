#ifndef LAB_6_1_TEXT_EDITOR_BUFFER_H
#define LAB_6_1_TEXT_EDITOR_BUFFER_H

#include "CircularLinkedList.h"
#include "CircularLinkedQueue.h"
#include "CircularLinkedStack.h"

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

template <typename T>
class TextEditorBuffer
{
private:
    CircularLinkedStack<T> buffer_;
    CircularLinkedQueue<T> redoQueue_;
    CircularLinkedList<std::string> history_;

    static std::string valueToString(const T& item)
    {
        std::ostringstream output;
        output << item;
        return output.str();
    }

    void clearRedoQueue()
    {
        while (!redoQueue_.isEmpty())
        {
            redoQueue_.dequeue();
        }
    }

    void addRedoItem(const T& item)
    {
        CircularLinkedQueue<T> reordered;
        reordered.enqueue(item);
        while (!redoQueue_.isEmpty())
        {
            reordered.enqueue(redoQueue_.dequeue());
        }
        redoQueue_ = std::move(reordered);
    }

public:
    void type(const T& item)
    {
        buffer_.push(item);
        clearRedoQueue();
        history_.insertRear("type(" + valueToString(item) + ")");
    }

    void undo()
    {
        if (buffer_.isEmpty())
        {
            throw std::underflow_error("Cannot undo an empty buffer.");
        }

        T item = buffer_.pop();
        addRedoItem(item);
        history_.insertRear("undo(" + valueToString(item) + ")");
    }

    void redo()
    {
        if (redoQueue_.isEmpty())
        {
            throw std::underflow_error("Nothing is available to redo.");
        }

        T item = redoQueue_.dequeue();
        buffer_.push(item);
        history_.insertRear("redo(" + valueToString(item) + ")");
    }

    void displayBuffer(std::ostream& out = std::cout) const
    {
        CircularLinkedStack<T> copy(buffer_);
        std::vector<T> items;

        while (!copy.isEmpty())
        {
            items.push_back(copy.pop());
        }

        out << "[";
        for (auto item = items.rbegin(); item != items.rend(); ++item)
        {
            if (item != items.rbegin())
            {
                out << ' ';
            }
            out << *item;
        }
        out << "]";
    }

    void displayHistory(std::ostream& out = std::cout) const
    {
        history_.display(out);
    }

    bool isEmpty() const
    {
        return buffer_.isEmpty();
    }

    std::size_t size() const
    {
        return static_cast<std::size_t>(buffer_.size());
    }
};

#endif
