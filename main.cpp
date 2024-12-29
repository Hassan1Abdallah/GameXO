#include <iostream>
#include <memory>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "BoardGame_Classes.h"
#include "games1_4.h"
#include "games2_5.h"
#include "games3_6.h"
#include "games8_9.h"

// Function to get a valid symbol (X or O) from the user
char getvalidsymbol() {
    char symbol; // Variable to store user input

    while (true) {
        cout << "Enter your symbol (X or O): ";
        cin >> symbol;

        // Convert the symbol to uppercase to standardize input
        symbol = toupper(symbol);

        // Check if the input is a valid symbol: X or O
        if (symbol == 'X' || symbol == 'O') {
            return symbol; // Return the valid symbol
        } else {
            // Prompt the user to enter a valid symbol if input is incorrect
            cout << "Invalid input! Please enter only 'X' or 'O'.\n";
        }
    }
}

//-----G1 DONE
void choose_pyr() {
    int choice;
    string name1, name2;
    char player1_symbol, player2_symbol;

    while (true) {
        cout << "\nChoose Game Mode:\n";
        cout << "1. Play against another human player\n";
        cout << "2. Play against the computer \n";
        cout << "3. Exit\n";
        cout << "Enter your choice (1, 2, or 3): ";
        cin >> choice;

        if (choice == 3) {
            cout << "Exiting the game...\n";
            break;  // Exit the loop and the program
        }

        // Ensure the input is valid
        if (choice != 1 && choice != 2) {
            cout << "Invalid choice! Please choose again.\n";
            continue;  // Continue the loop to prompt the user again
        }
        cout<<"NOTICE:"<<endl;
        cout<<"THE ROWS AND COL START FROM 1 TO 3\n";

        // Get player names
        cout << "Enter the name of Player 1: ";
        cin >> name1;
        player1_symbol=getvalidsymbol();
        if (choice == 1) {
            // Two human players mode
            cout << "Enter the name of Player 2: ";
            cin >> name2;

            PyramidPlayer player1(name1, player1_symbol);
            PyramidPlayer player2(name2, toupper(player2_symbol)== 'X' ? 'O' : 'X');
            Player<char>* players[] = { &player1, &player2 };
            Pyramid board;
            GameManager<char> game(&board, players);
            game.run();
        }
        else if (choice == 2) {
            // Human vs Random Player mode
            PyramidPlayer humanPlayer(name1, 'X');
            RandomPyramidPlayer computerPlayer('O');
            Player<char>* players[] = { &humanPlayer, &computerPlayer };
            Pyramid board;
            GameManager<char> game(&board, players);
            game.run();
        }
    }
}

//-----G2 DONE
template <typename T>
void choose_4_in_a_row_game() {
    unique_ptr<Player<T>> player1;
    unique_ptr<Player<T>> player2;
    unique_ptr<Board<T>> board;

    cout << "Welcome to Four-in-a-Row Game!\n";
    cout << "Choose Game Mode:\n";
    cout << "1. Player vs Player\n";
    cout << "2. Player vs Computer\n";
    int choice;
    cin >> choice;

    while (choice != 1 && choice != 2) {
        cout << "Invalid choice. Please enter 1 or 2:\n";
        cin >> choice;
    }

    string player1_name, player2_name;
    char player1_symbol, player2_symbol;

    // Player 1 input
    cout << "Enter Player 1 name: ";
    cin >> player1_name;
    player1_symbol=getvalidsymbol();

    // Create Player 1
    player1 = make_unique<Four_n_Row_Player>(player1_name, player1_symbol);

    // Setting up Player 2 based on game mode
    if (choice == 1) {
        // Player vs Player
        cout << "Enter Player 2 name: ";
        cin >> player2_name;
        player2_symbol=getvalidsymbol();
        player2 = make_unique<Four_n_Row_Player>(player2_name, player2_symbol);
    } else {
        // Player vs Computer
        player2_name = "Computer";
        player2_symbol = (toupper(player1_symbol) == 'X' ? 'O' : 'X');
        player2 = make_unique<Four_n_Row_RandomPlayer<T>>(player2_symbol);
    }

    // Create the board
    board = make_unique<Four_n_Row<T>>();

    // Set the board for both players
    player1->setBoard(board.get());
    player2->setBoard(board.get());

    // Initialize game manager
    Player<T>* players[2] = {player1.get(), player2.get()};
    GameManager<T> gameManager(board.get(), players);

    // Start the game
    gameManager.run();

    cout << "Thank you for playing Four-in-a-Row Game!\n";
}

//-----G3 S DONE
void choose_FXF_game() {
    unique_ptr<Player<char>> player1;
    unique_ptr<Player<char>> player2;
    unique_ptr<Board<char>> board;

    cout << "Welcome to Four-in-a-Row Game!\n";
    cout << "Choose Game Mode:\n";
    cout << "1. Player vs Player\n";
    cout << "2. Player vs Computer\n";
    int choice;
    cin >> choice;

    while (choice != 1 && choice != 2) {
        cout << "Invalid choice. Please enter 1 or 2:\n";
        cin >> choice;
    }

    string player1_name, player2_name;
    char player1_symbol, player2_symbol;

    // Player 1 input
    cout << "Enter Player 1 name: ";
    cin >> player1_name;
    player1_symbol=getvalidsymbol();


    player1 = make_unique<FXF_Player<char>>(player1_name, player1_symbol);

    if (choice == 1) {
        cout << "Enter Player 2 name: ";
        cin >> player2_name;
        cout << "Enter Player 2 symbol (single character): ";
        cin >> player2_symbol;
        player2 = make_unique<FXF_Player<char>>(player2_name, player2_symbol);
    } else {
        player2_name = "Computer";
        player2_symbol = (player1_symbol == 'X' ? 'O' : 'X');
        player2 = make_unique<FXF_Random_Player<char>>(player2_symbol);
    }

    board = make_unique<FXF_Board<char>>();

    // Set the board for both players
    player1->setBoard(board.get());
    player2->setBoard(board.get());

    // Initialize game manager
    Player<char>* players[2] = {player1.get(), player2.get()};
    GameManager<char> gameManager(board.get(), players);

    // Start the game
    gameManager.run();

    cout << "Thank you for playing 5x5 X-O Game!\n";
}

//----G4 DONE
void choose_word_game() {
    int choice;
    string dictionaryFilename;

    while (true) {
        cout << "Welcome to Word Tic-Tac-Toe!" << endl;
        cout << "1. Start game" << endl;
        cout << "2. Load your own dictionary" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cout<<"NOTICE: "<<endl;
        cout<<"THE ROWS AND COL START FROM 1 TO 3\n";


        switch (choice) {
            case 1: {
                loadDictionary("dic.txt");
                word_run();
                break;
            }
            case 2: {
                cout << "Enter the dictionary filename: ";
                cin >> dictionaryFilename;
                loadDictionary(dictionaryFilename);
                cout << "Dictionary loaded successfully!" << endl;
                word_run();
                break;
            }
            case 3: {
                cout << "Goodbye!" << endl;
                return;
            }
            default:
                cout << "Invalid choice! Please try again." << endl;
                break;
        }
    }
}

//----G5  DONE
void choose_Num_t_game() {
    cout << "Welcome to Num_T Game!" << endl;

    // Ask if the player wants to play against another player or the computer
    cout << "Choose game mode:" << endl;
    cout << "1. Player vs Player" << endl;
    cout << "2. Player vs Computer" << endl;

    int choice;
    cin >> choice;

    string player1Name, player2Name;

    cout << "Enter name for Player 1: ";
    cin >> player1Name;

    if (choice == 1) {
        // Player vs Player mode
        cout << "Enter name for Player 2: ";
        cin >> player2Name;
    } else {
        // Player vs Computer mode
        player2Name = "Computer";
    }

    // Initialize game variables
    Num_T<int> board;
    vector<int> player1Numbers = {1, 3, 5, 7, 9};
    vector<int> player2Numbers = {2, 4, 6, 8};
    Num_T_Player<int> player1(player1Name, 1, player1Numbers, &board);
    Player<int>* player2;

    if (choice == 1) {
        player2 = new Num_T_Player<int>(player2Name, 2, player2Numbers, &board);
    } else {
        player2 = new Num_T_Random_Player<int>(2, player2Numbers, &board);
    }

    // Start the game
    int currentPlayer = 1;
    while (!board.game_is_over()) {
        board.display_board();
        cout << (currentPlayer == 1 ? player1Name : player2Name) << "'s turn:" << endl;

        int row, col;
        if (currentPlayer == 1) {
            player1.getmove(row, col);
        } else {
            player2->getmove(row, col);
        }

        if (board.game_is_over()) {
            break;
        }

        currentPlayer = (currentPlayer == 1) ? 2 : 1;
    }

    board.display_board();
    if (board.is_win()) {
        cout << (currentPlayer == 1 ? player1Name : player2Name) << " wins!" << endl;
    } else {
        cout << "It's a draw!" << endl;
    }

    delete player2;
}

//----G6 Done
void choose_MisT_game() {
    MisereTicTacToeBoard<char> board; // Board instance
    int x, y;                         // Coordinates for moves
    char player_symbols[2] = {'X', 'O'}; // Player symbols
    string player_names[2];            // Player names
    bool isComputerPlayer = false;     // Flag for computer mode

    // Choose game mode
    cout << "Welcome to Misere Tic-Tac-Toe!\n";
    while (true) {
        cout << "Choose Game Mode:\n";
        cout << "1. Player vs Player\n";
        cout << "2. Player vs Computer\n";
        cout << "3. Exit\n";
        int choice;
        cin >> choice;

        if (choice == 3) {
            cout << "Exiting the game. Goodbye!\n";
            return; // Exit the function
        }

        if (choice != 1 && choice != 2) {
            cout << "Invalid choice. Please choose 1, 2, or 3.\n";
            continue;
        }

        // Get player names
        cout << "Enter Player 1 name (symbol X): ";
        cin >> player_names[0];

        if (choice == 1) {
            // Player vs Player mode
            cout << "Enter Player 2 name (symbol O): ";
            cin >> player_names[1];
        } else {
            // Player vs Computer mode
            player_names[1] = "Computer";
            isComputerPlayer = true;
        }

        board.display_board(); // Display initial board

        int current_player = 0; // Player 1 starts

        while (!board.game_is_over()) {
            // Display prompt for the current player
            cout << player_names[current_player] << " (" << player_symbols[current_player] << "), enter your move (row, col): ";

            if (isComputerPlayer && current_player == 1) {
                // Computer's move
                srand(time(0));
                do {
                    x = rand() % 3;
                    y = rand() % 3;
                } while (!board.update_board(x, y, player_symbols[current_player]));
                cout << x + 1 << " " << y + 1 << endl; // Display the computer's move (converted to 1-based indexing)
            } else {
                // Human player's move
                cin >> x >> y;

                // Convert user input to 0-based indexing
                x--;
                y--;

                // Check and update the board
                while (!board.update_board(x, y, player_symbols[current_player])) {
                    cout << "Invalid move! Try again.\n";
                    cout << player_names[current_player] << " (" << player_symbols[current_player] << "), enter your move (row, col): ";
                    cin >> x >> y;
                    x--;
                    y--;
                }
            }

            board.display_board(); // Display the updated board

            // Check if the current player won (Misere win condition means avoiding a normal win)
            if (board.is_win()) {
                cout << player_names[(current_player + 1) % 2] << " wins (Misere Tic-Tac-Toe)!\n";
                return;
            }

            // Check for a draw
            if (board.is_draw()) {
                cout << "It's a draw!\n";
                return;
            }

            // Switch player
            current_player = (current_player + 1) % 2;
        }
    }
}


//----G8 DONE
void choose_ultimate(UltimateBoard &game)
{
    int choice;
    while (true)
    {
        cout << "\nChoose Game Mode:\n";
        cout << "1. Play against another human player\n";
        cout << "2. Play against the computer \n";
        cout << "3. Exit\n";
        cout << "Enter your choice (1, 2, or 3): ";
        cin >> choice;

        if (choice == 3)
        {
            cout << "Exiting the game...\n";
            break;  // Exit the loop and the program
        }

        // Ensure the input is valid
        if (choice == 1)
        {
            // Human vs Human gameplay
            human_vs_human(game);
            break;
        }
        else if (choice == 2)
        {
            // Human vs AI gameplay
            human_vs_computer(game);
            break;
        }
        else
        {
            cout << "Invalid choice! Please choose again.\n";
        }
    }
}


//----G9 DONE
void choose_SUS() {
    int choice;
    while (true) {
        cout << "\nChoose Game Mode:\n";
        cout << "1. Play against another human player\n";
        cout << "2. Play against the computer\n";
        cout << "3. Exit\n";
        cout << "Enter your choice (1, 2, or 3): ";
        cin >> choice;

        cout<<"THE ROWS AND COL START FROM 1 TO 3\n";

        if (choice == 3) {
            cout << "Exiting the game...\n";
            break;  // Exit the loop and the program
        }

        cout<<"THE ROWS AND COL START FROM 1 TO 3\n";
        sus_game();
    }
}


int main() {
    int choice;

    while (true) {
        cout << "Welcome to FCAI Board Games!\n";
        cout << "Choose a game mode:\n";
        cout << "1. Pyramid Tic Tac Toe\n";
        cout << "2. Four in a Row\n";
        cout << "3. 5x5 X-O Game\n";
        cout << "4. Word Tic Tac Toe\n";
        cout << "5. Numerical Tic Tac Toe\n";
        cout << "6. Misere Tic Tac Toe\n";
        cout << "7. Ultimate Tic Tac Toe\n";
        cout << "8. SUS Tic Tac Toe\n";
        cout << "9. Exit\n";  // Option to exit the loop
        cin >> choice;

        switch (choice) {
            case 1:
                choose_pyr();  // Call for Pyramid Tic Tac Toe
                break;

            case 2:
                choose_4_in_a_row_game<char>();  // Call for Four in a Row
                break;

            case 3:
                choose_FXF_game();  // Call for 5x5 X-O Game
                break;

            case 4:
                choose_word_game();  // Call for Word Tic Tac Toe
                break;

            case 5:
                choose_Num_t_game();  // Call for Numerical Tic Tac Toe
                break;

            case 6:
                choose_MisT_game();  // Call for Misere Tic Tac Toe
                break;

            case 7: {
                UltimateBoard game;
                choose_ultimate(game);  // Call for Ultimate Tic Tac Toe
                break;
            }

            case 8:
                choose_SUS();  // Call for SUS Tic Tac Toe
                break;

            case 9:
                cout << "Exiting the game. Goodbye!\n";
                return 0;  // Exit the program

            default:
                cout << "Invalid choice! Please choose a valid game mode.\n";
                break;
        }
    }

    return 0;
}
