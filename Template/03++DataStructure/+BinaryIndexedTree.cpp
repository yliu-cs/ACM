const int maxn = "Edit";

class binary_indexed_tree {
#define lowbit(x) (x&(-x))
  public:
    int arr[maxn];

    void Update(int x, int v) {
      while (x < maxn) {
        arr[x] += v;
        x += lowbit(x);
      }
    }

    int GetSum(int x) {
      int ans = 0;
      while (x > 0) {
        ans += arr[x];
        x -= lowbit(x);
      }
    }
#undef
};

