#include <bits/stdc++.h>
const int maxn = 2e5 + 5;

int t;
int n;
int arr[maxn];
int size;
bool flag;

int main() {
  scanf("%d", &t);
  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);
    std::sort(arr, arr + n);
    size = std::unique(arr, arr + n) - arr;
    if (arr[0] != 0) {
      printf("0\n");
      continue;
    }
    flag = false;
    for (int i = 1; i < size; ++i) {
      if (arr[i] != arr[i - 1] + 1) {
        printf("%d\n", arr[i - 1] + 1);
        flag = true;
        break;
      }
    }
    if (!flag) printf("%d\n", arr[size - 1] + 1);
  }
  return 0;
}

