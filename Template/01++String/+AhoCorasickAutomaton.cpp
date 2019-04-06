const int maxn = "Edit";

class AhoCorasickAutomaton {
  public:
    int son[maxn][26];
    int val[maxn];
    int fail[maxn];
    int tot;

    // Trie Tree初始化
    void TrieInit() {
      tot = 0;
      memset(son, 0, sizeof(son));
      memset(val, 0, sizeof(val));
      memset(fail, 0, sizeof(fail));
    }

    // 计算字母下标
    int Pos(char x) {
      return x - 'a';
    }

    // 向Trie Tree中插入Str模式字符串
    void Insert(string str) {
      int cur = 0, Len = int(str.length());
      for (int i = 0; i < Len; ++i) {
        int index = Pos(str[i]);
        if (!son[cur][index]) son[cur][index] = ++tot;
        cur = son[cur][index];
      }
      val[cur]++;
    }

    // Bfs求得Trie Tree上失配指针
    void GetFail() {
      std::queue<int> que;
      for (int i = 0; i < 26; ++i) {
        if (son[0][i]) {
          fail[son[0][1]] = 0;
          que.push(son[0][i]);
        }
      }
      while (!que.empty()) {
        int cur = que.front(); que.pop();
        for (int i = 0; i < 26; ++i) {
          if (son[cur][i]) {
            fail[son[cur][i]] = son[fail[cur]][i];
            que.push(son[cur][i]);
          }
          else son[cur][i] = son[fail[cur]][i];
        }
      }
    }

    // 询问Str中出现的模式串数量
    int Query(string str) {
      int len = int(str.length());
      int cur = 0, ret = 0;
      for (int i = 0; i < len; ++i) {
        cur = son[cur][Pos(str[i])];
        for (int j = cur; j && ~val[j]; j = fail[j]) {
          ret += val[j];
          val[j] = -1;
        }
      }
      return ret;
    }
};

