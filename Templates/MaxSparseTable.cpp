template<int sz> struct Sparse {
	int lookup[sz][31 - __builtin_clz(sz)]; //contains index of maximum in the range [i,i+2^j-1]
	int* arr;
	Sparse(int* a) {
		arr = a;
		int power = 1;
		for (int i = 0; i <= 31 - __builtin_clz(sz); i++) {
			power *= 2;
			for (int j = 0; j < sz; j++) {
				if (i == 0) {
					lookup[j][0] = j;
					continue;
				}
				if (j + power / 2 - 1 >= sz) break;
				if (arr[lookup[j][i - 1]] >= arr[lookup[j + power / 4][i - 1]]) {
					lookup[j][i] = lookup[j][i - 1];
				}
				else {
					lookup[j][i] = lookup[j + power / 4][i - 1];
				}
			}
		}
	}

	int indexMax(int a, int b) {
		if ((b - a) == 0) return a;
		int k = 31 - __builtin_clz(b - a + 1);
		int j = (int)(pow(2, k));
		if (arr[lookup[a][k]] >= arr[lookup[b - j + 1][k]]) {
			return lookup[a][k];
		}
		return lookup[b - j + 1][k];
	}
	int getMax(int a, int b) {
		return arr[indexMax(a, b)];
	}
};
