#include <vector>
#include <algorithm>
#include <random>
#include <iostream>
#include <ncurses.h>
#include "Card.h"
#include "LinkedList.h"
#if defined(__has_include)
#if __has_include(<SFML/Graphics.hpp>)
#include <SFML/Graphics.hpp>
#define MEMORY_GAME_HAS_SFML 1
#else
#define MEMORY_GAME_HAS_SFML 0
#endif
#else
#define MEMORY_GAME_HAS_SFML 0
#endif

class MemoryGame
{
private:
    LinkedList cards;
    int rows, cols;
    int firstFlipIndex = -1, secondFlipIndex = -1;

    void initializeDeck()
    {
        char values[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
        for (char val : values)
        {
            cards.insert(Card(val));
            cards.insert(Card(val));
        }
    }

    void shuffle()
    {
        std::vector<Card> temp;
        for (int i = 0; i < cards.size(); i++)
        {
            temp.push_back(cards.getAt(i));
        }
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(temp.begin(), temp.end(), g);
        // Clear list (manually, since no clear method)
        while (cards.size() > 0)
            cards.removeAt(0);
        for (const auto &c : temp)
            cards.insert(c);
    }

public:
    MemoryGame(int r = 4, int c = 4) : rows(r), cols(c)
    {
        initializeDeck();
        shuffle();
    }

    bool flipCard(int row, int col)
    {
        int index = row * cols + col;
        if (index < 0 || index >= cards.size() || cards.getAt(index).isFaceUp || cards.getAt(index).isMatched)
        {
            return false;
        }
        cards.getAt(index).isFaceUp = true;

        if (firstFlipIndex == -1)
        {
            firstFlipIndex = index;
        }
        else
        {
            secondFlipIndex = index;
            return true;
        }
        return false;
    }
    bool checkMatch()
    {
        if (firstFlipIndex == -1 || secondFlipIndex == -1)
            return false;

        Card &c1 = cards.getAt(firstFlipIndex);
        Card &c2 = cards.getAt(secondFlipIndex);
        if (c1.value == c2.value)
        {
            c1.isMatched = true;
            c2.isMatched = true;
        }
        else
        {
            c1.isFaceUp = false;
            c2.isFaceUp = false;
        }
        firstFlipIndex = secondFlipIndex = -1;
        return allMatched();
    }

    bool allMatched()
    {
        for (int i = 0; i < cards.size(); i++)
        {
            if (!cards.getAt(i).isMatched)
                return false;
        }
        return true;
    }

    // Display functions go here (from step 4)

    void displayTerminal()
    {
        std::cout << "Memory Game Grid:\n";
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                int idx = r * cols + c;
                Card &card = cards.getAt(idx);
                if (card.isMatched)
                {
                    std::cout << "[ ]";
                }
                else if (card.isFaceUp)
                {
                    std::cout << "[" << card.value << "] ";
                }
                else
                {
                    std::cout << "[*] ";
                }
            }
            std::cout << "\n";
        }
    }

    void displayTerminalNurses()
    {
        initscr();
        noecho();
        keypad(stdscr, TRUE);
        curs_set(0);

        if (has_colors())
        {
            start_color();
            init_pair(1, COLOR_WHITE, COLOR_BLUE);
            init_pair(2, COLOR_BLACK, COLOR_WHITE);
            init_pair(3, COLOR_GREEN, COLOR_BLACK);
        }

        int cursorRow = 0;
        int cursorCol = 0;

        while (!allMatched())
        {
            clear();

            for (int row = 0; row < rows; row++)
            {
                for (int col = 0; col < cols; col++)
                {
                    int index = row * cols + col;
                    Card &card = cards.getAt(index);
                    int y = row * 2;
                    int x = col * 4;

                    if (row == cursorRow && col == cursorCol)
                        attron(A_REVERSE | A_BOLD);

                    if (card.isMatched)
                    {
                        mvprintw(y, x, "[ ]");
                    }
                    else if (card.isFaceUp)
                    {
                        if (has_colors())
                            attron(COLOR_PAIR(2));
                        mvprintw(y, x, "[%c]", card.value);
                        if (has_colors())
                            attroff(COLOR_PAIR(2));
                    }
                    else
                    {
                        if (has_colors())
                            attron(COLOR_PAIR(1));
                        mvprintw(y, x, "[*]");
                        if (has_colors())
                            attroff(COLOR_PAIR(1));
                    }

                    if (row == cursorRow && col == cursorCol)
                        attroff(A_REVERSE | A_BOLD);
                }
            }

            mvprintw(rows * 2 + 1, 0,
                     "Arrow keys: move | Space/Enter: flip | Q: quit");
            refresh();

            int key = getch();
            switch (key)
            {
            case KEY_UP:
                if (cursorRow > 0)
                    cursorRow--;
                break;
            case KEY_DOWN:
                if (cursorRow < rows - 1)
                    cursorRow++;
                break;
            case KEY_LEFT:
                if (cursorCol > 0)
                    cursorCol--;
                break;
            case KEY_RIGHT:
                if (cursorCol < cols - 1)
                    cursorCol++;
                break;
            case ' ':
            case '\n':
            case KEY_ENTER:
                if (flipCard(cursorRow, cursorCol))
                {
                    clear();
                    for (int row = 0; row < rows; row++)
                    {
                        for (int col = 0; col < cols; col++)
                        {
                            int index = row * cols + col;
                            Card &card = cards.getAt(index);
                            int y = row * 2;
                            int x = col * 4;
                            if (card.isMatched)
                                mvprintw(y, x, "[ ]");
                            else if (card.isFaceUp)
                                mvprintw(y, x, "[%c]", card.value);
                            else
                                mvprintw(y, x, "[*]");
                        }
                    }
                    refresh();
                    napms(1000);
                    checkMatch();
                }
                break;
            case 'q':
            case 'Q':
                endwin();
                return;
            }
        }

        clear();
        mvprintw(rows, 0, "You win! Press any key to exit.");
        refresh();
        getch();
        endwin();
    }

#if MEMORY_GAME_HAS_SFML
    void displaySFML()
    {
        sf::RenderWindow window(sf::VideoMode(400, 400), "Memory Game");
        sf::Font font;
        if (!font.loadFromFile("arial.ttf"))
        { /* Handle error */
        }

        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
                if (event.type == sf::Event::MouseButtonPressed)
                {
                    int x = event.mouseButton.x / 100;
                    int y = event.mouseButton.y / 100;
                    if (flipCard(y, x))
                        checkMatch();
                }
            }

            window.clear();
            for (int r = 0; r < rows; r++)
            {
                for (int c = 0; c < cols; c++)
                {
                    int idx = r * cols + c;
                    Card &card = cards.getAt(idx);

                    sf::RectangleShape rect(sf::Vector2f(90, 90));
                    rect.setPosition(c * 100 + 5, r * 100 + 5);
                    rect.setFillColor(card.isMatched ? sf::Color::Transparent : (card.isFaceUp ? sf::Color::White : sf::Color::Blue));

                    if (!card.isMatched)
                        window.draw(rect);

                    if (card.isFaceUp && !card.isMatched)
                    {
                        sf::Text text(std::string(1, card.value), font, 50);
                        text.setPosition(c * 100 + 30, r * 100 + 20);
                        text.setFillColor(sf::Color::Black);
                        window.draw(text);
                    }
                }
            }

            window.display();

            if (allMatched())
            {
                // Draw win message
                sf::Text winText("You Win!", font, 50);
                winText.setPosition(100, 180);
                window.draw(winText);
                window.display();
                sf::sleep(sf::seconds(3));
                window.close();
            }
        }
    }
#endif
};
