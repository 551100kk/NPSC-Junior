#include <bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()
#ifdef _DEBUG_
	#define debug(...) printf(__VA_ARGS__)
#else
	#define debug(...) (void)0
#endif
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;

const int seed=514;

mt19937 rng(seed);
int randint(int lb,int ub) { // [lb, ub]
	return uniform_int_distribution<int>(lb,ub)(rng);
}

void save_data(const VI &data, const int type, const int id) {
	char tmp[20];
	sprintf(tmp, "%02d-%02d.in", type, id);
	FILE *fp_i = fopen(tmp, "w");
	fprintf(fp_i, "%d\n", SZ(data));
	for(int i = 0; i < SZ(data); i++)
		fprintf(fp_i, "%d%c", data[i], " \n"[i == SZ(data) - 1]);
	fclose(fp_i);
	char tmp_a[20];
	sprintf(tmp_a, "%02d-%02d.ans", type, id);
	char sys_or[100];
	sprintf(sys_or, "../../submissions/accepted/old_modify < %s > %s", tmp, tmp_a);
	system( sys_or );
}

const int MAXN = 2000;
const int MAXX = 2000;

int rand_a() {
	return randint(1, MAXX);
}

int main() {
	{ // type0: small N, manual
		save_data({1}, 0, 0);
		save_data({2000}, 0, 1);
		save_data({2000, 1, 1, 2000}, 0, 2);
		save_data({7, 1, 7}, 0, 3);
		save_data({17, 9, 17, 22}, 0, 4);
		save_data({20, 12, 20, 12}, 0, 5);
		save_data({103, 11, 11}, 0, 6);
		save_data({19, 10, 1016, 907, 810}, 0, 7);
	}
	for(int id = 0; id < 10; id++) { // type1: MAXN, random
		VI arr;
		for(int i = 0; i < MAXN; i++)
			arr.PB(rand_a());
		save_data(arr, 1, id);
	}
	for(int id = 0; id < 8; id++) { // type2: big N, all unique
		int N = randint(MAXN - 514, MAXN);
		if(id < 3) N = MAXN;
		VI arr;
		for(int i = 1; i <= MAXX; i++)
			arr.PB(i);
		shuffle(ALL(arr), rng);
		while(SZ(arr) > N) arr.pop_back();
		save_data(arr, 2, id);
	}
	for(int id = 0; id < 3; id++) { // type3: (strictly) increase
		int N = randint(5, MAXN);
		if(id == 0) N = MAXN;
		VI arr;
		for(int i = 1; i <= MAXX; i++)
			arr.PB(i);
		shuffle(ALL(arr), rng);
		while(SZ(arr) > N) arr.pop_back();
		sort(ALL(arr));
		save_data(arr, 3, id);
	}
	for(int id = 0; id < 3; id++) { // type4: (strictly) decrease
		int N = randint(5, MAXN);
		if(id == 0) N = MAXN;
		VI arr;
		for(int i = 1; i <= MAXX; i++)
			arr.PB(i);
		shuffle(ALL(arr), rng);
		while(SZ(arr) > N) arr.pop_back();
		sort(ALL(arr));
		reverse(ALL(arr));
		save_data(arr, 4, id);
	}
	for(int id = 0; id < 2; id++) { // type5: all same
		int N;
		if(id == 0) N = MAXN;
		else N = 514;
		VI arr;
		int num = rand_a();
		for(int i = 0; i < N; i++)
			arr.PB(num);
		save_data(arr, 5, id);
	}
	for(int id = 0; id < 8; id++) { // type6: increase
		int N = randint(3, MAXN);
		if(id <= 1) N = MAXN;
		VI arr;
		for(int i = 0; i < N; i++)
			arr.PB(rand_a());
		sort(ALL(arr));
		save_data(arr, 6, id);
	}
	for(int id = 0; id < 8; id++) { // type7: decrease
		int N = randint(3, MAXN);
		if(id <= 1) N = MAXN;
		VI arr;
		for(int i = 0; i < N; i++)
			arr.PB(rand_a());
		sort(ALL(arr));
		reverse(ALL(arr));
		save_data(arr, 7, id);
	}
	for(int id = 0; id < 5; id++) { // type8: two symbols
		int N = randint(10, MAXN);
		if(id <= 1) N = MAXN;
		const int SZsym = 2;
		VI symbol(SZsym);
		for(int i = 0; i < SZsym; i++) {
			while(true) {
				bool fine = true;
				symbol[i] = rand_a();
				for(int j = 0; j < i; j++)
					if(symbol[j] == symbol[i]) {
						fine = false;
						break;
					}
				if(fine)
					break;
			}
		}
		VI arr;
		for(int i = 0; i < N; i++)
			arr.PB( symbol[randint(0, SZsym - 1)] );
		save_data(arr, 8, id);
	}
	for(int id = 0; id < 7; id++) { // type9: three symbols
		int N = randint(10, MAXN);
		if(id <= 1) N = MAXN;
		const int SZsym = 3;
		VI symbol(SZsym);
		for(int i = 0; i < SZsym; i++) {
			while(true) {
				bool fine = true;
				symbol[i] = rand_a();
				for(int j = 0; j < i; j++)
					if(symbol[j] == symbol[i]) {
						fine = false;
						break;
					}
				if(fine)
					break;
			}
		}
		VI arr;
		for(int i = 0; i < N; i++)
			arr.PB( symbol[randint(0, SZsym - 1)] );
		save_data(arr, 9, id);
	}
	for(int id = 0; id < 15; id++) { // type10: small N, random
		int N = randint(5, 514);
		VI arr;
		for(int i = 0; i < N; i++)
			arr.PB(rand_a());
		save_data(arr, 10, id);
	}
	for(int id = 0; id < 10; id++) { // type11: big N, random
		int N = randint(MAXN - 514, MAXN -1);
		VI arr;
		for(int i = 0; i < N; i++)
			arr.PB(rand_a());
		save_data(arr, 11, id);
	}
	return 0;
}
