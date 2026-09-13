#include "shapemaker.h"
using namespace std;
#include <iostream>

int main()
{
    ShapeMaker Shape;

    Shape.Initialize();

    cout << "initial settings" << endl;
    cout << "width: " << Shape.getWidth() << endl;
    cout << "height: " << Shape.getHeight() << endl;
    cout << "symbol: " << Shape.getSymbol() << endl;

    Shape.drawFilledSquare();

    cout << "" << endl;

    Shape.drawHorizontal();

    cout << "" << endl;

    Shape.setSymbol('?');
    Shape.setHeight(18);
    Shape.setWidth(18);
    Shape.drawVertical();

    cout << "" << endl;

    Shape.drawOpenSquare();

    cout << "" << endl;

    Shape.drawSmiley();

    cout << "" << endl;

    return 0;
}