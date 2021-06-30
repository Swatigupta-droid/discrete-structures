#include<iostream>
using namespace std;

void check(int in[],int out[],int n)
{
	int sumin=0,sumout=0;
	for(int i=0;i<n;i++)
	{
		sumin+=in[i];
		sumout+=out[i];
	}
	if(sumin=sumout)
		cout<<"The answer is correct"<<endl;
	else
		cout<<"The answer is wrong "<<endl;
}
int main()
{
	int n;
	cout<<"Enter the number of vertices "<<endl;
	cin>>n;
	int **ar;
	ar=new int*[n];
	for(int i=0;i<n;i++)
		ar[i]=new int[n];
	int *in=new int[n];
	int *out=new int[n];
	cout<<"Enter the matrix "<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cin>>ar[i][j];
	}
	/*   a  b  c
	   a 00 01 02
	   b 10 11 12
	   c 20 21 22   
	   basically we can say that 01 will be 1 or greater than 1 if there is 
	   an edge coming out of a and going into b same for 02 there is an edge 
	   coming out of a and going into c so we can conclude that the rows show 
	   the edges coming out and columns show the edges coming in so we can simply
	   get the sum of rows for outdegree and columns for in degree and since
	   we know that self loops lead to +2  therefore we will have a different 
	   if condition for it*/
	for(int i=0;i<n;i++)
	{
		in[i]=out[i]=0;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(ar[i][j]>=1)
			{
				if(j!=i)
				{
					in[j]+=ar[i][j];
					out[i]+=ar[i][j];
				}
				else
				{
					in[i]+=2;
					out[j]+=2;
				}
			}
		}
	}

	for(int i=0;i<n;i++)
	{
		cout<<"outdegree of vertex "<<i<<" is "<<out[i]<<endl;
		cout<<"indegree of vertex "<<i<<" is "<<in[i]<<endl;
		cout<<endl;
	}
	check(in,out,n);
}