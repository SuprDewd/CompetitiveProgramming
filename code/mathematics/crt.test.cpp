void test() {
  /* Field testing: Kattis CRT, Kattis generalchineseremainder, Kattis solarly */

  vector<ll> as, ns;

  as.clear();
  as.push_back(2);
  as.push_back(3);
  as.push_back(1);
  ns.clear();
  ns.push_back(3);
  ns.push_back(4);
  ns.push_back(5);
  assert_equal(11LL, crt(as, ns));
  assert_true(make_pair(11LL, 3*4*5LL) == gcrt(as, ns));

  as.clear();
  as.push_back(23);
  as.push_back(12);
  as.push_back(55);
  ns.clear();
  ns.push_back(11);
  ns.push_back(21);
  ns.push_back(31);
  assert_equal(5325LL, crt(as, ns));
  assert_true(make_pair(5325LL,11*21*31LL) == gcrt(as, ns));
}
// vim: cc=60 ts=2 sts=2 sw=2:
