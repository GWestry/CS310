#include <cstdlib>
#include <ctime>
#include <iostream>
#include <stdexcept>

template <typename T>
class QueueType
{
public:
    QueueType(int maxSize)
        : maxQueueSize(maxSize), queueFront(0), queueRear(0), length(0)
    {
        if (maxQueueSize <= 0)
        {
            throw std::invalid_argument("Queue size must be positive.");
        }

        data = new T[maxQueueSize];
    }

    QueueType(const QueueType&) = delete;
    QueueType& operator=(const QueueType&) = delete;

    ~QueueType()
    {
        delete[] data;
    }

    bool IsEmpty() const
    {
        return length == 0;
    }

    bool IsFull() const
    {
        return length == maxQueueSize;
    }

    int GetLength() const
    {
        return length;
    }

    bool Enqueue(const T& item)
    {
        if (IsFull())
        {
            return false;
        }

        data[queueRear] = item;
        queueRear = (queueRear + 1) % maxQueueSize;
        ++length;
        return true;
    }

    bool Dequeue(T& item)
    {
        if (IsEmpty())
        {
            return false;
        }

        item = data[queueFront];
        queueFront = (queueFront + 1) % maxQueueSize;
        --length;
        return true;
    }

    void Print(std::ostream& out) const
    {
        out << "[";
        for (int index = 0; index < length; ++index)
        {
            if (index > 0)
            {
                out << ' ';
            }

            out << data[(queueFront + index) % maxQueueSize];
        }
        out << "]";
    }

private:
    int maxQueueSize;
    int queueFront;
    int queueRear;
    int length;
    T* data;
};

int main()
{
    const int maxLineLength = 10;
    const int totalIterations = 100;

    QueueType<char> bankLine(maxLineLength);
    char nextCustomer = 'A';
    int customersServed = 0;
    int customersLeftInLine = 0;
    int customersTurnedAway = 0;
    int tellerIdleCount = 0;

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    for (int iteration = 1; iteration <= totalIterations; ++iteration)
    {
        // Two arrival outcomes for every one service outcome gives a 2:1 rate.
        if (std::rand() % 3 != 0)
        {
            if (bankLine.IsFull())
            {
                ++customersTurnedAway;
            }
            else
            {
                if (bankLine.Enqueue(nextCustomer))
                {
                    nextCustomer = (nextCustomer == 'Z') ? 'A' : nextCustomer + 1;
                }
            }
        }

        if (std::rand() % 3 == 0)
        {
            if (bankLine.IsEmpty())
            {
                ++tellerIdleCount;
            }
            else
            {
                char servedCustomer;
                if (bankLine.Dequeue(servedCustomer))
                {
                    ++customersServed;
                }
            }
        }

        std::cout << "Iteration " << iteration << ": ";
        bankLine.Print(std::cout);
        std::cout << '\n';
    }

    customersLeftInLine = bankLine.GetLength();

    std::cout << "\nSimulation statistics\n"
              << "Successfully served: " << customersServed << '\n'
              << "Left in line: " << customersLeftInLine << '\n'
              << "Turned away (full queue): " << customersTurnedAway << '\n'
              << "Teller idle (empty queue): " << tellerIdleCount << '\n';

    return 0;
}
