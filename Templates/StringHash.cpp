template<int SZ> struct StringHash {
	const ll mods[3] = { 1000000007, 999119999, 1000992299 };
	ll p[3][SZ];
	ll h[3][SZ];
	const ll base[3] = { 1000696969, 972663749, 911382323 };
	StringHash() {}
	void build(string a) {
		FOR(i, 3) {
			p[i][0] = 1;
			h[i][0] = (int)a[0];
			F0R(j, 1, (int)a.length()) {
				p[i][j] = (p[i][j - 1] * mods[i]) % base[i];
				h[i][j] = (h[i][j - 1] * mods[i] + (int)a[j]) % base[i];
			}
		}
	}
	tuple<ll, ll, ll> hsh(int a, int b) { // [a,b]
		if (a == 0) return MT(h[0][b], h[1][b], h[2][b]);
		tuple<ll, ll, ll> ans;
		get<0>(ans) = (((h[0][b] - (h[0][a - 1] * p[0][b - a + 1]) % base[0]) % base[0]) + base[0]) % base[0];
		get<1>(ans) = (((h[1][b] - (h[1][a - 1] * p[1][b - a + 1]) % base[1]) % base[1]) + base[1]) % base[1];
		get<2>(ans) = (((h[2][b] - (h[2][a - 1] * p[2][b - a + 1]) % base[2]) % base[2]) + base[2]) % base[2];
		return ans;
	}
};
