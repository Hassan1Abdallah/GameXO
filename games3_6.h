#ifndef GAMES3_6_H
#define GAMES3_6_H


#include "BoardGame_Classes.h"
#include <iomanip>

// 5x5 Board Class
template <typename T>
class FXF_Player : public Player<T> {
public:
    FXF_Player(string n, T symbol) : Player<T>(n, symbol) {}

    void getmove(int &x, int &y) override {
        cout << this->getname() << " (" << this->getsymbol() << "), enter your move (row and column): ";
        cin >> x >> y;
    }
};

template <typename T>
class FXF_Random_Player : public RandomPlayer<T> {
public:
    FXF_Random_Player(T symbol) : RandomPlayer<T>(symbol) {
        srand(time(0)); // Seed random number generator
    }

    void getmove(int &x, int &y) override {
        x = rand() % 5;
        y = rand() % 5;
        cout << "Computer (" << this->getsymbol() << ") chooses: (" << x << ", " << y << ")\n";
    }
};
template <typename T>

class FXF_Board : public Board<T> {
public:
    FXF_Board();
    bool update_board(int x, int y, T symbol);
    void display_board();
    bool is_win();  // Modified: Returns false, as we count sequences instead.
    int count_three_in_a_row(T symbol);  // Count sequences for a player.
    bool is_draw();
    bool game_is_over();
};

// Constructor: Initializes a 5x5 board
template <typename T>
FXF_Board<T>::FXF_Board() {
    this->rows = this->columns = 5;
    this->board = new T*[this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new T[this->columns]();
    }
    this->n_moves = 0;
}

// Update the board with a symbol
template <typename T>
bool FXF_Board<T>::update_board(int x, int y, T symbol) {
    if (x >= 0 && x < 5 && y >= 0 && y < 5 && this->board[x][y] == 0) {
        this->board[x][y] = toupper(symbol);
        this->n_moves++;
        return true;
    }
    return false;
}

// Display the board
template <typename T>
void FXF_Board<T>::display_board() {
    for (int i = 0; i < 5; i++) {
        cout << "\n| ";
        for (int j = 0; j < 5; j++) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << (this->board[i][j] ? this->board[i][j] : ' ') << " |";
        }
        cout << "\n-----------------------------------------";
    }
    cout << endl;
}

// Count three-in-a-row sequences for a given symbol
template <typename T>
int FXF_Board<T>::count_three_in_a_row(T symbol) {
    int count = 0;
    symbol = toupper(symbol);

    // Check rows
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 3; j++) {
            if (this->board[i][j] == symbol && this->board[i][j + 1] == symbol && this->board[i][j + 2] == symbol)
                count++;
        }
    }

    // Check columns
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            if (this->board[i][j] == symbol && this->board[i + 1][j] == symbol && this->board[i + 2][j] == symbol)
                count++;
        }
    }

    // Check diagonals (\)
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (this->board[i][j] == symbol && this->board[i + 1][j + 1] == symbol && this->board[i + 2][j + 2] == symbol)
                count++;
        }
    }

    // Check diagonals (/)
    for (int i = 0; i < 3; i++) {
        for (int j = 2; j < 5; j++) {
            if (this->board[i][j] == symbol && this->board[i + 1][j - 1] == symbol && this->board[i + 2][j - 2] == symbol)
                count++;
        }
    }

    return count;
}

// Draw condition: 24 moves completed
template <typename T>
bool FXF_Board<T>::is_draw() {
    return this->n_moves == 24;
}

// Game over: Ends after 24 moves
template <typename T>
bool FXF_Board<T>::game_is_over() {
    return is_draw();
}

// "Win" condition not used for this variant
template <typename T>
bool FXF_Board<T>::is_win() {
    return false;
}



//------------------------- GAME NUMBER 6 --------------------------------------
template <typename T>
class MisereTicTacToeBoard : public Board<T> {
public:
    MisereTicTacToeBoard();
    bool update_board(int x, int y, T symbol) override;
    void display_board() override;
    bool is_win() override;  // Fixed to override correctly
    bool is_win(T symbol);  // Separate helper function
    bool is_draw() override;
    bool game_is_over() override;
};

template <typename T>
class MisT_Player : public Player<T> {
public:
    MisT_Player(string name, T symbol) : Player<T>(name, symbol) {}
    void getmove(int& x, int& y) override {
        cout << this->getname() << "'s turn. Enter x and y: ";
        cin >> x >> y;
    }
};

template <typename T>
class MisT_Random_Player : public RandomPlayer<T> {
public:
    MisT_Random_Player(T symbol) : RandomPlayer<T>(symbol) {}
    void getmove(int& x, int& y) override {
        x = rand() % 3;
        y = rand() % 3;
    }
};

template <typename T>
MisereTicTacToeBoard<T>::MisereTicTacToeBoard() {
    this->rows = this->columns = 3;
    this->board = new T*[this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new T[this->columns]();
    }
    this->n_moves = 0;
}

template <typename T>
bool MisereTicTacToeBoard<T>::update_board(int x, int y, T symbol) {
    if (x >= 0 && x < 3 && y >= 0 && y < 3 && this->board[x][y] == '\0') {
        this->board[x][y] = symbol;
        this->n_moves++;
        return true;
    }
    return false;
}

template <typename T>
void MisereTicTacToeBoard<T>::display_board() {
    for (int i = 0; i < 3; i++) {
        cout << "\n| ";
        for (int j = 0; j < 3; j++) {
            // Change indices to start from 1
            cout << "(" << (i + 1) << "," << (j + 1) << ")";  // Now showing 1-based index
            cout << setw(2) << (this->board[i][j] ? this->board[i][j] : ' ') << " |";
        }
        cout << "\n-------------------------";
    }
    cout << endl;
}

template <typename T>
bool MisereTicTacToeBoard<T>::is_win() {
    return is_win('X') || is_win('O');
}

template <typename T>
bool MisereTicTacToeBoard<T>::is_win(T symbol) {
    // Check rows for a win
    for (int i = 0; i < 3; i++) {
        if (this->board[i][0] == symbol && this->board[i][1] == symbol && this->board[i][2] == symbol) {
            cout << "Win detected in row " << i + 1 << " for symbol: " << symbol << endl;
            return true;
        }
    }

    // Check columns for a win
    for (int i = 0; i < 3; i++) {
        if (this->board[0][i] == symbol && this->board[1][i] == symbol && this->board[2][i] == symbol) {
            cout << "Win detected in column " << i + 1 << " for symbol: " << symbol << endl;
            return true;
        }
    }

    // Check diagonals for a win
    if (this->board[0][0] == symbol && this->board[1][1] == symbol && this->board[2][2] == symbol) {
        cout << "Win detected in main diagonal for symbol: " << symbol << endl;
        return true;
    }
    if (this->board[0][2] == symbol && this->board[1][1] == symbol && this->board[2][0] == symbol) {
        cout << "Win detected in anti-diagonal for symbol: " << symbol << endl;
        return true;
    }

    return false;
}

template <typename T>
bool MisereTicTacToeBoard<T>::is_draw() {
    return this->n_moves == 9;
}

template <typename T>
bool MisereTicTacToeBoard<T>::game_is_over() {
    return is_win() || is_draw();
}
#endif //FULL_GAME_GAMES3_6_H
