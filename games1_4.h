#ifndef GAMES1_4_H
#define GAMES1_4_H

#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include <iostream>
#include <vector>
#include <limits>
#include "BoardGame_Classes.h"

const int MAX_ROWS = 3;
const int MAX_COLS[] = {1, 3, 5}; // Pyramid dimensions

// Pyramid Board Implementation
class Pyramid : public Board<char> {
public:
    Pyramid() {
      rows = MAX_ROWS;
      columns = 5; // Max columns in the widest row
      board = new char *[rows];
      for (int i = 0; i < rows; ++i) {
        board[i] = new char[MAX_COLS[i]];
        fill(board[i], board[i] + MAX_COLS[i], ' ');
      }
    }

    ~Pyramid() {
      for (int i = 0; i < rows; ++i) {
        delete[] board[i];
      }
      delete[] board;
    }

    bool update_board(int x, int y, char symbol) override {
      if (x >= 0 && x < rows && y >= 0 && y < MAX_COLS[x] && board[x][y] == ' ') {
        board[x][y] = symbol;
        n_moves++;
        return true;
      }
      return false;
    }

    void display_board() override {
      cout << "\nCurrent Board:\n";
      for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < (rows - i - 1); ++j) cout << "  ";
        for (int j = 0; j < MAX_COLS[i]; ++j) {
          cout << "[" << (board[i][j] == ' ' ? '.' : board[i][j]) << "] ";
        }
        cout << endl;
      }
    }

    bool is_win() override {
      // Check horizontal
      for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < MAX_COLS[i] - 2; ++j) {
          if (board[i][j] != ' ' && board[i][j] == board[i][j + 1] && board[i][j] == board[i][j + 2]) {
            return true;
          }
        }
      }
      // Check vertical
      for (int j = 0; j < MAX_COLS[1]; ++j) {
        if (board[0][j] != ' ' && board[0][j] == board[1][j] && board[0][j] == board[2][j]) {
          return true;
        }
      }
      // Check diagonals
      if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[0][0] == board[2][2]) return true;
      if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[0][2] == board[2][4]) return true;
      return false;
    }

    bool is_draw() override {
      return n_moves == 9; // Max moves for Pyramid Tic Tac Toe
    }

    bool game_is_over() override {
      return is_win() || is_draw();
    }
};

// Human Player Implementation
class PyramidPlayer : public Player<char> {
public:
    PyramidPlayer(string name, char symbol) : Player<char>(name, symbol) {}

    void getmove(int &x, int &y) override {
      cout << getname() << " (" << getsymbol() << "), enter your move (row and column) starting at index 1: ";
      cin >> x >> y;
      x--;
      y--; // Convert to 0-based indexing
    }
};

// Extend RandomPlayer for Pyramid Tic Tac Toe
class RandomPyramidPlayer : public RandomPlayer<char> {
public:
    RandomPyramidPlayer(char symbol) : RandomPlayer<char>(symbol) {}

    void getmove(int &x, int &y) override {
      x = rand() % MAX_ROWS;
      y = rand() % MAX_COLS[x];
    }
};



// ---------------------------- GAME NUMBER 4 --------------------


const int SIZE = 3;
set <string> validWords;

// Load valid 3-letter words from the dictionary file
void loadDictionary(const string &filename) {
  ifstream file(filename);
  string word;
  while (file >> word) {
    if (word.length() == 3) {
      validWords.insert(word);
    }
  }
}

// WordBoard class inheriting from the Board class
class WordBoard : public Board<char> {
public:
    // Constructor to initialize the board
    WordBoard() {
      rows = SIZE;
      columns = SIZE;
      board = new char *[rows];
      for (int i = 0; i < rows; ++i) {
        board[i] = new char[columns];
        for (int j = 0; j < columns; ++j) {
          board[i][j] = ' ';
        }
      }
    }

    // Destructor to clean up dynamically allocated memory
    ~WordBoard() {
      for (int i = 0; i < rows; ++i) {
        delete[] board[i];
      }
      delete[] board;
    }

    // Implement the update_board function to place a symbol on the board
    bool update_board(int x, int y, char symbol) override {
      if (x >= 0 && x < rows && y >= 0 && y < columns && board[x][y] == ' ') {
        board[x][y] = symbol;
        return true;
      }
      return false;
    }

    // Implement display_board to show the current state of the board
    void display_board() override {
      cout << "\nCurrent Board:\n";
      for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
          cout << (board[i][j] == ' ' ? '.' : board[i][j]);
          if (j < columns - 1) cout << " | ";
        }
        cout << endl;
        if (i < rows - 1) cout << "---+---+---" << endl;
      }
      cout << endl;
    }

    // Implement is_win to check if a valid word has been formed
    bool is_win() override {
      // Check rows
      for (int i = 0; i < rows; ++i) {
        string rowWord = "";
        for (int j = 0; j < columns; ++j) {
          rowWord += board[i][j];
        }
        if (rowWord.length() == 3 && validWords.find(rowWord) != validWords.end()) return true;
      }

      // Check columns
      for (int j = 0; j < columns; ++j) {
        string colWord = "";
        for (int i = 0; i < rows; ++i) {
          colWord += board[i][j];
        }
        if (colWord.length() == 3 && validWords.find(colWord) != validWords.end()) return true;
      }

      // Check diagonals
      string diag1 = "", diag2 = "";
      for (int i = 0; i < rows; ++i) {
        diag1 += board[i][i];
        diag2 += board[i][columns - 1 - i];
      }
      if ((diag1.length() == 3 && validWords.find(diag1) != validWords.end()) ||
          (diag2.length() == 3 && validWords.find(diag2) != validWords.end()))
        return true;

      return false;
    }

    // Implement is_draw to check if the game is a draw (no empty spots)
    bool is_draw() override {
      for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
          if (board[i][j] == ' ') return false;
        }
      }
      return true;
    }

    // Implement game_is_over to check if the game is over (win or draw)
    bool game_is_over() override {
      return is_win() || is_draw();
    }
};


// Random player for Word Tic Tac Toe
class RandomWordPlayer {
public:
    char symbol;

    RandomWordPlayer(char s) : symbol(s) {}

    // Makes a random move
    void make_move(WordBoard &board) {
      int row, col;
      char letter;
      bool validMove = false;

      while (!validMove) {
        // Generate random row, col, and letter
        row = rand() % SIZE;
        col = rand() % SIZE;
        letter = 'A' + rand() % 26;  // Random letter from A-Z

        // Try to update the board with the random move
        validMove = board.update_board(row, col, letter);
      }
    }
};

void word_run() {
  // Initialize the board with WordBoard
  WordBoard board;

  char currentPlayer = 'X'; // Start with player 'X'
  bool gameRunning = true;

  int choice6;

  cout << "Do you want to play against a random computer player? (1-Yes, 0-No): ";
  cin >> choice6;

  RandomWordPlayer *computerPlayer = nullptr;
  if (choice6 == 1) {
    computerPlayer = new RandomWordPlayer('O');
  }

  while (gameRunning) {
    board.display_board();

    // If it's the user's turn, ask for input
    if (currentPlayer == 'X') {
      int row, col;
      char letter;

      while (true) { // Loop until valid input is provided
        cout << "Player " << currentPlayer << ", enter your move (row, col, letter): ";
        cin >> row >> col >> letter;

        if (cin.fail()) { // Check if input is invalid
          cin.clear(); // Clear the error flag
          cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
          cout << "Invalid move! Please enter numbers for row and col, followed by a letter." << endl;
        } else {
          // Convert to 0-based indexing
          row--;
          col--;

          // Validate and make the move
          if (board.update_board(row, col, letter)) {
            break; // Exit the loop if the move is valid
          } else {
            cout << "Invalid move! Try again." << endl;
          }
        }
      }

      if (board.is_win()) {
        board.display_board();
        cout << "Player " << currentPlayer << " wins by forming a word!" << endl;
        gameRunning = false;
      } else if (board.is_draw()) {
        board.display_board();
        cout << "It's a draw! The board is full." << endl;
        gameRunning = false;
      } else {
        // Switch to the other player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
      }
    }
      // If it's the computer's turn, make a random move
    else if (currentPlayer == 'O' && computerPlayer) {
      computerPlayer->make_move(board);
      if (board.is_win()) {
        board.display_board();
        cout << "Computer (Player " << currentPlayer << ") wins by forming a word!" << endl;
        gameRunning = false;
      } else if (board.is_draw()) {
        board.display_board();
        cout << "It's a draw! The board is full." << endl;
        gameRunning = false;
      } else {
        // Switch to the other player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
      }
    }
  }

  // Clean up the computer player object if necessary
  if (computerPlayer) {
    delete computerPlayer;
  }
}

#endif //GAMES1_4_H
