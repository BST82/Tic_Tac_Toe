#include<bits/stdc++.h>

using namespace std ;

// array length with 9
string board[9]={" "," "," "," "," "," "," "," "," "};

// creating globle variables
int player=1;
// position will be 0 to 9 
int position = 0;

// creatin function for showing on board everything 
void intro(){
        cout<<"Press 'Enter' to start game : ";
        getchar(); // holds the screen;
        
        cout<<"\n";
        cout<<"***************\n";
        cout<<"Tic Tac Toe\n";
        cout<<"***************\n";

        cout<<"Player 1 : X\n";
        cout<<"Player 2 : 0\n\n";

        cout<<"3x3 grid shown below\n\n";

        cout<<"       |       |       \n";
        cout<<"  1    |  2    |   3   \n";
        cout<<" ______|_______|_______\n";
        cout<<"       |       |       \n";
        cout<<"  4    |  5    |   6   \n";
        cout<<" ______|_______|_______\n";
        cout<<"       |       |       \n";
        cout<<"  7    |  8    |   9   \n";
        cout<<"       |       |       \n\n";
}

bool is_winner(){
  
     bool winner =false; // default value // when no one condition true then default result will be execute

    //checking  all rows

     if((board[0]==board[1])&& (board[1]==board[2]) && board[0]!=" ")
     { winner = true;}
     else if((board[3]==board[4])&& (board[4]==board[5]) && board[3]!=" ")
     { winner = true;}  
     else if((board[6]==board[7])&& (board[7]==board[8]) && board[6]!=" ")
     { winner = true;}   

    // checking all columns

     else if((board[0]==board[3])&& (board[3]==board[6]) && board[0]!=" ")
     { winner = true;}
     else if((board[1]==board[4])&& (board[4]==board[7]) && board[1]!=" ")
     { winner = true;}  
     else if((board[2]==board[5])&& (board[5]==board[8]) && board[2]!=" ")
     { winner = true;}   

    // checking the diagonals

     else if((board[0]==board[4])&& (board[4]==board[8]) && board[0]!=" ")
     { winner = true;}
     else if((board[2]==board[4])&& (board[4]==board[6]) && board[2]!=" ")
     { winner = true;}  

     return winner;              
}

bool filling_up(){
    bool filled=true;
    // check empty it will return false 

    for(int i=0;i<9;i++){
        if(board[i]==" "){
            filled=false;

        }
    }
    return filled;

}

void draw(){

        cout<<"       |       |       \n";
        cout<<"  "<<board[0]<<"    |  "<<board[1]<<"    |  "<<board[2]<<"\n";
        cout<<" ______|_______|_______\n";
        cout<<"       |       |       \n";
        cout<<"  "<<board[3]<<"    |  "<<board[4]<<"    |  "<<board[5]<<"\n";
        cout<<" ______|_______|_______\n";
        cout<<"       |       |       \n";
        cout<<"  "<<board[6]<<"    |  "<<board[7]<<"    |  "<<board[8]<<"\n";
        cout<<"       |       |       \n";
        cout<<"\n";
}

// for setting positon on the dash board 
void set_position(){
   cout<<"Player "<<player<<"'s : Enter 1 to 9 : ";

   // check position in between 1 to 9 if it is not b/w the run the while loop
   while(!(cin>>position)){
     cout<<"Please enter valid number 1 to 9 : "<<endl;
     cin.clear();  // remove the buffer
     cin.ignore(); // ignore in the input buffer input stream and wipe/remove all unwanted/invalid input 
     }

     // if board position is not equal to empty
     while(board[position-1]!=" "){
        cout<<"Opps, that position is already filled\nTry again\n";
        cout<<"Player "<<player<<"'s Turn : Enter 1 to 9 : ";
        cin>>position;
        cout<<"\n";
     }
}



// updating the board 
void update_board(){
    // for konwing 1st player or secong player using % to identify player number 
    if(player%2==1){
        board[position-1]="X"; // for finding the correct position position is 1 to 9 and board is 0 to 8 using [posion-1] for getting correct position
        }else{
            board[position-1]="0";
        }
}

//changing the player 1 to 0
void change_player(){
  if(player==1){
    player++;
  }else{
    player--;
  }
}  

// for changing turn 

void take_turn(){
    while(!is_winner() && !filling_up()){

        //invoking the functions 
       set_position();
       update_board();
       change_player();
       draw();
    }
}


// end the gave with win or tie
void end_game(){
    if(is_winner()){
        cout<<"Blast of! There is a winner "<<endl;
    }
    else if(filling_up()){
      cout<<"There is a Tie! "<<endl;
    }
}
int main(){
   intro();
   take_turn();
   end_game();
    return 0;
}