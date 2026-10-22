#include "PostfixEval.h"

using namespace std;

int evaluatePostfix(string expr, Stack &stack)
{
    stack.makeEmpty();

    for (char character : expr)
    {
        if (character >= '0' && character <= '9')
        {
            stack.push(character - '0');
            continue;
        }

        if (character != '+' && character != '-' && character != '*' && character != '/')
        {
            stack.makeEmpty();
            return -999;
        }

        if (stack.isEmpty())
        {
            stack.makeEmpty();
            return -999;
        }
        int rightOperand = stack.pop();

        if (stack.isEmpty())
        {
            stack.makeEmpty();
            return -999;
        }
        int leftOperand = stack.pop();

        if (character == '/' && rightOperand == 0)
        {
            stack.makeEmpty();
            return -999;
        }

        int result;
        if (character == '+')
        {
            result = leftOperand + rightOperand;
        }
        else if (character == '-')
        {
            result = leftOperand - rightOperand;
        }
        else if (character == '*')
        {
            result = leftOperand * rightOperand;
        }
        else
        {
            result = leftOperand / rightOperand;
        }

        stack.push(result);
    }

    if (stack.isEmpty())
    {
        return -999;
    }

    int result = stack.pop();
    if (!stack.isEmpty())
    {
        stack.makeEmpty();
        return -999;
    }

    return result;
}