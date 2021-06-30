#include<iostream>
using namespace std;

class Insertionsort
{
	int *arr;
	int n;
	int c;
	public :
	Insertionsort(int size)
	{
		n=size;
		arr=new int [size];
		c=0;
	}
	void input();
	void display();
	void sort();
};

void Insertionsort::input()
{
	cout<<"Enter the elements in the array"<<endl;
	for(int i=0;i<n;i++)
		cin>>arr[i];
}
void Insertionsort::display()
{
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}
void Insertionsort::sort()
{
	int key,i,j,c=0;
	for(j=1;j<n;j++)
	{
		key=arr[j];
		i=j-1;
		
		while(i>=0&&arr[i]>key)
		{
			c++;
			arr[i+1]=arr[i];
			i=i-1;
		}
		
		arr[i+1]=key;
		if(key>arr[i])
		{
			c++;
		}
		cout<<"Intermediate result"<<endl;
		for(int f=0;f<n;f++)
			cout<<arr[f]<<" ";
		cout<<endl;
	}
		cout<<"The total number of comparisons are "<<c<<endl;
	
}
/*void Insertionsort::sort()
{
	int key,i,j,c=0;
	for(j=1;j<n;j++)
	{
		key=arr[j];
		i=j-1;
		
		while(i>=0)
		{
			c++;
			if(arr[i]>key){
						arr[i+1]=arr[i];
						i=i-1;
					}
		}
		
		arr[i+1]=key;
		cout<<"Intermediate result"<<endl;
		for(int f=0;f<n;f++)
			cout<<arr[f]<<" ";
		cout<<endl;
	}
		cout<<"The total number of comparisons are "<<c<<endl;
}
*/
int main()
{
	int size;
	cout<<"Enter the size of the array"<<endl;
	cin>>size;
	Insertionsort ins(size);
	ins.input();
	cout<<"Array before sorting "<<endl;
	ins.display();
	ins.sort();
}