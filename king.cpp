//#include <iostream>
//#include <limits>
//#include "xxoo111.h"
//#include "xxoo444.h"
//#include "Board111.h"
//#include "Board444.h"
//#include "Board999.h"
//#include "xxoo999.h"
//
//using namespace std;
//
//int main() {
//  int choice;
//  do {
//    cout << "\nWelcome to FCAI Multi-Game Center. :)\n";
//    cout << "Choose a game to play:\n";
//    cout << "1. X-O PyramidBoard (Variant)\n";
//    cout << "2. Word Tic-tac-toe\n";
//    cout << "3. SUS Game\n";
//    cout << "0. Exit\n";
//    cout << "Enter your choice: ";
//
//    cin >> choice;
//
//    // Clear the input buffer
//    cin.ignore(numeric_limits<streamsize>::max(), '\n');
//
//    switch (choice) {
//      case 1: {
//        Player<char> *players[2];
//        Pyramic_X_O_Board<char> *B = new Pyramic_X_O_Board<char>();
//        string playerXName, player2Name;
//        cout << "Welcome to FCAI X-O Game (Variant). :)\n";
//        cout << "Enter Player X name: ";
//        cin >> playerXName;
//        cout << "Choose Player X type:\n";
//        cout << "1. Human\n";
//        cout << "2. Random Computer\n";
//        int choice1;
//        cin >> choice1;
//        switch (choice1) {
//          case 1:
//            players[0] = new Pyramic_X_O_Player<char>(playerXName, 'X');
//            break;
//          case 2:
//            players[0] = new Pyramic_X_O_Random_Player<char>('X');
//            break;
//          default:
//            cout << "Invalid choice for Player 1. Returning to main menu.\n";
//            break;
//        }
//        cout << "Enter Player 2 name: ";
//        cin >> player2Name;
//        cout << "Choose Player 2 type:\n";
//        cout << "1. Human\n";
//        cout << "2. Random Computer\n";
//        int choice2;
//        cin >> choice2;
//        switch (choice2) {
//          case 1:
//            players[1] = new Pyramic_X_O_Player<char>(player2Name, 'O');
//            break;
//          case 2:
//            players[1] = new Pyramic_X_O_Random_Player<char>('O');
//            break;
//          default:
//            cout << "Invalid choice for Player 2. Returning to main menu.\n";
//            break;
//        }
//        GameManager<char> x_o_game(B, players);
//        x_o_game.run();
//        delete B;
//        for (int i = 0; i < 2; ++i) {
//          if (players[i]) delete players[i];
//        }
//        break;
//      }
//
//      case 2: {
//        Player<char> *players[2];
//        Word_Char_Board<char> *B = new Word_Char_Board<char>();
//        string playerXName, player2Name;
//        cout << "Welcome to FCAI Classic X-O Game. :)\n";
//        cout << "Enter Player X name: ";
//        cin >> playerXName;
//        cout << "Choose Player X type:\n";
//        cout << "1. Human\n";
//        cout << "2. Random Computer\n";
//        int choice1;
//        cin >> choice1;
//        switch (choice1) {
//          case 1:
//            players[0] = new Word_Char_Player<char>(playerXName, 'X');
//            break;
//          case 2:
//            players[0] = new Word_Char_Random_Player<char>('X');
//            break;
//          default:
//            cout << "Invalid choice for Player 1. Returning to main menu.\n";
//            break;
//        }
//        cout << "Enter Player 2 name: ";
//        cin >> player2Name;
//        cout << "Choose Player 2 type:\n";
//        cout << "1. Human\n";
//        cout << "2. Random Computer\n";
//        int choice2;
//        cin >> choice2;
//        switch (choice2) {
//          case 1:
//            players[1] = new Word_Char_Player<char>(player2Name, 'O');
//            break;
//          case 2:
//            players[1] = new Word_Char_Random_Player<char>('O');
//            break;
//          default:
//            cout << "Invalid choice for Player 2. Returning to main menu.\n";
//            break;
//        }
//        GameManager<char> x_o_game(B, players);
//        x_o_game.run();
//        delete B;
//        for (int i = 0; i < 2; ++i) {
//          if (players[i]) delete players[i];
//        }
//        break;
//      }
//
//      case 3: {
//        Player<char> *players[2];
//        Sus_Board<char> *B = new Sus_Board<char>();
//        string player1Name, player2Name;
//        cout << "Welcome to FCAI SUS Game. :)\n";
//        cout << "Enter Player 1 name: ";
//        cin >> player1Name;
//        cout << "Choose Player 1 type:\n";
//        cout << "1. Human\n";
//        cout << "2. Random Computer\n";
//        int choice1;
//        cin >> choice1;
//        switch (choice1) {
//          case 1:
//            players[0] = new Sus_Player<char>(player1Name, ' ');
//            break;
//          case 2:
//            players[0] = new Sus_Random_Player<char>(' ');
//            break;
//          default:
//            cout << "Invalid choice for Player 1. Returning to main menu.\n";
//            break;
//        }
//        cout << "Enter Player 2 name: ";
//        cin >> player2Name;
//        cout << "Choose Player 2 type:\n";
//        cout << "1. Human\n";
//        cout << "2. Random Computer\n";
//        int choice2;
//        cin >> choice2;
//        switch (choice2) {
//          case 1:
//            players[1] = new Sus_Player<char>(player2Name, ' ');
//            break;
//          case 2:
//            players[1] = new Sus_Random_Player<char>(' ');
//            break;
//          default:
//            cout << "Invalid choice for Player 2. Returning to main menu.\n";
//            break;
//        }
//        GameManager<char> sus_game(B, players);
//        sus_game.run();
//        delete B;
//        for (int i = 0; i < 2; ++i) {
//          if (players[i]) delete players[i];
//        }
//        break;
//      }
//      case 0:
//        cout << "Exiting the game center. Goodbye! :)\n";
//        break;
//      default:
//        cout << "Invalid choice. Please try again.\n";
//        break;
//    }
//  } while (choice != 0);
//
//  return 0;
//}

//#include <iostream>
//#include <limits>
//#include "xxoo111.h"
//#include "xxoo444.h"
//#include "Board111.h"
//#include "Board444.h"
//#include "Board999.h"
//#include "xxoo999.h"
//#include "BoardGame_Classes.h"
//#include "FourInARow.h"
//
//using namespace std;
//
//int main() {
//  int choice;
//  do {
//    cout << "\nWelcome to FCAI Multi-Game Center. :)\n";
//    cout << "Choose a game to play:\n";
//    cout << "1. X-O PyramidBoard (Variant)\n";
//    cout << "2. Word Tic-tac-toe\n";
//    cout << "3. SUS Game\n";
//    cout << "4. Four-in-a-Row\n";
//    cout << "0. Exit\n";
//    cout << "Enter your choice: ";
//
//    cin >> choice;
//
//    // Clear the input buffer
//    cin.ignore(numeric_limits<streamsize>::max(), '\n');
//
//    switch (choice) {
//      case 1: {
//        Player<char> *players[2];
//        Pyramic_X_O_Board<char> *B = new Pyramic_X_O_Board<char>();
//        string playerXName, player2Name;
//        cout << "Welcome to FCAI X-O Game (Variant). :)\n";
//        cout << "Enter Player X name: ";
//        cin >> playerXName;
//        cout << "Choose Player X type:\n";
//        cout << "1. Human\n";
//        cout << "2. Random Computer\n";
//        int choice1;
//        cin >> choice1;
//        switch (choice1) {
//          case 1:
//            players[0] = new Pyramic_X_O_Player<char>(playerXName, 'X');
//            break;
//          case 2:
//            players[0] = new Pyramic_X_O_Random_Player<char>('X');
//            break;
//          default:
//            cout << "Invalid choice for Player 1. Returning to main menu.\n";
//            break;
//        }
//        cout << "Enter Player 2 name: ";
//        cin >> player2Name;
//        cout << "Choose Player 2 type:\n";
//        cout << "1. Human\n";
//        cout << "2. Random Computer\n";
//        int choice2;
//        cin >> choice2;
//        switch (choice2) {
//          case 1:
//            players[1] = new Pyramic_X_O_Player<char>(player2Name, 'O');
//            break;
//          case 2:
//            players[1] = new Pyramic_X_O_Random_Player<char>('O');
//            break;
//          default:
//            cout << "Invalid choice for Player 2. Returning to main menu.\n";
//            break;
//        }
//        GameManager<char> x_o_game(B, players);
//        x_o_game.run();
//        delete B;
//        for (int i = 0; i < 2; ++i) {
//          if (players[i]) delete players[i];
//        }
//        break;
//      }
//
//      case 2: {
//        Player<char> *players[2];
//        Word_Char_Board<char> *B = new Word_Char_Board<char>();
//        string playerXName, player2Name;
//        cout << "Welcome to FCAI Classic X-O Game. :)\n";
//        cout << "Enter Player X name: ";
//        cin >> playerXName;
//        cout << "Choose Player X type:\n";
//        cout << "1. Human\n";
//        cout << "2. Random Computer\n";
//        int choice1;
//        cin >> choice1;
//        switch (choice1) {
//          case 1:
//            players[0] = new Word_Char_Player<char>(playerXName, 'X');
//            break;
//          case 2:
//            players[0] = new Word_Char_Random_Player<char>('X');
//            break;
//          default:
//            cout << "Invalid choice for Player 1. Returning to main menu.\n";
//            break;
//        }
//        cout << "Enter Player 2 name: ";
//        cin >> player2Name;
//        cout << "Choose Player 2 type:\n";
//        cout << "1. Human\n";
//        cout << "2. Random Computer\n";
//        int choice2;
//        cin >> choice2;
//        switch (choice2) {
//          case 1:
//            players[1] = new Word_Char_Player<char>(player2Name, 'O');
//            break;
//          case 2:
//            players[1] = new Word_Char_Random_Player<char>('O');
//            break;
//          default:
//            cout << "Invalid choice for Player 2. Returning to main menu.\n";
//            break;
//        }
//        GameManager<char> x_o_game(B, players);
//        x_o_game.run();
//        delete B;
//        for (int i = 0; i < 2; ++i) {
//          if (players[i]) delete players[i];
//        }
//        break;
//      }
//
//      case 3: {
//        Player<char> *players[2];
//        Sus_Board<char> *B = new Sus_Board<char>();
//        string player1Name, player2Name;
//        cout << "Welcome to FCAI SUS Game. :)\n";
//        cout << "Enter Player 1 name: ";
//        cin >> player1Name;
//        cout << "Choose Player 1 type:\n";
//        cout << "1. Human\n";
//        cout << "2. Random Computer\n";
//        int choice1;
//        cin >> choice1;
//        switch (choice1) {
//          case 1:
//            players[0] = new Sus_Player<char>(player1Name, ' ');
//            break;
//          case 2:
//            players[0] = new Sus_Random_Player<char>(' ');
//            break;
//          default:
//            cout << "Invalid choice for Player 1. Returning to main menu.\n";
//            break;
//        }
//        cout << "Enter Player 2 name: ";
//        cin >> player2Name;
//        cout << "Choose Player 2 type:\n";
//        cout << "1. Human\n";
//        cout << "2. Random Computer\n";
//        int choice2;
//        cin >> choice2;
//        switch (choice2) {
//          case 1:
//            players[1] = new Sus_Player<char>(player2Name, ' ');
//            break;
//          case 2:
//            players[1] = new Sus_Random_Player<char>(' ');
//            break;
//          default:
//            cout << "Invalid choice for Player 2. Returning to main menu.\n";
//            break;
//        }
//        GameManager<char> sus_game(B, players);
//        sus_game.run();
//        delete B;
//        for (int i = 0; i < 2; ++i) {
//          if (players[i]) delete players[i];
//        }
//        break;
//      }
//      case 4: {
//        Player<char> *players[2];
//        FourInARowBoard *B = new FourInARowBoard();
//        string player1Name, player2Name;
//        cout << "Welcome to Four-in-a-Row Game.\n";
//        cout << "Enter Player 1 name: ";
//        cin >> player1Name;
//        cout << "Choose Player 1 type:\n";
//        cout << "1. Human\n";
//        cout << "2. Random Computer\n";
//        int choice1;
//        cin >> choice1;
//        switch (choice1) {
//          case 1:
//            players[0] = new HumanPlayer(player1Name, 'X');
//            break;
//          case 2:
//            players[0] = new RandomPlayerAI('X');
//            break;
//          default:
//            cout << "Invalid choice for Player 1. Returning to main menu.\n";
//            break;
//        }
//        cout << "Enter Player 2 name: ";
//        cin >> player2Name;
//        cout << "Choose Player 2 type:\n";
//        cout << "1. Human\n";
//        cout << "2. Random Computer\n";
//        int choice2;
//        cin >> choice2;
//        switch (choice2) {
//          case 1:
//            players[1] = new HumanPlayer(player2Name, 'O');
//            break;
//          case 2:
//            players[1] = new RandomPlayerAI('O');
//            break;
//          default:
//            cout << "Invalid choice for Player 2. Returning to main menu.\n";
//            break;
//        }
//
//        GameManager<char> four_in_row_game(B, players);
//        four_in_row_game.run();
//
//        delete B;
//        for (int i = 0; i < 2; ++i) {
//          if (players[i]) delete players[i];
//        }
//        break;
//      }
//
//      case 0:
//        cout << "Exiting the game center. Goodbye! :)\n";
//        break;
//      default:
//        cout << "Invalid choice. Please try again.\n";
//        break;
//    }
//  } while (choice != 0);
//
//  return 0;
//}

#include <iostream>
#include <limits>
#include "xxoo111.h"
#include "xxoo444.h"
//#include "Board111.h"
//#include "Board444.h"
//#include "Board999.h"
#include "xxoo999.h"
#include "FourInARow.h"
#include "NumericalBoard.h"
#include "3X3X_O.h"
#include "5X5X_O.h"
#include "BoardGame_Classes.h"

using namespace std;

int main() {
  int choice;
  do {
    cout << "\nWelcome to FCAI Multi-Game Center. :)\n";
    cout << "Choose a game to play:\n";
    cout << "1. G1 X-O PyramidBoard (Variant)\n";
    cout << "2. G4 Word Tic-tac-toe\n";
    cout << "3. G9 SUS Game\n";
    cout << "4. G2 Four-in-a-Row\n";
    cout << "5. G5 Numerical Board\n";
    cout << "6. G8 X-O 9x9\n";
    cout << "7. G3 X-O 5x5\n";
    cout << "0. Exit\n";
    cout << "Enter your choice: ";

    cin >> choice;

    // Clear the input buffer
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    switch (choice) {
      case 1: {
        Player<char> *players[2];
        Pyramic_X_O_Board<char> *B = new Pyramic_X_O_Board<char>();
        string playerXName, player2Name;
        cout << "Welcome to FCAI X-O Game (Variant). :)\n";
        cout << "Enter Player X name: ";
        cin >> playerXName;
        cout << "Choose Player X type:\n";
        cout << "1. Human\n";
        cout << "2. Random Computer\n";
        int choice1;
        cin >> choice1;
        switch (choice1) {
          case 1:
            players[0] = new Pyramic_X_O_Player<char>(playerXName, 'X');
            break;
          case 2:
            players[0] = new Pyramic_X_O_Random_Player<char>('X');
            break;
          default:
            cout << "Invalid choice for Player 1. Returning to main menu.\n";
            break;
        }
        cout << "Enter Player 2 name: ";
        cin >> player2Name;
        cout << "Choose Player 2 type:\n";
        cout << "1. Human\n";
        cout << "2. Random Computer\n";
        int choice2;
        cin >> choice2;
        switch (choice2) {
          case 1:
            players[1] = new Pyramic_X_O_Player<char>(player2Name, 'O');
            break;
          case 2:
            players[1] = new Pyramic_X_O_Random_Player<char>('O');
            break;
          default:
            cout << "Invalid choice for Player 2. Returning to main menu.\n";
            break;
        }
        GameManager<char> x_o_game(B, players);
        x_o_game.run();
        delete B;
        for (int i = 0; i < 2; ++i) {
          if (players[i]) delete players[i];
        }
        break;
      }

      case 2: {
        Player<char> *players[2];
        Word_Char_Board<char> *B = new Word_Char_Board<char>();
        string playerXName, player2Name;
        cout << "Welcome to FCAI Classic X-O Game. :)\n";
        cout << "Enter Player X name: ";
        cin >> playerXName;
        cout << "Choose Player X type:\n";
        cout << "1. Human\n";
        cout << "2. Random Computer\n";
        int choice1;
        cin >> choice1;
        switch (choice1) {
          case 1:
            players[0] = new Word_Char_Player<char>(playerXName, 'X');
            break;
          case 2:
            players[0] = new Word_Char_Random_Player<char>('X');
            break;
          default:
            cout << "Invalid choice for Player 1. Returning to main menu.\n";
            break;
        }
        cout << "Enter Player 2 name: ";
        cin >> player2Name;
        cout << "Choose Player 2 type:\n";
        cout << "1. Human\n";
        cout << "2. Random Computer\n";
        int choice2;
        cin >> choice2;
        switch (choice2) {
          case 1:
            players[1] = new Word_Char_Player<char>(player2Name, 'O');
            break;
          case 2:
            players[1] = new Word_Char_Random_Player<char>('O');
            break;
          default:
            cout << "Invalid choice for Player 2. Returning to main menu.\n";
            break;
        }
        GameManager<char> x_o_game(B, players);
        x_o_game.run();
        delete B;
        for (int i = 0; i < 2; ++i) {
          if (players[i]) delete players[i];
        }
        break;
      }

      case 3: {
        Player<char> *players[2];
        Sus_Board<char> *B = new Sus_Board<char>();
        string player1Name, player2Name;
        cout << "Welcome to FCAI SUS Game. :)\n";
        cout << "Enter Player 1 name: ";
        cin >> player1Name;
        cout << "Choose Player 1 type:\n";
        cout << "1. Human\n";
        cout << "2. Random Computer\n";
        int choice1;
        cin >> choice1;
        switch (choice1) {
          case 1:
            players[0] = new Sus_Player<char>(player1Name, ' ');
            break;
          case 2:
            players[0] = new Sus_Random_Player<char>(' ');
            break;
          default:
            cout << "Invalid choice for Player 1. Returning to main menu.\n";
            break;
        }
        cout << "Enter Player 2 name: ";
        cin >> player2Name;
        cout << "Choose Player 2 type:\n";
        cout << "1. Human\n";
        cout << "2. Random Computer\n";
        int choice2;
        cin >> choice2;
        switch (choice2) {
          case 1:
            players[1] = new Sus_Player<char>(player2Name, ' ');
            break;
          case 2:
            players[1] = new Sus_Random_Player<char>(' ');
            break;
          default:
            cout << "Invalid choice for Player 2. Returning to main menu.\n";
            break;
        }
        GameManager<char> sus_game(B, players);
        sus_game.run();
        delete B;
        for (int i = 0; i < 2; ++i) {
          if (players[i]) delete players[i];
        }
        break;
      }
      case 4: {
        Player<char> *players[2];
        FourInARowBoard *B = new FourInARowBoard();
        string player1Name, player2Name;
        cout << "Welcome to Four-in-a-Row Game.\n";
        cout << "Enter Player 1 name: ";
        cin >> player1Name;
        cout << "Choose Player 1 type:\n";
        cout << "1. Human\n";
        cout << "2. Random Computer\n";
        int choice1;
        cin >> choice1;
        switch (choice1) {
          case 1:
            players[0] = new HumanPlayer(player1Name, 'X');
            break;
          case 2:
            players[0] = new RandomPlayerAI('X');
            break;
          default:
            cout << "Invalid choice for Player 1. Returning to main menu.\n";
            break;
        }
        cout << "Enter Player 2 name: ";
        cin >> player2Name;
        cout << "Choose Player 2 type:\n";
        cout << "1. Human\n";
        cout << "2. Random Computer\n";
        int choice2;
        cin >> choice2;
        switch (choice2) {
          case 1:
            players[1] = new HumanPlayer(player2Name, 'O');
            break;
          case 2:
            players[1] = new RandomPlayerAI('O');
            break;
          default:
            cout << "Invalid choice for Player 2. Returning to main menu.\n";
            break;
        }

        GameManager<char> four_in_row_game(B, players);
        four_in_row_game.run();

        delete B;
        for (int i = 0; i < 2; ++i) {
          if (players[i]) delete players[i];
        }
        break;
      }
      case 5: {
        Player<int> *players[2];
        CustomNumericalBoard *B = new CustomNumericalBoard(3, 3);
        string player1Name, player2Name;
        cout << "Welcome to Numerical Board Game.\n";
        cout << "Enter Player 1 name: ";
        cin >> player1Name;
        cout << "Choose Player 1 type:\n";
        cout << "1. Human\n";
        cout << "2. Random Computer\n";
        int choice1;
        cin >> choice1;
        switch (choice1) {
          case 1:
            players[0] = new NumericalHumanPlayer(player1Name, 0);
            break;
          case 2:
            players[0] = new NumericalRandomPlayer(0);
            break;
          default:
            cout << "Invalid choice for Player 1. Returning to main menu.\n";
            break;
        }
        cout << "Enter Player 2 name: ";
        cin >> player2Name;
        cout << "Choose Player 2 type:\n";
        cout << "1. Human\n";
        cout << "2. Random Computer\n";
        int choice2;
        cin >> choice2;
        switch (choice2) {
          case 1:
            players[1] = new NumericalHumanPlayer(player2Name, 0);
            break;
          case 2:
            players[1] = new NumericalRandomPlayer(0);
            break;
          default:
            cout << "Invalid choice for Player 2. Returning to main menu.\n";
            break;
        }

        GameManager<int> numerical_game(B, players);
        numerical_game.run();

        delete B;
        for (int i = 0; i < 2; ++i) {
          if (players[i]) delete players[i];
        }
        break;
      }
      case 6: {
        Player<char> *players[2];
        X_O_Board<char> *B = new X_O_Board<char>();
        string player1Name, player2Name;
        cout << "Welcome to  X-O 3x3 Game.\n";
        cout << "Enter Player 1 name: ";
        cin >> player1Name;
        cout << "Choose Player 1 type:\n";
        cout << "1. Human\n";
        cout << "2. Random Computer\n";
        int choice1;
        cin >> choice1;
        switch (choice1) {
          case 1:
            players[0] = new X_O_Player<char>(player1Name, 'X');
            break;
          case 2:
            players[0] = new X_O_Random_Player<char>('X');
            break;
          default:
            cout << "Invalid choice for Player 1. Returning to main menu.\n";
            break;
        }
        cout << "Enter Player 2 name: ";
        cin >> player2Name;
        cout << "Choose Player 2 type:\n";
        cout << "1. Human\n";
        cout << "2. Random Computer\n";
        int choice2;
        cin >> choice2;
        switch (choice2) {
          case 1:
            players[1] = new X_O_Player<char>(player2Name, 'O');
            break;
          case 2:
            players[1] = new X_O_Random_Player<char>('O');
            break;
          default:
            cout << "Invalid choice for Player 2. Returning to main menu.\n";
            break;
        }

        GameManager<char> x_o_3x3_game(B, players);
        x_o_3x3_game.run();

        delete B;
        for (int i = 0; i < 2; ++i) {
          if (players[i]) delete players[i];
        }
        break;
      }
      case 7: {
        Player<char> *players[2];
        X_O_5x5_Board<char> *B = new X_O_5x5_Board<char>();
        string player1Name, player2Name;
        cout << "Welcome to X-O 5x5 Game.\n";
        cout << "Enter Player 1 name: ";
        cin >> player1Name;
        cout << "Choose Player 1 type:\n";
        cout << "1. Human\n";
        cout << "2. Random Computer\n";
        int choice1;
        cin >> choice1;
        switch (choice1) {
          case 1:
            players[0] = new Player<char>(player1Name, 'X');
            break;
          case 2:
            players[0] = new RandomPlayer<char>('X');
            break;
          default:
            cout << "Invalid choice for Player 1. Returning to main menu.\n";
            break;
        }
        cout << "Enter Player 2 name: ";
        cin >> player2Name;
        cout << "Choose Player 2 type:\n";
        cout << "1. Human\n";
        cout << "2. Random Computer\n";
        int choice2;
        cin >> choice2;
        switch (choice2) {
          case 1:
            players[1] = new Player<char>(player2Name, 'O');
            break;
          case 2:
            players[1] = new RandomPlayer<char>('O');
            break;
          default:
            cout << "Invalid choice for Player 2. Returning to main menu.\n";
            break;
        }
        GameManager<char> x_o_5x5_game(B, players);
        x_o_5x5_game.run();

        delete B;
        for (int i = 0; i < 2; ++i) {
          if (players[i]) delete players[i];
        }
        break;
      }

      case 0:
        cout << "Exiting the game center. Goodbye! :)\n";
        break;
      default:
        cout << "Invalid choice. Please try again.\n";
        break;
    }
  } while (choice != 0);

  return 0;
}