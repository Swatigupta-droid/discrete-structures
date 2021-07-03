#include<iostream>
using namespace std;
int T1(int n)
{
    if(n==0)
        return 1;

    return T1(n-1)+n;
}
int T2(int n)
{
    if(n==0)
        return 1;

    return T2(n-1)+(n*n);
}
int T3(int n)
{
    if(n==1)
        return 1;

    return 2*T3(n/2)+n;
}
int main()
{
    int n;
    
    int ch;char c;
    do
    {
        cout<<"Enter the value of n"<<endl;
        cin>>n;
        cout<<"*****MENU*****"<<endl;
        cout<<"1.First function"<<endl;
        cout<<"2.Second function"<<endl;
        cout<<"3.Third function"<<endl;
        cout<<"Enter your choice"<<endl;
        cin>>ch;
        switch(ch)
        {
            case 1:
            {
                for(int i=0;i<=n;i++)
                    cout<<"The result for "<<i<<" is "<<T1(i)<<endl;
                break;
            }
            case 2:
            {
                for(int i=0;i<=n;i++)
                    cout<<"The result for "<<i<<" is "<<T2(i)<<endl;
                break;
            }
            case 3:
            {
                for(int i=1;i<=n;i++)
                    cout<<"The result for "<<i<<" is "<<T3(i)<<endl;
                 break;
            }
            default:
            {
                cout<<"Wrong choice"<<endl;
                break;
            }
        }
        cout<<"Do you want to continue (Y/N)"<<endl;
        cin>>c;
    }
    
    while(c=='Y'||c=='y');
}