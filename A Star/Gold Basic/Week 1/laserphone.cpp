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
#define maxN 200000

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int w,h;
queue<pii> que;

int main()
{
    for(int i=5; i<4; i++) cout<<"Hello World"<<endl;
    cin >> w >> h;
    char arr[h][w];
    int charCount[h][w];
    pii p1;
    pii p2;
    bool p1T=true;
    F0R(i, h)
    {

        string s;
        cin >> s;
        F0R(j, w)
        {
            charCount[i][j]=-1;
            arr[i][j]=s[j];
            if(s[j]=='C' && p1T)
            {
                p1=MP(i,j);
                p1T=false;
            }
            else if(s[j]=='C')
            {
                p2=MP(i,j);
            }
        }
    }
    que.push(p1);
    charCount[p1.F][p1.S]=0;
    while (true)
    {
        pii p=que.front();
        que.pop();
        int fir=p.F;
        int sec=p.S;
        int count=charCount[fir][sec];
        FOR(i, fir+1, h)
        {
            if(arr[i][sec]=='C' && charCount[i][sec]==-1)
            {
                cout<<count<<"\n";
                return 0;
            }
            if(arr[i][sec]=='*')
            {
                break;
            }
            if(charCount[i][sec]==-1)
            {
                charCount[i][sec]=count+1;
                que.push(MP(i,sec));
            }
        }
        R0F(i, fir)
        {
            if(arr[i][sec]=='C' && charCount[i][sec]==-1)
            {
                cout<<count<<"\n";
                return 0;
            }
            if(arr[i][sec]=='*')
            {
                break;
            }
            if(charCount[i][sec]==-1)
            {
                charCount[i][sec]=count+1;
                que.push(MP(i,sec));
            }
        }
        FOR(i, sec+1, w)
        {
            if(arr[fir][i]=='C' && charCount[fir][i]==-1)
            {
                cout<<count<<"\n";
                return 0;
            }
            if(arr[fir][i]=='*')
            {
                break;
            }
            if(charCount[fir][i]==-1)
            {
                charCount[fir][i]=count+1;
                que.push(MP(fir,i));
            }
        }
        R0F(i,sec)
        {
            if(arr[fir][i]=='C' && charCount[fir][i]==-1)
            {
                cout<<count<<"\n";
                return 0;
            }
            if(arr[fir][i]=='*')
            {
                break;
            }
            if(charCount[fir][i]==-1)
            {
                charCount[fir][i]=count+1;
                que.push(MP(fir,i));
            }
        }
    }
    return 0;
}
