// 最长不下降子序列(LIS)，arr:序列
int GetLIS(std::vector<int> &arr) {
  int ret = 1;
  // last[i]为长度为i的不下降子序列末尾元素的最小值
  std::vector<int> last(int(arr.size()) + 1, 0);
  last[1] = arr[1];
  for (int i = 2; i <= int(arr.size()); ++i) {
    if (arr[i] >= last[ret]) last[++ret] = arr[i];
    else {
      int pos = std::upper_bound(last.begin() + 1, last.end(), arr[i]) - last.begin();
      last[pos] = arr[i];
    }
  }
  // 返回结果
  return ret;
}
