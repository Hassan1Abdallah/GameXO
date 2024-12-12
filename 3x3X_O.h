#ifndef _3X3X_O_H
#define _3X3X_O_H

#include "BoardGame_Classes.h"

template<typename T>
class X_O_Board : public Board<T> {
public:
    X_O_Board();

    bool update_board(int x, int y, T symbol);

    void display_board();

    bool is_win();

    bool is_draw();

    bool game_is_over();
};

template<typename T>
class X_O_Player : public Player<T> {
public:
    X_O_Player(std::string name, T symbol);

    void getmove(int &x, int &y, T &symbol);
};

template<typename T>
class X_O_Random_Player : public RandomPlayer<T> {
public:
    X_O_Random_Player(T symbol);

    void getmove(int &x, int &y, T &symbol);
};

#include <iostream>
#include <iomanip>
#include <cctype>

using namespace std;

template<typename T>
X_O_Board<T>::X_O_Board() {
  this->rows = this->columns = 3;
  this->board = new char *[this->rows];
  for (int i = 0; i < this->rows; i++) {
    this->board[i] = new char[this->columns];
    for (int j = 0; j < this->columns; j++) {
      this->board[i][j] = 0;
    }
  }
  this->n_moves = 0;
}

template<typename T>
bool X_O_Board<T>::update_board(int x, int y, T mark) {
  if (!(x < 0 || x >= this->rows || y < 0 || y >= this->columns) && (this->board[x][y] == 0 || mark == 0)) {
    if (mark == 0) {
      this->n_moves--;
      this->board[x][y] = 0;
    } else {
      this->n_moves++;
      this->board[x][y] = toupper(mark);
    }
    return true;
  }
  return false;
}

template<typename T>
void X_O_Board<T>::display_board() {
  for (int i = 0; i < this->rows; i++) {
    cout << "\n| ";
    for (int j = 0; j < this->columns; j++) {
      cout << "(" << i << "," << j << ")";
      cout << setw(2) << this->board[i][j] << " |";
    }
    cout << "\n-----------------------------";
  }
  cout << endl;
}

template<typename T>
bool X_O_Board<T>::is_win() {
  for (int i = 0; i < this->rows; i++) {
    if ((this->board[i][0] == 'S' && this->board[i][1] == 'U' && this->board[i][2] == 'S') ||
        (this->board[0][i] == 'S' && this->board[1][i] == 'U' && this->board[2][i] == 'S')) {
      return true;
    }
  }

  if ((this->board[0][0] == 'S' && this->board[1][1] == 'U' && this->board[2][2] == 'S') ||
      (this->board[0][2] == 'S' && this->board[1][1] == 'U' && this->board[2][0] == 'S')) {
    return true;
  }

  return false;
}

template<typename T>
bool X_O_Board<T>::is_draw() {
  return (this->n_moves == 9 && !is_win());
}

template<typename T>
bool X_O_Board<T>::game_is_over() {
  return is_win() || is_draw();
}

template<typename T>
X_O_Player<T>::X_O_Player(std::string name, T symbol) : Player<T>(name, symbol) {}

template<typename T>
void X_O_Player<T>::getmove(int &x, int &y, T &symbol) {
  cout << this->name << "'s turn.\n";
  cout << "\nPlease enter your move x and y (0 to 2) separated by spaces: ";
  cin >> x >> y;
  do {
    cout << "Enter the symbol (S or U): ";
    cin >> symbol;
    symbol = toupper(symbol);
    if (symbol != 'S' && symbol != 'U') { cout << "Invalid symbol! Please enter 'S' or 'U'.\n"; }
  } while
          (symbol != 'S' && symbol != 'U');
}

template<typename T>
X_O_Random_Player<T>::X_O_Random_Player(T symbol) : RandomPlayer<T>(symbol) {
  this->dimension = 3;
  this->name = "Random Computer Player";
  srand(static_cast<unsigned int>(time(0)));
}

template<typename T>
void X_O_Random_Player<T>::getmove(int &x, int &y, T &symbol) {
  x = rand() % this->dimension;
  y = rand() % this->dimension;
  symbol = (rand() % 2 == 0) ? 'S' : 'U'; // Randomly choose between 'S' and 'U'
  cout << this->name << " played at (" << x << ", " << y << ") with symbol " << symbol << ".\n";
}

#endif //_3X3X_O_H
