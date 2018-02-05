#include <bits/stdc++.h>
#define PB push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
using namespace std;
typedef vector<int> VI;

const int seed=514;

mt19937 rng(seed);
int randint(int lb,int ub) { // [lb, ub]
	return uniform_int_distribution<int>(lb,ub)(rng);
}

struct TestData {
	int N;
	VI cross;
	int A, B;
};

void save_data(const TestData &data, const int type, const int id) {
	if(type == 0 && (id == 0 || id == 1)) return; // cancel case A=B, but keep other data the same
	char tmp[20];
	sprintf(tmp, "%02d-%02d.in", type, id);
	FILE *fp_i = fopen(tmp, "w");
	fprintf(fp_i, "%d\n", data.N);
	assert(data.N == SZ(data.cross));
	for(int i = 0; i < data.N; i++)
		fprintf(fp_i, "%d%c", data.cross[i], " \n"[i == data.N - 1]);
	if(data.A == data.B) {
		fprintf(stderr, "%02d-%02d, A==B\n", type, id);
		int A = data.A + 1;
		if(A > data.N) A = 1;
		fprintf(fp_i, "%d %d\n", A, data.B);
	}
	else {
		fprintf(fp_i, "%d %d\n", data.A, data.B);
	}
	fclose(fp_i);
	char tmp_a[20];
	sprintf(tmp_a, "%02d-%02d.ans", type, id);
	char sys_or[100];
	sprintf(sys_or, "../../submissions/accepted/sol < %s > %s", tmp, tmp_a);
	system( sys_or );
}

const int MINN = 4;
const int MAXN = 1000000;
int main() {
	{ // type0: simple N = 4
		TestData data;
		data.N = 4;
		data.cross=VI{1, 2, 3, 4};
		for(int id = 0; id < 2; id++) { // 0~1 A==B
			shuffle( ALL(data.cross), rng);
			data.A = data.B = randint(1, 4);
			save_data(data, 0, id);
		}
		for(int id = 2; id < 4; id++) { // 2~3 total random
			shuffle( ALL(data.cross), rng);
			data.A = randint(1, 4);
			data.B = randint(1, 4);
			save_data(data, 0, id);
		}
	}
	{ // type1: N = MAXN, random
		TestData data;
		data.N = MAXN;
		for(int i = 1; i <= MAXN; i++)
			data.cross.PB(i);
		for(int id = 0; id < 5; id++) {
			shuffle( ALL(data.cross), rng);
			data.A = randint(1, MAXN);
			data.B = randint(1, MAXN);
			save_data(data, 1, id);
		}
	}
	for(int id = 0; id < 4; id++) { // type2: (almost)maxans for some big N
		int N = 0;
		if(id == 0) N = MAXN;
		else N = randint(MAXN - 100, MAXN - 1);
		TestData data;
		data.N = N;
		data.A = randint(1, N);
		data.B = (data.A - 1 + N / 2) % N + 1;
		int pid1 = data.B;
		int pid2 = data.B - 1;
		if(pid2 == 0) pid2 = N;
		int dir = randint(0, 1);
		for(int i = 0; i < N; i++) {
			if(i % 2 == dir) {
				data.cross.PB(pid1);
				pid1++;
				if(pid1 > N)
					pid1 = 1;
			}
			else {
				data.cross.PB(pid2);
				pid2--;
				if(pid2 == 0)
					pid2 = N;
			}
		}
		save_data(data, 2, id);
	}
	for(int id = 0; id < 3; id++) { // type3: A, B neighboring but not good
		TestData data;
		data.N = MAXN - 1016 * id;
		if(id <= 1) {
			if(id == 0) data.A = data.N, data.B = 1;
			else data.A = 8382, data.B = data.A + 1;
			for(int i = data.N; i > 0; i--)
				data.cross.PB(i);
			rotate(begin(data.cross), begin(data.cross) + (data.N + 1 - data.A) % data.N, end(data.cross));
			save_data(data, 3, id);
		}
		else {
			data.A = 1, data.B = data.N;
			for(int i = 1; i <= data.N; i++)
				data.cross.PB(i);
			rotate(begin(data.cross), begin(data.cross) + (data.A - 1), end(data.cross));
			save_data(data, 3, id);
		}
	}
	for(int id = 0; id < 10; id++) { // type4: random, small N
		TestData data;
		int N = randint(5, 12345);
		data.N = N;
		for(int i = 1; i <= N; i++) data.cross.PB(i);
		data.A = randint(1, N);
		data.B = randint(1, N);
		save_data(data, 4, id);
	}
	for(int id = 0; id < 7; id++) { // type5: random, large N
		TestData data;
		int N = randint(MAXN / 10, MAXN);
		data.N = N;
		for(int i = 1; i <= N; i++) data.cross.PB(i);
		data.A = randint(1, N);
		data.B = randint(1, N);
		save_data(data, 5, id);
	}
	return 0;
}
