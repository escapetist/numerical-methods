#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    cout<<"Enter unknowns"<<endl;
    int n;
    cin>>n;
    float x[25][26],ans[25];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n+1 ;j++)
        {
            cout<<"Enter a"<<i+1<<j+1<<":";
            cin>>x[i][j];
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n+1 ;j++)
        {
            cout<<x[i][j]<<"\t";
        }
        cout<<"\n";
    }
    for(int i = 0; i < n; i++)
    {   
        for(int j = 0; i < n ; j++)
            {
                float t = x[i][j]/x[i][i];
                if(i>j)
                {
                    for(int k = 0; k < n + 1 ; k++)
                        x[k][j] = x[k][j] - t*x[k][k];
                }
            }
    }
    ans[n-1] =  x[n][n]; 
    for(int k = n-1; k>=0;k--)
    {
        for(int l = n-1; l>=0; l--)
        {
            if(l>k)
                ans[k] -= x[k][l]*x[l][l];
        }
        ans[k]/=x[k][k];
    }
    for(int i = 0;i<n;i++)
        cout<<"The answer matrix is"<<ans[i]<<endl;
    cin>>n;
    return 0;
}