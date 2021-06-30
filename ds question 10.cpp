#include<iostream>
using namespace std;

void swap(int *x,int *y)
{
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}

void permutation(int *a,int n,int f,int l)
{
	if(f==l)
	{
		for(int i=0;i<n;i++)
			cout<<a[i];
	}
	else
	{
		for(int i=f;i<=l;i++)
		{
			swap(a[f],a[i]);
			permutation(a,n,f+1,l);
			swap(a[f],a[i]);
			cout<<"\n";
		}
	}
}
void permut(int *a,int *B,int f,int n)
{
	if(f==n)
	{
		for(int i=0;i<f;i++)
			cout<<B[i];
		cout<<endl;
	}
	else
	{
		for(int i=0;i<n;i++)
		{
			B[f]=a[i];
			permut(a,B,f+1,n);
			cout<<"\n";
		}
	}
}
int main()
{
	int n;
	cout<<"Enter number of elements in the set ";
	cin>>n;
	int *arr=new int[n];
	int *B=new int [n];
	cout<<endl<<"Enter the elements of the set ";
	for(int i=0;i<n;i++)
		cin>>arr[i];
	int c;char ch;
	do
	{
	cout<<"**********PERMUTATIONS**********"<<endl;
	cout<<"1.WITH REPETITION"<<endl;
	cout<<"2.WITHOUT REPETITION"<<endl;
	cout<<"Enter your choice";cin>>c;
	switch(c)
	{
		case 1:
		{
			cout<<"\n Possible permutations of the set with repitition is \n";
			permut(arr,B,0,n);
			break;
		}
		case 2:
		{
			cout<<"\n Possible permutations of the set without repetition is \n";
			permutation(arr,n,0,n-1);
			break;
		}
		default:
		{
			cout<<"Wrong choice"<<endl;break;
		}
	}
	cout<<"Do you want to continue (y/n) ? ";
		cin>>ch;
	}
	while(ch=='Y'||ch=='y');
}