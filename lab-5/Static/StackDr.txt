#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "StackType.h"

using namespace std;

namespace
{
void CopyStack(StackType& source, StackType& copy)
{
  StackType reversed;
  while (!source.IsEmpty())
  {
    ItemType item = source.Top();
    source.Pop();
    reversed.Push(item);
  }
  while (!reversed.IsEmpty())
  {
    ItemType item = reversed.Top();
    reversed.Pop();
    source.Push(item);
    copy.Push(item);
  }
}

ItemType BottomAndEmpty(StackType& stack)
{
  ItemType bottom = stack.Top();
  while (!stack.IsEmpty())
  {
    bottom = stack.Top();
    stack.Pop();
  }
  return bottom;
}

ItemType BottomUnchanged(StackType& stack)
{
  StackType reversed;
  while (!stack.IsEmpty())
  {
    ItemType item = stack.Top();
    stack.Pop();
    reversed.Push(item);
  }
  ItemType bottom = reversed.Top();
  while (!reversed.IsEmpty())
  {
    ItemType item = reversed.Top();
    reversed.Pop();
    stack.Push(item);
  }
  return bottom;
}
}

int main()
{
  ifstream inFile("StackType.in");
  ofstream outFile("StackType.out");
  if (!inFile || !outFile)
    return 1;

  StackType stack;
  vector<ItemType> values;
  ItemType item;
  while (inFile >> item)
  {
    values.push_back(item);
    stack.Push(item);
  }

  outFile << "Initial top: " << stack.Top() << '\n';

  ItemType secondElement;
  stack.Pop();
  secondElement = stack.Top();
  stack.Pop();
  outFile << "1. Second element: " << secondElement << '\n';

  ItemType bottom = BottomAndEmpty(stack);
  outFile << "2. Bottom element: " << bottom << '\n';

  for (ItemType value : values)
    stack.Push(value);
  bottom = BottomUnchanged(stack);
  outFile << "3. Bottom element: " << bottom << '\n';

  StackType copy;
  CopyStack(stack, copy);
  outFile << "4. Copy top: " << copy.Top() << '\n';
  outFile << "Stack top after copy: " << stack.Top() << '\n';
}
