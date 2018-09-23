struct Matrix {
	int rows, columns;
	ll **mat;

	Matrix() {
		rows = 0; columns = 0;
	}

	Matrix(int r, int c) {
		rows = r, columns = c;
		mat = new ll*[r];
		FOR(i, r) {
			mat[i] = new ll[c];
			memset(mat[i], 0, c * sizeof(ll));
		}
	}
	
	Matrix(int n) {
		*this = ident(n);
	}
	
	Matrix ident(int n) {
		Matrix m(n, n);
		FOR(i, n) m.mat[i][i] = 1;
		return m;
	}

	Matrix operator +(Matrix b) {
		if (b.rows != rows || b.columns != columns) return Matrix();
		Matrix m(rows, columns);
		FOR(r, rows) FOR(c, columns) m.mat[r][c] = (mat[r][c] + b.mat[r][c]) % MOD;
		return m;
	}

	Matrix operator -(Matrix b) {
		if (b.rows != rows || b.columns != columns) return Matrix();
		Matrix m(rows, columns);
		FOR(r, rows) FOR(c, columns) m.mat[r][c] = (mat[r][c] + MOD - b.mat[r][c]) % MOD;
		return m;
	}

	Matrix operator *(Matrix b) {
		if (columns != b.rows) return Matrix(0, 0);
		Matrix m(rows, b.columns);
		FOR(r, rows) {
			FOR(c, b.columns) {
				m.mat[r][c] = 0;
				FOR(i, columns) {
					m.mat[r][c] += mat[r][i] * b.mat[i][c] % MOD;
					m.mat[r][c] %= MOD;
				}
			}
		}
		return m;
	}

	Matrix operator ^(ll p) {
		if (columns != rows) return Matrix();
		if (p == 0) return ident(rows);
		if (p % 2 == 1) return ((*this ^ (p - 1)) * (*this));
		Matrix sq = (*this ^ (p >> 1));
		return (sq * sq);
	}

	void operator +=(Matrix b) {
		*this = *this + b;
	}
  
  	void operator *=(Matrix b) {
		*this = *this * b;
	}
  
	void operator -=(Matrix b) {
		*this = *this - b;
	}

	void operator ^=(ll p) {
		*this = *this ^ p;
	}
	
	void print() {
		FOR(i, rows) {
		    FOR(j, columns) {
			if(j != 0) cout << " ";
			cout << mat[i][j];
		    }
		    cout << "\n";
		}
    	}
};
