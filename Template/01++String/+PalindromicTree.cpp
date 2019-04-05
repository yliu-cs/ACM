const int maxn = "Edit";

class PalindromicTree {
  public:
    // 子节点记录数组
    long long son[maxn][26];
    // 失配指针Fail数组
    long long fail[maxn];
    // len[i]:节点i表示的回文串长度(一个节点表示一个回文串)
    long long len[maxn];
    // cnt[i]:节点i表示的本质不同的串的个数(最后需要运行Count()函数才可求出正确结果)
    long long cnt[maxn];
    // num[i]:以节点i表示的最长回文串的最右端为回文串结尾的回文串个数
    long long num[maxn];
    // 字符
    long long str[maxn];
    // 新添加字符后最长回文串表示的节点
    long long last;
    // 字符数量
    long long str_len;
    // 节点数量
    long long tot;

    // 新建节点
    long long NewNode(long long x) {
      for (long long i = 0; i < 26; ++i) son[tot][i] = 0;
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

    long long GetFail(long long x) {
      while (str[str_len - len[x] - 1] != str[str_len]) x = fail[x];
      return x;
    }

    void Add(long long c) {
      c -= 'a';
      Str[++str_len] = c;
      long long Cur = GetFail(last);
      if (!son[Cur][c]) {
        long long New = NewNode(len[Cur] + 2);
        fail[New] = son[GetFail(fail[Cur])][c];
        son[Cur][c] = New;
        num[New] = num[fail[New]] + 1;
      }
      last = son[Cur][c];
      cnt[last]++;
    }

    void Count() {
      // 若fail[V]=U，则U一定是V回文子串，所以双亲累加孩子的cnt
      for (long long i = tot - 1; i >= 0; --i) cnt[fail[i]] += cnt[i];
    }
};

