// Author: Tonyst4rk Time: 2019-10-29 20:19:35
#include <bits/stdc++.h>

const int D = 2;
const int N = 1e5 + 5;
const int MOD = 1e9 + 7;

struct Matrix {
  long long mat[D][D];
  Matrix() { memset(mat, 0, sizeof(mat)); }
};

Matrix A, B;
Matrix operator * (Matrix k1, Matrix k2) {
  Matrix ret;
  for (int i = 0; i < D; ++i)
    for (int j = 0; j < D; ++j)
      for (int k = 0; k < D; ++k)
        ret.mat[i][j] = (ret.mat[i][j] + k1.mat[i][k] * k2.mat[k][j] % MOD) % MOD;
  return ret;
}

Matrix tree[N * 4][2];
int lazy[N * 4];

void Pull(int o) {
  tree[o][0] = tree[o * 2][0] * tree[o * 2 + 1][0];
  tree[o][1] = tree[o * 2][1] * tree[o * 2 + 1][1];
}

void Push(int o) {
  if (lazy[o] != 0) {
    std::swap(tree[o * 2][0], tree[o * 2][1]);
    std::swap(tree[o * 2 + 1][0], tree[o * 2 + 1][1]);
    lazy[o * 2] ^= 1;
    lazy[o * 2 + 1] ^= 1;
    lazy[o] = 0;
  }
}

void Build(int o, int l, int r, char str[]) {
  if (l == r) {
    if (str[l] == 'A') {
      tree[o][0] = A;
      tree[o][1] = B;
    }
    else {
      tree[o][0] = B;
      tree[o][1] = A;
    }
    return;
  }
  int m = (l + r) / 2;
  Build(o * 2, l, m, str);
  Build(o * 2 + 1, m + 1, r, str);
  Pull(o);
}

void Modify(int o, int l, int r, int ll, int rr) {
  if (ll <= l && rr >= r) {
    std::swap(tree[o][0], tree[o][1]);
    lazy[o] ^= 1;
    return;
  }
  Push(o);
  int m = (l + r) / 2;
  if (ll <= m) Modify(o * 2, l, m, ll, rr);
  if (rr > m) Modify(o * 2 + 1, m + 1, r, ll, rr);
  Pull(o);
}

Matrix qry;
void Query(int o, int l, int r, int ll, int rr) {
  if (ll <= l && rr >= r) {
    qry = qry * tree[o][0];
    return;
  }
  Push(o);
  int m = (l + r) / 2;
  if (ll <= m) Query(o * 2, l, m, ll, rr);
  if (rr > m) Query(o * 2 + 1, m + 1, r, ll, rr);
  Pull(o);
}

int n, q;
char str[N];

int main() {
  A.mat[0][0] = A.mat[1][0] = A.mat[1][1] = 1;
  B.mat[0][0] = B.mat[0][1] = B.mat[1][1] = 1;
  scanf("%d%d", &n, &q);
  scanf("%s", str + 1);
  Build(1, 1, n, str);
  while (q--) {
    int opt;
    scanf("%d", &opt);
    if (opt == 1) {
      int l, r;
      scanf("%d%d", &l, &r);
      Modify(1, 1, n, l, r);
    }
    else {
      int l, r, a, b;
      scanf("%d%d%d%d", &l, &r, &a, &b);
      qry.mat[0][0] = qry.mat[1][1] = 1;
      qry.mat[0][1] = qry.mat[1][0] = 0;
      Query(1, 1, n, l, r);
      Matrix ans;
      ans.mat[0][0] = a;
      ans.mat[0][1] = b;
      ans = ans * qry;
      printf("%lld %lld\n", ans.mat[0][0], ans.mat[0][1]);
    }
  }
  return 0;
}

