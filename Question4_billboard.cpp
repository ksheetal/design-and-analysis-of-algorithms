#include<iostream>
#include<stdlib.h>
using namespace std; 
  
int maxRevenue(int m, int x[], int revenue[], int n, int t) 
{ 

	/*
	Objective:To place billboards on the highway such that revenue is maximized
	
	Input Parameters : m-> Length of highway in miles
					   x[]-> stores possible sites on the highway
					   revenue[]-> stores revenue of each possible site
					   n-> no of possible sites
					   t->Minimum distance between billboard
					   
	Output Parameters:Returns Maximum revenue
	*/
     
    int Rev[m+1]; 			// Array to store maximum revenue at each miles. 
    for(int i=0;i<m+1;i++)
    	Rev[i]=0;
  
    
    int k = 0; 
    for (int i = 1; i <= m; i++) 
    {   
        if (k < n) 
        {  
            if (x[k] != i) 
                Rev[i] = Rev[i-1]; 
    
            else
            {         
                if (i <= t) 
                    Rev[i] = max(Rev[i-1], revenue[k]); 
                else
                    Rev[i] = max(Rev[i-t-1]+revenue[k], 
                                                  Rev[i-1]); 
  
                k++; 
            } 
        } 
        else
            Rev[i] = Rev[i - 1]; 
    } 
  
    return Rev[m]; 
} 
  

int main() 
{ 
	/*
	Objective:To place billboards on the highway such that revenue is maximized
	*/

   	int m,n;
	int x[50];
	int revenue[50]; 
   	cout<<"\nEnter the value of m : ";
   	cin>>m;
   	cout<<"\nEnter no of possible sites(n): ";
   	cin>>n;
   	cout<<"\nEnter possible sites for billboards \n";
   	for(int i=0;i<n;i++)
   		cin>>x[i];
	cout<<"\nEnter revenue \n";
	for(int j=0;j<n;j++)
		cin>>revenue[j];
    cout <<"\nMaximum Revenue : "<<maxRevenue(m, x, revenue, n, 5) << endl; 
    return 0; 
} 
