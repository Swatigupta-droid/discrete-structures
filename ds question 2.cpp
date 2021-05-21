#include<iostream>
using namespace std;

class set
{
	public:
		int *ar;
		int size;
		int count;

		set()
		{   
			size=10;
			ar=new int[size];
			count=0;
		}

		set(const set &a1)
		{
			size=5;
			ar=new int[size];
			count=0;
		}

		void getdata();
		void printdata();
		int subset(set &a1);
		set union_(set &a1);
		set intersection(set &a1);
		set difference(set &a1);
		set symmetricdifference(set &a1);

};

void set::getdata()
{
	cout<<"size"<<endl;
		cin>>size;

	cout<<"elements"<<endl;
	for(int i=0;i<size;i++)
		cin>>ar[i];

    cout<<endl;
}

void set::printdata()
{
	cout<<"The set is { ";

  for(int i=0;i<size;i++)
  {
    if(i==0)
      cout<<ar[i];
    else
      cout<<" , "<<ar[i];
  }

  cout<<" }"<<endl;

 }

int set::subset(set &a1)
{
	int c=0,s=0;

	for(int i=0;i<size;i++)
		cout<<ar[i]<<" ";

	cout<<endl;

	for(int j=0;j<a1.size;j++)
		cout<<a1.ar[j]<<" ";

	cout<<endl;

	for(int i=0;i<size;i++)
	{    
		c=0;

		for(int j=0;j<a1.size;j++)
		{
			if(ar[i]==a1.ar[j])
			c++;
		}

		if(c>=1)
			s++;

	}

	if(s==size)
	{
		return 1;
	}
    else
    {
		return 0;
    }
		
}

set set::union_(set &a1)
{
   set c;

   c.size=size+a1.size;

   int k=0,i=0,j=0;

   while(i<size&&j<a1.size)
   {
   	if(ar[i]<a1.ar[j])
   	{
   		c.ar[k++]=ar[i++];
   	}
   	else
   	{
   		c.ar[k++]=a1.ar[j++];
   	}

   }
   while(i<size)
   	c.ar[k++]=ar[i++];

   while(j<a1.size)
   	c.ar[k++]=a1.ar[j++];
   
    c.count=k;
   
   for(i=0;i<c.count;i++)
   	for(j=i+1;j<c.count;)
   	{
   		if(c.ar[i]==c.ar[j])
   		{
   			for(int f=j;f<c.count-1;++f)
   				c.ar[f]=c.ar[f+1];

   			--c.count;
   		}
   		else
   			++j;
   	}
   	  c.size=j;

   		return c;
}
set set::intersection(set &a1)
{
	set c;

	int i=0,j=0,k=0;

	for(i=0;i<size;i++)
	{
		for(j=0;j<a1.size;j++)
			if(ar[i]==a1.ar[j])
				c.ar[k++]=ar[i];
	}

	c.size=k;

	return c;

}

set set::difference(set &a1)
{
	int i=0,j=0,k=0,s=0;
	
	set c;

	for(i=0;i<size;i++)
	{
		for(j=0;j<a1.size;j++)
		{
			if(ar[i]!=a1.ar[j])
				s++;
		}

		if(s==a1.size)
			c.ar[k++]=ar[i];

		s=0;
	}

	c.size=k;

	return c;
}

set set::symmetricdifference(set &a1)
{
	set c=set::union_(a1);
	set d=set::intersection(a1);

	set e;
	int s=0,f=0;

	for(int i=0;i<c.size;i++)
	{
		for(int j=0;j<d.size;j++)
		{
			if(c.ar[i]!=d.ar[j])
                  s++;
		}
		if(s==d.size)
			e.ar[f++]=c.ar[i];

		s=0;
	}

	e.size=f;
	
	return e;

}

 int main()
 {
 	set a;
 	set b(a);

    a.getdata();
    b.getdata();
    a.printdata();
    b.printdata();
    
    int ch;
	cout<<"     Menu    "<<endl;
	cout<<"1. Subset "<<endl;
	cout<<"2. Union  "<<endl;
	cout<<"3. Intersection "<<endl;
	cout<<"4. Difference  "<<endl;
	cout<<"5. Symmetric difference "<<endl;
	cout<<"6. Cartesian product  "<<endl;
	cout<<"Enter choice "<<endl;
	cin>>ch;

	switch(ch)
	{

		case 1:
		{
          if(a.subset(b))
          	cout<<"Array1 is a subset of array2"<<endl;
          else 
          	cout<<"array1 is not a subset of array2"<<endl;
         
          break;

		}

		case 2:
		
		{
			set c=a.union_(b);

			cout<<"Union of both sets is "<<endl<<"{ ";
			
			for(int i=0;i<c.count;i++)
   				{
   					if(i==0)
   						cout<<c.ar[i];
   					else{
   						cout<<" , ";
   					cout<<c.ar[i];}
   				}
   				cout<<" }"<<endl;
   			
   				break;
		
		}
		
		case 3:
		
		{
			set c=a.intersection(b);
            int i=0;
		
			cout<<"Intersection of both sets is "<<"{ ";
        
        for(i=0;i<c.size;i++)
        {
          if(i==0)
            cout<<c.ar[i];

          else
            cout<<" , "<<c.ar[i];

        }

        cout<<" }"<<endl;
        
        break;
		
		}

		case 4:
		{

         set c=a.difference(b);
         int i=0;
        
         cout<<"Difference between two sets is "<<" { ";
        for(i=0;i<c.size;i++)
        {
          if(i==0)
            cout<<c.ar[i];

          else
            cout<<" , "<<c.ar[i];
        }

        cout<<" }"<<endl;
      
        break;

		}

		case 5:
		{
    
         set e=a.symmetricdifference(b);
         int i=0;

        cout<<"Symmetric difference of the two sets is "<<" { ";

        for(i=0;i<e.size;i++)
        {
          if(i==0)
            cout<<e.ar[i];

          else
            cout<<" , "<<e.ar[i];
        }

        cout<<" }"<<endl;
        
        break;
		}

		case 6:
		{

			cout<<"Cartesian product of the two sets is "<<" { ";

        for(int i=0;i<a.size;i++)
        {
          for(int j=0;j<b.size;j++)
            cout<<"{ "<<a.ar[i]<<","<<b.ar[j]<<"} ";
        } 

        cout<<" }"<<endl;

        break;
		}

		default:
		{
			cout<<"Wrong choice"<<endl;
			break;
		}
	}

return 0;
 }