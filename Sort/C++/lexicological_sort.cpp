#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
  vector<string> v{"d", "c", "b"};
sort(v.begin(), v.end());

    for (const auto& s : v)
      std::cout << s << " ";
  std::cout << std::endl;
}
