#include<iostream>
using namespace std;

void sort(int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		if(arr[i]>arr[i+1])
			swap(arr[i],arr[i+1]);
	}
}

void swap(int a,int b)
{
	int t=a;
	a=b;
	b=t;
}

int bSearch(int arr[],int l,int u,int x)
{
	if(u>=l)
	{
		int mid=l+(u-1)/2;
		if(arr[mid]==x)
			return mid;
		if(arr[mid]<x)
			return bSearch(arr,mid+1,u,x);

		return bSearch(arr,0,mid-1,x);
	}
	return -1;
}

int main()
{
	int n;
	cout<<"Enter size of array : ";
	cin>>n;
	int* arr;
	arr=new int [n];
	cout<<"Enter the array "<<endl;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	sort(arr,n);
	int x;
	cout<<"Enter the number to be searched "<<endl;
	cin>>x;
	int position=bSearch(arr,0,n-1,x);
	if(position==-1)
		cout<<"Value not present in the array "<<endl;
	else
		cout<<"The value is present at index "<<position<<endl;
}