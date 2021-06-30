#include<iostream>
using namespace std;

void ToH(int n,char A,char B,char C)
{
	if(n==1)
	{
		cout<<"Moving disk 1 from "<<A<<" to "<<B<<endl;
		return;
	}
	 ToH(n-1,A,C,B);
	cout<<"Moving disk "<< n<<" from "<<A<<" to "<<B<<endl;
	 ToH(n-1,C,B,A);
}

int main()
{
	int n;
	cout<<"Enter the number of disks"<<endl;
	cin>>n;
	ToH(n,'A','B','C');
	return 0;
}