#include <iostream>
using namespace std;
int binary_s (int v[10], int ini, int fim, int ex ){
	 int i=(ini+fim)/2;
	 if (v[i] = ex) return i;
	 if (ini = fim) return -1;
	 if(v[i] <ex) return binary_s(v, i+1, fim, ex);
              return(v, ini, i-1, ex);
     
	
}
int main() {
	int a, g[100], r, p;

	printf("enter 10 ordered numbers:\n");
	for(p=0; p<10; p++){
		scanf("%d", &g[p]);
	}
	printf("enter the number to be searched:\n");
	scanf("%d", &p); 
	printf("%d\n" ,binary_s(g, 0, 9, p));	
	return 0;
}
