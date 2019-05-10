#include <bits/stdc++.h>
#include <bits/extc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr); std::cout.tie(nullptr);

  int n; std::cin >> n;
  std::vector<int> arr(n);
  for (int &v : arr) std::cin >> v;

  int ans = 0;
  std::map<int, int> cnt;
  std::map<int, int> cnt_cnt;

  for (int i = 0; i < n; ++i) {
    ++cnt[arr[i]];
    ++cnt_cnt[cnt[arr[i]]];
    if (cnt[arr[i]] > 1) {
      --cnt_cnt[cnt[arr[i]] - 1];
      if (cnt_cnt[cnt[arr[i]] - 1] == 0) cnt_cnt.erase(cnt[arr[i]] - 1);
    }

    std::map<int, int>::iterator it = cnt_cnt.end();
    --it;
    std::pair<int, int> max_cnt = *it;
    int se_cnt = 0;
    if ((int)cnt_cnt.size() > 1) {
      --it;
      se_cnt = it->first;
    }

    if ((int)cnt_cnt.size() == 1 && cnt_cnt.find(1) != cnt_cnt.end()) ans = i + 1;
    if ((int)cnt_cnt.size() == 1 && cnt_cnt.begin()->second == 1) ans = i + 1;
    if ((int)cnt_cnt.size() == 2 && max_cnt.first == se_cnt + 1 && max_cnt.second == 1) ans = i + 1;
    if ((int)cnt_cnt.size() == 2 && cnt_cnt.find(1) != cnt_cnt.end() && cnt_cnt[1] == 1) ans = i + 1;
  }

  std::cout << ans << '\n';

  return 0;
}

