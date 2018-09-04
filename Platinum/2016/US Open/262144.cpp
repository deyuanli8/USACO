#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define SQ(a) (a)*(a)

#define F0R(i, a, b) for (int i=(a); i<(b); i++)
#define FOR(i, a) for (int i=0; i<(a); i++)
#define F0Rd(i,a,b) for (int i = (b)-1; i >= (a); i--)
#define FORd(i,a) for (int i = (a)-1; i >= 0; i--)

#define FAST ios::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vp;

int n;
int arr[262144];
vi st[2][262144];
vi en[2][262144];
int curHigh=-1;
int main() { 
    FAST
    freopen("262144.in", "r", stdin);
    freopen("262144.out", "w", stdout);
	cin>>n;
	FOR(i,n){
		int x;
		cin>>x;
		arr[i]=x;
		if(x==1){
			st[1][i].PB(i);
			en[1][i].PB(i);
		}
		curHigh=max(curHigh,x);
	}
	bool bo = false;
	F0R(i,2,59){
		FOR(j,n){
				st[i%2][j].clear();
				en[i%2][j].clear();
		}
		bo=true;
		FOR(j,n-1){
			for(auto a : en[(i-1)%2][j]){
				for(auto b : st[(i-1)%2][j+1]){
					st[i%2][a].PB(b);
					en[i%2][b].PB(a);
					curHigh=max(curHigh,i);
					bo=false;
				}
			}
		}
		FOR(j,n){
			if(arr[j]==i){
					st[(i)%2][j].PB(j);
					en[(i)%2][j].PB(j);
					bo=false;
			}
		}
	}
	cout<<curHigh<<"\n";
    return 0;
}
