#include<bits/stdc++.h>

using namespace std;

int parent[1000];

int find_set(int x){
	return parent[x] == x ? x : parent[x] = find_set(parent[x]);
}

bool same_set(int x, int y){
	return find_set(x) == find_set(y);
}

void union_set(int x, int y){
	if(same_set(x,y)) return;
	int p = find_set(x);
	int q = find_set(y);
	parent[p] = q;
}

int main(){
	for(int i=0; i<10; ++i){
		parent[i] = i;
	}
	union_set(2,4);
	if(same_set(2,4)){
		cout << "same\n";
	}
	return 0;
}
