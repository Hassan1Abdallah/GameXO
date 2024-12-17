//#ifndef _5X5X_O_H
//#define _5X5X_O_H
//
//#include "BoardGame_Classes.h"
//#include <iomanip>
//#include <iostream>
//
//template<typename T>
//class X_O_5x5_Board : public G4_Board<T> {
//public:
//    X_O_5x5_Board();
//
//    bool update_board(int x, int y, T symbol) override;
//
//    void display_board() override;
//
//    bool is_win() override;
//
//    bool is_draw() override;
//
//    bool game_is_over() override;
//
//    int count_threes(T symbol);
//};
//
//template<typename T>
//X_O_5x5_Board<T>::X_O_5x5_Board() {
//  this->rows = this->columns = 5;
//  this->board = new T *[this->rows];
//  for (int i = 0; i < this->rows; i++) {
//    this->board[i] = new T[this->columns];
//    for (int j = 0; j < this->columns; j++) {
//      this->board[i][j] = 0;
//    }
//  }
//  this->n_moves = 0;
//}
//
//template<typename T>
//bool X_O_5x5_Board<T>::update_board(int x, int y, T symbol) {
//  if (x >= 0 && x < 5 && y >= 0 && y < 5 && this->board[x][y] == 0) {
//    this->board[x][y] = symbol;
//    this->n_moves++;
//    return true;
//  }
//  return false;
//}
//
//template<typename T>
//void X_O_5x5_Board<T>::display_board() {
//  std::cout << "\n";
//  for (int i = 0; i < 5; i++) {
//    std::cout << "| ";
//    for (int j = 0; j < 5; j++) {
//      if (this->board[i][j] == 0)
//        std::cout << "(" << i << "." << j << ") |";
//      else
//        std::cout << "  " << this->board[i][j] << "  |";
//    }
//    std::cout << "\n-----------------------------\n";
//  }
//}
//
//template<typename T>
//int X_O_5x5_Board<T>::count_threes(T symbol) {
//  int count = 0;
//  for (int i = 0; i < 5; i++) {
//    for (int j = 0; j < 3; j++) {
//      if (this->board[i][j] == symbol && this->board[i][j + 1] == symbol && this->board[i][j + 2] == symbol)
//        count++;
//      if (this->board[j][i] == symbol && this->board[j + 1][i] == symbol && this->board[j + 2][i] == symbol)
//        count++;
//    }
//  }
//  return count;
//}
//
//template<typename T>
//bool X_O_5x5_Board<T>::is_win() { return false; }
//
//template<typename T>
//bool X_O_5x5_Board<T>::is_draw() { return this->n_moves == 24; }
//
//template<typename T>
//bool X_O_5x5_Board<T>::game_is_over() { return is_draw(); }
//
//#endif

#ifndef _5X5X_O_H
#define _5X5X_O_H

#include "BoardGame_Classes.h"
#include <iomanip>
#include <iostream>
#include <cstdlib> // Required for srand and rand
#include <ctime>   // Required for time

template<typename T>
class X_O_5x5_Board : public G4_Board<T> {
public:
    X_O_5x5_Board();

    bool update_board(int x, int y, T symbol) override;

    void display_board() override;

    bool is_win() override;

    bool is_draw() override;

    bool game_is_over() override;

    int count_threes(T symbol);
};

template<typename T>
class X_O_5x5_Player : public Player<T> {
public:
    X_O_5x5_Player(std::string name, T symbol);

    void getmove(int &x, int &y) override;

    void getmove(int &x, int &y, T &symbol) override;
};

template<typename T>
class X_O_5x5_Random_Player : public RandomPlayer<T> {
public:
    X_O_5x5_Random_Player(T symbol);

    void getmove(int &x, int &y) override;

    void getmove(int &x, int &y, T &symbol) override;
};


template<typename T>
X_O_5x5_Board<T>::X_O_5x5_Board() {
  this->rows = this->columns = 5;
  this->board = new T *[this->rows];
  for (int i = 0; i < this->rows; i++) {
    this->board[i] = new T[this->columns];
    for (int j = 0; j < this->columns; j++) {
      this->board[i][j] = 0;
    }
  }
  this->n_moves = 0;
}

template<typename T>
bool X_O_5x5_Board<T>::update_board(int x, int y, T symbol) {
  if (x >= 0 && x < 5 && y >= 0 && y < 5 && this->board[x][y] == 0) {
    this->board[x][y] = symbol;
    this->n_moves++;
    return true;
  }
  return false;
}

template<typename T>
void X_O_5x5_Board<T>::display_board() {
  std::cout << "\n";
  for (int i = 0; i < 5; i++) {
    std::cout << "| ";
    for (int j = 0; j < 5; j++) {
      if (this->board[i][j] == 0)
        std::cout << "(" << i << "." << j << ") |";
      else
        std::cout << "  " << this->board[i][j] << "  |";
    }
    std::cout << "\n-----------------------------\n";
  }
}

template<typename T>
int X_O_5x5_Board<T>::count_threes(T symbol) {
  int count = 0;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 3; j++) {
      if (this->board[i][j] == symbol && this->board[i][j + 1] == symbol && this->board[i][j + 2] == symbol)
        count++;
      if (this->board[j][i] == symbol && this->board[j + 1][i] == symbol && this->board[j + 2][i] == symbol)
        count++;
    }
  }
  return count;
}

template<typename T>
bool X_O_5x5_Board<T>::is_win() {
  return false;
}

template<typename T>
bool X_O_5x5_Board<T>::is_draw() {
  return this->n_moves == 24;
}

template<typename T>
bool X_O_5x5_Board<T>::game_is_over() {
  return is_draw();
}


template<typename T>
X_O_5x5_Player<T>::X_O_5x5_Player(std::string name, T symbol) : Player<T>(name, symbol) {}

template<typename T>
void X_O_5x5_Player<T>::getmove(int &x, int &y) {
  std::cout << "Please enter your move (row and column): ";
  std::cin >> x >> y;
}

template<typename T>
void X_O_5x5_Player<T>::getmove(int &x, int &y, T &symbol) {
  std::cout << "Please enter your move (row and column): ";
  std::cin >> x >> y;
  symbol = this->symbol;
}

template<typename T>
X_O_5x5_Random_Player<T>::X_O_5x5_Random_Player(T symbol) : RandomPlayer<T>(symbol) {
  this->dimension = 5;
  this->name = "Random Computer Player";
  srand(static_cast<unsigned int>(time(0)));
}

template<typename T>
void X_O_5x5_Random_Player<T>::getmove(int &x, int &y) {
  x = rand() % this->dimension;
  y = rand() % this->dimension;
}

template<typename T>
void X_O_5x5_Random_Player<T>::getmove(int &x, int &y, T &symbol) {
  x = rand() % this->dimension;
  y = rand() % this->dimension;
  symbol = this->symbol;
}


#endif