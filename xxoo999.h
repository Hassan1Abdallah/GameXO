//#ifndef _SUS_GAME_H
//#define _SUS_GAME_H
//
//#include "Board999.h"
//
//template<typename T>
//class Sus_Board : public G4_Board<T> {
//public:
//    Sus_Board();
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
//    virtual ~Sus_Board() override = default;
//};
//
//template<typename T>
//class Sus_Player : public Player<T> {
//public:
//    Sus_Player(string name, T symbol);
//
//    void getmove(int &x, int &y) override;
//
//    void getmove(int &x, int &y, T &symbol) override;
//
//    void setSymbol(T symbol) override;
//};
//
//template<typename T>
//class Sus_Random_Player : public RandomPlayer<T> {
//public:
//    Sus_Random_Player(T symbol);
//
//    void getmove(int &x, int &y) override;
//
//    void getmove(int &x, int &y, T &symbol) override;
//
//    void setSymbol(T symbol) override;
//};
//
////--------------------------------------- IMPLEMENTATION
//
//#include <iostream>
//#include <iomanip>
//#include <cctype>
//
//using namespace std;
//
//template<typename T>
//Sus_Board<T>::Sus_Board() {
//  this->rows = this->columns = 3;
//  this->board = new char *[this->rows];
//  for (int i = 0; i < this->rows; i++) {
//    this->board[i] = new char[this->columns];
//    for (int j = 0; j < this->columns; j++) {
//      this->board[i][j] = 0;
//    }
//  }
//  this->n_moves = 0;
//}
//
//template<typename T>
//bool Sus_Board<T>::update_board(int x, int y, T mark) {
//  if (!(x < 0 || x >= this->rows || y < 0 || y >= this->columns) && (this->board[x][y] == 0 || mark == 0)) {
//    if (mark == 0) {
//      this->n_moves--;
//      this->board[x][y] = 0;
//    } else {
//      this->n_moves++;
//      this->board[x][y] = toupper(mark);
//    }
//    return true;
//  }
//  return false;
//}
//
//template<typename T>
//void Sus_Board<T>::display_board() {
//  for (int i = 0; i < this->rows; i++) {
//    cout << "\n| ";
//    for (int j = 0; j < this->columns; j++) {
//      cout << "(" << i << "," << j << ")";
//      cout << setw(2) << this->board[i][j] << " |";
//    }
//    cout << "\n-----------------------------";
//  }
//  cout << endl;
//}
//
//template<typename T>
//bool Sus_Board<T>::is_win() {
//  for (int i = 0; i < this->rows; i++) {
//    if ((this->board[i][0] == 'S' && this->board[i][1] == 'U' && this->board[i][2] == 'S') ||
//        (this->board[0][i] == 'S' && this->board[1][i] == 'U' && this->board[2][i] == 'S')) {
//      return true;
//    }
//  }
//
//  if ((this->board[0][0] == 'S' && this->board[1][1] == 'U' && this->board[2][2] == 'S') ||
//      (this->board[0][2] == 'S' && this->board[1][1] == 'U' && this->board[2][0] == 'S')) {
//    return true;
//  }
//
//  return false;
//}
//
//template<typename T>
//bool Sus_Board<T>::is_draw() {
//  return (this->n_moves == 9 && !is_win());
//}
//
//template<typename T>
//bool Sus_Board<T>::game_is_over() {
//  return is_win() || is_draw();
//}
//
//template<typename T>
//Sus_Player<T>::Sus_Player(std::string name, T symbol) : Player<T>(name, symbol) {}
//
//template<typename T>
//void Sus_Player<T>::getmove(int &x, int &y) {
//  cout << this->name << "'s turn.\n";
//  cout << "\nPlease enter your move x and y (0 to 2) separated by spaces: ";
//  cin >> x >> y;
//}
//
//template<typename T>
//void Sus_Player<T>::getmove(int &x, int &y, T &symbol) {
//
//}
//
//template<typename T>
//void Sus_Player<T>::setSymbol(T symbol) {
//  this->symbol = symbol;
//}
//
//template<typename T>
//Sus_Random_Player<T>::Sus_Random_Player(T symbol) : RandomPlayer<T>(symbol) {
//  this->dimension = 3;
//  this->name = "Random Computer Player";
//  srand(static_cast<unsigned int>(time(0)));
//}
//
//template<typename T>
//void Sus_Random_Player<T>::getmove(int &x, int &y) {
//  x = rand() % this->dimension;
//  y = rand() % this->dimension;
//  cout << this->name << " played at (" << x << ", " << y << ").\n";
//}
//
//template<typename T>
//void Sus_Random_Player<T>::getmove(int &x, int &y, T &symbol) {
//
//}
//
//template<typename T>
//void Sus_Random_Player<T>::setSymbol(T symbol) {
//  this->symbol = symbol;
//}
//
//
//#endif //_SUS_GAME_H

#ifndef _SUS_GAME_H
#define _SUS_GAME_H

#include "BoardGame_Classes.h"

template<typename T>
class Sus_Board : public G4_Board<T> {
public:
    Sus_Board();

    bool update_board(int x, int y, T symbol) override;

    void display_board() override;

    bool is_win() override;

    bool is_draw() override;

    bool game_is_over() override;

    ~Sus_Board() override;
};

template<typename T>
class Sus_Player : public Player<T> {
public:
    Sus_Player(string name, T symbol);

    virtual void getmove(int &x, int &y) override;

    virtual void getmove(int &x, int &y, T &symbol) override;

    virtual void setSymbol(T symbol) override;
};

template<typename T>
class Sus_Random_Player : public RandomPlayer<T> {
public:
    Sus_Random_Player(T symbol);

    void getmove(int &x, int &y) override;

    void getmove(int &x, int &y, T &symbol) override;

    void setSymbol(T symbol) override;
};

//--------------------------------------- IMPLEMENTATION

#include <iostream>
#include <iomanip>
#include <cctype>

using namespace std;

template<typename T>
Sus_Board<T>::Sus_Board() {
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
bool Sus_Board<T>::update_board(int x, int y, T mark) {
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
void Sus_Board<T>::display_board() {
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
bool Sus_Board<T>::is_win() {
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
bool Sus_Board<T>::is_draw() {
  return (this->n_moves == 9 && !is_win());
}

template<typename T>
bool Sus_Board<T>::game_is_over() {
  return is_win() || is_draw();
}

template<typename T>
Sus_Player<T>::Sus_Player(std::string name, T symbol) : Player<T>(name, symbol) {}

template<typename T>
void Sus_Player<T>::getmove(int &x, int &y) {
  cout << this->name << "'s turn.\n";
  cout << "\nPlease enter your move x and y (0 to 2) separated by spaces: ";
  cin >> x >> y;
}

template<typename T>
void Sus_Player<T>::getmove(int &x, int &y, T &symbol) {

}

template<typename T>
void Sus_Player<T>::setSymbol(T symbol) {
  this->symbol = symbol;
}

template<typename T>
Sus_Random_Player<T>::Sus_Random_Player(T symbol) : RandomPlayer<T>(symbol) {
  this->dimension = 3;
  this->name = "Random Computer Player";
  srand(static_cast<unsigned int>(time(0)));
}

template<typename T>
void Sus_Random_Player<T>::getmove(int &x, int &y) {
  x = rand() % this->dimension;
  y = rand() % this->dimension;
  cout << this->name << " played at (" << x << ", " << y << ").\n";
}

template<typename T>
void Sus_Random_Player<T>::getmove(int &x, int &y, T &symbol) {
}

template<typename T>
void Sus_Random_Player<T>::setSymbol(T symbol) {
  this->symbol = symbol;
}

template<typename T>
Sus_Board<T>::~Sus_Board() = default;

#endif //_SUS_GAME_H