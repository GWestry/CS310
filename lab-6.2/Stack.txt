#ifndef STACK_H
#define STACK_H

class Stack
{
private:
    static const int MAX = 1000;
    int arr[MAX];
    int top;

public:
    Stack()
        : top(-1) {}

    // 3.1 Implement push
    bool push(int x)
    {
        if (isFull())
            return false;

        arr[++top] = x;
        return true;
    }

    // 3.2 Implement pop
    int pop()
    {
        if (isEmpty())
            return -1;

        return arr[top--];
    }

    int peek() const
    {
        if (isEmpty())
            return -1;

        return arr[top];
    }

    bool isEmpty() const
    {
        return top == -1;
    }

    bool isFull() const
    {
        return top == MAX - 1;
    }
};

// 3.3 Next Greater Element
void nextGreater(int arr[], int n, int out[])
{
    Stack values;

    for (int i = n - 1; i >= 0; --i)
    {
        while (!values.isEmpty() && values.peek() <= arr[i])
            values.pop();

        out[i] = values.isEmpty() ? -1 : values.peek();
        values.push(arr[i]);
    }
}

// 3.4 Check Balanced Parentheses
bool balanced(const char* s)
{
    Stack values;

    for (int i = 0; s[i] != '\0'; ++i)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            values.push(s[i]);
        }
        else if (s[i] == ')' || s[i] == ']' || s[i] == '}')
        {
            if (values.isEmpty())
                return false;

            int opening = values.pop();
            if ((s[i] == ')' && opening != '(') ||
                (s[i] == ']' && opening != '[') ||
                (s[i] == '}' && opening != '{'))
            {
                return false;
            }
        }
    }

    return values.isEmpty();
}

int precedence(char operation)
{
    if (operation == '+' || operation == '-')
        return 1;
    if (operation == '*' || operation == '/')
        return 2;
    return 0;
}

// 3.5 Infix to Postfix
void infixToPostfix(const char* infix, char* postfix)
{
    Stack operators;
    int outputIndex = 0;

    for (int i = 0; infix[i] != '\0'; ++i)
    {
        char current = infix[i];

        if (current == ' ')
            continue;

        if (current >= '0' && current <= '9')
        {
            postfix[outputIndex++] = current;
        }
        else if (current == '(')
        {
            operators.push(current);
        }
        else if (current == ')')
        {
            while (!operators.isEmpty() && operators.peek() != '(')
                postfix[outputIndex++] = static_cast<char>(operators.pop());

            if (!operators.isEmpty())
                operators.pop();
        }
        else
        {
            while (!operators.isEmpty() &&
                   operators.peek() != '(' &&
                   precedence(static_cast<char>(operators.peek())) >=
                       precedence(current))
            {
                postfix[outputIndex++] = static_cast<char>(operators.pop());
            }

            operators.push(current);
        }
    }

    while (!operators.isEmpty())
        postfix[outputIndex++] = static_cast<char>(operators.pop());

    postfix[outputIndex] = '\0';
}

int applyOperation(int left, int right, char operation)
{
    if (operation == '+')
        return left + right;
    if (operation == '-')
        return left - right;
    if (operation == '*')
        return left * right;
    if (operation == '/')
        return left / right;
    return 0;
}

// 3.6 Evaluate Postfix
int evalPostfix(const char* postfix)
{
    Stack values;

    for (int i = 0; postfix[i] != '\0'; ++i)
    {
        char current = postfix[i];

        if (current == ' ')
            continue;

        if (current >= '0' && current <= '9')
        {
            values.push(current - '0');
        }
        else
        {
            int right = values.pop();
            int left = values.pop();
            values.push(applyOperation(left, right, current));
        }
    }

    return values.pop();
}

// 3.7 Sort Stack using one extra stack
void sortStack(Stack& s)
{
    Stack sorted;

    while (!s.isEmpty())
    {
        int value = s.pop();

        while (!sorted.isEmpty() && sorted.peek() > value)
            s.push(sorted.pop());

        sorted.push(value);
    }

    while (!sorted.isEmpty())
        s.push(sorted.pop());
}

// 3.8 Stock Span Problem
void stockSpan(int price[], int n, int span[])
{
    Stack indices;

    for (int i = 0; i < n; ++i)
    {
        while (!indices.isEmpty() && price[indices.peek()] <= price[i])
            indices.pop();

        span[i] = indices.isEmpty() ? i + 1 : i - indices.peek();
        indices.push(i);
    }
}

// 3.9 Min Stack
class MinStack
{
private:
    static const int MAX = 1000;
    int values[MAX];
    int minimums[MAX];
    int top;

public:
    MinStack()
        : top(-1) {}

    bool push(int value)
    {
        if (top == MAX - 1)
            return false;

        values[++top] = value;
        if (top == 0 || value < minimums[top - 1])
            minimums[top] = value;
        else
            minimums[top] = minimums[top - 1];

        return true;
    }

    int pop()
    {
        if (top == -1)
            return -1;

        return values[top--];
    }

    int getMin() const
    {
        if (top == -1)
            return -1;

        return minimums[top];
    }

    bool isEmpty() const
    {
        return top == -1;
    }
};

#endif