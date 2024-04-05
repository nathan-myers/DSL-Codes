// This code runs properly

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, i, j, k, min, row, col, mincost = 0;
    char ch;
    cout << "Enter no of vertices: ";
    cin >> n;

    vector<vector<int>> cost(n, vector<int>(n, -1));
    vector<int> visit(n, 0);

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            cout << "Do you want to store weight between " << i << " and " << j << " ? (Y/N)";
            cin >> ch;
            if (ch == 'Y' || ch == 'y') {
                cout << "Enter the weight: ";
                cin >> cost[i][j];
                cost[j][i] = cost[i][j];
            }
        }
    }

    visit[0] = 1;

    for (k = 0; k < n - 1; k++) {
        min = 999;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (visit[i] == 1 && visit[j] == 0) {
                    if (cost[i][j] != -1 && min > cost[i][j]) {
                        min = cost[i][j];
                        row = i;
                        col = j;
                    }
                }
            }
        }

        mincost += min;
        visit[col] = 1;
        cost[row][col] = cost[col][row] = -1;
        cout << row << "->" << col << endl;
    }

    cout << "The minimum cost is: " << mincost;
    return 0;
}















/*

This code is giving segmentation fault. 

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, i, j, k, min, row, col, mincost = 0;
    char ch;
    cout << "Enter no of vertices: ";
    cin >> n;
    
    int cost[n][n];
    int visit[n];

    
    // Initially cost matrix is '-1'
    for(i=0; i<=n; i++)
    {
        for(j=i; j<=n; j++)
        {
            cost[i][j] = cost[j][i] = -1;
        }
    }
    
    
    // Initially visit matrix is '0'
    for(i=0; i<=n; i++)
    {
        visit[i] = 0;
    }

    for(i=0; i<n; i++)
    {
        for(j=i+1; j<n; j++)
        {
            cout << "Do you want to store weight between " << i << " and " << j << " ? (Y/N)";
            cin >> ch;
            if(ch == 'Y' || ch == 'y')
            {
                cout << "Enter the weight: ";
                cin >> cost[i][j];
                cost[i][j] = cost[j][i];
            }

            // else
            // {
            //     continue;
            // }

        }
    }

    visit[0] = 1;

    for(k=0; k < n-1; k++)
    {
        min = 999;
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                if(visit[i]==1 && visit[j]==0)
                {
                    if(cost[i][j] != -1 && min > cost[i][j])
                    {
                        min = cost[i][j];
                        row = i;
                        col = j;
                    }
                }
            }
        }

        mincost += min; 
        visit[col] = 1;
        cost[row][col] = cost[col][row] = -1;
        cout << row << "->" << col << endl;
    }

    cout << "The minimum cost is: " << mincost;
    return 0;   
}

*/
