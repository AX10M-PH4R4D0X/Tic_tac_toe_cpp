#include <iostream>
#include <ctime>
#include <cctype>

using namespace std;



void DrawBoardLine(char *blanks);

void PlayerMove(char *blanks , char player);

void ComputerMove(char *blanks , char computer);

bool CheckWinner(char *blanks , char player , char computer);

bool CheckTie(char *blanks);





int main() {

    char blanks[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};

    char player;
    char computer;
    bool running = true; 


    cout << '\n' << "Please choice X/O" << '\n';
    cin >> player;



    switch (toupper(player)) {
    
    case 'X':
    
    computer = 'O';
    break;
    


    case 'O':

    computer = 'X';
    break;


    default:
        cout << '\n' << "Invalid input please choice X or O";
        break;
    }



    DrawBoardLine(blanks);


    while (running) {
        

        PlayerMove(blanks , player);
        DrawBoardLine(blanks);

        if (CheckWinner(blanks , player , computer)) {
            
            running = false;
            break;

        } else if (CheckTie(blanks)) {

            running = false;
            break;

        }
        


        ComputerMove(blanks , computer);
        DrawBoardLine(blanks);

        if (CheckWinner(blanks , player , computer)) {
            
            running = false;
            break;

        } else if (CheckTie(blanks)) {

            running = false;
            break;
            
        }
        

    }

    cout << "\n*THX FOR PLAYING!*\n";
    

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



void PlayerMove(char *blanks , char player) {

    int number;


    do {


        cout << '\n' << "Please choose a spot to place a marker [1-9]" << '\n';
        cin >> number; 
        number--;

    
        if (blanks[number] == ' ') {
            
            blanks[number] = player;
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



bool CheckWinner(char *blanks , char player , char computer) {

    if ((blanks[0] != ' ') && (blanks[0] == blanks[1]) && (blanks[1] == blanks[2])) {
        
        blanks[0] == player ? cout << "You win!\n" : cout << "You Lose!\n";

    } else if ((blanks[3] != ' ') && (blanks[3] == blanks[4]) && (blanks[4] == blanks[5])) {

        blanks[3] == player ? cout << "You win!\n" : cout << "You Lose!\n";
    
    } else if ((blanks[6] != ' ') && (blanks[6] == blanks[7]) && (blanks[7] == blanks[8])) {

        blanks[6] == player ? cout << "You win!\n" : cout << "You Lose!\n";
    
    } else if ((blanks[0] != ' ') && (blanks[0] == blanks[3]) && (blanks[3] == blanks[6])) {

        blanks[3] == player ? cout << "You win!\n" : cout << "You Lose!\n";
    
    } else if ((blanks[1] != ' ') && (blanks[1] == blanks[4]) && (blanks[4] == blanks[7])) {

        blanks[1] == player ? cout << "You win!\n" : cout << "You Lose!\n";
    
    } else if ((blanks[2] != ' ') && (blanks[2] == blanks[5]) && (blanks[5] == blanks[8])) {

        blanks[2] == player ? cout << "You win!\n" : cout << "You Lose!\n";
    
    } else if ((blanks[0] != ' ') && (blanks[0] == blanks[4]) && (blanks[4] == blanks[8])) {

        blanks[0] == player ? cout << "You win!\n" : cout << "You Lose!\n";
    
    } else if ((blanks[2] != ' ') && (blanks[2] == blanks[4]) && (blanks[4] == blanks[6])) {

        blanks[2] == player ? cout << "You win!\n" : cout << "You Lose!\n";
    
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
