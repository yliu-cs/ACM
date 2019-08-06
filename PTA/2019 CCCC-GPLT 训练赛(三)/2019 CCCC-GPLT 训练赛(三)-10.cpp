#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int n, l, h; cin >> n >> l >> h;
  struct person {int id, v1, v2;};
  vector<person> p1, p2, p3, p4;
  for (int i = 0, id, v1, v2; i < n; ++i) {
    cin >> id >> v1 >> v2;
    if (v1 < l || v2 < l) continue;
    if (v1 >= h && v2 >= h) p1.emplace_back((person){id, v1, v2});
    else if (v1 >= h && v2 < h) p2.emplace_back((person){id, v1, v2});
    else if (v1 < h && v2 < h && v1 >= v2) p3.emplace_back((person){id, v1, v2});
    else p4.emplace_back((person){id, v1, v2});
  }
  sort(p1.begin(), p1.end(), [&](person k1, person k2) {
    if (k1.v1 + k1.v2 == k2.v1 + k2.v2) {
      if (k1.v1 == k2.v1) return k1.id < k2.id;
      return k1.v1 > k2.v1;
    }
    return k1.v1 + k1.v2 > k2.v1 + k2.v2;
  });
  sort(p2.begin(), p2.end(), [&](person k1, person k2) {
    if (k1.v1 + k1.v2 == k2.v1 + k2.v2) {
      if (k1.v1 == k2.v1) return k1.id < k2.id;
      return k1.v1 > k2.v1;
    }
    return k1.v1 + k1.v2 > k2.v1 + k2.v2;
  });
  sort(p3.begin(), p3.end(), [&](person k1, person k2) {
    if (k1.v1 + k1.v2 == k2.v1 + k2.v2) {
      if (k1.v1 == k2.v1) return k1.id < k2.id;
      return k1.v1 > k2.v1;
    }
    return k1.v1 + k1.v2 > k2.v1 + k2.v2;
  });
  sort(p4.begin(), p4.end(), [&](person k1, person k2) {
    if (k1.v1 + k1.v2 == k2.v1 + k2.v2) {
      if (k1.v1 == k2.v1) return k1.id < k2.id;
      return k1.v1 > k2.v1;
    }
    return k1.v1 + k1.v2 > k2.v1 + k2.v2;
  });
  cout << p1.size() + p2.size() + p3.size() + p4.size() << endl;
  for (auto &it : p1) {
    cout << setiosflags(ios::right) << setfill('0') << setw(8) << it.id;
    cout << " " << it.v1 << " " << it.v2 << endl;
  }
  for (auto &it : p2) {
    cout << setiosflags(ios::right) << setfill('0') << setw(8) << it.id;
    cout << " " << it.v1 << " " << it.v2 << endl;
  }
  for (auto &it : p3) {
    cout << setiosflags(ios::right) << setfill('0') << setw(8) << it.id;
    cout << " " << it.v1 << " " << it.v2 << endl;
  }
  for (auto &it : p4) {
    cout << setiosflags(ios::right) << setfill('0') << setw(8) << it.id;
    cout << " " << it.v1 << " " << it.v2 << endl;
  }
  return 0;
}

