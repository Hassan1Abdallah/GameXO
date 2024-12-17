// FourInARow.h - Complementary header file to extend BoardGame_Classes.h
#ifndef _FOURINAROW_H
#define _FOURINAROW_H

#include "BoardGame_Classes.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// --------------------------------------- Custom Board for Four-in-a-Row
class FourInARowBoard : public Board<char> {
public:

    FourInARowBoard() {
        rows = 6;
        columns = 7;
        board = new char*[rows];
        for (int i = 0; i < rows; ++i) {
            board[i] = new char[columns];
            for (int j = 0; j < columns; ++j) {
                board[i][j] = ' '; // Initialize empty board
            }
        }
    }


    bool update_board(int x, int y, char symbol) override {
        if (y < 0 || y >= columns || x != -1) return false; // Invalid column or incorrect usage
        for (int i = rows - 1; i >= 0; --i) { // Start from the bottom row
            if (board[i][y] == ' ') {
                board[i][y] = symbol;
                ++n_moves;
                return true;
            }
        }
        return false;
    }


    void display_board() override {
        cout << "\n  0   1   2   3   4   5   6\n";
        for (int i = 0; i < rows; ++i) {
            cout << "|";
            for (int j = 0; j < columns; ++j) {
                cout << " " << board[i][j] << " |";
            }
            cout << "\n-----------------------------\n";
        }
    }


    bool is_win() override {

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                if (board[i][j] == ' ') continue;
                char symbol = board[i][j];
                if (check_direction(i, j, 0, 1, symbol) || // Horizontal
                    check_direction(i, j, 1, 0, symbol) || // Vertical
                    check_direction(i, j, 1, 1, symbol) || // Diagonal (down-right)
                    check_direction(i, j, 1, -1, symbol))  // Diagonal (down-left)
                    return true;
            }
        }
        return false;
    }


    bool is_draw() override {
        return n_moves >= rows * columns && !is_win();
    }


    bool game_is_over() override {
        return is_win() || is_draw();
    }

private:

    bool check_direction(int x, int y, int dx, int dy, char symbol) {
        for (int k = 0; k < 4; ++k) {
            int new_x = x + k * dx;
            int new_y = y + k * dy;
            if (new_x < 0 || new_x >= rows || new_y < 0 || new_y >= columns || board[new_x][new_y] != symbol)
                return false;
        }
        return true;
    }
};

// --------------------------------------- Human Player
class HumanPlayer : public Player<char> {
public:
    HumanPlayer(string n, char s) : Player(n, s) {}

    void getmove(int& x, int& y) override {
        cout << name << " (" << symbol << "), enter column (0-6): ";
        cin >> y;
        while (y < 0 || y > 6) {
            cout << "Invalid input. Enter a column between 0 and 6: ";
            cin >> y;
        }
        x = -1;
    }
};

// --------------------------------------- Random Computer Player
class RandomPlayerAI : public RandomPlayer<char> {
public:
    RandomPlayerAI(char s) : RandomPlayer(s) { srand(time(0)); }

    void getmove(int& x, int& y) override {
        x = -1;
        y = rand() % 7;
        cout << "Computer (" << symbol << ") chooses column: " << y << endl;
    }
};

#endif
