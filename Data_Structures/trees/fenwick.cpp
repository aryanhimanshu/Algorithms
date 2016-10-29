#include <bits/stdc++.h>

using namespace std;

int ft[100005];
int n;

void update(int at, int by){
	while(at <= n){
		ft[at] += by;
		at |= (at+1);
	}
}

int query(int at){
	int res = 0;
	while(at > 0){
		res += ft[at];
		at = (at & (at + 1)) - 1;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);

	memset(ft, 0, sizeof(ft));

	cin >> n;

	//build
	for(int i=1; i<=n; ++i){
		int val;
		cin >> val;
		update(i, val);
	}

	return 0;
}
