#ifndef _BOARDGAME_CLASSES_H
#define _BOARDGAME_CLASSES_H

#include <string>
#include <vector>

using namespace std;

// Base class for all boards
template<typename T>
class Board {
protected:
    int rows, columns;
    T **board;
    int n_moves = 0;

public:
    virtual bool update_board(int x, int y, T symbol) = 0;

    virtual void display_board() = 0;

    virtual bool is_win() = 0;

    virtual bool is_draw() = 0;

    virtual bool game_is_over() = 0;
    virtual ~Board()
    {
      if (board)
      {
        for (int i = 0; i < rows; ++i)
        {
          delete[] board[i];
        }
        delete[] board;
        board = nullptr;
      }

    }
};

template<typename T>
class G4_Board {
protected:
    int rows, columns;
    T **board;
    int n_moves = 0;

public:
    virtual bool update_board(int x, int y, T symbol) = 0;

    virtual void display_board() = 0;

    virtual bool is_win() = 0;

    virtual bool is_draw() = 0;

    virtual bool game_is_over() = 0;
    virtual ~G4_Board()
    {
      if (board)
      {
        for (int i = 0; i < rows; ++i)
        {
          delete[] board[i];
        }
        delete[] board;
        board = nullptr;
      }

    }
};
// Base class for all players
template<typename T>
class Player {
protected:
    string name;
    T symbol;
    Board<T>* boardPtr;
    G4_Board<T>* g4BoardPtr;
public:
    Player(string n, T symbol);

    Player(T symbol);

    virtual void getmove(int &x, int &y) = 0;
    virtual void getmove(int &x, int &y, T &symbol) = 0;

    T getsymbol();

    string getname();
    void setBoard(Board<T> *b);
    void setBoard(G4_Board<T> *b);
    virtual void setSymbol(T symbol) ;
};
// Base class for random players
template<typename T>
class RandomPlayer : public Player<T> {
protected:
    int dimension;
public:
    RandomPlayer(T symbol);

    virtual void getmove(int &x, int &y) = 0;
    virtual void getmove(int &x, int &y, T &symbol) = 0;
};

// Base class for game managers
template<typename T>
class GameManager {
private:
    Board<T> *boardPtr;
    G4_Board<T> *g4BoardPtr;
    Player<T> *players[2];
public:
    GameManager(Board<T> *, Player<T> *playerPtr[2]);
    GameManager(G4_Board<T> *, Player<T> *playerPtr[2]);
    void run();
};

//--------------------------------------- IMPLEMENTATION

#include <iostream>

using namespace std;

template<typename T>
GameManager<T>::GameManager(Board<T> *bPtr, Player<T> *playerPtr[2]) {
  boardPtr = bPtr;
  players[0] = playerPtr[0];
  players[1] = playerPtr[1];
}
template<typename T>
GameManager<T>::GameManager(G4_Board<T> *bPtr, Player<T> *playerPtr[2]) {
  g4BoardPtr = bPtr;
  players[0] = playerPtr[0];
  players[1] = playerPtr[1];
}

template<typename T>
void GameManager<T>::run() {
  int x, y;
  T symbol;

  if(boardPtr){
    boardPtr->display_board();
    while (!boardPtr->game_is_over()) {
      for (int i: {0, 1}) {
        players[i]->getmove(x, y);
        while (!boardPtr->update_board(x, y, players[i]->getsymbol())) {
          players[i]->getmove(x, y);
        }
        boardPtr->display_board();
        if (boardPtr->is_win()) {
          cout << players[i]->getname() << " wins\n";
          return;
        }
        if (boardPtr->is_draw()) {
          cout << "Draw!\n";
          return;
        }
      }
    }

  }else if (g4BoardPtr){
    g4BoardPtr->display_board();

    while (!g4BoardPtr->game_is_over()) {
      for (int i: {0, 1}) {

        players[i]->getmove(x, y, symbol);
        while (!g4BoardPtr->update_board(x, y, symbol)) {
          players[i]->getmove(x, y, symbol);
        }
        g4BoardPtr->display_board();
        if (g4BoardPtr->is_win()) {
          cout << players[i]->getname() << " wins\n";
          return;
        }
        if (g4BoardPtr->is_draw()) {
          cout << "Draw!\n";
          return;
        }
      }
    }

  }
}

template<typename T>
Player<T>::Player(std::string n, T symbol) {
  this->name = n;
  this->symbol = symbol;
}

template<typename T>
Player<T>::Player(T symbol) {
  this->name = "Computer";
  this->symbol = symbol;
}

template<typename T>
RandomPlayer<T>::RandomPlayer(T symbol) : Player<T>(symbol) {}

template<typename T>
std::string Player<T>::getname() {
  return this->name;
}

template<typename T>
T Player<T>::getsymbol() {
  return this->symbol;
}

template<typename T>
void Player<T>::setBoard(Board<T> *b) {
  this->boardPtr = b;
}
template<typename T>
void Player<T>::setBoard(G4_Board<T> *b) {
  this->g4BoardPtr = b;
}
template <typename T>
void Player<T>::setSymbol(T symbol)
{
  this->symbol = symbol;
}

#endif //_BOARDGAME_CLASSES_H