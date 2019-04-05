const int maxn = "Edit";

char convert_str[maxn << 1];
int len[maxn << 1];

// Manacher算法求Str字符串最长回文子串长度
int Manacher(char Str[]) {
  int L = 0, str_len = int(strlen(Str));
  convert_str[L++] = '$'; convert_str[L++] = '#';
  for (int i = 0; i < str_len; ++i) {
    convert_str[L++] = Str[i];
    convert_str[L++] = '#';
  }
  int mx = 0, id = 0, ret = 0;
  for (int i = 0; i < L; ++i) {
    len[i] = mx > i ? std::min(len[2 * id - i], mx - i) : 1;
    while (convert_str[i + len[i]] == convert_str[i - len[i]]) len[i]++;
    if (i + len[i] > mx) {
      mx = i + len[i];
      id = i;
    }
    ret = std::max(ret, len[i] - 1);
  }
  return ret;
}

