#include<iostream>
#include<stdlib.h>
using namespace std;

int n;


int isSafe(int board[ ][100],int row,int col)
{
	/*
	Objective:function to check if a queen can be placed on board[row][col].
	Input Parameters : board[][]->Queens are placed on this board
						col->stores current column value
						row->stores current row value
	Output Parameters : none
	*/
	for(int i=0;i<n;i++)
		if(board[row][i])
			return 0;
	for(int i=row,j=col;i>=0 && j>=0;i--,j--)
		if(board[i][j])
			return 0;
	for(int i=row,j=col;i<n && j>=0;i++,j--)
		if(board[i][j])
			return 0;
			
	return 1;
	
}


void print(int board[ ][100])
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cout<<board[i][j]<<" ";
		cout<<"\n";	
	}
}


int nQueen(int board[ ][100],int col)
{
	/*
	Objective:To implement N Queen's problem using Back Tracking.
	Input Parameters : board[][]->Queens are placed on this board
						col->stores current column value
	Output Parameters : none
	*/
	if(col>=n)
		return 1;
	
	for(int i=0;i<n;i++)
	{
		if(isSafe(board,i,col))
		{
			board[i][col]=1;
			if(nQueen(board,col+1))
				return 1;
				
			board[i][col]=0;
		}
	}
	return 0;
	
}


int main()
{
	/*
	Objective:To implement N Queen's problem using Back Tracking.
	*/
	int board[100][100];
	cout<<"\nEnter the value of n : ";
	cin>>n;

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			board[i][j]=0;
		}
	}

	if(nQueen(board,0)==0)
		cout<<"\nSolution does not exist ";
	else
		print(board);
	return 0;
	
}

/*
	Time Complexity: O(n!)
*/

