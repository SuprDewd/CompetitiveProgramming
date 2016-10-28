
vvi perms;
vi cur;

void rec(dancing_links<int> &left) {
  if (left.front == NULL) {
    perms.push_back(vi(cur));
  } else {
    for (dancing_links<int>::node *it = left.front; it; it = it->r) {
      cur.push_back(it->item);
      left.erase(it);
      rec(left);
      left.restore(it);
      cur.pop_back();
    }
  }
}

void test() {
  int N = 8;
  dancing_links<int> left;
  int *arr = new int[N];
  for (int i = 0; i < N; i++) left.push_back(arr[i] = i + 1);
  rec(left);
  int at = 0;
  do {
    for (int i = 0; i < N; i++) {
      assert_equal(arr[i], perms[at][i]);
    }

    at++;
  } while(next_permutation(arr, arr + N));

  assert(at == size(perms));

  delete[] arr;
}
// vim: cc=60 ts=2 sts=2 sw=2:
