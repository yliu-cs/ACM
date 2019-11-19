#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  std::cin >> n;
  struct Triple { int x, y, z; };
  std::vector<Triple> q(n - 2);
  std::set<int> idx[n];
  for (int i = 0; i < n - 2; ++i) {
    int x, y, z;
    std::cin >> x >> y >> z;
    --x;
    --y;
    --z;
    q[i] = (Triple){x, y, z};
    idx[x].insert(i);
    idx[y].insert(i);
    idx[z].insert(i);
  }
  int s = 0;
  for (int i = 0; i < n; ++i) {
    if ((int)idx[i].size() == 1) {
      s = i;
      break;
    }
  }
  std::vector<int> ans;
  ans.push_back(s);
  int id = (*idx[s].begin());
  idx[s].erase(id);
  Triple buf = q[id];
  int a = 0, b = 0;
  if (buf.x == s) {
    a = buf.y;
    b = buf.z;
  }
  else if (buf.y == s) {
    a = buf.x;
    b = buf.z;
  }
  else {
    a = buf.x;
    b = buf.y;
  }
  ans.push_back(a);
  ans.push_back(b);
  idx[a].erase(id);
  idx[b].erase(id);
  while (true) {
    a = ans[(int)ans.size() - 2], b = ans[(int)ans.size() - 1];
    if (idx[a].empty()) {
      a = ans[(int)ans.size() - 3];
    }
    bool f = false;
    for (auto &v : idx[a]) {
      if (idx[b].count(v)) {
        id = v;
        f = true;
        break;
      }
    }
    if (!f) {
      for (auto &v : idx[b]) {
        if (idx[a].count(v)) {
          id = v;
          f = true;
          break;
        }
      }
    }
    if (!f) {
      break;
    }
    buf = q[id];
    if (buf.x != a && buf.x != b) {
      ans.push_back(buf.x);
    }
    else if (buf.y != a && buf.y != b) {
      ans.push_back(buf.y);
    }
    else {
      ans.push_back(buf.z);
    }
    idx[a].erase(id);
    idx[b].erase(id);
    idx[ans.back()].erase(id);
  }
  for (int i = 0; i < (int)ans.size(); ++i) {
    std::cout << ans[i] + 1 << ' ';
  }
  std::cout << '\n';
  return 0;
}

