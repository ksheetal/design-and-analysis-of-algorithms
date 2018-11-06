#include<iostream>
#include<stdlib.h>
#define INFINITY 1000000
#define MAX_NODES 100
using namespace std;

int n,a[MAX_NODES][MAX_NODES];

void enter()
{
	cout<<"\t Enter the no. of nodes : \t";
	cin>>n;
	cout<<"\t Enter the weight-matrix : \n"<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
  		{
			cin>>a[i][j];
		}
	}

	cout<<"\n\t The weight matrix is : \n";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

void dijkstra(int s,int d,int path[])
{
	class node
	{

	  public:
		int pred;
		int length;
		int label;
	}node1[n];
	
	int i,k,min;
	node *p;
	for(p=&node1[0];p < &node1[n];p++)
	{
		p->pred=-1;
		p->length=INFINITY;
		p->label=0;
	}
	
	node1[d].length=0;
	node1[d].label=1;
	k=d;
	do
	{
		for(i=0;i<n;i++)
		{
			if(a[k][i]!=0 && node1[i].label==0)
			{
				if(node1[k].length + a[k][i] < node1[i].length)
				{
					node1[i].pred=k;
					node1[i].length=node1[k].length + a[k][i];
				}
			}
		}
		
		k=0;
		min=INFINITY;
		for(i=0;i<n;i++)
		{
			if(node1[i].label==0 && node1[i].length < min)
			{
				min=node1[i].length;
				k=i;
			}
		}
		node1[k].label=1;
	}while(k!=s);
	
	i=0;
	k=s;
	do{
		path[i++]=k;
		k=node1[k].pred;
          }while(k>=0);
	cout<<"\t SHORTEST PATH IS : \t";
	for(int j=0;j<i;j++)
	{
		cout<<path[j]<<" ";
	}
}

int main()
{
	int s,d,path[10];
	enter();
	cout<<"\t Enter the source node : \t";
	cin>>s;
	cout<<"\t Enter the destination node : \t";
	cin>>d;
	dijkstra(s,d,path);
	cout<<endl;
}			

