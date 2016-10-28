#include "../code/data-structures/avl_tree.cpp"

void test() {
  misof_tree t1;
  avl_tree<int> t2;

  for (int i = 0; i < 1000000; i++) {
    int op = rand() % 3;

    if (op == 0) {
      int x = rand() % (1 << BITS);

      // printf("insert %d\n", x);

      if (t2.find(x) == NULL)
      {
        t1.insert(x);
        t2.insert(x);
      }
      else i--;

    } else if (op == 1 && size(t2) > 0) {
      int x = t2.nth(rand() % size(t2))->item;

      // printf("erase %d\n", x);

      t1.erase(x);
      t2.erase(x);
    } else if (op == 2 && size(t2) > 0) {
      int n = rand() % size(t2);

      // printf("nth %d: %d, %d\n", n, t2.nth(n)->item, t1.nth(n));

      assert_equal(t2.nth(n)->item, t1.nth(n), true);
    } else i--;
  }
}
// vim: cc=60 ts=2 sts=2 sw=2:
