#include <iostream>
#include <windows.h>
using namespace std;

class tictactoe;
void game();
void settings();

int main()
{
  int num;

  cout<<R"(
  ___________.__               ___________                     ___________            
  \__    ___/|__| ____         \__    ___/____    ____         \__    ___/___   ____  
     |    |   |  |/ ___\   ______ |    |  \__  \ _/ ___\   ______ |    | /  _ \_/ __ \
     |    |   |  \  \___  /_____/ |    |   / __ \\  \___  /_____/ |    |(  <_> )  ___/ 
     |____|   |__|\___  >         |____|  (____  /\___  >         |____| \____/ \___  >
                      \/                       \/     \/                            \/ 
  )"<<endl;
  cout<<endl;

  cout<<"1. Local PvP"<<endl;
  cout<<"2. Settings"<<endl;

  cout<<"> ";
  cin>>num;

  if(num == 1)
  {
    system("cls");
    game();
  }
  else if(num == 2)
  {
    system("cls");
    settings();
  }
  
  return 0;
}


// settings screen
void settings()
{
  int colourNum;

  cout<<R"(
        _________       __    __  .__                      
      /   _____/ _____/  |__/  |_|__| ____    ____  ______
      \_____  \_/ __ \   __\   __\  |/    \  / ___\/  ___/
      /        \  ___/|  |  |  | |  |   |  \/ /_/  >___ \ 
    /_______  /\___  >__|  |__| |__|___|  /\___  /____  >
            \/     \/                   \//_____/     \/ 
  )"<<endl;
  cout<<endl;

  // text colour settings
  cout<<"Pick a colour setting for the text"<<endl;
  cout<<endl;
  cout<<"1. Blue"<<endl;
  cout<<"2. Green"<<endl;
  cout<<"3. Aqua"<<endl;
  cout<<"4. Red"<<endl;
  cout<<"5. Purple"<<endl;
  cout<<endl;

  cout<<"> ";
  cin>>colourNum;

  // set text colour based on input
  switch (colourNum)
  {
  case 1:
    system("color 01");
    system("cls");
    main();
    break;
  case 2:
    system("color 02");
    system("cls");
    main();
    break;
  case 3:
    system("color 03");
    system("cls");
    main();
    break;
  case 4:
    system("color 04");
    system("cls");
    main();
    break;
  case 5:
    system("color 05");
    system("cls");
    main();
    break;
  default:
    system("color 0F");
    system("cls");
    main();
    break;
  }
}


// this class will contain all the information about the game
class tictactoe
{
  private:
    // 2d array is used to simulate the 2d board in tic tac toe 
    // letters are used for each position because x and o can't be represented well with numbers
    char board[3][3] = {
      {'A', 'B', 'C'},
      {'D', 'E', 'F'},
      {'G', 'H', 'I'}
    };

  public:
    void printBoard()
    {
      cout<<endl;
      cout<<"    "<<board[0][0]<<" | "<<board[0][1]<<" | "<<board[0][2]<<endl;
      cout<<"    "<<"----------"<<endl;
      cout<<"    "<<board[1][0]<<" | "<<board[1][1]<<" | "<<board[1][2]<<endl;
      cout<<"    "<<"----------"<<endl;
      cout<<"    "<<board[2][0]<<" | "<<board[2][1]<<" | "<<board[2][2]<<endl;
      cout<<endl;
    }

    void updateBoard(char input, bool playerXTurn)
    {

      /*
      the nested for loop goes through each position on the board and compares 
      it to the user input. Then when it finds the correct spot it checks which player's 
      turn it is and places a X or O
      */
      for(int i = 0; i < 3; i++)
      {
        for(int j = 0; j < 3; j++)
        {
          if(board[i][j] == input && playerXTurn == true)
          {
            board[i][j] = 'X';
          } 
          else if(board[i][j] == input)
          {
            board[i][j] = 'O';
          }
          else
          {
            continue;
          }
        }
      }

      // clear the screen then print the updated board
      system("cls");
      printBoard();
    }


    // this function checks for a win by checking every possible win sequence
    bool checkWin()
    {
      if(board[0][0] == board[1][1] && board[1][1] == board[2][2]) // check from top right corner to bottom left corner
      {
        return true;
      }
      else if(board[0][2] == board[1][1] && board[1][1] == board[2][0]) // check from top left corner to bottom right
      {
        return true;
      }
      else if(board[0][0] == board[0][1] && board[0][1] == board[0][2]) // check top row
      {
        return true;
      }
      else if(board[1][0] == board[1][1] && board[1][1] == board[1][2]) // check middle row
      {
        return true;
      }
      else if(board[2][0] == board[2][1] && board[2][1] == board[2][2]) // check bottom row
      {
        return true;
      }
      else if(board[0][0] == board[1][0] && board[1][0] == board[2][0])// check left colum
      {
        return true;
      }
      else if(board[0][1] == board[1][1] && board[1][1] == board[2][1]) // check middle colum
      {
        return true;
      }
      else if(board[0][2] == board[1][2] && board[1][2] == board[2][2]) // check right colum
      {
        return true;
      }

      return false;
    }


/*
    void resetBoard()
    {
      char board[3][3] = {
        {'A', 'B', 'C'},
        {'D', 'E', 'F'},
        {'G', 'H', 'I'}
      };
    }
*/
};



// this function is where the game takes place and where the tictactoe instance will be
void game()
{
  tictactoe game;
  char input;
  bool playerXTurn = true;  // player x always goes first so if this is false then it is player O's turn

  game.printBoard();

  while(!game.checkWin()) // loop will continue to run if game.checkWin() returns false
  {
    if(playerXTurn == true)
    {
      game.checkWin();
      cout<<"Player X enter a position: ";
      cin>>input;
      input = toupper(input);   // convert the input to uppercase to make it easier to find the entered position
      game.updateBoard(input, playerXTurn);
      playerXTurn = false;
    }
    else
    {
      game.checkWin();
      cout<<"Player O enter a position: ";
      cin>>input;
      input = toupper(input);
      game.updateBoard(input, playerXTurn);
      playerXTurn = true;
    }
  }
    

  // display which player wins
  /*
  The game decides who wins based on the opposite value of what the playerXTurn is currently set to.
  This means that the previous value is what determines the winner.
  */
  if(playerXTurn == false) 
  {   
    cout<<"Player X wins!"<<endl;
    system("pause");
    system("cls");
    main();
  }
  else
  {
    cout<<"Player O wins!"<<endl;
    system("pause");
    system("cls");
    main();
  }
}
