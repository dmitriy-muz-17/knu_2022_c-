#include <iostream>
#include <vector>

using namespace std;

void output(vector<vector <int>> matrix, int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            cout<< matrix[i][j] << " ";
        cout<< '\n';
    }    
}
int main()
{
    int n;
    vector<vector <int>> matrix;

    cout<< "Input n: ";
    cin>>n;
    matrix.resize(n);
    for(int i=0; i<n; i++)
        matrix[i].resize(n);
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin>>matrix[i][j]; 
    cout<<'\n';
   
    for(int i=0; i<n; i++)
    { 
        int mult = 1;
        for(int j=0; j<i+1 ; j++)
            mult *= matrix[n-i-j-1][j];
        cout<<mult<<' ';
    }
    for(int i=0; i<n-1; i++)
    {
        int mult = 1;
        for(int j=i+1; j<n; j++)
            mult *= matrix[i+j-1][j];
        cout<< mult <<' ';

    }
    cout<<'\n';
    output(matrix, n);
    return 0;
}