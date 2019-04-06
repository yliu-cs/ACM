// ret不为零则先手赢，否则为后手赢
bool GetNim(std::vector<int> arr) {
  int ret = 0;
  for (auto &v : arr) ret ^= v;
  return ret != 0;
}
