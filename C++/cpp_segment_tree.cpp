#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#define deb(x) cout << #x << " : " << x << '\n'
#define logn(x) cout << x << '\n'
#define logs(x) cout << x << ' '
#define log(x) cout << x
#define MOD 1000000007
#define uInt unsigned long long int
#define Int long long int

using namespace std;

template <typename T, typename U>
void debArr(T arr[], U n) {
    for (U i = 0; i <= n - 1; i++) {
        logs(arr[i]);
    }
    log(endl);
}

template <typename T>
void debVect(vector<T> arr) {
    for (auto i : arr) {
        logs(i);
    }
    log(endl);
}

// Range Sum Problem
class SegTree {
   public:
    vector<Int> arr;
    vector<Int> tree, lazy;
    Int n;
    SegTree(const vector<Int> &v) {
        n = v.size();
        arr = v;
        tree.resize(4 * n, 0);
        lazy.resize(4 * n, 0);
        build();
    }
    void build(const Int &node, const Int &start, const Int &end) {
        if (start <= end) {
            if (start == end) {
                tree[node] = arr[start];
            } else {
                Int mid = (start + end) / 2;
                Int lChild = 2 * node + 1;
                Int rChild = 2 * node + 2;
                build(lChild, start, mid);
                build(rChild, mid + 1, end);
                tree[node] = tree[lChild] + tree[rChild];
            }
        }
    }
    void build() {
        build(0, 0, n - 1);
    }
    void update(const Int &node, const Int &start, const Int &end, const Int &ind, const Int &upd) {
        if (start <= end) {
            if (start > ind or end < ind)
                return;
            if (start == end) {
                tree[node] += upd;
                arr[ind] += upd;
            } else {
                Int mid = (start + end) / 2;
                Int lChild = 2 * node + 1;
                Int rChild = 2 * node + 2;
                update(lChild, start, mid, ind, upd);
                update(rChild, mid + 1, end, ind, upd);
                tree[node] = tree[lChild] + tree[rChild];
            }
        }
    }
    void update(const Int &ind, const Int &upd) {
        update(0, 0, n - 1, ind, upd);
    }
    void updateRange(const Int &node, const Int &start, const Int &end, const Int &left, const Int &right, const Int &upd) {
        if (start <= end) {
            if (left > end or right < start)
                return;
            if (start == end) {
                tree[node] += upd;
                arr[start] += upd;
            } else {
                Int mid = (start + end) / 2;
                Int lChild = 2 * node + 1;
                Int rChild = 2 * node + 2;
                updateRange(lChild, start, mid, left, right, upd);
                updateRange(rChild, mid + 1, end, left, right, upd);
                tree[node] = tree[lChild] + tree[rChild];
            }
        }
    }
    void updateRange(const Int &left, const Int &right, const Int &upd) {
        updateRange(0, 0, n - 1, left, right, upd);
    }
    Int query(const Int &node, const Int &start, const Int &end, const Int &left, const Int &right) {
        if (start <= end) {
            if (left > end or right < start)
                return 0;
            if (left <= start and end <= right)
                return tree[node];
            Int mid = (start + end) / 2;
            Int lChild = 2 * node + 1;
            Int rChild = 2 * node + 2;
            Int v1 = query(lChild, start, mid, left, right);
            Int v2 = query(rChild, mid + 1, end, left, right);
            return v1 + v2;
        }
    }
    Int query(const Int &left, const Int &right) {
        return query(0, 0, n - 1, left, right);
    }
    void lazyUpdateRange(const Int &node, const Int &start, const Int &end, const Int &left, const Int &right, const Int &upd) {
        if (start <= end) {
            Int lChild = 2 * node + 1;
            Int rChild = 2 * node + 2;
            if (lazy[node] != 0) {
                tree[node] += (end - start + 1) * lazy[node];
                if (start != end) {
                    lazy[lChild] += lazy[node];
                    lazy[rChild] += lazy[node];
                }
                lazy[node] = 0;
            }
            if (right < start or left > end)
                return;
            if (left <= start and end <= right) {
                tree[node] += (end - start + 1) * upd;
                if (start != end) {
                    lazy[lChild] += upd;
                    lazy[rChild] += upd;
                }
                return;
            }
            Int mid = (start + end) / 2;
            lazyUpdateRange(lChild, start, mid, left, right, upd);
            lazyUpdateRange(rChild, mid + 1, end, left, right, upd);
            tree[node] = tree[lChild] + tree[rChild];
        }
    }
    void lazyUpdateRange(const Int &left, const Int &right, const Int &upd) {
        lazyUpdateRange(0, 0, n - 1, left, right, upd);
    }
    Int lazyQuery(const Int &node, const Int &start, const Int &end, const Int &left, const Int &right) {
        if (start <= end) {
            Int lChild = 2 * node + 1;
            Int rChild = 2 * node + 2;
            if (lazy[node] != 0) {
                tree[node] += (end - start + 1) * lazy[node];
                if (start != end) {
                    lazy[lChild] += lazy[node];
                    lazy[rChild] += lazy[node];
                }
                lazy[node] = 0;
            }
            if (right < start or left > end)
                return 0;
            if (left <= start and end <= right)
                return tree[node];
            Int mid = (start + end) / 2;
            Int v1 = lazyQuery(lChild, start, mid, left, right);
            Int v2 = lazyQuery(rChild, mid + 1, end, left, right);
            return v1 + v2;
        }
    }
    Int lazyQuery(const Int &left, const Int &right) {
        return lazyQuery(0, 0, n - 1, left, right);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<Int> v({1, 3, 5, 7, 9, 10});
    Int n = v.size();

    SegTree st(v);
    debVect(st.arr);
    debVect(st.tree);
    deb(st.query(0, 2));

    st.lazyUpdateRange(0, 1, 4);
    debVect(st.arr);
    debVect(st.lazy);
    debVect(st.tree);

    deb(st.lazyQuery(0, 2));

    return 0;
}