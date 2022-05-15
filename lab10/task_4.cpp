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
        cout<< matrix[i][i] << " ";
    cout<<'\n';

    for(int i=n-1; i>=0; i--)
        for(int j=0; j<n; j++)
            if(i+j == n - 1)
                cout<< matrix[i][j]<< " ";
    cout<<'\n'<<'\n';

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(i<=j && i>=n-1-j)
                matrix[i][j] = 0;
    
    output(matrix, n);
    return 0;
}