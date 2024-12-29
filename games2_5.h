
#ifndef GAMES2_5_H
#define GAMES2_5_H

#include <iomanip>
#include <cctype>
#include <algorithm>
#include <iostream>
#include "BoardGame_Classes.h"


template <typename T>
class Four_n_Row : public Board<T> {
public:
    // Constructor initializes a 7x6 grid
    Four_n_Row() {
        this->rows = 6;
        this->columns = 7;
        this->board = new T * [this->rows];
        for (int i = 0; i < this->rows; i++) {
            this->board[i] = new T[this->columns];
            for (int j = 0; j < this->columns; j++) {
                this->board[i][j] = '-';  // Empty cells initialized as '-'
            }
        }
    }

    // Destructor to clean up dynamically allocated memory
    ~Four_n_Row() {
        for (int i = 0; i < this->rows; i++) {
            delete[] this->board[i];
        }
        delete[] this->board;
    }

    // Update the board by placing a symbol at the lowest available row in the chosen column
    bool update_board(int x, int y, T symbol) override {
        if (x < 0 || x >= this->rows || y < 0 || y >= this->columns || this->board[x][y] != '-') {
            return false;  // Invalid move if the position is already taken or out of bounds
        }

        // Find the lowest available row in column y
        for (int i = this->rows - 1; i >= 0; i--) {
            if (this->board[i][y] == '-') {
                this->board[i][y] = symbol;
                this->n_moves++;
                return true;
            }
        }
        return false;  // Column is full
    }

    // Display the board
    void display_board() override {
        for (int i = 0; i < this->rows; i++) {
            for (int j = 0; j < this->columns; j++) {
                cout << this->board[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Check if there is a winner
    bool is_win() override {
        // Check horizontal, vertical, and diagonal for four-in-a-row
        for (int i = 0; i < this->rows; i++) {
            for (int j = 0; j < this->columns; j++) {
                if (this->board[i][j] == '-') continue;

                T symbol = this->board[i][j];

                // Check horizontal (right direction)
                if (j + 3 < this->columns &&
                    this->board[i][j + 1] == symbol &&
                    this->board[i][j + 2] == symbol &&
                    this->board[i][j + 3] == symbol) {
                    return true;
                }

                // Check vertical (down direction)
                if (i + 3 < this->rows &&
                    this->board[i + 1][j] == symbol &&
                    this->board[i + 2][j] == symbol &&
                    this->board[i + 3][j] == symbol) {
                    return true;
                }

                // Check diagonal (bottom-right direction)
                if (i + 3 < this->rows && j + 3 < this->columns &&
                    this->board[i + 1][j + 1] == symbol &&
                    this->board[i + 2][j + 2] == symbol &&
                    this->board[i + 3][j + 3] == symbol) {
                    return true;
                }

                // Check diagonal (bottom-left direction)
                if (i + 3 < this->rows && j - 3 >= 0 &&
                    this->board[i + 1][j - 1] == symbol &&
                    this->board[i + 2][j - 2] == symbol &&
                    this->board[i + 3][j - 3] == symbol) {
                    return true;
                }
            }
        }
        return false;
    }

    // Check if the game is a draw (no empty spaces left)
    bool is_draw() override {
        return this->n_moves == this->rows * this->columns;
    }

    // Check if the game is over (either a win or a draw)
    bool game_is_over() override {
        return is_win() || is_draw();
    }
};

// Human Player Implementation
class Four_n_Row_Player : public Player<char> {
public:
    Four_n_Row_Player(string name, char symbol) : Player<char>(name, symbol) {}

    void getmove(int& x, int& y) override {
        x = 1;
        cout << getname() << " (" << getsymbol() << "), enter your move (column) starting at index 1: ";
        cin >> y;
        x--; y--; // Convert to 0-based indexing
    }
};


template <typename T>
class Four_n_Row_RandomPlayer : public RandomPlayer<char> {
public:
    Four_n_Row_RandomPlayer(char symbol) : RandomPlayer<char>(symbol) {}

    void getmove(int& x, int& y) override {
        x = rand() % 6; // Rows
        y = rand() % 7; // Columns
    }
};




//------------------------GAME NUMBER 5---------------------------





using namespace std;

template <typename T>
class Num_T: public Board<T> {
public:
    Num_T();
    ~Num_T();
    bool update_board(int x, int y, T symbol);
    void display_board();
    bool is_win();
    bool is_draw();
    bool game_is_over();
};

// Implementation

template <typename T>
Num_T<T>::Num_T() {
    this->rows = this->columns = 3;
    this->board = new T*[this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new T[this->columns];
        for (int j = 0; j < this->columns; j++) {
            this->board[i][j] = 0;
        }
    }
    this->n_moves = 0;
}

template<typename T>
Num_T<T>::~Num_T() {
    for (int i = 0; i < this->rows; i++) {
        delete[] this->board[i];
    }
    delete[] this->board;
}

template <typename T>
bool Num_T<T>::update_board(int x, int y, T symbol) {
    if (x < 0 || x >= 3 || y < 0 || y >= 3 || this->board[x][y] != 0) {
        return false; // Invalid move (out of bounds or cell already occupied)
    }
    this->board[x][y] = symbol; // Place the number (symbol) on the board
    this->n_moves++;
    return true;
}

// Display the board and the pieces on it
template <typename T>
void Num_T<T>::display_board() {
    for (int i = 0; i < this->rows; i++) {
        cout << "\n| ";
        for (int j = 0; j < this->columns; j++) {
            cout << "(" << i << "," << j << ") "; // Show the index of each cell
            cout << setw(2) << this->board[i][j] << " |";
        }
        cout << "\n-----------------------------";
    }
    cout << endl;
}

// Returns true if there is any winner
template <typename T>
bool Num_T<T>::is_win() {
    // Check rows
    for (int i = 0; i < this->rows; i++) {
        if (this->board[i][0] != 0 && this->board[i][1] != 0 && this->board[i][2] != 0 &&
            this->board[i][0] + this->board[i][1] + this->board[i][2] == 15) {
            return true;
        }
    }

    // Check columns
    for (int i = 0; i < this->columns; i++) {
        if (this->board[0][i] != 0 && this->board[1][i] != 0 && this->board[2][i] != 0 &&
            this->board[0][i] + this->board[1][i] + this->board[2][i] == 15) {
            return true;
        }
    }

    // Check diagonals
    if (this->board[0][0] != 0 && this->board[1][1] != 0 && this->board[2][2] != 0 &&
        this->board[0][0] + this->board[1][1] + this->board[2][2] == 15) {
        return true;
    }

    if (this->board[0][2] != 0 && this->board[1][1] != 0 && this->board[2][0] != 0 &&
        this->board[0][2] + this->board[1][1] + this->board[2][0] == 15) {
        return true;
    }

    return false;
}

// Return true if 9 moves are done and no winner
template <typename T>
bool Num_T<T>::is_draw() {
    return (this->n_moves == 9 && !is_win());
}

template <typename T>
bool Num_T<T>::game_is_over() {
    return is_win() || is_draw();
}

// Player Class with number validation
template <typename T>
class Num_T_Player : public Player<T> {
private:
    vector<int>& numbers; // Reference to the player's available numbers
    Num_T<T>* boardPtr;  // Pointer to the game board

public:
    Num_T_Player(string name, int player_num, vector<int>& numbers, Num_T<T>* board)
            : Player<T>(name, player_num), numbers(numbers), boardPtr(board) {}

    void getmove(int& x, int& y) override {
        int number;

        // Display the available numbers for the player
        cout << this->name << ", your numbers are: ";
        for (int num : numbers) {
            cout << num << " ";
        }
        cout << endl;

        // Ask the player to choose a number and a position
        cout << "Enter the and position (x y): ";
        cin >> x >> y;
        cout << "Enter the your number: ";
        cin >> number;

        // Check if the chosen number is in the available list
        while (find(numbers.begin(), numbers.end(), number) == numbers.end()) {
            cout << "Invalid number! Please choose a number from your available list: ";
            cin >> number;
        }

        // Check if the position is valid
        while (x < 0 || x >= 3 || y < 0 || y >= 3 || !boardPtr->update_board(x, y, number)) {
            cout << "Invalid position! Try again with valid coordinates (0-2) and an empty cell: ";
            cin >> x >> y;
        }

        // Remove the used number from the list
        numbers.erase(find(numbers.begin(), numbers.end(), number));
    }
};

// Random Player Logic (Computer)
template <typename T>
class Num_T_Random_Player : public Player<T> {
private:
    vector<int>& numbers; // Reference to the player's available numbers
    Num_T<T>* boardPtr;  // Pointer to the game board

public:
    Num_T_Random_Player(int player_num, vector<int>& numbers, Num_T<T>* board)
            : Player<T>("Computer", player_num), numbers(numbers), boardPtr(board) {}

    void getmove(int& x, int& y) override {
        // Select a random number from the available numbers list
        int randomIndex = rand() % numbers.size();
        int number = numbers[randomIndex];

        // Select a random position on the board
        x = rand() % 3;
        y = rand() % 3;

        // Keep selecting random positions until an empty one is found
        while (!boardPtr->update_board(x, y, number)) {
            x = rand() % 3;
            y = rand() % 3;
        }

        // Remove the used number from the available numbers list
        numbers.erase(numbers.begin() + randomIndex);
    }
};

/*

using namespace std;

const int SIZE2 = 3;
const int WIN_SUM = 15; // Sum to win the game

// Define a helper function to check if the sum of three numbers is 15
bool check_sum_15(int a, int b, int c) {
    return (a + b + c == WIN_SUM);
}

// NumericalBoard class inherits from Board<int>
class NumericalBoard : public Board<int> {
public:
    NumericalBoard() {
        rows = SIZE2;
        columns = SIZE2;
        board = new int* [rows];
        for (int i = 0; i < rows; ++i) {
            board[i] = new int[columns] {0}; // Initialize to 0 (empty cells)
        }
    }

    // Destructor to deallocate the dynamically allocated memory
    ~NumericalBoard() {
        for (int i = 0; i < rows; ++i) {
            delete[] board[i];
        }
        delete[] board;
    }

    // Implement the pure virtual functions

    bool update_board(int x, int y, int symbol) override {
        if (x >= 0 && x < rows && y >= 0 && y < columns && board[x][y] == 0) {
            board[x][y] = symbol;
            n_moves++;
            return true;
        }
        return false;
    }

    void display_board() override {
        cout << "\nCurrent Board:\n";
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                if (board[i][j] == 0)
                    cout << ".";
                else
                    cout << board[i][j];
                if (j < columns - 1) cout << " | ";
            }
            cout << endl;
            if (i < rows - 1) cout << "---+---+---" << endl;
        }
        cout << endl;
    }

    bool is_win() override {
        // Check rows, columns, and diagonals for a winning sum of 15
        for (int i = 0; i < rows; ++i) {
            // Check row
            if (check_sum_15(board[i][0], board[i][1], board[i][2])) return true;
            // Check column
            if (check_sum_15(board[0][i], board[1][i], board[2][i])) return true;
        }

        // Check diagonals
        if (check_sum_15(board[0][0], board[1][1], board[2][2])) return true;
        if (check_sum_15(board[0][2], board[1][1], board[2][0])) return true;

        return false;
    }

    bool is_draw() override {
        // Check if all moves are done and there is no winner
        return (n_moves == rows * columns && !is_win());
    }

    bool game_is_over() override {
        // Game is over if there is a winner or draw
        return is_win() || is_draw();
    }
};

// Extend RandomPlayer for Numerical Tic Tac Toe
class RandomNumericalPlayer : public RandomPlayer<int> {
    vector<int> availableNumbers;

public:
    RandomNumericalPlayer(int symbol, const vector<int>& numbers) : RandomPlayer<int>(symbol), availableNumbers(numbers) {}

    void getmove(int& x, int& y) override {
        do {
            x = rand() % 3; // 3x3 grid
            y = rand() % 3;
        } while (!this->boardPtr->update_board(x, y, 0)); // Ensure valid move
    }

    int getRandomNumber() {
        if (availableNumbers.empty()) return -1; // No numbers left
        int index = rand() % availableNumbers.size();
        int number = availableNumbers[index];
        availableNumbers.erase(availableNumbers.begin() + index);
        return number;
    }
};
*/



#endif //GAMES2_5_H
