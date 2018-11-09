template<int SZ> struct Trie { //not tested well
	int trie[SZ][26];
	bool mark[SZ][26];
	int idx;
	Trie() {
		FOR(i, SZ) {
			FOR(j, 26) {
				trie[i][j] = -1;
				mark[i][j] = false;
			}
		}
		idx = 1;
	}
	void insert(string s) {
		int cur = 0;
		FOR(i, s.length()) {
			int v = s[i] - 'a';
			if (trie[cur][v] == -1) trie[cur][v] = idx++;
			if (i == s.length() - 1) mark[cur][v] = 1;
			cur = trie[cur][v];
		}
	}
	bool find(string s) {
		int cur = 0;
		FOR(i, s.length()) {
			int v = s[i] - 'a';
			if (trie[cur][v] == -1) return false;
			if (i == s.length() - 1) return mark[cur][v];
			cur = trie[cur][v];
		}
	}
};
