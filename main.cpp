#include<bits/stdc++.h>
using namespace std;

int n, istart, jstart, icomoara,jcomoara;
bool isValid(int a[5][5], int x, int y)
{

    if (x < 0 || y < 0 || x >= n || y >= n)
    {
        return false;
    }
    if (a[x][y] == 0)
        return true;
    return false;
}



void fill(int a[5][5], int xstart, int ystart)
{

    a[xstart][ystart] = 5;

    int dl[] = { -1, 0, 1, 0};
    int dc[] = { 0, 1, 0, -1};

    queue<int> X, Y;

    X.push(xstart);
    Y.push(ystart);

    int xx, yy;
    while (!X.empty())
    {
        xstart = X.front();
        ystart = Y.front();
        for (int i = 0; i < 4; i++)
        {
            xx = xstart + dl[i];
            yy = ystart + dc[i];
            if (isValid(a,xx,yy))
            {
                X.push(xx);
                Y.push(yy);
                a[xx][yy] = 5;
            }

        }

        X.pop();
        Y.pop();
    }

}

int main()
{
    int a[5][5];
    cin >> n;
    cin>>istart>>jstart;
    cin>>icomoara>>jcomoara;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == 1)
            {
                fill(a,istart,jstart);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}
if(a[icomoara][jcomoara]==a[istart][jstart])
{
    cout<<"Exista o ruta pana la comoara";
    if(a[icomoara][jcomoara]!=a[istart][jstart])
        cout<<"NU EXISTA";
    return 0;
}
