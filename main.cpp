#include <iostream>

using namespace std;
// void printGrid();
// void checkWin();

char grid[3][3] = {
    { 'A', 'B', 'c' }, // row 1
    { 'D', 'E', 'F' }, // row 2
    { 'G', 'H', 'I' }  // row 3
};

void printGrid()
{
    cout<<endl;
    cout<<"    "<<grid[0][0]<<" | "<<grid[0][1]<<" | "<<grid[0][2]<<endl;
    cout<<"    "<<"----------"<<endl;
    cout<<"    "<<grid[1][0]<<" | "<<grid[1][1]<<" | "<<grid[1][2]<<endl;
    cout<<"    "<<"----------"<<endl;
    cout<<"    "<<grid[2][0]<<" | "<<grid[2][1]<<" | "<<grid[2][2]<<endl;
    cout<<endl;
}


void checkWin()
{
    if(grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2]) // check from top right corner to bottom left corner
    {
        if(grid[0][0] == 'X')
        {
            cout<<"Player X wins!"<<endl;
        }
        else if(grid[0][0] == 'O')
        {
            cout<<"Player O wins!"<<endl;
        }
    }
    else if(grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0]) // check from top left corner to bottom right
    {
        if(grid[0][2] == 'X')
        {
            cout<<"Player X wins!"<<endl;
        }
        else if(grid[0][2] == 'O')
        {
            cout<<"Player O wins!"<<endl;
        }
    }
    else if(grid[0][0] == grid[0][1] && grid[0][1] == grid[0][2]) // check top row
    {
        if(grid[0][0] == 'X')
        {
            cout<<"Player X wins!"<<endl;
        }
        else if(grid[0][0] == 'O')
        {
            cout<<"Player O wins!"<<endl;
        }
    }
    else if(grid[1][0] == grid[1][1] && grid[1][1] == grid[1][2]) // check middle row
    {
        if(grid[1][0] == 'X')
        {
            cout<<"Player X wins!"<<endl;
        }
        else if(grid[1][0] == 'O')
        {
            cout<<"Player O wins!"<<endl;
        }
    }
    else if(grid[2][0] == grid[2][1] && grid[2][1] == grid[2][2]) // check bottom row
    {
        if(grid[2][0] == 'X')
        {
            cout<<"Player X wins!"<<endl;
        }
        else if(grid[2][0] == 'O')
        {
            cout<<"Player O wins!"<<endl;
        }
    }
    else if(grid[0][0] == grid[1][0] && grid[1][0] == grid[2][0])// check left colum
    {
        if(grid[0][0] == 'X')
        {
            cout<<"Player X wins!"<<endl;
        }
        else if(grid[0][0] == 'O')
        {
            cout<<"Player O wins!"<<endl;
        }
    }
    else if(grid[0][1] == grid[1][1] && grid[1][1] == grid[2][1]) // check middle colum
    {
        if(grid[0][1] == 'X')
        {
            cout<<"Player X wins!"<<endl;
        }
        else if(grid[0][1] == 'O')
        {
            cout<<"Player O wins!"<<endl;
        }
    }
    else if(grid[0][2] == grid[1][2] && grid[1][2] == grid[2][2]) // check right colum
    {
        if(grid[0][2] == 'X')
        {
            cout<<"Player X wins!"<<endl;
        }
        else if(grid[0][2] == 'O')
        {
            cout<<"Player O wins!"<<endl;
        }
    }
}


int main()
{
    char entry;
    cout<<"Tic-Tac-Toe Game"<<endl;

    printGrid();

    while(true)
    {
        cout<<"Enter a position to put for x (use capital letters): ";
        cin>>entry;

        switch(entry)
        {
            case 'A':
                grid[0][0] = 'X';
                break;
            case 'B':
                grid[0][1] = 'X';
                break;
            case 'C':
                grid[0][2] = 'X';
                break;
            case 'D':
                grid[1][0] = 'X';
                break;
            case 'E':
                grid[1][1] = 'X';
                break;
            case 'F':
                grid[1][2] = 'X';
                break;
            case 'G':
                grid[2][0] = 'X';
                break;
            case 'H':
                grid[2][1] = 'X';
                break;
            case 'I':
                grid[2][2] = 'X';
                break;
        }

        printGrid();
        checkWin();

        cout<<"Enter a postion to put for O (use capital letters): ";
        cin>>entry;

        switch(entry)
        {
            case 'A':
                grid[0][0] = 'O';
                break;
            case 'B':
                grid[0][1] = 'O';
                break;
            case 'C':
                grid[0][2] = 'O';
                break;
            case 'D':
                grid[1][0] = 'O';
                break;
            case 'E':
                grid[1][1] = 'O';
                break;
            case 'F':
                grid[1][2] = 'O';
                break;
            case 'G':
                grid[2][0] = 'O';
                break;
            case 'H':
                grid[2][1] = 'O';
                break;
            case 'I':
                grid[2][2] = 'O';
                break;
        }

        printGrid();
        checkWin();

    }
}
