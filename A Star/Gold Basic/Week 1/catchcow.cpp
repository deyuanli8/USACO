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

int n,k;
queue<pii> que;

void add(pii p, bool arr[])
{
    if (p.F==k){
        cout << p.S <<"\n";
        exit(0);
    }
    else{
        if (arr[p.F]==false){
            que.push(p);
            arr[p.F]=true;
        }
    }
};

int main()
{
    cin >> n >> k;
    if (n==k) {
        cout<<0<<"\n";
        return 0;
    }
    int sizeArr=2*(k-1);
    bool arr[maxN]={false}; //maybe use sizeArr
    pii firP(n,0);
    que.push(firP);
    while (true){
        pii curP=que.front();
        int fir=curP.F;
        int sec=curP.S;
        if(fir < k){
            add(MP(fir+1,sec+1), arr);
            if (fir>=1)
                add(MP(fir-1,sec+1), arr);
            add(MP(2*fir,sec+1), arr);
            que.pop();
        }
        else{
            add(MP(fir-1,sec+1), arr);
            que.pop();
        }
    }
    return 0;
}

