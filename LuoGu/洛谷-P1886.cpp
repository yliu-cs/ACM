#include <bits/stdc++.h>
const int maxn = 1e6 + 5;

int n, k;
int arr[maxn];
int que[maxn];

void GetMin() {
  int head = 0, tail = 0;
  for (int i = 1; i < k; ++i) {
    while (head <= tail && arr[que[tail]] >= arr[i]) --tail;
    que[++tail] = i;
  }
  for (int i = k; i <= n; ++i) {
    while (head <= tail && arr[que[tail]] >= arr[i]) --tail;
    que[++tail] = i;
    while (que[head] <= i - k) ++head;
    printf("%d ", arr[que[head]]);
  }
}

void GetMax() {
  int head = 0, tail = 0;
  for (int i = 1; i < k; ++i) {
    while (head <= tail && arr[que[tail]] <= arr[i]) --tail;
    que[++tail] = i;
  }
  for (int i = k; i <= n; ++i) {
    while (head <= tail && arr[que[tail]] <= arr[i]) --tail;
    que[++tail] = i;
    while (que[head] <= i - k) ++head;
    printf("%d ", arr[que[head]]);
  }
}

int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; ++i) scanf("%d", &arr[i]);
  GetMin();
  printf("\n");
  GetMax();
  printf("\n");
  return 0;
}