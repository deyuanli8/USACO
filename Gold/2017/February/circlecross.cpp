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

#define maxN 50000
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;

int n;
pii len[maxN];
template<int size> struct BIT {
	int tree[size + 1];
	BIT() {
		for (int i = 0; i<size + 1; i++) tree[i] = 0;
	}

	void add(int k, int x) {
		k++;
		while (k <= size) {
			tree[k] += x;
			k += k & -k;
		}
	}
	int sum(int k) {
		k++;
		int s = 0;
		while (k >= 1) {
			s += tree[k];
			k -= k & -k;
		}
		return s;
	}
	int sum(int l, int r) {
		return sum(r) - sum(l - 1);
	}
};
bool comp(pii a, pii b) {
	return (a.S - a.F) < (b.second - b.F);
}
int main() {
	FAST
	ofstream cout("circlecross.out");
	ifstream cin("circlecross.in");
	cin >> n;
	BIT<2 * maxN> bi = BIT<2 * maxN>();
	for (int i = 0; i < n; i++) {
		len[i] = MP(-1,-1);
	}
	int next;
	for (int i = 0; i < 2*n; i++) {
		cin >> next;
		next--;
		bi.add(i, 1);
		if (len[next].first==-1) {
			len[next] = MP(i,-1);
		}
		else {
			len[next] = MP(len[next].first,i);
		}
	}
	sort(len, len + n, comp);
	int counter = 0;
	for (int i = 0; i < n; i++) {
		int fir = len[i].first;
		int sec = len[i].second;
		bi.add(fir, -1);
		bi.add(sec, -1);
		counter += bi.sum(fir, sec);
	}
	cout << counter << endl;
	return 0;
}
