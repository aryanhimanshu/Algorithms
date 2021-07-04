int F[N];

void insert(int idx, int val) {
  while (idx < N) {
    F[idx] += val;
    idx += idx&(-idx);
  }
}

int value(int idx) {
  int val = 0;
  while (idx > 0) {
    val += F[idx];
    idx -= idx&(-idx);
  }
  return val;
}

//segment update
int MultF[N];
int SumF[N];

void update(int left, int right, int val) {
  internalupdate(left - 1, -(left - 1)*val, val);
  internalupdate(right, right*val, -val);
}

void internalupdate(int idx, int sumval, int multval) {
  while (idx < N) {
    MultF[idx] +=  multval;
    SumF[idx] += sumval;
    idx += idx&(-idx);
  }
}

int value(int idx) {
  int x = idx;
  int sumval = 0, multval = 0;
  while (idx > 0) {
    sumval += SumF[idx];
    multval += MultF[idx];
    idx -= idx&(-idx);
  }
  return multval*x + sumval;
}
