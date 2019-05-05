// 最长不下降子序列(LIS)，arr:序列
int GetLIS(std::vector<int> &arr) {
  int ret = 1;
  // last[i]:长度为i的不下降子序列末尾元素的最小值
  std::vector<int> last((int)arr.size(), 0);
  last[0] = arr[0];
  for (int i = 1; i < (int)arr.size(); ++i) {
    if (arr[i] >= last[ret]) last[++ret] = arr[i];
    else {
      int pos = std::upper_bound(last.begin(), last.end(), arr[i]) - last.begin();
      last[pos] = arr[i];
    }
  }
  return ret;
}
