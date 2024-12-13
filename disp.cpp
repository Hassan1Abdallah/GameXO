include <iostream>
#include "BoardGame_Classes.h"
#include "3x3X_O.h"

using namespace std;

int main() {
  int choice;
  Player<char> *players[2];
  X_O_Board<char> *B = new X_O_Board<char>();
  string player1Name, player2Name;

  cout << "Welcome to FCAI SUS Game. :)\n";

  
  cout << "Enter Player 1 name: ";
  cin >> player1Name;
  cout << "Choose Player 1 type:\n";
  cout << "1. Human\n";
  cout << "2. Random Computer\n";
  cin >> choice;

  switch (choice) {
    case 1:
      players[0] = new X_O_Player<char>(player1Name, ' ');
      break;
    case 2:
      players[0] = new X_O_Random_Player<char>(' ');
      break;
    default:
      cout << "Invalid choice for Player 1. Exiting the game.\n";
      return 1;
  }

  
  cout << "Enter Player 2 name: ";
  cin >> player2Name;
  cout << "Choose Player 2 type:\n";
  cout << "1. Human\n";
  cout << "2. Random Computer\n";
  cin >> choice;

  switch (choice) {
    case 1:
      players[1] = new X_O_Player<char>(player2Name, ' ');
      break;
    case 2:
      players[1] = new X_O_Random_Player<char>(' '); 
      break;
    default:
      cout << "Invalid choice for Player 2. Exiting the game.\n";
      return 1;
  }

  GameManager<char> sus_game(B, players);
  sus_game.run();

 
  delete B;
  for (int i = 0; i < 2; ++i) {
    delete players[i];
  }

  return 0;
}
