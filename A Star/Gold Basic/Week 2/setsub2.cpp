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
#define maxInt 2147483647

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

int m;
int arr[10];

int main()
{
    cin >> m;
    F0R(i,10)
    {
        if (i<m){
            int newInt;
            cin >>newInt;
            arr[i]=newInt;
            continue;
        }
        arr[i]=-1;
    }
    for(int curBit=1; curBit<(1<<m); curBit++){
        for (int i = 0; i < m; i++) {
            if (curBit&(1<<i)) cout << arr[i];
        }
        cout<<"\n";
    }
    return 0;
}
