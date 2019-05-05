const int maxn = "Edit";

struct Trie {
  int son[maxn][26];
  int tot;
  int cnt[maxn];

  void TrieInit() {
    tot = 0;
    memset(cnt, 0, sizeof(cnt));
    memset(son, 0, sizeof(son));
  }

  int Pos(char x) { return x - 'a'; }

  // 向Trie Tree中插入字符串str
  void Insert(std::string str) {
    int cur = 0, len = (int)str.length();
    for (int i = 0; i < len; ++i) {
      int idx = Pos(str[i]);
      if (!son[cur][idx]) son[cur][idx] = ++tot;
      cur = son[cur][idx]; 
      cnt[cur]++;
    }
  }

  // 查找字符串str，存在返回true，不存在返回false
  bool Find(std::string str) {
    int cur = 0, len = (int)str.length();
    for (int i = 0; i < len; ++i) {
      int idx = Pos(str[i]);
      if (!son[cur][idx]) return false;
      cur = son[cur][idx];
    }
    return true;
  }

  // 查询字典树中以str为前缀的字符串数量
  int PathCnt(std::string str) {
    int cur = 0, len = (int)str.length();
    for (int i = 0; i < len; ++i) {
      int idx = Pos(Str[i]);
      if (!son[cur][idx]) return 0;
      cur = son[cur][idx];
    }
    return cnt[cur];
  }
};
