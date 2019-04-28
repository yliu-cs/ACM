const int mod = "Edit";

// 多项式求值（低次在前）
long long F(long long x, std::vector<long long> &coef) {
  long long ret = 0;
  for (int i = (int)coef.size() - 1; ~i; --i) {
    ret = (ret * x + coef[i]) % mod;
  }
  return ret;
}
