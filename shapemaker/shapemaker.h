#include <iostream>
using namespace std;

class ShapeMaker
{
private:
    int width;
    int height;
    char symbol;

public:
    void Initialize()
    {
        width = 21;
        height = 21;
        symbol = '*';
    }

    int getWidth()
    {
        return width;
    }

    int getHeight()
    {
        return height;
    }

    char getSymbol()
    {
        return symbol;
    }

    void setWidth(int w)
    {
        width = w;
    }

    void setHeight(int h)
    {
        height = h;
    }

    void setSymbol(char s)
    {
        symbol = s;
    }

    void drawHorizontal()
    {
        int mid = height / 2;
        for (int i = 0; i < mid; i++)
        {
            cout << "" << endl;
        }
        for (int i = 0; i < width; i++)
        {
            cout << symbol;
        }
        cout << "" << endl;
    }

    void drawVertical()
    {
        int mid = width / 2;
        for (int j = 0; j < height; j++)
        {
            for (int i = 0; i < mid; i++)
            {
                cout << ' ';
            }

            cout << symbol << endl;
        }
    }

    void drawFilledSquare()
    {
        for (int i = 0; i < width; i++)
        {
            for (int j = 0; j < width; j++)
            {
                cout << symbol;
            }
            cout << endl;
        }
    }

    void drawOpenSquare()
    {
        for (int i = 0; i < width; i++)
        {
            cout << symbol;
        }
        cout << endl;

        for (int i = 0; i < width - 2; i++)
        {
            cout << symbol;

            for (int j = 0; j < width - 2; j++)
            {
                cout << ' ';
            }

            cout << symbol << endl;
        }

        for (int i = 0; i < width; i++)
        {
            cout << symbol;
        }
        cout << endl;
    }

    void drawSmiley()
    {
        int eyeRow = height / 3;
        int leftEye = width / 3;
        int rightEye = (width * 2) / 3;
        int middle = width / 2;
        int noseRow = height / 2;
        int mouthRow = noseRow + 2;
        int mouthFillRow = mouthRow + 1;

        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                if (i == eyeRow && j == leftEye)
                {
                    cout << symbol;
                }
                else if (i == eyeRow && j == rightEye)
                {
                    cout << symbol;
                }
                else if (i == noseRow && j == middle)
                {
                    cout << symbol;
                }
                else if (i == mouthRow && j == leftEye)
                {
                    cout << symbol;
                }
                else if (i == mouthRow && j == rightEye)
                {
                    cout << symbol;
                }
                else if (i == mouthFillRow && j > leftEye && j < rightEye)
                {
                    cout << symbol;
                }
                else
                {
                    cout << ' ';
                }
            }
            cout << endl;
        }
    }

};