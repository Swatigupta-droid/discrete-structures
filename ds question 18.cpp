#include<iostream>
using namespace std;

class gr
{
	int **a;
	int n;
	int a1;
	int b1;
public:
	void enter();
	//int path();
	void multiply();

};
void gr::enter()
{
	
	cout<<"Enter the length of path"<<endl;
	cin>>n;
	a=new int *[n];
		for(int i=0;i<n;i++)
		{
			a[i]=new int[n];
		}
	cout<<"Enter the matrix"<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cin>>a[i][j];
	}
	cout<<"Enter the start point and the end point"<<endl;
	cin>>a1>>b1;
}


void gr::multiply()
{
	int **b,**c;int i=0;
	b=new int*[n];
	c=new int*[n];
	for(int i=0;i<n;i++)
	{
		c[i]=new int[n];
		b[i]=new int[n];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			b[i][j]=a[i][j];
	}
	if(n!=1)
	{
		for(int l=2;l<=n;l++)
		{
			cout<<"Matrix after multiplication "<<"A^"<<l;
			for(int i=0;i<n;i++)
			{
				cout<<endl;
				for(int j=0;j<n;j++)
				{
					c[i][j]=0;
					for(int k=0;k<n;k++)
					{
						c[i][j]+=a[i][k]*b[k][j];
					}
					cout<<c[i][j]<<" ";
				}
			}
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
				{	
					b[i][j]=c[i][j];
				}
			}
			cout<<endl;
			cout<<"The number of path between "<<a1<<" and "<<b1<<" of length "<<n<<" is "<<c[a1][b1-1]<<endl;
		}
	}
}


int main()
{
	gr g1;
	g1.enter();
	g1.multiply();
}
