#include <iostream>
using namespace std; 
/*functions up here*/ 
void displayBoard(int board[9][9]) 
{
  for (int y=0; y<9; y++)
  {
    string rowString=""; 
    if(y%3==0)
      cout<<"\n"<<".............";
    for(int z=0; z<9; z++)
    {
      if(z%3==0)
        rowString = rowString + "|" + "\u001B[35m" + std::to_string(board[y][z]) + "\u001B[0m"; 
      else 
       rowString = rowString + "\u001B[35m" + std::to_string(board[y][z])  + "\u001B[0m";        
      if(z==8)
      {
        rowString+="|";
        cout<<"\n"<<rowString; 
      }
    }
  }
  cout<<"\n"<<"............."<<endl;     
}

int main() {
  //1: Create a while loop that creates a 9 x 9 grid from 1-9 
  //Make sure that it is a 2D ARRAY 
  int xCoord=0; 
  int yCoord=0; 
  bool win=false; 
  bool lose=false; 
  int num=0; 
  int ogBoard[9][9]= {{0,0,4,0,5,0,0,0,0}, {9,0,0,7,3,4,6,0,0}, {0,0,3,0,2,1,0,4,9}, {0,3,5,0,9,0,4,8,0}, {0,9,0,0,0,0,0,3,0}, {0,7,6,0,1,0,9,2}, {3,1,0,9,7,0,2,0,0}, {0,0,9,1,8,2,0,0,3}, {0,0,0,0,6,0,1,0,0} };
  int p1[9][9]  = {{0,0,4,0,5,0,0,0,0}, {9,0,0,7,3,4,6,0,0}, {0,0,3,0,2,1,0,4,9}, {0,3,5,0,9,0,4,8,0}, {0,9,0,0,0,0,0,3,0}, {0,7,6,0,1,0,9,2}, {3,1,0,9,7,0,2,0,0}, {0,0,9,1,8,2,0,0,3}, {0,0,0,0,6,0,1,0,0} };
  displayBoard(p1); 

  while(win!=true) 
  {
    do{
      displayBoard(p1);  
      cout<<"Enter the x Coordinate you'd like to put/replace a #:"<<endl;
      cin>>xCoord; 
      cout<<"Enter the y Coordinate you'd like to put/replace a #:"<<endl; 
      cin>>yCoord;
      cout<<"Enter the number you would like to put from 1-9"<<endl; 
      cin>>num; 
      xCoord-=1; 
      yCoord-=1; 
      if(p1[yCoord][xCoord]>0 && ogBoard[yCoord][xCoord]!=0)
      {
        cout<<"Oopsies! You can't put a number where the default number is! Try again!"<<endl; 
      }
    } while (p1[yCoord][xCoord]>0 && ogBoard[yCoord][xCoord]!=0);

    p1[yCoord][xCoord]=num; 
    
    /* gets the first three numbers in the columns */
    int colStart; 
    int colEnd; 
    int rowStart; 
    int rowEnd; 
    if(xCoord%3==0)
    {
      colStart=xCoord; 
      colEnd=xCoord+2; 
    }
    if(xCoord%3==1)
    {
      colStart= xCoord-1; 
      colEnd = xCoord+1;       
    }
    if(xCoord%3==2)
    {
      colStart = xCoord-2; 
      colEnd = xCoord; 
    }
    /* gets the first three numbers in the rows */
    if(yCoord%3==0)
    {
      rowStart = yCoord; 
      rowEnd = yCoord+2; 
    }
    if(yCoord%3==1)
    {
      rowStart = yCoord-1; 
      rowEnd = yCoord+1; 
    }
    if(yCoord%3==2)
    {
      rowStart = yCoord-2;  
      rowEnd = yCoord; 
    }   
    
    for(int n=colStart; n<=colEnd; n++)
    {
      for(int j=rowStart; j<=rowEnd; j++)
      {
        if(p1[n][j]==num && yCoord!=n && xCoord!=j)
        {
          cout<<"Uh Oh! You have a number in the exact same cell!"<<endl;
          lose=true; 
        }
      }
    }
    //check if same row or same column # 
    for(int i=0; i<9; i++) //go through the array 
    {
      //same row 
      if(i!=xCoord)
        if(p1[yCoord][i]==num)    
        {
          cout<<"Uh Oh! You have a number in the exact same row! "<<endl; 
          lose=true; 
        }
      //same column 
      if(i!=yCoord)
      {
        if(p1[i][xCoord]==num)
        {
          lose=true; 
          cout<<"Uh Oh! You have a number in the exact same column! "<<endl;   
        }        
      }
    }
    //if the win value is false, exit the loop! 
    if(lose==true)
    {
      displayBoard(p1); 
      cout<<"You've lost!"<<endl; 
      break; 
    }
    /*
    //if the win value is false, exit the loop! 

    */
  }

   
}