#include<iostream>
#include<conio.h>

using namespace std;
class Logic
{
	public:
		int x=0,y=0;
		Logic();
	char Bool(int val);
	void conjunction(bool check);
	void disjunction(bool check);
	void exclusiveOr(bool check);
	void conditional();
	void negation();
};
Logic::Logic()
{
	cout<<"Start of program"<<endl;
}
char Logic::Bool(int val)
{
	if(val==0)
		return 'F';
	else
		return 'T';
}

void Logic::conjunction(bool check)
{	
	for(x=0;x<=1;x++)
	{
		for(y=0;y<=1;y++)
		{
			cout << Bool(x) << "   |   " << Bool(y) << "   |   ";
			if(check)
				cout<<Bool(x&y)<<endl;
			else
				cout<<Bool(!(x&y))<<endl;
		}
	}
}

void Logic::disjunction(bool check)
{
	for(x=0;x<=1;x++)
	{
		for(y=0;y<=1;y++)
		{
			cout << Bool(x) << "   |   " << Bool(y) << "   |   ";
		if(check)
			cout<<Bool(x|y)<<endl;
		else
			cout<<Bool(!(x|y))<<endl;
		}
	}
}
void Logic::exclusiveOr(bool check)
{
	for(x=0;x<=1;x++)
	{
		for(y=0;y<=1;y++)
		{
			cout << Bool(x) << "   |   " << Bool(y) << "   |   ";
			if(check)
				cout<<Bool(x^y)<<endl;
			else
				cout<<Bool(!(x^y))<<endl;
		}
	}
}

void Logic::conditional()
{
	
	for(x=0;x<=1;x++)
	{
		for(y=0;y<=1;y++)
		{
				cout << Bool(x) << "   |   " << Bool(y) << "   |   ";
				cout<<Bool((!x)|y)<<endl;	
		}
	}
}
void Logic::negation()
{
	for(x=0;x<=1;x++)
	{
		for(y=0;y<=1;y++)
		cout << Bool(x) << "   |   " << Bool(y) << "   |   " << Bool(!x) << "   |   " << Bool(!y)<<endl;
	}
}
int main()
{
	int choice;
	char repeat;
	Logic logic;
		do
		{
		cout<<"*****MENU*****"<<endl;
		cout<<"1.Conjunction"<<endl;
		cout<<"2.Disjunction"<<endl;
		cout<<"3.Exclusive OR"<<endl;
		cout<<"4.Conditional"<<endl;
		cout<<"5.Biconditional"<<endl;
		cout<<"6.Exclusive NOR"<<endl;
		cout<<"7.Negation"<<endl;
		cout<<"8.Nand"<<endl;
		cout<<"9.Nor"<<endl;
		cout<<"Enter your choice"<<endl;
		cin>>choice;
	
		switch(choice)
		{
			case 1:
			{
				cout << endl;
        		cout << "x   |   "<< "y   |   "<< "x&y"<<endl;
        		cout << "===================="<<endl;
        		logic.conjunction(true);
				break;
			}		
   			case 2:
   			{
   			 	cout << endl;
        	 	cout << "x   |   "<< "y   |   "<< "x|y"<<endl;
        	 	cout << "===================="<<endl;
        		 logic.disjunction(true);
        		 break;
   			}
   			case 3:
   			{
   				cout<<endl;
   				cout << "x   |   "<< "y   |   "<< "x^y"<<endl;
        	 	logic.exclusiveOr(true);
        	 	break;
   			}

   			case 4:
   			{
   				cout << endl;
        		cout << "x   |   "<< "y   |   "<< "x->y"<<endl;
        		cout << "===================="<<endl;
        		logic.conditional();
     			break;
   			}
   			case 5:
   			{
   				cout << endl;
        		cout << "x   |   "<< "y   |   "<< "x<->y"<<endl;
        		cout << "===================="<<endl;
        	 	logic.exclusiveOr(false);
        	 	break;
   			}
   			case 6:
   			{
   				cout << endl;
        		cout << "x   |   "<< "y   |   "<< "!(x^y)"<<endl;
        		cout << "===================="<<endl;
        	 	logic.exclusiveOr(false);
        	 	break;
   			}
   			case 7:
   			{
   				cout << endl;
        		cout << "x   |   "<< "y   |   "<< "~x   |   "<< "~y      "<<endl;
        		cout << "==============================="<<endl;
        		logic.negation();
        		break;
   			}
   			case 8:
   			{
   				cout << endl;
        		cout << "x   |   "<< "y   |   "<< "xNANDy"<<endl;
        		cout << "===================="<<endl;
        		logic.conjunction(false);
				break;
   			}
   			case 9:
   			{
   				cout << endl;
        		cout << "x   |   "<< "y   |   "<< "xNORy"<<endl;
        		cout << "===================="<<endl;
        		logic.disjunction(false);
        		break;
   			}
   			default:
   			{
   				cout<<"Wrong choice"<<endl;break;
			}
		}
		cout<<"Do you want to continue :(Y?N) "<<endl;
			cin>>repeat;
		}
			while(repeat=='Y'||repeat=='y');


}


