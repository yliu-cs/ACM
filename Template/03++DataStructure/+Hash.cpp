template <typename type>
class Hash {
  public:
    int size;
    vector<int> arr;

    Hash(const vector<type> &v) {
      arr.assign(v.begin(), v.end());
      sort(arr.begin(), arr.end());
      arr.erase(unique(arr.begin(), arr.end()), arr.end());
      size = arr.size();
    }

    int Get(type k) {
      return lower_bound(arr.begin(), arr.end(), k) - arr.begin();
    }
};
