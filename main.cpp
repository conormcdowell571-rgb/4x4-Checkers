#include <iostream>
using namespace std;
#include <list>

list<int> board;

int b1 = 1;
int b2 = 2;
int b3 = 3;
int b4 = 4;
int w1 = 13;
int w2 = 14;
int w3 = 15;
int w4 = 16;

//Creates the board.
void init_list(){
    for (int i = 0; i < 16; i++){
        board.push_back(i + 1);
    }
}

//Displays the board in a 2-D plane.
void num_board (){
    for (int spot : board){
        cout << spot << " ";
        if (spot % 4 == 0){
            cout << "\n";
        }
    }

    cout << "\n";
}

//Displays the board with pieces.
void piece_board (int b1, int b2, int b3, int b4, int w1, int w2, int w3, int w4){
    for (int spot : board){
        if (spot == b1 || spot == b2 || spot == b3 || spot == b4){
            cout << "b" << " ";
            if (spot % 4 == 0){
                cout << "\n";
            }
        }
        else if (spot == w1 || spot == w2 || spot == w3 || spot == w4){
            cout << "w" << " ";
            if (spot % 4 == 0){
                cout << "\n";
            }
        }
        else{
            cout << spot << " ";
            if (spot % 4 == 0){
                cout << "\n";
            }
        }
    }
    cout << "\n";
}

//Determines if a move made by a player is legal. If legal returns true otherwise it returns false. 
bool legal_move (int start, int finish, std::string turn){
    //Checks white moves for legality
    if (turn == "white"){
        if (start == w1 || start == w2 || start == w3 || start == w4){
            if (finish == start - 5 || finish == start - 3){
                return true;
            }
            else{
                return false;
            }
        }
        else{
            return false;
        }
    }

    //Checks black moves for legality
    if (turn == "black"){
        if (start == b1 || start == b2 || start == b3 || start == b4){
            if (finish == start + 5 || finish == start + 3){
                return true;
            }
            else{
                return false;
            }
        }
        else{
            return false;
        }
    }

}

//Determine whether a piece is captured and if so remove it from the board.
void capture (std::string turn){
    //Determine if white has captured a black piece.
    if (turn == "white"){
        if (w1 == b1 || w2 == b1 || w3 == b1 || w4 == b1){
            b1 = 0;
        }
        else if (w1 == b2 || w2 == b2 || w3 == b2 || w4 == b2){
            b2 = 0;
        }
        else if (w1 == b3 || w2 == b3 || w3 == b3 || w4 == b3){
            b3 = 0;
        }
        else if (w1 == b4 || w2 == b4 || w3 == b4 || w4 == b4){
            b4 = 0;
        }
    }

    //Determine if black has captured a white piece.
    if (turn == "black"){
        if (b1 == w1 || b2 == w1 || b3 == w1 || b4 == w1){
            w1 = 0;
        }
        else if (b1 == w2 || b2 == w2 || b3 == w2 || b4 == w2){
            w2 = 0;
        }
        else if (b1 == w3 || b2 == w3 || b3 == w3 || b4 == w3){
            w3 = 0;
        }
        else if (b1 == w4 || b2 == w4 || b3 == w4 || b4 == w4){
            w4 = 0;
        }
    }
}

//Check if there are any white pieces or any black pieces left on the board. If no to either, declare the winner.
int winner (){
    if (b1 == 0 && b2 == 0 && b3 == 0 && b4 == 0){
        return 0;
    }
    else if (w1 == 0 && w2 == 0 && w3 == 0 && w4 == 0){
        return 1;
    }
    else{
        return 2;
    }
}

//Displays which player's turn it is. 
void turn_chooser (std::string turn){
    int start = 0;
    int finish = 0;
    cout << "It is " << turn << "'s turn." << "\n";
    cout << "Start: ";
    cin >> start;
    cout << "\n";
    cout << "Finish: ";
    cin >> finish;
    cout << "\n";

    //If a move is illegal, recursively call the function until a legal move is made.
    if (legal_move(start, finish, turn) == false){
        cout << "Invalid move.";
        turn_chooser(turn);
    }
    else{
        if (start == b1){
            b1 = finish;
        }
        else if (start == b2){
            b2 = finish;
        }
        else if (start == b3){
            b3 = finish;
        }
        else if (start == b4){
            b4 = finish;
        }
        else if (start == w1){
            w1 = finish;
        }
        else if (start == w2){
           w2 = finish; 
        }
        else if (start == w3){
            w3 = finish;
        }
        else if (start == w4){
            w4 = finish;
        }
        capture(turn);
    }
}

//Determines which player's turn it is.
void whos_turn (){
    bool i = true;
    while(i == true){
        std::string turn = "white";
        turn_chooser(turn);
        num_board();
        piece_board(b1, b2, b3, b4, w1, w2, w3, w4);
        if (winner() == 0){
            i = false;
            cout << "White Wins!";
        }

        if (i == true){
            turn = "black";
            turn_chooser(turn);
            num_board();
            piece_board(b1, b2, b3, b4, w1, w2, w3, w4);
            if (winner() == 1){
                i = false;
                cout << "Black Wins!";
            }
        }
    }
}

int main (){
    init_list();
    num_board();
    piece_board(b1, b2, b3, b4, w1, w2, w3, w4);
    whos_turn();
}