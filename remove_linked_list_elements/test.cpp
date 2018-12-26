#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> v = {1, 2, 3, 4, 5, 6, 6, 5, 5, 6};
  for (auto it = v.begin(); it != v.end(); ++it) {
    cout << "it:" << *it << endl;
    v.erase(it);
  }
  return 0;
}
