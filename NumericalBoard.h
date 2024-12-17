#ifndef NUMERICAL_BOARD_H
#define NUMERICAL_BOARD_H

#include "BoardGame_Classes.h"
#include <iostream>
#include <iomanip>

class NumericalBoard : public Board<int> {
public:

    NumericalBoard(int r, int c) {
        rows = r;
        columns = c;
        board = new int*[rows];
        for (int i = 0; i < rows; i++) {
            board[i] = new int[columns]();
        }
    }

    // Destructor to clean up the board
    ~NumericalBoard() {
        for (int i = 0; i < rows; i++) {
            delete[] board[i];
        }
        delete[] board;
    }


    bool update_board(int x, int y, int symbol) override {
        if (x >= 0 && x < rows && y >= 0 && y < columns && board[x][y] == 0) {
            board[x][y] = symbol;
            n_moves++;
            return true;
        }
        return false;
    }


    void display_board() override {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                std::cout << std::setw(2) << (board[i][j] == 0 ? "." : std::to_string(board[i][j])) << " ";
            }
            std::cout << std::endl;
        }
    }


    bool is_win() override {

        for (int i = 0; i < rows; i++) {
            if (sum_line(board[i], columns) == 15) return true;
            int col_sum = 0;
            for (int j = 0; j < columns; j++) col_sum += board[j][i];
            if (col_sum == 15) return true; // Column check
        }

        int main_diag = 0, anti_diag = 0;
        for (int i = 0; i < rows; i++) {
            main_diag += board[i][i];
            anti_diag += board[i][rows - 1 - i];
        }
        return (main_diag == 15 || anti_diag == 15);
    }

    bool is_draw() override {
        return (n_moves == rows * columns && !is_win());
    }

    bool game_is_over() override {
        return is_win() || is_draw();
    }

private:
    int sum_line(int* line, int size) {
        int sum = 0;
        for (int i = 0; i < size; i++) {
            sum += line[i];
        }
        return sum;
    }
};


class NumericalHumanPlayer : public Player<int> {
public:
    NumericalHumanPlayer(std::string n, int s) : Player<int>(n, s) {}

    void getmove(int& x, int& y) override {
        cout << "Enter your move (row and column): ";
        cin >> x >> y;
    }

    int getSymbolFromUser() {
        int symbol;
        cout << "Enter the number you want to place on the board: ";
        cin >> symbol;
        return symbol;
    }
};


class NumericalRandomPlayer : public RandomPlayer<int> {
public:
    NumericalRandomPlayer(int symbol) : RandomPlayer<int>(symbol) {
        this->dimension = 3;
        srand(static_cast<unsigned int>(time(0)));
    }

    void getmove(int& x, int& y) override {
        x = rand() % dimension;
        y = rand() % dimension;
    }

    int getSymbolFromAI() {
        return rand() % 10 + 1;
    }
};


class CustomNumericalBoard : public NumericalBoard {
public:
    using NumericalBoard::NumericalBoard;

    void display_board() override {
        cout << "\nCurrent Board State:\n";
        for (int i = 0; i < rows; i++) {
            cout << "\n| ";
            for (int j = 0; j < columns; j++) {
                if (board[i][j] == 0)
                    cout << "(" << i << "," << j << ")  ";
                else
                    cout << setw(3) << board[i][j] << "   ";
                cout << "| ";
            }
            cout << "\n--------------------------------";
        }
        cout << endl;
    }
};



#endif