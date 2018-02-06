#include <bits/stdc++.h>
using namespace std;

const int seed=514;

mt19937 rng(seed);
int randint(int lb,int ub) { // [lb, ub]
	return uniform_int_distribution<int>(lb,ub)(rng);
}

struct TestData {
	int N;
	string S;
	int K;
};

void save_data(const TestData &data, int type, int id) {
	char tmp[20];
	sprintf(tmp, "%d-%d.in", type, id);
	FILE *fp_i = fopen(tmp, "w");
	fprintf(fp_i, "%d\n", data.N);
	fprintf(fp_i, "%s\n", data.S.c_str());
	fprintf(fp_i, "%d\n", data.K);
	fclose(fp_i);
	//FILE *fp_a = fopen(tmp, "w");
	//fclose(fp_a);
	char tmp_a[20];
	sprintf(tmp_a, "%d-%d.ans", type, id);
	char sys_or[100];
	sprintf(sys_or, "../../submissions/accepted/sol1 < %s > %s", tmp, tmp_a);
	system( sys_or );
}
void make_data(int N, int C, int K, int type, int id) {
	TestData data;
	data.N = N;
	for(int i = 0; i < N; i++)
		data.S += 'M';
	data.S[C - 1] = 'C';
	data.K = K;
	save_data(data, type, id);
}

const int MINN = 4; // all case with N = 3 was generated
const int MAXN = 514;
int main() {
	{ // type 0: N = 3, all
		int cnt = 0;
		for(int C = 1; C <= 3; C++)
			for(int K = 1; K <= 3; K++)
				make_data(3, C, K, 0, cnt++);
	}
	for(int cnt = 0; cnt < 5; cnt++) { // type 1: all random
		int N = randint(MINN, MAXN);
		int C = randint(1, N);
		int K = randint(1, N);
		make_data(N, C, K, 1, cnt);
	}
	for(int cnt = 0; cnt < 5; cnt++) { // type 2: N = 514(MAXN)
		int N = MAXN;
		int C = randint(1, N);
		int K = randint(1, N);
		make_data(N, C, K, 2, cnt);
	}
	for(int cnt = 0; cnt < 3; cnt++) { // type 3: K = C
		int N = randint(MINN, MAXN);
		int C = randint(1, N);
		int K = C;
		make_data(N, C, K, 3, cnt);
	}
	make_data(MAXN, MAXN, MAXN, 4, 0);
	make_data(MAXN,    1, MAXN, 4, 1);
	make_data(MAXN, MAXN,    1, 4, 2);
	make_data(MAXN,    1,    1, 4, 3);
	return 0;
}
