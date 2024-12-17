#ifndef _WORD_CHAR_H
#define _WORD_CHAR_H

#include "BoardGame_Classes.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

template<typename T>
class Word_Char_Board : public G4_Board<T> {
private:
    vector<string> dictionary;

    bool is_valid_word(const string &word);

    void load_dictionary(const string &filename);

public:
    Word_Char_Board();

    bool update_board(int x, int y, T symbol) override;

    void display_board() override;

    bool is_win() override;

    bool is_draw() override;

    bool game_is_over() override;

    virtual ~Word_Char_Board() override = default;
};

template<typename T>
class Word_Char_Player : public Player<T> {
public:
    Word_Char_Player(string name, T symbol);

    void getmove(int &x, int &y) override;

    void getmove(int &x, int &y, T &symbol) override;
};

template<typename T>
class Word_Char_Random_Player : public RandomPlayer<T> {
public:
    Word_Char_Random_Player(T symbol);

    void getmove(int &x, int &y) override;

    void getmove(int &x, int &y, T &symbol) override;
};

//--------------------------------------- IMPLEMENTATION

#include <iostream>
#include <iomanip>
#include <cctype>
#include <cstdlib>
#include <ctime>


using namespace std;


template<typename T>
Word_Char_Board<T>::Word_Char_Board() {
  this->rows = this->columns = 3;
  this->board = new char *[this->rows];
  for (int i = 0; i < this->rows; i++) {
    this->board[i] = new char[this->columns];
    for (int j = 0; j < this->columns; j++) {
      this->board[i][j] = 0;
    }
  }
  this->n_moves = 0;
  load_dictionary("dic.txt");
}

template<typename T>
void Word_Char_Board<T>::load_dictionary(const string &filename) {
  ifstream file(filename);
  if (file.is_open()) {
    string word;
    while (file >> word) {
      dictionary.push_back(word);
    }
    file.close();
  } else {
    cerr << "Error: Unable to open dictionary file: " << filename << endl;
  }
}

template<typename T>
bool Word_Char_Board<T>::is_valid_word(const string &word) {
  return find(dictionary.begin(), dictionary.end(), word) != dictionary.end();
}

template<typename T>
bool Word_Char_Board<T>::update_board(int x, int y, T mark) {
  // Only update if move is valid
  if (!(x < 0 || x >= this->rows || y < 0 || y >= this->columns) && (this->board[x][y] == 0)) {
    this->n_moves++;
    this->board[x][y] = toupper(mark);
    return true;
  }
  return false;
}

template<typename T>
void Word_Char_Board<T>::display_board() {
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

// Returns true if there is any winner
template<typename T>
bool Word_Char_Board<T>::is_win() {

  // Check rows and columns
  for (int i = 0; i < this->rows; i++) {
    string row_str;
    for (int j = 0; j < this->columns; j++) {
      row_str += this->board[i][j];
    }
    if (is_valid_word(row_str)) {
      return true;
    }
  }
  for (int i = 0; i < this->columns; i++) {
    string col_str;
    for (int j = 0; j < this->rows; j++) {
      col_str += this->board[j][i];
    }
    if (is_valid_word(col_str)) {
      return true;
    }
  }

  // Check diagonals
  string diag1_str;
  diag1_str += this->board[0][0];
  diag1_str += this->board[1][1];
  diag1_str += this->board[2][2];
  if (is_valid_word(diag1_str)) {
    return true;
  }
  string diag2_str;
  diag2_str += this->board[0][2];
  diag2_str += this->board[1][1];
  diag2_str += this->board[2][0];
  if (is_valid_word(diag2_str)) {
    return true;
  }

  return false;
}

// Return true if 9 moves are done and no winner
template<typename T>
bool Word_Char_Board<T>::is_draw() {
  return (this->n_moves == 9 && !is_win());
}

template<typename T>
bool Word_Char_Board<T>::game_is_over() {
  return is_win() || is_draw();
}

//--------------------------------------


template<typename T>
Word_Char_Player<T>::Word_Char_Player(string name, T symbol) : Player<T>(name, symbol) {}

template<typename T>
void Word_Char_Player<T>::getmove(int &x, int &y, T &symbol) {
  cout << "\nPlease enter your move x and y (0 to 2) separated by spaces and your char: ";
  cin >> x >> y >> symbol;
}

template<typename T>
void Word_Char_Player<T>::getmove(int &x, int &y) {
  cout << "\nPlease enter your move x and y (0 to 2) separated by spaces : ";
  cin >> x >> y;
}

template<typename T>
Word_Char_Random_Player<T>::Word_Char_Random_Player(T symbol) : RandomPlayer<T>(symbol) {
  this->dimension = 3;
  this->name = "Random Computer Player";
  srand(static_cast<unsigned int>(time(0)));
}

template<typename T>
void Word_Char_Random_Player<T>::getmove(int &x, int &y, T &symbol) {
  x = rand() % this->dimension;
  y = rand() % this->dimension;
  symbol = (rand() % 26) + 'A';
}

template<typename T>
void Word_Char_Random_Player<T>::getmove(int &x, int &y) {
  x = rand() % this->dimension;
  y = rand() % this->dimension;
}

#endif //_WORD_CHAR_H