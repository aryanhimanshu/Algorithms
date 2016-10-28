string a, b;
vector<int> P(a.size() + 1, 0);
int k = 0;
for (int i = 2; i <= a.size(); ++i) {
  while (k > 0 and a[i - 1] != a[k]) k = P[k];
  if (a[i - 1] == P[k]) k++;
  P[i] = k;
}
k = 0;
for (int i = 0; i < b.size(); ++i) {
  while (k > 0 and b[i] != a[k]) k = P[k];
  if (b[i] == a[k]) k++;
  if (k == a.size()) k = P[k]; //Matching
}
