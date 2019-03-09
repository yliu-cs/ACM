// 离散化
class Hash {
  public:
    int size;
    vector<int> arr;

    Hash(const vector<int> &v) {
      arr.assign(v.begin(), v.end());
      sort(arr.begin(), arr.end());
      arr.erase(unique(arr.begin(), arr.end()), arr.end());
      size = arr.size();
    }

    int Get(int k) {
      return lower_bound(arr.begin(), arr.end(), k) - arr.begin();
    }
};