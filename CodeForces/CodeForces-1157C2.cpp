#include <bits/stdc++.h>

std::vector<int> arr;
std::vector<char> ans, buf;

void Dfs(int l, int r, int last) {
  if ((int)buf.size() > (int)ans.size()) ans = buf;
  if (l > r) return;
  if (arr[l] > last && arr[r] > last) {
    if (arr[l] == arr[r]) {
      buf.push_back('L');
      Dfs(l + 1, r, arr[l]);
      buf.pop_back();
      buf.push_back('R');
      Dfs(l, r - 1, arr[r]);
      buf.pop_back();
    }
    else if (arr[l] < arr[r]) {
      buf.push_back('L');
      Dfs(l + 1, r, arr[l]);
      buf.pop_back();
    }
    else if (arr[r] < arr[l]) {
      buf.push_back('R');
      Dfs(l, r - 1, arr[r]);
      buf.pop_back();
    }
  }
  else if (arr[l] > last) {
    buf.push_back('L');
    Dfs(l + 1, r, arr[l]);
    buf.pop_back();
  }
  else if (arr[r] > last) {
    buf.push_back('R');
    Dfs(l, r - 1, arr[r]);
    buf.pop_back();
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr); std::cout.tie(nullptr);

  int n; std::cin >> n;
  arr.resize(n);
  for (auto &v : arr) std::cin >> v;

  Dfs(0, n - 1, -1);

  std::cout << ans.size() << '\n';
  for (auto &v : ans) std::cout << v;
  return 0;
}
