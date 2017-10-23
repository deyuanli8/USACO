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

int arr[SQ(251)];
int n,m;
int main() {
	ofstream fout ("ariprog.out");
    ifstream fin ("ariprog.in");
    fin >> n >> m;
    F0R(i, m+1){
    	F0R(j,m+1){
    		arr[i*(m+1)+j]=SQ(i)+SQ(j);
    	}
    }
    
	return 0;
}
