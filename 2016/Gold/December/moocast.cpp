#include <iostream>
#include <fstream>
//#include <string>
//#include <cmath>
#include <vector>
//#include <iomanip>
#include <algorithm>
//#include <functional>
//#include <queue>
//#include <set>
#include <vector>
//#include <stack>
//#include <map>
#include <unordered_set>
//#include <unordered_map>
//#include <assert.h>

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define SQ(a) (a)*(a)

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define ROF(i,a,b) for (int i = (b)-1; i >= a; i--)
#define R0F(i,a) for (int i = (a)-1; i >= 0; i--)
#define endl "\n"
#define FAST ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

#define maxN 1000
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;


int n;
pii arr[maxN];
//int dist[maxN][maxN];
vector<pii> order[maxN];
//int distanceA[maxN];
unordered_set<int> added;
//priority_queue <pair<int, int>> q;
bool comp(pii a, pii b) {
	return a > b;
}
int main() {
	FAST
	ofstream cout("moocast.out");
	ifstream cin("moocast.in");
	cin >> n;
	int x, y;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		arr[i] = MP(x, y);
	}
	int distance;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			distance = (int)(pow((arr[i].first - arr[j].first), 2) + pow(arr[i].second - arr[j].second, 2));
			order[i].PB(MP(distance,j));
		}
	}
	for (int i = 0; i < n; i++) {
		sort(order[i].begin(), order[i].end(), comp);
	}
	added.insert(0);
	int curMax = 0;
	while ((int)added.size() < n) {
		int localMin = -1;
		int whatAdd = -1;
		int whereFrom = -1;
		for (int i : added) {
			while (order[i].size() > 0 && added.count(order[i][order[i].size() - 1].S) == 1) {
				order[i].pop_back();
			}
			if (order[i].size()>0 && added.count(order[i][order[i].size() - 1].S) == 0) {
				if (localMin == -1 || order[i][order[i].size() - 1].F < localMin) {
					localMin = order[i][order[i].size() - 1].F;
					whatAdd = order[i][order[i].size() - 1].S;
					whereFrom = i;
				}
			}
		}
		added.insert(whatAdd);
		order[whereFrom].pop_back();
		if (localMin > curMax) curMax = localMin;
	}
	cout << curMax << endl;
	return 0;
}
/*
for (int i = 0; i < n; i++) {
processed[i] = false;
}
for (int i = 1; i < n; i++) distanceA[i] = -1;
distanceA[0] = 0;
q.push({ 0,0 });
while (!q.empty()) {
int a = q.top().second; q.pop();
if (processed[a]) continue;
processed[a] = true;
for (int i = 0; i < n; i++) {
int w = dist[a][i];
if (distanceA[a] + w < distanceA[i] || distanceA[i]==-1) {
distanceA[i] = distanceA[a] + w;
q.push({ -distanceA[i],i });
}
}
}*/
