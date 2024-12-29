#ifndef GAMES8_9_H
#define GAMES8_9_H

#include "BoardGame_Classes.h"
#include <iostream>
#include <vector>
using namespace std;


class UltimateBoard : public Board<char>
{
private:
    vector<vector<char>> mainBoard;         // 3x3 grid for the main board
    vector<vector<vector<char>>> subBoards; // 3x3x3 grids for smaller boards
    char currentPlayer;
    int n_moves;

public:
    // Constructor
    UltimateBoard() : mainBoard(3, vector<char>(3, '-')),
                      subBoards(3, vector<vector<char>>(3, vector<char>(9, '-'))),
                      currentPlayer('X'), n_moves(0) {}

    // Simple implementation of pure virtual function
    bool update_board(int x, int y, char symbol) override
    {
        return true;
    }

    // Display the main board and sub-boards
    void display_board() override
    {
        cout << "\nMain Board:" << endl;
        for (const auto &row : mainBoard)
        {
            for (char cell : row)
            {
                cout << cell << " ";
            }
            cout << endl;
        }

        cout << "\nSub Boards:" << endl;
        for (int i = 0; i < 3; ++i)
        {
            for (int subRow = 0; subRow < 3; ++subRow)
            {
                for (int j = 0; j < 3; ++j)
                {
                    for (int k = 0; k < 3; ++k)
                    {
                        cout << subBoards[i][j][subRow * 3 + k] << " ";
                    }
                    cout << "   ";
                }
                cout << endl;
            }
            cout << endl;
        }
    }

    // Check if a sub-board is won
    bool checkSubBoardWin(const vector<char> &subBoard)
    {
        return (subBoard[0] == currentPlayer && subBoard[1] == currentPlayer && subBoard[2] == currentPlayer) ||
               (subBoard[3] == currentPlayer && subBoard[4] == currentPlayer && subBoard[5] == currentPlayer) ||
               (subBoard[6] == currentPlayer && subBoard[7] == currentPlayer && subBoard[8] == currentPlayer) ||
               (subBoard[0] == currentPlayer && subBoard[3] == currentPlayer && subBoard[6] == currentPlayer) ||
               (subBoard[1] == currentPlayer && subBoard[4] == currentPlayer && subBoard[7] == currentPlayer) ||
               (subBoard[2] == currentPlayer && subBoard[5] == currentPlayer && subBoard[8] == currentPlayer) ||
               (subBoard[0] == currentPlayer && subBoard[4] == currentPlayer && subBoard[8] == currentPlayer) ||
               (subBoard[2] == currentPlayer && subBoard[4] == currentPlayer && subBoard[6] == currentPlayer);
    }

    // Check if the main board is won
    bool is_win() override
    {
        return (mainBoard[0][0] == currentPlayer && mainBoard[0][1] == currentPlayer && mainBoard[0][2] == currentPlayer) ||
               (mainBoard[1][0] == currentPlayer && mainBoard[1][1] == currentPlayer && mainBoard[1][2] == currentPlayer) ||
               (mainBoard[2][0] == currentPlayer && mainBoard[2][1] == currentPlayer && mainBoard[2][2] == currentPlayer) ||
               (mainBoard[0][0] == currentPlayer && mainBoard[1][0] == currentPlayer && mainBoard[2][0] == currentPlayer) ||
               (mainBoard[0][1] == currentPlayer && mainBoard[1][1] == currentPlayer && mainBoard[2][1] == currentPlayer) ||
               (mainBoard[0][2] == currentPlayer && mainBoard[1][2] == currentPlayer && mainBoard[2][2] == currentPlayer) ||
               (mainBoard[0][0] == currentPlayer && mainBoard[1][1] == currentPlayer && mainBoard[2][2] == currentPlayer) ||
               (mainBoard[0][2] == currentPlayer && mainBoard[1][1] == currentPlayer && mainBoard[2][0] == currentPlayer);
    }

    // Check for draw
    bool is_draw() override
    {
        return n_moves == 81; // Max moves for Ultimate Tic Tac Toe
    }

    // Check if the game is over
    bool game_is_over() override
    {
        return is_win() || is_draw();
    }

    // Make a move on the board
    bool makeMove(int boardRow, int boardCol, int row, int col)
    {
        if (boardRow < 0 || boardRow >= 3 || boardCol < 0 || boardCol >= 3 ||
            row < 0 || row >= 3 || col < 0 || col >= 3 ||
            subBoards[boardRow][boardCol][row * 3 + col] != '-')
        {
            cout << "Invalid move!" << endl;
            return false;
        }

        if (mainBoard[boardRow][boardCol] != '-')
        {
            cout << "This sub-board has already been won!" << endl;
            return false;
        }

        subBoards[boardRow][boardCol][row * 3 + col] = currentPlayer;
        n_moves++;

        if (checkSubBoardWin(subBoards[boardRow][boardCol]))
        {
            mainBoard[boardRow][boardCol] = currentPlayer;
            cout << "Player " << currentPlayer << " wins sub-board (" << boardRow << ", " << boardCol << ")!" << endl;

            if (is_win())
            {
                cout << "Player " << currentPlayer << " wins the game!" << endl;
                return true;
            }
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        return true;
    }

    char currentPlayerSymbol() const
    {
        return currentPlayer;
    }
};

// Human vs Human gameplay
void human_vs_human(UltimateBoard &game)
{
    while (!game.game_is_over())
    {
        game.display_board();
        int boardRow, boardCol, row, col;
        cout << "Player " << game.currentPlayerSymbol() << ", enter (boardRow, boardCol, row, col): ";
        cin >> boardRow >> boardCol >> row >> col;

        if (!game.makeMove(boardRow, boardCol, row, col))
        {
            cout << "Try again!" << endl;
        }
    }
}

// Simple AI logic: random moves
void human_vs_computer(UltimateBoard &game)
{
    srand(time(0));

    while (!game.game_is_over())
    {
        game.display_board();
        if (game.currentPlayerSymbol() == 'X')
        {
            int boardRow, boardCol, row, col;
            cout << "Player X, enter (boardRow, boardCol, row, col): ";
            cin >> boardRow >> boardCol >> row >> col;

            if (!game.makeMove(boardRow, boardCol, row, col))
            {
                cout << "Try again!" << endl;
            }
        }
        else
        {
            cout << "AI (Player O) is making a move..." << endl;
            int boardRow, boardCol, row, col;
            do
            {
                boardRow = rand() % 3;
                boardCol = rand() % 3;
                row = rand() % 3;
                col = rand() % 3;
            } while (!game.makeMove(boardRow, boardCol, row, col));
        }
    }
}


//------------------------------- GAME NUMBER  9  SUS ---------------------


using namespace std;

const int SIZE4 = 3;
const string WIN_SEQUENCE = "SUS"; // Sequence to win


// SUSBoard class inheriting from Board
class SUSBoard : public Board<char> {
public:
    // Constructor to initialize the board
    SUSBoard() {
        rows = SIZE4;
        columns = SIZE4;
        board = new char* [rows];
        for (int i = 0; i < rows; ++i) {
            board[i] = new char[columns];
            for (int j = 0; j < columns; ++j) {
                board[i][j] = '.'; // Empty cells initialized to '.'
            }
        }
    }

    // Destructor to clean up allocated memory
    ~SUSBoard() {
        for (int i = 0; i < rows; ++i) {
            delete[] board[i];
        }
        delete[] board;
    }

    void get_computer_move(SUSBoard& board, int& row, int& col) {
        vector<pair<int, int>> emptyCells;
        for (int i = 0; i < SIZE4; ++i) {
            for (int j = 0; j < SIZE4; ++j) {
                if (board.board[i][j] == '.') { // Check directly if cell is empty
                    emptyCells.push_back({ i, j });
                }
            }
        }
        if (!emptyCells.empty()) {
            int index = rand() % emptyCells.size();
            row = emptyCells[index].first;
            col = emptyCells[index].second;
        }
    }

    // Display the board
    void display_board() override {
        cout << "\nCurrent Board:\n";
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                cout << board[i][j];
                if (j < columns - 1) cout << " | ";
            }
            cout << endl;
            if (i < rows - 1) cout << "---+---+---" << endl;
        }
        cout << endl;
    }

    // Update the board with a player's move
    bool update_board(int row, int col, char symbol) override {
        if (row >= 0 && row < rows && col >= 0 && col < columns && board[row][col] == '.') {
            board[row][col] = symbol;
            n_moves++;
            return true;
        }
        return false;
    }

    // Check for "SUS" sequences in rows, columns, and diagonals
    bool check_sus_sequence(int row, int col, char symbol) {
        // Check the row for "SUS"
        string rowSequence = string(1, board[row][0]) + board[row][1] + board[row][2];
        if (rowSequence == WIN_SEQUENCE) return true;

        // Check the column for "SUS"
        string colSequence = string(1, board[0][col]) + board[1][col] + board[2][col];
        if (colSequence == WIN_SEQUENCE) return true;

        // Check the diagonals for "SUS"
        if (row == col) { // Check main diagonal
            string diag1 = string(1, board[0][0]) + board[1][1] + board[2][2];
            if (diag1 == WIN_SEQUENCE) return true;
        }
        if (row + col == SIZE4 - 1) { // Check anti-diagonal
            string diag2 = string(1, board[0][2]) + board[1][1] + board[2][0];
            if (diag2 == WIN_SEQUENCE) return true;
        }

        return false;
    }

    // Check if there is any winner
    bool is_win() override {
        // This method can be expanded as needed
        return false;
    }

    // Check if the game is a draw
    bool is_draw() override {
        return n_moves == rows * columns;
    }

    // Check if the game is over
    bool game_is_over() override {
        return is_win() || is_draw();
    }
};


// Function to get a random empty cell for the computer's move


// Function to validate user input
bool get_valid_input(int& row, int& col) {
    cout << "Enter your move (row, col): ";
    if (!(cin >> row >> col)) {
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        cout << "Invalid input! Please enter numbers only.\n";
        return false;
    }
    return true;
}
// Function to run the SUS game with an option to play against a computer
void sus_game() {
    srand(time(0)); // Seed for random number generator
    SUSBoard board;
    bool gameRunning = true;
    int currentPlayer = 1; // Player 1 starts
    int player1Score = 0, player2Score = 0;
    char currentLetter;

    // Ask the user if they want to play against the computer
    bool playAgainstComputer;
    cout << "Do you want to play against the computer? (1 for Yes, 0 for No): ";
    cin >> playAgainstComputer;

    while (gameRunning) {
        board.display_board();
        int row, col;

        // Determine which player's turn it is and the letter to place
        if (currentPlayer == 1) {
            currentLetter = 'S'; // Player 1 uses 'S'
            if (!get_valid_input(row, col)) {
                continue; // Retry if input is invalid
            }
            row--; col--; // Convert to 0-based indexing
        }
        else {
            currentLetter = 'U'; // Player 2 uses 'U'
            if (playAgainstComputer) {
                cout << "Computer (U) is making a move...\n";
                board.get_computer_move(board, row, col);
            }
            else {
                if (!get_valid_input(row, col)) {
                    continue; // Retry if input is invalid
                }
                row--; col--; // Convert to 0-based indexing
            }
        }

        // Make the move
        if (board.update_board(row, col, currentLetter)) {
            // After placing the move, check if a "SUS" sequence is formed
            bool isSUS = board.check_sus_sequence(row, col, currentLetter);

            // Update the score only if a valid "SUS" sequence is created
            if (isSUS) {
                if (currentPlayer == 1) {
                    player1Score++;  // Update Player 1's score
                }
                else {
                    player2Score++;  // Update Player 2's score
                }
            }

            // Display the updated score after checking for sequences
            cout << "Score - Player 1: " << player1Score << " | Player 2: " << player2Score << endl;

            // Check if the game is over (board is full or win condition is met)
            if (board.game_is_over()) {
                gameRunning = false;
                board.display_board();
                cout << "Game over!\n";
                // Declare the winner
                if (player1Score > player2Score) {
                    cout << "Player 1 wins with " << player1Score << " SUS sequences!\n";
                }
                else if (player2Score > player1Score) {
                    cout << "Player 2 wins with " << player2Score << " SUS sequences!\n";
                }
                else {
                    cout << "It's a draw! Both players have " << player1Score << " SUS sequences.\n";
                }
            }
            else {
                // Switch to the other player
                currentPlayer = (currentPlayer == 1) ? 2 : 1;
            }
        }
        else {
            cout << "Invalid move! The cell is already occupied. Try again.\n";
        }
    }
}



/*
void sus_game(bool vsComputer) {
    SUSBoard board;
    int player1Score = 0, player2Score = 0;
    int currentPlayer = 1;
    bool gameRunning = true;
    char currentLetter;
    int row, col;

    string player1Name, player2Name;

    // Set player names
    cout << "Enter name for Player 1 (S): ";
    cin >> player1Name;

    if (vsComputer) {
        player2Name = "Computer (U)";
    } else {
        cout << "Enter name for Player 2 (U): ";
        cin >> player2Name;
    }

    SUSRandomPlayer computer('U');
    if (vsComputer) {
        computer.setBoard(&board);
    }

    while (gameRunning) {
        board.display_board();
        if (currentPlayer == 1) {
            currentLetter = 'S';
            cout << player1Name << " (S), enter your move (row, col): ";
            cin >> row >> col;
            row--; col--;
        } else {
            currentLetter = 'U';
            if (vsComputer) {
                cout << player2Name << " is making a move...\n";
                computer.getmove(row, col);
            } else {
                cout << player2Name << " (U), enter your move (row, col): ";
                cin >> row >> col;
                row--; col--;
            }
        }

        if (board.update_board(row, col, currentLetter)) {
            bool isSUS = board.check_sus_sequence(row, col, currentLetter);
            if (isSUS) {
                if (currentPlayer == 1) {
                    player1Score++;
                } else {
                    player2Score++;
                }
            }

            cout << "Score - " << player1Name << ": " << player1Score << " | "
                 << player2Name << ": " << player2Score << endl;

            if (board.game_is_over()) {
                gameRunning = false;
                board.display_board();
                cout << "Game over!\n";
                if (player1Score > player2Score) {
                    cout << player1Name << " wins with " << player1Score << " SUS sequences!\n";
                } else if (player2Score > player1Score) {
                    cout << player2Name << " wins with " << player2Score << " SUS sequences!\n";
                } else {
                    cout << "It's a draw! Both players have " << player1Score << " SUS sequences.\n";
                }
            } else {
                currentPlayer = (currentPlayer == 1) ? 2 : 1;
            }
        } else {
            cout << "Invalid move! The cell is already occupied. Try again.\n";
        }
    }
}
*/


#endif //GAMES8_9_H
