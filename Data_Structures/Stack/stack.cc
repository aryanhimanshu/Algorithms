#include<iostream>

class stack {
private:
  static const int MAXN = 1000000;
  int last;
  int D[MAXN];
  
public:
  stack() {
    last = 0;
  };
  ~stack(){};
  
  void push(int x) {
    D[last] = x;
    ++last;
  }
  
  void pop() {
    --last;
  }
  
  int top() {
    return D[last - 1];
  }
};

int main() {
  stack S;
  int t, x;
  while (std::cin >> t) {
    if (t) {
      std::cin >> x;
      S.push(x);
    }
    else {
      std::cout << S.top() << '\n';
      S.pop();
    }
  }
}
