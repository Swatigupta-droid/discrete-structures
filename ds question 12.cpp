#include<iostream>
using namespace std;

void solve(int *arr,int n,int c,int index)
{
	if(index>=n-1)
	{
		arr[index]=c;
		for(int i=0;i<n;i++)
			cout<<arr[i]<<" ";
		cout<<endl;
	}
	else
	{

		for(int i=0;i<=c;i++)
		{
			arr[index]=i;
			solve(arr,n,c-i,index+1);
		}
	}
}
int main()
{
	int n;
	cout<<"Enter the value of n "<<endl;
	cin>>n;
	int c;
	cout<<"Enter the value for c"<<endl;
	cin>>c;
	int *arr=new int[n];
	for(int i=0;i<n;i++)
		arr[i]=0;
	cout<<"The set is "<<endl;
	solve(arr,n,c,0);
}