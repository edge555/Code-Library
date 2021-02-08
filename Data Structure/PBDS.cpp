#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
                         //less_equal //<ll>                                     //ordered_multiset

find_by_order(k) returns an iterator to the k-th largest element (counting from zero)
order_of_key(X) returns the number of items in a set that are strictly smaller than X

ordered_set os
os.insert(1)
*os.find_by_order(k)
os.order_of_key(X)