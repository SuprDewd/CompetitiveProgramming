#include "../code/mathematics/is_prime.cpp"

void test() {
  for (int i = 0; i < 10000; i++) {
    bool a = is_probable_prime(i, 10),
       b = is_prime(i);

    assert_equal(b, a);
  }

  for (int i = 0; i < 10000; i++) {
    int x = rand() % 100000000;
    bool a = is_probable_prime(x, 10),
       b = is_prime(x);

    assert_equal(b, a);
  }
}

// vim: cc=60 ts=2 sts=2 sw=2:
