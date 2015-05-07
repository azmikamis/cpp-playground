#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

set< pair<int, int> > pawn_moves (int a, int b)
{
    set< pair<int,int> > pset;
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
    int moves[8][2]={{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}};
    for (int i=0; i<2; i++)
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
    set< pair<int,int> > qset = bishop_moves(a,b);
    set< pair<int,int> > rset = rook_moves(a,b);
    qset.insert(rset.begin(), rset.end()); 
    return qset;
}

set< pair<int, int> > king_moves (int a, int b)
{
    set< pair<int,int> > kset;
    int moves[8][2]={{1,-1},{1,0},{1,1},{0,-1},{0,1},{-1,-1},{-1,0},{-1,1}};
    for (int i=0; i<2; i++)
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
    set< pair<int,int> > myset2 = queen_moves(1,2);
    set< pair<int,int> >::iterator it2;

    //for (int i=0; i<=5; i++) myset2.insert(make_pair(1,i*10));
    //for (int i=0; i<=5; i++) myset2.insert(make_pair(1,i*10));


    for (it2=myset2.begin(); it2!=myset2.end(); ++it2)
        cout << '(' << it2->first << ' ' << it2->second << ')' << '\n';

    cout << '\n';
    return 0;
}
