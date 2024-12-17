#ifndef _PYRAMIC_X_O_H
#define _PYRAMIC_X_O_H

#include "BoardGame_Classes.h"

template<typename T>
class Pyramic_X_O_Board : public Board<T> {
public:
    Pyramic_X_O_Board();

    bool update_board(int x, int y, T symbol) override;

    void display_board() override;

    bool is_win() override;

    bool is_draw() override;

    bool game_is_over() override;

    virtual ~Pyramic_X_O_Board() = default;
};

template<typename T>
class Pyramic_X_O_Player : public Player<T> {
public:
    Pyramic_X_O_Player(string name, T symbol);

    void getmove(int &x, int &y) override;

    void getmove(int &x, int &y, T &symbol) override;

};

template<typename T>
class Pyramic_X_O_Random_Player : public RandomPlayer<T> {
public:
    Pyramic_X_O_Random_Player(T symbol);

    void getmove(int &x, int &y) override;

    void getmove(int &x, int &y, T &symbol) override;

};

//--------------------------------------- IMPLEMENTATION

#include <iostream>
#include <iomanip>
#include <cctype>  // for toupper()
#include <cstdlib> // Required for srand and rand
#include <ctime>   // Required for time

using namespace std;

template<typename T>
Pyramic_X_O_Board<T>::Pyramic_X_O_Board() {
  this->rows = 3;
  this->columns = 5;
  this->board = new char *[this->rows];
  for (int i = 0; i < this->rows; i++) {
    this->board[i] = new char[this->columns];
    for (int j = 0; j < ((i == 0) ? 1 : (i == 1) ? 3 : 5); j++) {
      this->board[i][j] = 0;
    }
  }
  this->n_moves = 0;
}

template<typename T>
bool Pyramic_X_O_Board<T>::update_board(int x, int y, T mark) {
  if (!(x < 0 || x >= this->rows || y < 0 || y >= ((x == 0) ? 1 : (x == 1) ? 3 : 5)) &&
      (this->board[x][y] == 0 || mark == 0)) {
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
void Pyramic_X_O_Board<T>::display_board() {
  cout << "                      | (0,0) " << setw(2) << this->board[0][0] << " |\n";
  cout << "-----------------------------\n";

  cout << "           | (1,0) " << setw(2) << this->board[1][0] << " | (1,1) " << setw(2) << this->board[1][1]
       << " | (1,2) " << setw(2) << this->board[1][2] << " |\n";
  cout << "-----------------------------\n";

  cout << "| (2,0) " << setw(2) << this->board[2][0] << " | (2,1) " << setw(2) << this->board[2][1] << " | (2,2) "
       << setw(2) << this->board[2][2] << " | (2,3) " << setw(2) << this->board[2][3] << " | (2,4) " << setw(2)
       << this->board[2][4] << " |\n";
  cout << "-----------------------------\n";
  cout << endl;
}

// Returns true if there is any winner
template<typename T>
bool Pyramic_X_O_Board<T>::is_win() {
  if (this->board[1][0] == this->board[1][1] && this->board[1][1] == this->board[1][2] && this->board[1][0] != 0) {
    return true;
  }
  if (this->board[2][0] == this->board[2][1] && this->board[2][1] == this->board[2][2] && this->board[2][0] != 0) {
    return true;
  }
  if (this->board[2][2] == this->board[2][3] && this->board[2][3] == this->board[2][4] && this->board[2][2] != 0) {
    return true;
  }
  if (this->board[2][1] == this->board[2][2] && this->board[2][2] == this->board[2][3] && this->board[2][1] != 0) {
    return true;
  }
  if (this->board[0][0] == this->board[1][1] && this->board[1][1] == this->board[2][2] && this->board[0][0] != 0) {
    return true;
  }
  if (this->board[0][0] == this->board[1][0] && this->board[1][0] == this->board[2][0] && this->board[0][0] != 0) {
    return true;
  }
  if (this->board[0][0] == this->board[1][2] && this->board[1][2] == this->board[2][4] && this->board[0][0] != 0) {
    return true;
  }
  return false;
}

template<typename T>
bool Pyramic_X_O_Board<T>::is_draw() {
  return (this->n_moves == 9 && !is_win());
}

template<typename T>
bool Pyramic_X_O_Board<T>::game_is_over() {
  return is_win() || is_draw();
}

//--------------------------------------

// Constructor for Pyramic_X_O_Player
template<typename T>
Pyramic_X_O_Player<T>::Pyramic_X_O_Player(string name, T symbol) : Player<T>(name, symbol) {}

template<typename T>
void Pyramic_X_O_Player<T>::getmove(int &x, int &y) {
  cout << "\nPlease enter your move x and y (0 to 2 for x and corresponding y) separated by spaces: ";
  cin >> x >> y;
}

template<typename T>
void Pyramic_X_O_Player<T>::getmove(int &x, int &y, T &symbol) {
  cout << "\nPlease enter your move x and y (0 to 2 for x and corresponding y) separated by spaces: ";
  cin >> x >> y;
  symbol = this->symbol;
}


// Constructor for Pyramic_X_O_Random_Player
template<typename T>
Pyramic_X_O_Random_Player<T>::Pyramic_X_O_Random_Player(T symbol) : RandomPlayer<T>(symbol) {
  this->dimension = 3;
  this->name = "Random Computer Player";
  srand(static_cast<unsigned int>(time(0)));
}

template<typename T>
void Pyramic_X_O_Random_Player<T>::getmove(int &x, int &y) {
  x = rand() % 3;
  y = rand() % 5;
}

template<typename T>
void Pyramic_X_O_Random_Player<T>::getmove(int &x, int &y, T &symbol) {
  x = rand() % 3;
  y = rand() % 5;
  symbol = this->symbol;

}

#endif //_PYRAMIC_X_O_H