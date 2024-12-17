//#ifndef MISERE_XO_H
//#define MISERE_XO_H
//
//#include "BoardGame_Classes.h"
//#include <iostream>
//#include <iomanip>
//
//using namespace std;
//
//
//template <typename T>
//class MisereBoard : public Board<T> {
//public:
//    MisereBoard();
//    bool update_board(int x, int y, T symbol) override;
//    void display_board() override;
//    bool is_win() override;
//    bool is_loss();
//    bool is_draw() override;
//    bool game_is_over() override;
//};
//
//template <typename T>
//class MiserePlayer : public Player<T> {
//public:
//    MiserePlayer(string n, T symbol);
//    void getmove(int& x, int& y) override;
//};
//
////--------------------------------------- IMPLEMENTATION
//
//template <typename T>
//MisereBoard<T>::MisereBoard() {
//    this->rows = this->columns = 3;
//    this->board = new T*[this->rows];
//    for (int i = 0; i < this->rows; i++) {
//        this->board[i] = new T[this->columns]();
//    }
//}
//
//template <typename T>
//bool MisereBoard<T>::update_board(int x, int y, T symbol) {
//    if (x >= 0 && x < this->rows && y >= 0 && y < this->columns && this->board[x][y] == 0) {
//        this->board[x][y] = symbol;
//        this->n_moves++;
//
//        display_board();
//
//        if (is_loss()) {
//            cout << " Player " << symbol << " loses ";
//            exit(0);
//        }
//
//        if (is_draw()) {
//            cout << "Game Over: It's a draw!\n";
//            exit(0);
//        }
//
//        return true;
//    }
//    return false;
//}
//
//template <typename T>
//void MisereBoard<T>::display_board() {
//    for (int i = 0; i < this->rows; i++) {
//        cout << "\n| ";
//        for (int j = 0; j < this->columns; j++) {
//            cout << setw(2) << (this->board[i][j] ? this->board[i][j] : '-') << " |";
//        }
//        cout << "\n-------------------";
//    }
//    cout << endl;
//}
//
//template <typename T>
//bool MisereBoard<T>::is_win() {
//    return false;
//}
//
//template <typename T>
//bool MisereBoard<T>::is_loss() {
//    for (int i = 0; i < this->rows; i++) {
//        if (this->board[i][0] != 0 && this->board[i][0] == this->board[i][1] && this->board[i][1] == this->board[i][2])
//            return true;
//    }
//
//    for (int i = 0; i < this->columns; i++) {
//        if (this->board[0][i] != 0 && this->board[0][i] == this->board[1][i] && this->board[1][i] == this->board[2][i])
//            return true;
//    }
//
//    if ((this->board[0][0] != 0 && this->board[0][0] == this->board[1][1] && this->board[1][1] == this->board[2][2]) ||
//        (this->board[0][2] != 0 && this->board[0][2] == this->board[1][1] && this->board[1][1] == this->board[2][0]))
//        return true;
//
//    return false;
//}
//
//template <typename T>
//bool MisereBoard<T>::is_draw() {
//    return this->n_moves == 9 && !is_loss();
//}
//
//template <typename T>
//bool MisereBoard<T>::game_is_over() {
//    if (is_loss()) {
//        cout << "A player has lost";
//        return true;
//    }
//    if (is_draw()) {
//        cout << "Game Over: It's a draw!\n";
//        return true;
//    }
//    return false;
//}
//
//template <typename T>
//MiserePlayer<T>::MiserePlayer(string n, T symbol) : Player<T>(n, symbol) {}
//
//template <typename T>
//void MiserePlayer<T>::getmove(int& x, int& y) {
//    cout << this->getname() << ", enter your move (row and column 0-2): ";
//    cin >> x >> y;
//}
//
//#endif


#ifndef MISERE_XO_H
#define MISERE_XO_H

#include "BoardGame_Classes.h"
#include <iostream>
#include <iomanip>

using namespace std;

template<typename T>
class MisereBoard : public Board<T> {
public:
    MisereBoard();

    bool update_board(int x, int y, T symbol) override;

    void display_board() override;

    bool is_win() override;

    bool is_loss();

    bool is_draw() override;

    bool game_is_over() override;
};

template<typename T>
class MiserePlayer : public Player<T> {
public:
    MiserePlayer(string n, T symbol);

    void getmove(int &x, int &y) override;

    void getmove(int &x, int &y, T &symbol) override;
};

//--------------------------------------- IMPLEMENTATION

template<typename T>
MisereBoard<T>::MisereBoard() {
  this->rows = this->columns = 3;
  this->board = new T *[this->rows];
  for (int i = 0; i < this->rows; i++) {
    this->board[i] = new T[this->columns]();
  }
}

template<typename T>
bool MisereBoard<T>::update_board(int x, int y, T symbol) {
  if (x >= 0 && x < this->rows && y >= 0 && y < this->columns && this->board[x][y] == 0) {
    this->board[x][y] = symbol;
    this->n_moves++;

    display_board();

    if (is_loss()) {
      cout << " Player " << symbol << " loses ";
      exit(0);
    }

    if (is_draw()) {
      cout << "Game Over: It's a draw!\n";
      exit(0);
    }

    return true;
  }
  return false;
}

template<typename T>
void MisereBoard<T>::display_board() {
  for (int i = 0; i < this->rows; i++) {
    cout << "\n| ";
    for (int j = 0; j < this->columns; j++) {
      cout << setw(2) << (this->board[i][j] ? this->board[i][j] : '-') << " |";
    }
    cout << "\n-------------------";
  }
  cout << endl;
}

template<typename T>
bool MisereBoard<T>::is_win() {
  return false;
}

template<typename T>
bool MisereBoard<T>::is_loss() {
  for (int i = 0; i < this->rows; i++) {
    if (this->board[i][0] != 0 && this->board[i][0] == this->board[i][1] && this->board[i][1] == this->board[i][2])
      return true;
  }

  for (int i = 0; i < this->columns; i++) {
    if (this->board[0][i] != 0 && this->board[0][i] == this->board[1][i] && this->board[1][i] == this->board[2][i])
      return true;
  }

  if ((this->board[0][0] != 0 && this->board[0][0] == this->board[1][1] && this->board[1][1] == this->board[2][2]) ||
      (this->board[0][2] != 0 && this->board[0][2] == this->board[1][1] && this->board[1][1] == this->board[2][0]))
    return true;

  return false;
}

template<typename T>
bool MisereBoard<T>::is_draw() {
  return this->n_moves == 9 && !is_loss();
}

template<typename T>
bool MisereBoard<T>::game_is_over() {
  if (is_loss()) {
    cout << "A player has lost";
    return true;
  }
  if (is_draw()) {
    cout << "Game Over: It's a draw!\n";
    return true;
  }
  return false;
}

template<typename T>
MiserePlayer<T>::MiserePlayer(string n, T symbol) : Player<T>(n, symbol) {}

template<typename T>
void MiserePlayer<T>::getmove(int &x, int &y) {
  cout << this->getname() << ", enter your move (row and column 0-2): ";
  cin >> x >> y;
}

template<typename T>
void MiserePlayer<T>::getmove(int &x, int &y, T &symbol) {
  cout << this->getname() << ", enter your move (row and column 0-2): ";
  cin >> x >> y;
  symbol = this->symbol;
}

#endif