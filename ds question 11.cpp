#include<iostream>
using namespace std;

 int Combinations(int n,int r)
 {
 	if(r>n)
 		return 0;
 	else if((n==0)||(n==r)||(r==0))
 	{
 		return 1;
 	}
 	return(n*Combinations(n-1,r-1))/r;
 }

 int Permutations(int n,int r)
 {
 	if(r>n)
 		return 0;
	else if(r==0)
	{
		return 1;
	}
	return n*Permutations(n-1,r-1);
 }

int main()
{
	int n,r;
	cout<<"Enter the value of n and r"<<endl;
	cin>>n>>r;
	cout<<"Total number of combinations using formula nCr is "<<Combinations(n,r)<<endl;
	cout<<"Total number of permutations using formula nPr is "<<Permutations(n,r)<<endl;
	return 0;
}