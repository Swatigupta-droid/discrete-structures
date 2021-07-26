/*
20. Given a full m-ary tree with i internal vertices, Write a Program to find the number of leaf
nodes.
*/
#include<iostream>
using namespace std;

int main()
{
	int m;//value of m in m-ary
	int i;//number of internal vertices
	cout<<"Enter the value of m in a m-ary tree"<<endl;
	cin>>m;
	cout<<"Enter the number of internal vertices"<<endl;
	cin>>i;
	int l;
	l=(m-1)*i+1;//formula for finding the number of leaf nodes if internal vertices for full m-ary tree is given.
	cout<<"The number of leaf nodes are "<<l<<endl;
	return 0;
}

//OUTPUt

/*
Enter the value of m in a m-ary tree
4
Enter the number of internal vertices
33
The number of leaf nodes are 100

C:\Users\Lenovo-Laptop\Desktop\Backup\Second semester\discrete structures>
*/