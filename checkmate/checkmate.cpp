#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

set< pair<int, int> > pawn_moves (int a, int b)
{
    set< pair<int,int> > pset;
    pset.insert(make_pair(a,b));
    int moves[2][2]={{1,-1},{1,1}};
    for (int i=0; i<2; i++)
    {
        if (a+moves[i][0]>0 && a+moves[i][0]<9 && b+moves[i][1]>0 && b+moves[i][1]<9) 
        {
            pset.insert(make_pair(a+moves[i][0], b+moves[i][1]));
        }
    }
    return pset;
}

set< pair<int, int> > bishop_moves (int a, int b)
{
    set< pair<int,int> > bset;
    int i;
    int j;
    i = a;
    j = b;
    bset.insert(make_pair(a,b));
    while (i>0 && i<9 || j>0 && j<9)
    {
        i-=1;
        j-=1;
        if (i>0 && i<9 && j>0 && j<9)
            bset.insert(make_pair(i,j));
    }
    i = a;
    j = b;
    while (i>0 && i<9 || j>0 && j<9)
    {
        i+=1;
        j+=1;
        if (i>0 && i<9 && j>0 && j<9)
            bset.insert(make_pair(i,j));
    }
    i = a;
    j = b;
    while (i>0 && i<9 || j>0 && j<9)
    {
        i-=1;
        j+=1;
        if (i>0 && i<9 && j>0 && j<9)
            bset.insert(make_pair(i,j));
    }
    i = a;
    j = b;
    while (i>0 && i<9 || j>0 && j<9)
    {
        i+=1;
        j-=1;
        if (i>0 && i<9 && j>0 && j<9)
            bset.insert(make_pair(i,j));
    }
    return bset;
}

set< pair<int, int> > knight_moves (int a, int b)
{
    set< pair<int,int> > nset;
    nset.insert(make_pair(a,b));
    int moves[8][2]={{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}};
    for (int i=0; i<8; i++)
    {
        if (a+moves[i][0]>0 && a+moves[i][0]<9 && b+moves[i][1]>0 && b+moves[i][1]<9) 
        {
            nset.insert(make_pair(a+moves[i][0], b+moves[i][1]));
        }
    }
    return nset;
}

set< pair<int, int> > rook_moves (int a, int b)
{
    set< pair<int,int> > rset;
    int i;
    int j;
    i = a;
    j = b;
    rset.insert(make_pair(a,b));
    while (i>1)
    {
        i-=1;
        rset.insert(make_pair(i,j));
    }
    i = a;
    while (i<8)
    {
        i+=1;
        rset.insert(make_pair(i,j));
    }
    i = a;
    j = b;
    while (j<8)
    {
        j+=1;
        rset.insert(make_pair(i,j));
    }
    j = b;
    while (j>1)
    {
        j-=1;
        rset.insert(make_pair(i,j));
    }
    return rset;
}

set< pair<int, int> > queen_moves (int a, int b)
{
    set< pair<int,int> > qset;
    qset.insert(make_pair(a,b));
    set< pair<int,int> > bset = bishop_moves(a,b);
    qset.insert(bset.begin(), bset.end()); 
    set< pair<int,int> > rset = rook_moves(a,b);
    qset.insert(rset.begin(), rset.end()); 
    return qset;
}

set< pair<int, int> > king_moves (int a, int b)
{
    set< pair<int,int> > kset;
    int moves[8][2]={{1,-1},{1,0},{1,1},{0,-1},{0,1},{-1,-1},{-1,0},{-1,1}};
    for (int i=0; i<8; i++)
    {
        if (a+moves[i][0]>0 && a+moves[i][0]<9 && b+moves[i][1]>0 && b+moves[i][1]<9) 
        {
            kset.insert(make_pair(a+moves[i][0], b+moves[i][1]));
        }
    }
    return kset;
}

int main()
{
    int t;
    cin >> t;
    for (int i=0; i<t; i++)
    {
        set< pair<int,int> > mymoves;
        set< pair<int,int> > oppmoves;
        int n;
        cin >> n;
        for (int j=0; j<n; j++)
        {
            char ca;
            char cb;
            char cc;
            cin >> ca >> cb >> cc;

            int ia;
            int ib;
            ia = (int)ca - '0';
            ib = (int)cb - 'A' + 1;
            switch(cc)
            {
                case 'K':
                    {
                        set< pair<int,int> > kmoves = king_moves(ia,ib);
                        mymoves.insert(kmoves.begin(), kmoves.end());
                    }
                    break;
                case 'P':
                    {
                        set< pair<int,int> > pmoves = pawn_moves(ia,ib);
                        oppmoves.insert(pmoves.begin(), pmoves.end());
                    }
                    break;
                case 'B':
                    {
                        set< pair<int,int> > bmoves = bishop_moves(ia,ib);
                        oppmoves.insert(bmoves.begin(), bmoves.end());
                    }
                    break;
                case 'N':
                    {
                        set< pair<int,int> > nmoves = knight_moves(ia,ib);
                        oppmoves.insert(nmoves.begin(), nmoves.end());
                    }
                    break;
                case 'R':
                    {
                        set< pair<int,int> > rmoves = rook_moves(ia,ib);
                        oppmoves.insert(rmoves.begin(), rmoves.end());
                    }
                    break;
                case 'Q':
                    {
                        set< pair<int,int> > qmoves = queen_moves(ia,ib);
                        oppmoves.insert(qmoves.begin(), qmoves.end());
                    }
                    break;
            }
        }
        bool checkmate = true;
        set< pair<int,int> >::iterator it;
        for (it=mymoves.begin(); it!=mymoves.end(); ++it)
        {
            if (oppmoves.count(*it)==0)
            {
                cout << it->first << ' ' << it->second << '\n';
                checkmate = false;
                break;
            }
        }
        if (checkmate)
            cout << "CHECKMATE" << '\n';
        else
            cout << "YES" << '\n';

    }
    return 0;
}
