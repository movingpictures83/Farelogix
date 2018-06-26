#pragma once

template<class T=float>
class BioAdj {
private:
	vector<vector<T>> adjMatrix;
	const BioAdj& operator *= (T scale) { adjMatrix[i][j] *= T; }
public:

	virtual void print() = 0;
};
