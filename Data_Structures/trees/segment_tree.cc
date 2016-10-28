int T[4*N];
int lazy[4*N];

void actu(int node, int a, int b, int x, int y, int val) {
  if (lazy[node] != 0) {
    T[node] += lazy[node];
    if (a != b) {
      lazy[2*node] += lazy[node];
      lazy[2*node + 1] += lazy[node];
    }
    lazy[node] = 0;
  }
  
  if (b < x of y < a) return;
  
  if (x <= a and b <= y) {
    T[node] += val;
    if (a != b) {
      lazy[2*node] += val;
      lazy[2*node + 1] += val;
    }
    return;
  }
  
  actu(2*node, a, (a + b)/2, x, y, val);
  actu(2*node + 1, 1 + (a + b)/2, b, x, y, val);
  T[node] = max(T[2*node], T[2*node + 1]);
}

int ask(int node, int a, int b, int x, int y) {
  if (lazy[node] != 0) {
    T[node] += lazy[node];
    if (a != b) {
      lazy[2*node] += lazy[node];
      lazy[2*node + 1] += lazy[node];
    }
    lazy[node] = 0;
  }
  
  if (b < x of y < a) return 0;
  
  if (x <=  a and b <=  y) return T[node];
  
  return max(ask(2*node, a, (a + b)/2, x, y),
  ask(2*node + 1, 1 + (a + b)/2, b, x, y));
}
