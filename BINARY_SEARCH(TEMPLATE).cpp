#include<iostream>
using namespace std;


template<typename T>
int binary_search(T data[],int n,T x)
{
	int left = 0;
	int right = n-1;
	while(left<=right)
	{
		int mid = (left+right)/2;
		if(data[mid]==x)	
			return mid;
		else if(data[mid]<x)	
			left = mid + 1;
		else	
			right = mid - 1;
	}
	return -1;
}


template<typename T>
void Print(T data[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << data[i] << " ";
    cout <<endl;
}

int main()
{

    int *data,n;
    cout<<"Enter the size of the array"<<endl;
    cin>>n;
    data=new int[n];
    cout<<"Enter the elements of the array"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>data[i];
}
    
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(data[j]>data[j+1])
            {
                int temp=data[j];
                data[j]=data[j+1];
                data[j+1]=temp;
            }
        }
    }
    
    cout << "Array : " << endl;
    Print(data, n);
    
    int x, index;
    cout<<"Enter value you want to Search: ";
    cin>>x;
    
    index = binary_search(data, n, x);
    
    if(index==-1)
    	cout<<x<<" is not present in the array"<<endl;
    else
    	cout<<x<<" is present in the array at index "<<index<<endl;

}
/*output:
Enter the size of the array
6
Enter the elements of the array
1
2
3
9
8
7
Array :
1 2 3 7 8 9
Enter value you want to Search: 7
7 is present in the array at index 3
*/
