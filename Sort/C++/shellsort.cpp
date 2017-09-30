#include <bits/stdc++.h>
using namespace std;

void shellSort(vector<int> &vet)
{
	int n = vet.size();
	for (int gap = n/2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i += 1)
        {
            int temp = vet[i], j;            
            
            for (j = i; j >= gap && vet[j - gap] > temp; j -= gap)
                vet[j] = vet[j - gap];
             
            vet[j] = temp;
        }
    }
}

void test(){
	vector<int> aux;
	
	cout << "Before" << endl;
	for(int i = 10; i >= 1; i--){
		aux.push_back(i);
		cout << i << " ";
	}
	cout << endl;
	
	shellSort(aux);
	
	cout << "After" << endl;
	for(int i = 0; i < aux.size(); i++)
	{
		cout << aux[i] << " ";
	}
	cout << endl;
}

main()
{
	test();
}
