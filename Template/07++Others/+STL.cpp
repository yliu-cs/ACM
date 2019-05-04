// pbds

#include <bits/extc++.h>
using namespace __gnu_pbds;

// --- tree ---

template< typename Key,
          typename Mapped,
          typename Cmp_Fn = std::less<Key>,
          typename Tag = rb_tree_tag,
          template<typename Node_Cltr,
                   typename Node_Itr,
                   typename Cmp_Fn_,
                   typename _Alloc_> class Node_Update = null_node_update,
          typename _Alloc = std::allocator<char> >

__gnu_pbds::tree< Key, Mapped, Cmp_Fn, Tag, Node_Update, _Alloc >

/*

Member types:
  Key:
    Key type.
  Mapped:
    Map type.
  Cmp_Fn:
    Comparison functior.
  Tag:
    Instantiating data structure type
    __gnu_pbds::ov_tree_tag: Ordered-vector tree.
    __gnu_pbds::rb_tree_tag: Red-black tree;
    __gnu_pbds::splay_tree_tag: Splay tree.
  Node_Update:
    Updates nodes, restores invariants when invalidated.
    XXX See design::tree-based-containers::node invariants.
  _Alloc:
    Allocator type.


Member functions:
  insert({key, mapped}):
    Insert element.
  erase({key, mapped}):
    Delete element.
  order_of_key({key, mapped}):
    Get the rank of {key, mapped}.
  find_by_order(int x):
    Find the k-th element. Return iterator.
  join(tree t):
    Insert the tree t into the tree if the origin tree type is the same ans there are no duplicate elements.
  split(value, t):
    Split the tree, the origin tree contains elements that are less than or equal to value, the tree t contains elements that are greater to value.
  lower_bound(value):
    Reture the iterator of the first element greater or equal to value.
  upper_bound(value):
    Reture the iterator of the first element greater to value.

*/

