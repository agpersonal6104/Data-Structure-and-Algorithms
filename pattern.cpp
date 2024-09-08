#include <iostream>
using namespace std;

void pattern1(int n)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

void pattern2(int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            cout<<" ";
        }
        for(int j=0;j<(2*i+1);j++)
        {
            cout<<"*";
        }
        for(int j=0;j<n-i-1;j++)
        {
            cout<<" ";
        }
        cout << endl;
    }
}

void pattern3(int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            cout<< " ";
        }
        for(int j=0;j<(2*n-(2*i+1));j++)
        {
            cout << "*";
        }
        for(int j=0;j<i;j++)
        {
            cout << " ";
        }
        cout << endl;
    }
}

void pattern4(int n)
{
    pattern2(n);
    pattern3(n);
}

void pattern5(int n)
{
    for(int i=1; i<=(2*n-1); i++)
    {
        int stars=i;
        if(i > n) stars=2*n-i;
        for(int j=1;j<=stars;j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

void pattern6(int n)
{
    for (int i=0; i<n; i++)
    {
        int start=1;
        if(i%2==0) start=1;
        else start=0;
        for(int j=0;j<=i;j++)
        {
            cout << start << " ";
            start =1-start;
        }
        cout << endl;
    }
    
}

int main()
{
    int m;
    cin >> m;
    while(m!=0)
    {
        int n;
        cin >> n;
        pattern6(n);
        m--;
    }
    return 0;
}
// is this in github