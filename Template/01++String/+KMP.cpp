// 对模式串pattern计算next数组
void KMPPre(std::string pattern, vector<int> &next) {
  int i = 0, j = -1;
  next[0] = -1;
  int len = (int)pattern.length();
  while (i != len) {
    if (j == -1 || pattern[i] == pattern[j]) next[++i] = ++j;
    else j = next[j];
  }
}

// 优化对模式串pattern计算next数组
void PreKMP(std::string pattern, vector<int> &next) {
  int i, j;
  i = 0;
  j = next[0] = -1;
  int len = (int)pattern.length();
  while (i < len) {
    while (j != -1 && pattern[i] != pattern[j]) j = next[j];
    if (pattern[++i] == pattern[++j]) next[i] = next[j];
    else next[i] = j;
  }
}

// 利用预处理next数组计数模式串pattern在主串main中出现次数
int KMPCount(std::string pattern, std::string main) {
  int pattern_len = (int)pattern.length(), main_len = (int)main.length();
  vector<int> next(pattern_len + 1, 0);
  //PreKMP(pattern, next);
  KMPPre(pattern, next);
  int i = 0, j = 0;
  int ret = 0;
  while (i < main_len) {
    while (j != -1 && main[i] != pattern[j]) j = next[j];
    i++; j++;
    if (j >= pattern_len) {
      ret++;
      j = next[j];
    }
  }
  return ret;
}
