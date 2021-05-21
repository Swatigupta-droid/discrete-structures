 #include<iostream>
using namespace std;

class relation
{
public:
    int n;
    int m[5][5];
   
    void getdata();
    void printdata();
    int reflexive();
    int symmetric();
    int assymmetric();
    int transitive();
};
void relation::getdata()
{
    cout<<"Enter order of matrix"<<endl;
    cin>>n;
    cout<<"Enter matrix of order "<<n<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cin>>m[i][j];
    } 
}

void relation::printdata()
{
    cout<<endl<<"The matrix is "<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<m[i][j]<<" ";
        cout<<endl;
    }
}

int relation::reflexive()
{
    int c=0;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(i==j)
                    {
                        if(m[i][j]==1)
                            c++;
                    }
                }
            }
            if(c==n)
                return 1;
            else
                return 0;
}

int relation::symmetric()
{
    int t=1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i!=j)
            {
                if((m[i][j]==1)&&(m[j][i]!=1))
                    t=0;
            }
        }
    }
    return t;
}

int relation::assymmetric()
{
     int t=1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i!=j)
            {
                if((m[i][j]==1)&&(m[j][i]==1))
                    t=0;
            }
        }
    }
    return t;
}

int relation::transitive()
{
    int t=1;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            for(int k=0;k<n;k++)
                if((m[i][j]==1)&&(m[j][k]==1)&&(m[i][k]!=1))
                    t=0;
    return t;
}


int main()
{
    relation a;
    a.getdata();
    a.printdata();
    int ch;
    cout<<"     Menu    "<<endl;
    cout<<"1. Reflexive relation "<<endl;
    cout<<"2. Symmetric relation  "<<endl;
    cout<<"3. Assymmetric relation "<<endl;
    cout<<"4. Transitive relation  "<<endl;
    cout<<"Enter choice "<<endl;
    cin>>ch;

    switch(ch)
    {
        case 1:
        {
            int r=a.reflexive();
            if(r==1)
                cout<<"The relation is reflexive"<<endl;
            else
                cout<<"The relation is not reflexive"<<endl;
            break;
        }
        case 2:
        {
            int s=a.symmetric();
            if(s==1)
                cout<<"The relation is symmetric"<<endl;
            else
                cout<<"The relation is not symmetric"<<endl;
            break;
        }
        case 3:
        {
            int as=a.assymmetric();
            if(as==1)
                cout<<"The relation is assymmetric"<<endl;
            else
                cout<<"The relation is not assymmetric"<<endl;
            break;
        }
        case 4:
        {
            int t=a.transitive();
            if(t==1)
                cout<<"The relation is transitive"<<endl;
            else
                cout<<"The relation is not transitive"<<endl;
            break;
        }

        default:
        {
            cout<<"Wrong choice "<<endl;
            break;
        }
    }
}
