#include<iostream>
using namespace std;

class sorting
{
	int n;
	int *a;
	int c;
public:
	sorting(int size)
	{
		n=size;
		a=new int[n];
	}
	void input();
	void display();
	void BubbleSort();
};
void sorting::input()
{
	for(int i=0;i<n;i++)
		cin>>a[i];
}
void sorting::BubbleSort()
{
	int i,j,f=0,sum=0;
	for(i=n;i>1;i--)
	{
		c=0;
		for(j=0;j<i-1;j++)
		{
			c++;
			if(a[j]>a[j+1])
				{
					int temp=a[j];
					a[j]=a[j+1];
					a[j+1]=temp;
				}
		}
		++f;sum+=f;
		cout<<endl<<"The number of comparisons is "<<c<<endl;
		cout<<"Pass number "<<f<<endl;
		cout<<"Intermediate array ";
		display();
	}
	cout<<" Total number of comparisons is "<<+sum<<endl;
}
void sorting::display()
{
	cout<<endl;
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}
int main()
{
	int size;
	cout<<"Enter the size of array"<<endl;
	cin>>size;
	sorting sort(size);
	cout<<"Enter the elements in the array "<<endl;
	sort.input();
	cout<<endl<<"The array before sorting is";
	sort.display();
	sort.BubbleSort();
	cout<<endl<<"The array after sorting is ";
	sort.display();

}