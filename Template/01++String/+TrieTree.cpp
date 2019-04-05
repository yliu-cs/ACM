const int maxn = "Edit";

class Trie {
  public:
    // Trie Tree节点
    int son[maxn][26];
    // Trie Tree节点数量
    int tot;

    // 字符串数量统计数组
    int cnt[maxn];

    // Trie Tree初始化
    void TrieInit() {
      tot = 0;
      memset(cnt, 0, sizeof(cnt));
      memset(son, 0, sizeof(son));
    }

    // 计算字母下标
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
