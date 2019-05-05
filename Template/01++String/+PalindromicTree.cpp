const int maxn = "Edit";

struct PalindromicTree {
  // 子节点记录数组
  int son[maxn][26];
  // 失配指针fail数组
  int fail[maxn];
  // len[i]:节点i表示的回文串长度(一个节点表示一个回文串)
  int len[maxn];
  // cnt[i]:节点i表示的本质不同的串的个数(最后需要运行Count()函数才可求出正确结果)
  int cnt[maxn];
  // num[i]:以节点i表示的最长回文串的最右端为回文串结尾的回文串个数
  int num[maxn];
  // 字符
  int str[maxn];
  // 新添加字符后最长回文串表示的节点
  int last;
  // 字符数量
  int str_len;
  // 节点数量
  int tot;

  // 新建节点
  int NewNode(int x) {
    for (int i = 0; i < 26; ++i) son[tot][i] = 0;
    cnt[tot] = 0;
    num[tot] = 0;
    len[tot] = x;
    return tot++;
  }

  // 初始化
  void Init() {
    tot = 0;
    NewNode(0); NewNode(-1);
    last = 0;
    str_len = 0;
    // 开头存字符集中没有的字符，减少特判
    str[0] = -1;
    fail[0] = 1;
  }

  int GetFail(int x) {
    while (str[str_len - len[x] - 1] != str[str_len]) x = fail[x];
    return x;
  }

  void Add(int c) {
    c -= 'a';
    Str[++str_len] = c;
    int Cur = GetFail(last);
    if (!son[Cur][c]) {
      int New = NewNode(len[Cur] + 2);
      fail[New] = son[GetFail(fail[Cur])][c];
      son[Cur][c] = New;
      num[New] = num[fail[New]] + 1;
    }
    last = son[Cur][c];
    cnt[last]++;
  }

  void Count() {
    // 若fail[v]=u，则u一定是v回文子串，所以双亲累加孩子的cnt
    for (int i = tot - 1; i >= 0; --i) cnt[fail[i]] += cnt[i];
  }
};

