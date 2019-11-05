#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr); std::cout.tie(nullptr);

  int n; std::cin >> n;
  
  int ans = 0, spec = 0;
  std::priority_queue<int> alice, bob, others;
  for (int i = 0, x; i < n; ++i) {
    std::string str; std::cin >> str >> x;
    if (str == "11") {
      ans += x;
      ++spec;
    }
    else if (str == "10") alice.push(x);
    else if (str == "01") bob.push(x);
    else others.push(x);
  }

  int alice_size = (int)alice.size(), bob_size = (int)bob.size();
  int sup = spec + std::min(alice_size, bob_size);
  spec += 2 * std::min(alice_size, bob_size);
  for (int i = 0; i < std::min(alice_size, bob_size); ++i) {
    ans += alice.top();
    alice.pop();
    ans += bob.top();
    bob.pop();
  }
  while (!alice.empty()) {
    others.push(alice.top());
    alice.pop();
  }
  while (!bob.empty()) {
    others.push(bob.top());
    bob.pop();
  }
  int others_size = (int)others.size();
  for (int i = 0; i < std::min(others_size, 2 * sup - spec); ++i) {
    ans += others.top();
    others.pop();
  }

  std::cout << ans << '\n';
  return 0;
}

