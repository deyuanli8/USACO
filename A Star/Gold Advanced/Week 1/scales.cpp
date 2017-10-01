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


int arr[50];
int N,C;
int high=0;
void nextAdd(pii curP){
    int first=curP.F;
    int sec=curP.S;
    int X=C-sec;
    if(first==-1) high=max(high,sec);
    else if(first==0){
        int lastAdd;
        sec+arr[0]<=C ? lastAdd=sec+arr[0]: lastAdd=sec;
        high=max(high, lastAdd);
    }
    else if(arr[first]+arr[first-1] <= X){
        nextAdd(MP(first-1, sec+arr[first]));
    }
    else if(arr[first]<=X){
        nextAdd(MP(first-1,sec+arr[first]));
        nextAdd(MP(first-2, sec+arr[first-1]));
    }
    else{
        nextAdd(MP(first-1, sec));
    }

};

int main()
{
    cin>>N>>C;
    int curW;
    F0R(i,N){
        cin>>curW;
        arr[i]=curW;
    }
    nextAdd(MP(N-1,0));
    cout << high << endl;
}
