#include <iostream>

template <typename T>
T max(T a, T b)
{
    return (a > b) ? a : b;
}

template <typename T, typename U>
T add(T a, U b)
{
    return a + b;
}

template <typename T1, typename T2>
class Pair
{

public:
    T1 first;
    T2 second;
    Pair(T1 f, T2 s) : first(f), second(s) {}
};

template <typename T, int size>
class FixedArray
{
    T arr[size];

public:
    FixedArray()
    {
        for (int i = 0; i < size; i++)
        {
            arr[i] = T();
        }
    }

    T &operator[](int index)
    {
        return arr[index];
    }
};

int main()
{
    std::cout << max(3, 5) << std::endl;
    std::cout << max(3.5, 5.2) << std::endl;
    std::cout << max('a', 'z') << std::endl;
    std::cout << max("apple", "banana") << std::endl;
    std::cout << add(3, 5) << std::endl;
    std::cout << add(3.5, 5) << std::endl;
    std::cout << add('a', 'z') << std::endl;
    std::cout << add("apple", 3) << std::endl;

    Pair<int, std::string> p(5, "hello");
    std::cout << p.first << " " << p.second << std::endl;

    FixedArray<int, 5> fa;
    fa[0] = 10;
    fa[1] = 20;
    std::cout << fa[0] << " " << fa[1] << std::endl;

    FixedArray<std::string, 5> fa2;
    fa2[0] = "apple";
    fa2[1] = "banana";
    std::cout << fa2[0] << " " << fa2[1] << std::endl;

    return 0;
}