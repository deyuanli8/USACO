#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <functional>
#include <queue>
#include <set>
#include <vector>
#include <stack>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <assert.h>

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define SQ(a) (a)*(a)

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define ROF(i,a,b) for (int i = (b)-1; i >= a; i--)
#define R0F(i,a) for (int i = (a)-1; i >= 0; i--)
#define endl "\n"
#define FAST ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

#define maxN 500
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;

int n, m;
string sp[maxN];
string nsp[maxN];
vi arr[maxN][maxN];
priority_queue<pair<int,pii>> pq;
int main() {
	FAST
	ofstream cout("cownomics.out");
	ifstream cin("cownomics.in");
	cin >> n >> m;
	string next;
	for (int i = 0; i < n; i++) {
		cin >> next;
		sp[i] = next;
	}
	for (int i = 0; i < n; i++) {
		cin >> next;
		nsp[i] = next;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = m-1; k >=0; k--) {
				if (sp[i][k] != nsp[j][k]) {
					arr[i][j].PB(k);
				}
			}
		}
	}
	int b=-1, a=-1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (b == -1 || arr[i][j].back() > b) {
				b= arr[i][j].back();
			}
			if (a == -1 || arr[i][j].back() < a) {
				a = arr[i][j].back();
			}
			pq.push(MP(-arr[i][j].back(), MP(i,j)));
		}
	}
	int counter = -1;
	while (b < m) {
		if (counter == -1 || b - a + 1 < counter) {
			counter = b - a + 1;
		}
		do {
			auto whatNext = pq.top();
			arr[whatNext.S.F][whatNext.S.S].pop_back();
			if (arr[whatNext.S.F][whatNext.S.S].size() == 0) {
				goto here;
			}
			pq.pop();
			b = max(b, arr[whatNext.S.F][whatNext.S.S].back());
			pq.push(MP(-arr[whatNext.S.F][whatNext.S.S].back(), MP(whatNext.S.F, whatNext.S.S)));
		} while (a == -pq.top().F);
		a = -pq.top().F;
	}
	here:
	cout << counter << endl;
	return 0;
}
