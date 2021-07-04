#include<iostream>

class queue {
private:
  static const int MAXN = 1000000;
  int first;
  int last;
  int D[MAXN];
  
public:
  queue() {
    first = 0;
    last = 0;
  };
  ~queue(){};
  
  void push(int x) {
    D[last] = x;
    last = (last + 1)%MAXN;
  }
  
  void pop() {
    first = (first + 1)%MAXN;
  }
  
  int front() {
    return D[first];
  }
};

int main() {
  queue Q;
  int t, x;
  while (std::cin >> t) {
    if (t) {
      std::cin >> x;
      Q.push(x);
    }
    else {
      std::cout << Q.front() << '\n';
      Q.pop();
    }
  }
}
