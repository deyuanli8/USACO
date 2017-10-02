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
#define maxN 10000
#define width 30000

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;


int arr[maxN][3];
queue<int> que;
int h,f;
bool dist(int i, int j)
{
    int xi=arr[i][0];
    int yi=arr[i][1];
    int xj=arr[j][0];
    int yj=arr[j][1];
    bool curB=(xi-xj)*(xi-xj)+(yi-yj)*(yi-yj) <= 1000000 ? true : false;
    return curB;
};
int main()
{
    cin >> h >> f;
    F0R(i,f)
    {
        int x,y;
        cin>>x>>y;
        arr[i][0]=x;
        arr[i][1]=y;
        if(y<=1000)
        {
            que.push(i);
            arr[i][2]=1;
            continue;
        }
        arr[i][2]=-1;
    }
    while (true)
    {
        int curHoof=que.front();
        que.pop();
        if(arr[curHoof][1]>=h-1000)
        {
            cout << arr[curHoof][2]<<"\n";
            return 0;
        }
        F0R(i,f)
        {
            if(arr[i][2]==-1 && dist(i,curHoof))
            {
                arr[i][2]=arr[curHoof][2]+1;
                que.push(i);
            }
        }
    }
    return 0;
}
