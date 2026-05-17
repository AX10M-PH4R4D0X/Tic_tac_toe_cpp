#include <iostream>
#include <ctime>
#include <cctype>

using namespace std;



void DrawBoardLine(char *blanks);


void PlayerMove1(char *blanks , char player1);

void PlayerMove2(char *blanks , char player2);

void ComputerMove(char *blanks , char computer);


bool CheckWinnerPvE(char *blanks , char player , char computer);

bool CheckWinnerPvP(char *blanks , char player1 , char player2);


bool CheckTie(char *blanks);





int main() {
    
    char keep_play;

    do
    {
        char blanks[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};

    
        char game_type;

        char player1;

        char player2;

        char computer;



        cout << "\nChoose game type -- '1' for PvE | '2' for PvP\n";
        cin >> game_type;

        if (game_type == '1') {

            bool running = true;

            cout << "\nPlease choose X or O\n";
            cin >> player1;

            switch (toupper(player1)) {

            case 'X':

                computer ='O';
                break;
                
                
            case 'O':

                computer ='X';
                break;


            default:

                cout << "\nInvalid choice!\n";
                break;

            } 
            
            
            
            while (running) {

                cout << "\n----------------------\n";
                DrawBoardLine(blanks);
                cout << "\n----------------------\n";
                

                PlayerMove1(blanks , player1);

                cout << "\n----------------------\n";
                DrawBoardLine(blanks);
                cout << "\n----------------------\n";

                
                if (CheckWinnerPvE(blanks , player1 , computer)) {
                    
                    running = false;
                    break;

                } else if (CheckTie(blanks)) {

                    running = false;
                    break;

                }
                


                ComputerMove(blanks , computer);

                cout << "\n----------------------\n";
                DrawBoardLine(blanks);
                cout << "\n----------------------\n";


                if (CheckWinnerPvE(blanks , player1 , computer)) {
                    
                    running = false;
                    break;

                } else if (CheckTie(blanks)) {

                    running = false;
                    break;
                    
                }
            
            }
            
            cout << "\n--THX FOR PLAYING--\n";
            

        } else if (game_type == '2') {

            bool running = true;
            
            cout << "\nPlease choose X or O\n";
            cin >> player1;

            switch (toupper(player1)) {

            case 'X':

                player2 ='O';
                break;
                
                
            case 'O':

                player2 ='X';
                break;


            default:

                cout << "\nInvalid choice!\n";
                break;
                
            }
            


            while (running) {

                cout << "\n----------------------\n";
                DrawBoardLine(blanks);
                cout << "\n----------------------\n";
                

                PlayerMove1(blanks , player1);

                cout << "\n----------------------\n";
                DrawBoardLine(blanks);
                cout << "\n----------------------\n";

                
                if (CheckWinnerPvP(blanks , player1 , player2)) {
                    
                    running = false;
                    break;

                } else if (CheckTie(blanks)) {

                    running = false;
                    break;

                }
                


                PlayerMove2(blanks , player2);

                cout << "\n----------------------\n";
                DrawBoardLine(blanks);
                cout << "\n----------------------\n";


                if (CheckWinnerPvP(blanks , player1 , player2)) {
                    
                    running = false;
                    break;

                } else if (CheckTie(blanks)) {

                    running = false;
                    break;
                    
                }
            
            }

            cout << "\n--THX FOR PLAYING--\n";

            
        } else {

            cout << "\nThere is no other option\n";

        }
        
        cout << "\nDo you want play again?\nY for yes! | N for no!\n";
        cin >> keep_play;

    } while (toupper(keep_play) == 'Y');

    cout << "\nExiting the game...\n";

    return 0 ;
}



void DrawBoardLine(char *blanks) { 

    cout << '\n' ;

    cout << "     |     |     " << '\n';
    
    cout << "  " << blanks[0] << "  |  " << blanks[1] << "  |  " << blanks[2] << "  " << '\n';
    
    cout << "_____|_____|_____" << '\n';
    cout << "     |     |     " << '\n';
    
    cout << "  " << blanks[3] << "  |  " << blanks[4] << "  |  " << blanks[5] << "  " << '\n';
    
    cout << "_____|_____|_____" << '\n';
    cout << "     |     |     " << '\n';
    
    cout << "  " << blanks[6] << "  |  " << blanks[7] << "  |  " << blanks[8] << "  " << '\n';
    
    cout << "_____|_____|_____" << '\n';
    cout << "     |     |     " << '\n';

    cout << '\n' ;

}



void PlayerMove1(char *blanks , char player1) {

    int number;


    do {


        cout << "\nPlease choose a spot to place a marker [1-9]\n";
        cin >> number;

        number--;

    
        if (blanks[number] == ' ') {
            
            blanks[number] = player1;
            break;

        }
        

    } while (!number > 0 || number < 8);
    

}



void PlayerMove2(char *blanks , char player2) {

    int number;


    do {


        cout << "\nPlease choose a spot to place a marker [1-9]\n";
        cin >> number;

        number--;

    
        if (blanks[number] == ' ') {
            
            blanks[number] = player2;
            break;

        }
        

    } while (!number > 0 || number < 8);
    

}



void ComputerMove(char *blanks , char computer) {

    int number;
    srand(time(NULL));

    while (true){
        
        number = rand() %9;

        
        if (blanks[number] == ' ') {
            
            blanks[number] = computer;
            break;
        
        }
        

    }

}



bool CheckWinnerPvE(char *blanks , char player1 , char computer) {

    if ((blanks[0] != ' ') && (blanks[0] == blanks[1]) && (blanks[1] == blanks[2])) {
        
        blanks[0] == player1 ? cout << "You win!\n" : cout << "You Lose!\n";

    } else if ((blanks[3] != ' ') && (blanks[3] == blanks[4]) && (blanks[4] == blanks[5])) {

        blanks[3] == player1 ? cout << "You win!\n" : cout << "You Lose!\n";
    
    } else if ((blanks[6] != ' ') && (blanks[6] == blanks[7]) && (blanks[7] == blanks[8])) {

        blanks[6] == player1 ? cout << "You win!\n" : cout << "You Lose!\n";
    
    } else if ((blanks[0] != ' ') && (blanks[0] == blanks[3]) && (blanks[3] == blanks[6])) {

        blanks[3] == player1 ? cout << "You win!\n" : cout << "You Lose!\n";
    
    } else if ((blanks[1] != ' ') && (blanks[1] == blanks[4]) && (blanks[4] == blanks[7])) {

        blanks[1] == player1 ? cout << "You win!\n" : cout << "You Lose!\n";
    
    } else if ((blanks[2] != ' ') && (blanks[2] == blanks[5]) && (blanks[5] == blanks[8])) {

        blanks[2] == player1 ? cout << "You win!\n" : cout << "You Lose!\n";
    
    } else if ((blanks[0] != ' ') && (blanks[0] == blanks[4]) && (blanks[4] == blanks[8])) {

        blanks[0] == player1 ? cout << "You win!\n" : cout << "You Lose!\n";
    
    } else if ((blanks[2] != ' ') && (blanks[2] == blanks[4]) && (blanks[4] == blanks[6])) {

        blanks[2] == player1 ? cout << "You win!\n" : cout << "You Lose!\n";
    
    } else {

        return false;

    }
    
    return true;

}



bool CheckWinnerPvP(char *blanks , char player1 , char player2) {

    if ((blanks[0] != ' ') && (blanks[0] == blanks[1]) && (blanks[1] == blanks[2])) {
        
        blanks[0] == player1 ? cout << "You win P1!\n" : cout << "You win P2!\n";

    } else if ((blanks[3] != ' ') && (blanks[3] == blanks[4]) && (blanks[4] == blanks[5])) {

        blanks[3] == player1 ? cout << "You win P1!\n" : cout << "You win P2!\n";
    
    } else if ((blanks[6] != ' ') && (blanks[6] == blanks[7]) && (blanks[7] == blanks[8])) {

        blanks[6] == player1 ? cout << "You win P1!\n" : cout << "You win P2!\n";
    
    } else if ((blanks[0] != ' ') && (blanks[0] == blanks[3]) && (blanks[3] == blanks[6])) {

        blanks[3] == player1 ? cout << "You win P1!\n" : cout << "You win P2!\n";
    
    } else if ((blanks[1] != ' ') && (blanks[1] == blanks[4]) && (blanks[4] == blanks[7])) {

        blanks[1] == player1 ? cout << "You win P1!\n" : cout << "You win P2!\n";
    
    } else if ((blanks[2] != ' ') && (blanks[2] == blanks[5]) && (blanks[5] == blanks[8])) {

        blanks[2] == player1 ? cout << "You win P1!\n" : cout << "You win P2!\n";
    
    } else if ((blanks[0] != ' ') && (blanks[0] == blanks[4]) && (blanks[4] == blanks[8])) {

        blanks[0] == player1 ? cout << "You win P1!\n" : cout << "You win P2!\n";
    
    } else if ((blanks[2] != ' ') && (blanks[2] == blanks[4]) && (blanks[4] == blanks[6])) {

        blanks[2] == player1 ? cout << "You win P1!\n" : cout << "You win P2!\n";
    
    } else {

        return false;

    }
    
    return true;

}




bool CheckTie(char *blanks) {

    for (int i = 0 ; i < 9; i++) {
        
        if (blanks[i] == ' ') {

            return false;

        } 
        
    }
    
    cout << "IT'S A TIE!\n";


    return true;

}
