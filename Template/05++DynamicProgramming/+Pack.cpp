const int maxn = "Edit";

int dp[maxn];
// cap:背包容量，cnt:总物品数
int cap, cnt;

// 01背包，代价为cost，获得的价值为weight
void ZeroOnePack(int cost, int weight) {
  for (int i = cap; i >= cost; --i) dp[i] = std::max(dp[i], dp[i - cost] + weight);
}

// 完全背包，代价为cost，获得的价值为weight
void CompletePack(int cost, int weight) {
  for (int i = cost; i <= cap; ++i) dp[i] = std::max(dp[i], dp[i - cost] + weight);
}

// 多重背包，代价为cost，获得的价值为weight，数量为amount
void MultiplePack(int cost, int weight, int amount) {
  if (cost * amount >= cap) CompletePack(cost, weight);
  else {
    int k = 1;
    while (k < amount) {
      ZeroOnePack(k * cost, k * weight);
      amount -= k;
      k <<= 1;
    }
    ZeroOnePack(amount * cost, amount * weight);
  }
}
