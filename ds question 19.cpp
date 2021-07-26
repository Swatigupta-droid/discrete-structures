/*Given an adjacency matrix of a graph, write a program to check whether a given set of
vertices {v1,v2,v3.....,vk} forms an Euler path / Euler Circuit (for circuit assume vk=v1).*/
#include<iostream>
using namespace std;

class euler
{
	int **a;//contains adjacency matrix of graph
	int **b;//constructed new matrix using the path given
	int *c;//contains the path
	public:
	 int n;//number of vertices
	 int p;//length of path

	 /*Constructor*/
	euler()
	{
		cout<<"Enter the number of vertices"<<endl;
		cin>>n;

		/*dynamic allocation is used for the matrices*/

		a=new int*[n];
		b=new int*[n];
		for (int i = 0; i < n; ++i)
		{
			a[i]=new int[n];
			b[i]=new int[n];
		}

		cout<<"Enter the length of path"<<endl;
		cin>>p;
		c=new int[p];

		/*intialised the matrices to 0*/

		for(int i=0;i<n;i++)
		{
			for (int j=0;j<n;j++)
			{
				a[i][j]=0;
				b[i][j]=0;
			}
		}
	}

	void input();//for taking input
	void newmatrix();//creating the new matrix using new matrix
	int eulerpath();//checking for euler path
	int eulercircuit();//checking for euler circuit

};
void euler::input()
{
	cout<<"Enter the adjacency matrix for the graph"<<endl;
	for (int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cin>>a[i][j];
	}
	cout<<"Enter the path "<<endl;
	for (int i=0;i<p;i++)
	{
		cin>>c[i];
	}
}
void euler::newmatrix()
{
	for(int i=0;i<p-1;i++)
	{
		int d=c[i],f=c[i+1];
		b[d][f]=1;
	}
	for (int i = 0; i < n; ++i)
	{
		for(int j=0;j<n;j++)
			cout<<b[i][j];
		cout<<endl;
	}
}
int euler::eulerpath()
{
	int k=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			/*If both matrices are equal for directed graph and if have an edge for undirected graph counter will go ++ */
			if(a[i][j]==b[i][j]||a[i][j]==a[j][i])
				k++;
		}
		
	}
	return k;
}
int euler::eulercircuit()
{
	if (eulerpath()==(n*n))//if counter is equal to the length of matrix it is a euler path since the matrices will then be equal
	{
		if (c[0]==c[p-1])
		{
			return 1;
		}
	}
	return 0;
}
int main()
{
	int ch;
	cout<<"****Menu****"<<endl;
	cout<<"1. Euler path."<<endl;
	cout<<"2. Euler circuit"<<endl;
	cout<<"Enter your choice"<<endl;
	cin>>ch;

	euler e1;
	e1.input();
	e1.newmatrix();

	switch(ch)
	{
		case 1:
		{
			int m=e1.eulerpath();
			int s=e1.n*e1.n;
			if(m==s)
				cout<<"The path is a euler path"<<endl;
			else
				cout<<"The path is not a euler path"<<endl;
			break;
		}
		case 2:
		{
			int g=e1.eulercircuit();
			if(g==1)
				cout<<"The graph contains a euler circuit"<<endl;
			else
				cout<<"The graph does not contain a euler circuit"<<endl;
			break;
		}
		default:
		{
			cout<<"Wrong choice"<<endl;
			break;
		}
	
	}
	return 0;

}
//OUTPUT

/*
	****Menu****
1. Euler path.
2. Euler circuit
Enter your choice
1
Enter the number of vertices
5
Enter the length of path
6
Enter the adjacency matrix for the graph
0 1 1 1 0
1 0 1 0 0
1 1 0 0 0
1 0 0 0 1
0 0 0 1 0
Enter the path
4 3 0 1 2 0
01000
00100
10000
10000
00010
The path is a euler path

C:\Users\Lenovo-Laptop\Desktop\Backup\Second semester\discrete structures>

****Menu****
1. Euler path.
2. Euler circuit
Enter your choice
2
Enter the number of vertices
5
Enter the length of path
7
Enter the adjacency matrix for the graph
0 1 1 1 0
1 0 1 0 0
1 1 0 0 0
1 0 0 0 1
0 0 0 1 0
Enter the path
2 1 0 3 4 0 2
00110
10000
01000
00001
10000
The graph contains a euler circuit

C:\Users\Lenovo-Laptop\Desktop\Backup\Second semester\discrete structures>



*/