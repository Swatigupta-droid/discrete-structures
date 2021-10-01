#include<iostream>
using namespace std;

int fibbonacci(int n){
	if(n==0||n==1)
		return n;
	return fibbonacci(n-1)+fibbonacci(n-2);
}


int main(){
	int n;
	cout<<"Enter your number:";
	cin>>n;
	cout<<"The fibbonacci series : "<<endl;
	for(int i=0;i<n;i++){
	cout<<fibbonacci(i)<<" ";
	}
	return 0;
}