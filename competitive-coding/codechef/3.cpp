#include<bits/stdc++.h>
using namespace std;

int main()
{
        char a[8][8];
        int f[8][8]={0};
        int i,j,bx,by,qx,qy,px,py,sx,sy,rx,ry,flag=0;
        for(i=0; i<8; i++)
        {
                for(j=0; j<8; j++)
                {
                        cin >> a[i][j];
                        if(a[i][j] == 'B')
                        {
                                bx=i;
                                by=j;
                        }
                        else if(a[i][j] == 'P')
                        {
                                px=i;
                                py=j;
                        }
                        else if(a[i][j] == 'Q')
                        {
                                qx=i;
                                qy=j;
                        }
                        else if(a[i][j] == 'R')
                        {
                                rx=i;
                                ry=j;
                        }
                        else if(a[i][j] == 'S')
                        {
                                sx=i;
                                sy=j;
                        }
                }
        }

        for(i=0; i<8; i++)
        {
                a[rx][i] = a[i][ry] = 'x';
                f[rx][i]++;
                f[i][ry]++;
        }
        a[rx][ry] = 'R';

        for(i=sx-1; i<sx+2; i++)
        for(j=sy-1; j<sy+2; j++)
        if((i>=0 && i<8) && (j>=0 && j<8))
        {
                a[i][j] = 'x';
                f[i][j]++;
        }
        a[sx][sy] = 'S';

        i=bx;
        j=by;
        while(i>=0 && j>=0)
        {
                f[i][j]++;
                a[i--][j--] = 'x';

        }
        i=bx;
        j=by;
        while(i<=7 && j>=0)
        {
                f[i][j]++;
                a[i++][j--] = 'x';
        }
        i=bx;
        j=by;
        while(i<=7 && j<=7)
        {
                f[i][j]++;
                a[i++][j++] = 'x';
        }
        i=bx;
        j=by;
        while(i>=0 && j<=7)
        {
                f[i][j]++;
                a[i--][j++] = 'x';
        }

        a[bx][by] = 'B';

        for(i=0; i<8; i++)
        a[qx][i] = a[i][qy] = 'x';

        i=qx;
        j=qy;
        while(i>=0 && j>=0)
        {
                f[i][j]++;
                a[i--][j--] = 'x';
        }
        i=qx;
        j=qy;
        while(i<=7 && j>=0)
        {
                f[i][j]++;
                a[i++][j--] = 'x';
        }
        i=qx;
        j=qy;
        while(i<=7 && j<=7)
        {
                f[i][j]++;
                a[i++][j++] = 'x';
        }
        i=qx;
        j=qy;
        while(i>=0 && j<=7)
        {
                f[i][j]++;
                a[i--][j++] = 'x';
        }
        a[qx][qy] = 'Q';
        a[px][py] = 'P';


        for(i=px-1; i<px+2; i++)
        {
                for(j=py-1; j<py+2; j++)
                {
                        if((i>=0 && i<8) && (j>=0 && j<8))
                        {
                                if(a[i][j]=='_')
                                {
                                        cout << "NOT YET!";
                                        flag=1;
                                        break;
                                }
                                else if((a[i][j] == 'B' || a[i][j] == 'R' || a[i][j] == 'Q' || a[i][j] == 'S') && f[i][j]<2)
                                {
                                        cout << "NOT YET!";
                                        flag=1;
                                        break;
                                }
                        }
                }
                if(flag==1)
                break;
        }
        if(flag==0)
        cout << "CHECKMATE!";



        /*for(i=0; i<8; i++)
        {
                for(j=0; j<8; j++)
                cout << a[i][j];
                cout << endl << endl;
        }
        for(i=0; i<8; i++)
        {
                for(j=0; j<8; j++)
                cout << f[i][j];
                cout << endl << endl;
        }*/
        return 0;
}
