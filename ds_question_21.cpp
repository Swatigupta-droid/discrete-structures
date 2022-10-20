#include<bits/stdc++.h>

using namespace std;

void ismember(int element, int *A, int n){
    if(n>0){
        cout<<"Enter the element you want to check: "; cin >> element;
    
        int count1 = 0;
        for(int i =0; i<n;i++){
            if(A[i] == element){
                count1 = 1; break;
            }
        }
        if(count1 == 0){
            cout << "\nElement is not the member of set.\n";
        }
        else{
            cout <<"Element is member of the set.\n";
        }
    }
}

void power_set(int *A,int size){
    int psize = pow(2,size);
    int b[] = {0,0,0,0};
    cout << "\nPower set: \n";
    cout << "{ ";
    for(int i=0;i<psize;i++){
        int n =0;
        for(int l=i;l>0;l/2){
            b[n] = l%2;
            n++;
        }
        cout << "{ ";
        for(int j=0;j<size;j++){
            if(b[j] ==1){
                cout <<A[j] << " , ";
            }
        }
        if(i==0){
            cout << " } , ";
        }else{
            cout <<"\b}, ";
        }
    }
    cout << "\b}" << endl;
}


int main()
{
    int n;
    cout <<"Enter number of elements you want: ";
    cin >> n;

    int *A = new int[n];
    if(n>0){
        cout<< "Enter the elements: ";
        for(int i=0;i<n;i++){ cin >> A[i]; }
    }
    if(n == 0){
        cout << "SET A = { } \n OR SET A = (NULL SET)\n";
    }
    else{
        cout << "\n SET A = { ";
        for(int i =0;i<n;i++){
            cout << A[i] << ", ";
        }
        cout << "}" << endl;
    }

    if(n == 0){ 
        cout << "\nCardinality is 0.\n";
    }
    else{
        int count = 1;
        for(int i =1 ; i < n; i++){
            int j = 0 ;
            for(j = 0 ; j < i ; j ++){
                if(A[i] == A[j]){ break; }
            }
            if(i == j){ count ++; }
        }
        cout <<" \n Cardinality of the set is: " << count << endl;
    }

    int element = 0;
    ismember(element,A,n);
    power_set(A,n);

    delete []A;

    return 0;
}