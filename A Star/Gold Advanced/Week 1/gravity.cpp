#include <bits/stdc++.h>

#define SQ(a) (a)*(a)

#define F0R(i, a) for(int i = 0; i < (a); i++)
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define R0F(i, a) for(int i = (a) - 1; i >= 0; i--)
#define ROF(i, a, b) for(int i = (b) - 1; i >= (a); i--)

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define UB upper_bound
#define LB lower_bound
#define maxN 500

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int arrT[maxN][maxN];
int arrF[maxN][maxN];
bool mapArr[maxN][maxN];
int N,M;
pii D;
pii C;
deque<tuple<int,int,bool>> que;

void gravity(pii curP, bool curB, pii origP, bool didFlip)
{
    int newFir=-1;
    int newSec=curP.S;
    if(curB)
    {
        FOR(i, curP.F, N)
        {
            if(MP(i,curP.S)==D){
                cout << (didFlip ? arrF[origP.F][origP.S]+1 : arrT[origP.F][origP.S]) <<"\n";
                exit(0);
            }
            if(!(mapArr[i][curP.S]))
            {
                newFir=i-1;
                break;
            }
        }
        if(newFir!=-1 && arrT[newFir][newSec]==-1)
        {
            if(didFlip)
            {
                arrT[newFir][newSec]=arrF[origP.F][origP.S]+1;
                que.PB(MT(newFir, newSec, true));
            }
            else
            {
                arrT[newFir][newSec]=arrT[origP.F][origP.S];
                que.push_front(MT(newFir, newSec, true));
            }
        }
    }
    else
    {
        R0F(i, curP.F+1)
        {
            if(MP(i,curP.S)==D){
                cout << (didFlip ? arrT[origP.F][origP.S]+1 : arrF[origP.F][origP.S]) <<"\n";
                exit(0);
            }
            if(!mapArr[i][curP.S])
            {
                newFir=i+1;
                break;
            }
        }
        if(newFir!=-1 && arrF[newFir][newSec]==-1)
        {
            if(didFlip)
            {
                arrF[newFir][newSec]=arrT[origP.F][origP.S]+1;
                que.PB(MT(newFir, newSec, false));
            }
            else
            {
                arrF[newFir][newSec]=arrF[origP.F][origP.S];
                que.push_front(MT(newFir, newSec, false));
            }
        }
    }
};
int main()
{
    cin >> N >>M;
    F0R(i,N)
    {
        F0R(j, M)
        {
            char curChar;
            cin >> curChar;
            mapArr[i][j]= (curChar == '#' ? false : true);
            if(curChar=='C')
            {
                C=MP(i,j);
            }
            if(curChar=='D')
            {
                D=MP(i,j);
            }
            arrT[i][j]=-1;
            arrF[i][j]=-1;
        }
    }
    bool fall=true;
    FOR(i, C.F,N){
        if(mapArr[i][C.S]==false){
            arrT[i-1][C.S]=0;
            que.push_back(MT(i-1,C.S,true));
            fall=false;
            break;
        }
    }
    if(fall){
        cout<<-1<<"\n";
        return 0;
    }
    while (true)
    {
        if(que.empty())
        {
            cout << -1 << "\n";
            return 0;
        }
        tuple<int,int,bool> curT=que.front();
        int fir=get<0>(curT);
        int sec=get<1>(curT);
        if(MP(fir,sec)==D)
        {
            if(get<2>(curT))
                cout << arrT[fir][sec] << "\n";
            else
                cout << arrF[fir][sec] << "\n";
            return 0;
        }
        que.pop_front();
        bool curB=get<2>(curT);
        gravity(MP(fir,sec), !curB, MP(fir,sec), true);
        if(sec+1 < M && mapArr[fir][sec+1])
        {
            gravity(MP(fir,sec+1), curB, MP(fir,sec), false);
        }
        if(sec-1 >=0 && mapArr[fir][sec-1])
        {
            gravity(MP(fir,sec-1), curB, MP(fir,sec),false);
        }
    }
    return 0;
}
