#include<iostream>
#include<math.h>
using namespace std;
class set
{
	int *ar;
	int size;
	
		public:set()
		{
			size=0;
			ar=new int[size];
		}
		void getinput();
		void print();
		void cardinality();
		void is_member();
		void power_set();
	    
		
 };
 void set::getinput()
 {
 	cout<<"enter the size of an array ";
 	cin>>size;
 	ar=new int[size];
 	cout<<"enter the elements "<<endl;
 	for(int i=0;i<size;i++)
 	cin>>ar[i];
  } 
 void set::print(){
 
 cout<<"the given set is";
  cout<<"\nSET A : { ";
 for(int i=0;i<size;i++)
 {
 	if(i==0)
 	cout<<ar[i];
 	else
 	cout<<","<<ar[i];
 }
 cout<<" }"<<endl;
}
void set::cardinality()
{
cout<<"\nAfter removing redudancy ";
cout<<"\nSET A : {";int c=0;
for(int i=0;i<size;++i)
		for(int j=i+1;j<size;)
		{
			if(ar[i]==ar[j])
			{
				for(int k=j;k<size-1;++k)
					ar[k]=ar[k+1];
					
				--size;
			}
			else
				++j;
		}
	
	
	for(int i=0;i<size;++i)
	if(i==0)
		cout<<ar[i];
		else
		cout<<","<<ar[i];
cout<<"}"<<endl;

cout<<"\nCardinality "<<size;
}
void set::is_member()
{
	int k,flag=0;
	cout<<"\nEnter the number to be checked ";
	cin>>k;
	for(int i=0;i<size;i++)
	{
		if(ar[i]==k)
		{
			flag=1;
			break;
		}
	}
	if(flag==1)
	cout<<"element is the member of setA\n";
	else
	cout<<"element is not the member of set A";
}
void set::power_set()
{
 int count,temp;
 cout<<"{ {},";


 	 for(int i=0;i<size;++i)
		for(int j=i+1;j<size;)
		{
			if(ar[i]==ar[j])
			{
				for(int k=j;k<size-1;++k)
					ar[k]=ar[k+1];
					
				--size;
			}
			else
				++j;
		}
		count=pow(2,size);
    for(int i=0;i<count;i++)
    {
 	cout<<"{";
 	for(int j=0;j<size;j++)
 	{
 		
 		if(i&(1<<j))
 		
	
 		 cout<<ar[j]<<",";
 		 
	 }
	 cout<<"\b},";
	 }	
	 cout<<"\b}";


}

int main()
{
   int ch;
   set a;
   a.getinput();
   a.print();
   
   cout<<"\n1.cardinality ";
   cout<<"\n2. to check whether the element is member of set or not ";
   cout<<"\n3. powerset ";
   cout<<"\nenter your choice : ";
   cin>>ch;
   switch(ch)
   {
   
   case 1:a.cardinality();
          break;
   case 2:a.is_member();
          break;
   case 3:a.power_set();
          break;
}
}