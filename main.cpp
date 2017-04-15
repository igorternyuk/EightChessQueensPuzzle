#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "queens.h"

using namespace std;

int main()
{
   int boardSize;
 
//   inputData(boardSize);
   ifstream fi("boardSize.txt");
   fi >> boardSize;
  //Выделяем память под массив моделирующий доску	
  
  int **board = new int*[boardSize];
    for(int i = 0; i < boardSize; i++)
       board[i] = new int[boardSize];

  cout << "Board size = " << boardSize << endl;
  tryQ(board, boardSize, 0); // Вызов фунции для поиска решений

// Освобождение динамической памяти
   
 for(int i = 0; i < boardSize; i++)
	delete[] board[i];   
    delete[] board;   
 
  return 0;
}
