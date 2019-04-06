const int maxn = "Edit";

class Trie {
  public:
    int son[maxn][26];
    int tot;
    int cnt[maxn];

    void TrieInit() {
      tot = 0;
      memset(cnt, 0, sizeof(cnt));
      memset(son, 0, sizeof(son));
    }

    int Pos(char x) {
      return x - 'a';
    }

    // 向Trie Tree中插入字符串Str
    void Insert(string str) {
      int cur = 0, len = int(str.length());
      for (int i = 0; i < len; ++i) {
        int index = Pos(str[i]);
        if (!son[cur][index]) son[cur][index] = ++tot;
        cur = son[cur][index];
        cnt[cur]++;
      }
    }

    // 查找字符串str，存在返回true，不存在返回false
    bool Find(string str) {
      int cur = 0, len = int(str.length());
      for (int i = 0; i < len; ++i) {
        int index = Pos(str[i]);
        if (!son[cur][index]) return false;
        cur = son[cur][index];
      }
      return true;
    }

    // 查询字典树中以str为前缀的字符串数量
    int PathCnt(string str) {
      int cur = 0, len = int(str.length());
      for (int i = 0; i < len; ++i) {
        int index = Pos(Str[i]);
        if (!son[cur][index]) return 0;
        cur = son[cur][index];
      }
      return cnt[cur];
    }
};
