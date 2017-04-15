#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "queens.h"

using namespace std;

void setQ(int** board, const int& boardSize, const int& x, const int& y)
{
 for(int i = 0; i < boardSize; i++)
   {
	board[x][i]++;
	board[i][y]++;
        int foo = y - x + i;
        if (foo >= 0 && foo < boardSize)
        board[i][foo]++;
        foo = y + x - i;
        if (foo >= 0 && foo < boardSize)
        board[i][foo]++;
   }
   board[x][y]=-1;
}

void resetQ(int** board, const int& boardSize, const int& x, const int& y)
{
 for(int i = 0; i < boardSize; i++)
   {
	board[x][i]--;
	board[i][y]--;
        int foo = y - x + i;
        if (foo >= 0 && foo < boardSize)
        board[i][foo]--;
        foo = y + x - i;
        if (foo >= 0 && foo < boardSize)
        board[i][foo]--;
   }
   board[x][y]= 0;
}

bool tryQ(int** board, const int& boardSize, const int& j)
{
   bool res = false;
   for(int i= 0; i < boardSize; i++)
    {
     if (board[i][j] == 0)
     {
       setQ(board, boardSize, i, j);
       if (j == (boardSize - 1))
         {
           drawBoard(board, boardSize);
           writeToFile(board, boardSize);
           resetQ(board, boardSize, i, j); 
         }
       else
         {
          if (!(res = tryQ(board, boardSize, j + 1)))
          resetQ(board, boardSize, i, j);
         }
      } 
    }
   return res;
}

void drawBoard(int** board, const int& boardSize)
{
 static int numberOfSetups1 = 0;
 cout << "\nSetup of queens number " << ++numberOfSetups1 << " : " << endl;
 switch (boardSize)
 {
   case 1: cout << "   a " << endl; break;
   case 2: cout << "   a   b " << endl; break;
   case 3: cout << "   a   b   c " << endl; break;
   case 4: cout << "   a   b   c   d " << endl; break;
   case 5: cout << "   a   b   c   d   e " << endl; break;
   case 6: cout << "   a   b   c   d   e   f " << endl; break;
   case 7: cout << "   a   b   c   d   e   f   g " << endl; break;
   case 8: cout << "   a   b   c   d   e   f   g   h " << endl; break;
   case 9: cout << "   a   b   c   d   e   f   g   h   i " << endl; break;
   case 10: cout << "   a   b   c   d   e   f   g   h  i  j " << endl; break;
 }
     cout << "  ";
     for (int i = 0; i < boardSize; i++) cout << "----";
     cout << endl;
 for(int i = 0; i < boardSize ; i++)
   {
    cout << boardSize - i;
    for(int j = 0; j < boardSize; j++)
      {
       if (board[i][j] == -1)
       cout << "| Q ";
       else
       cout << "|   ";
      }
    cout << "|" << boardSize - i << endl;
    cout << "  ";
    for (int k = 0; k < boardSize; k++) cout << "----";
    cout << endl;
   }
      
 switch (boardSize)
 {
   case 1: cout << "   a " << endl; break;
   case 2: cout << "   a   b " << endl; break;
   case 3: cout << "   a   b   c " << endl; break;
   case 4: cout << "   a   b   c   d " << endl; break;
   case 5: cout << "   a   b   c   d   e " << endl; break;
   case 6: cout << "   a   b   c   d   e   f " << endl; break;
   case 7: cout << "   a   b   c   d   e   f   g " << endl; break;
   case 8: cout << "   a   b   c   d   e   f   g   h " << endl; break;
   case 9: cout << "   a   b   c   d   e   f   g   h   i " << endl; break;
   case 10: cout << "   a   b   c   d   e   f   g   h  i  j " << endl; break;
 }
}

void writeToFile(int** board, const int& boardSize)
{
   static int numberOfSetups2 = 0;
   static ofstream fo("Result.txt");
   fo << "Setup of " << boardSize << " queens number " << ++numberOfSetups2 << " :\n\n ";
      switch (boardSize)
        {
	   case 1: fo << "   a \n"; break;
	   case 2: fo << "   a   b \n"; break;
	   case 3: fo << "   a   b   c \n"; break;
	   case 4: fo << "   a   b   c   d \n"; break;
	   case 5: fo << "   a   b   c   d   e \n"; break;
	   case 6: fo << "   a   b   c   d   e   f \n"; break;
	   case 7: fo << "   a   b   c   d   e   f   g \n"; break;
	   case 8: fo << "   a   b   c   d   e   f   g   h \n"; break;
	   case 9: fo << "   a   b   c   d   e   f   g   h   i \n"; break;
	   case 10: fo << "   a   b   c   d   e   f   g   h  i  j \n"; break;
        }
 fo << "  ";
 for (int k = 0; k < boardSize; k++) fo << "----";
 fo << "\n";
 for(int i = 0; i < boardSize; i++)
   {
    fo << boardSize - i;
    for(int j = 0; j < boardSize; j++)
      {
       if (board[i][j] == -1)
       fo << "| Q ";
       else
       fo << "|   ";
      }
    fo << "|" << boardSize - i << "\n";
    fo << "  ";
    for (int k = 0; k < boardSize; k++) fo << "----";
    fo << "\n";
   }      
        switch (boardSize)
        {
	   case 1: fo << "   a \n\n"; break;
	   case 2: fo << "   a   b \n\n"; break;
	   case 3: fo << "   a   b   c \n\n"; break;
	   case 4: fo << "   a   b   c   d \n\n"; break;
	   case 5: fo << "   a   b   c   d   e \n\n"; break;
	   case 6: fo << "   a   b   c   d   e   f \n\n"; break;
	   case 7: fo << "   a   b   c   d   e   f   g \n\n"; break;
	   case 8: fo << "   a   b   c   d   e   f   g   h \n\n"; break;
	   case 9: fo << "   a   b   c   d   e   f   g   h   i \n\n"; break;
	   case 10: fo << "   a   b   c   d   e   f   g   h  i  j \n\n"; break;
        }
    fo << "**************************************\n\n";
}
