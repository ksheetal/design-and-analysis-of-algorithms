#include<stdio.h> 
#include<conio.h> 
#include<stdlib.h>
#include<iostream>
#define INF 100000
using namespace std;
  

int MatrixChainOrder(int p[], int n) 
{ 

	/*
	Objecive : To find the minimum multiplication operations required for multiplying n matrices.
	Input Parameters : p[] ->strore dimension of matrices
					   n-> size of p[] matrix
	Output Parameters : returns minimum no of multiplications
	*/
  
    int m[n][n]; 				//m[i,j] stores minimum no of scaler multiplications needed 
    int i, j, k, l, q; 
    
    for (i=1; i<n; i++) 
        m[i][i] = 0; 			//cost is zero when multiplying one matrix
  
   
    for (l=2; l<n; l++)     // l is chain length
    { 
        for (i=1; i<n-l+1; i++) 
        { 
            j = i+l-1; 
            m[i][j] = INF; 		//INF stores very large number
            for (k=i; k<=j-1; k++) 
            { 
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];    //q stores cost of multiplications
                if (q < m[i][j]) 
                    m[i][j] = q; 
            } 
        } 
    } 
    
  
    return m[1][n-1]; 
} 
  
int main() 
{
	/*
	Objecive : To find the minimum multiplication operations required for multiplying n matrices.
	*/
	 int arr[50];
	 int size;
	 cout<<"\nEnter size of array : ";
	 cin>>size;
	 cout<<"\nEnter array : \n";
	 for(int i=0;i<size;i++)
	 {
	 	cin>>arr[i];
	 
	 }
     cout<<"\nMinimum no of multiplications is : "<<MatrixChainOrder(arr,size);
  
    getch();
    return 0; 
} 
