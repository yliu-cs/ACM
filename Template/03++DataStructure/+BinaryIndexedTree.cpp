#define lowbit(x) (x&(-x))
const int maxn = "Edit";

struct BitTree {
  int arr[maxn];

  void Init() { memset(arr, 0, sizeof(0)); }

  void Modify(int idx, int x) {
    while (idx < maxn) {
      arr[idx] += x;
      idx += lowbit(idx);
    }
  }

  int Query(int idx) {
    int ret = 0;
    while (idx > 0) {
      ret += arr[idx];
      idx -= lowbit(idx);
    }
    return ret;
  }

  int GetRank(int x) {
    int ret = 1;
    --x;
    while (x) {
      ret += arr[x];
      x -= lowbit(x);
    }
    return ret;
  }

  // min
  int GetKth(int k) {
    int ret = 0, cnt = 0, max = log2(maxn);
    for (int i = max; i >= 0; --i) {
      ret += (1 << i);
      if (ret >= maxn || cnt + arr[ret] >= k) ret -= (1 << i);
      else cnt += arr[ret];
    }
    return ++ret;
  }

  int GetPrev(int x) { return GetKth(GetRank(x) - 1); }

  int GetNext(int x) { return GetKth(GetRank(x) + 1); }
};

