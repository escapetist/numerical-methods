#include<iostream>
#include<cmath>

using namespace std;

int main()
{
    cout<<"Enter unknowns";
    int n;
    cin>>n;
    float x[25][26],ans[25];
    cout<<"Enter matrix"<<endl;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n+1 ;j++)
        {
            cin>>x[i][j];
        }
    }
    for(int i = 0; i < n; i++)
    {   
        for(int j = 0; j < n+1 ; j++)
            {
                if((i==j)&&fabs(x[i][j])<0.005)
                {
                    cout<<"Pivot zero";
                    exit(1);
                }
                float t = x[j][i]/x[i][i];
                if(i!=j && x[j][i]!=0)
                    for(int k = 0; k < n + 1 ; k++)
                        x[j][k] = x[j][k] - t * x[i][k];
                   /* for(int i = 0; i<n;i++)
                    {
                        for(int j = 0; j<n+1;j++)
                            cout<<x[i][j]<<"\t";
                        cout<<endl;
                    } 
                    cout<<endl;*/
            }
    }
    cout<<"The answer matrix is"<<endl;
    for(int k = 0; k<n;k++)
    {
        ans[k] = x[k][n]/x[k][k];
        cout<<ans[k]<<endl;
    }
    return 0;
}