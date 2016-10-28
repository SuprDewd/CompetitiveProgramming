void test() {
  exact_cover ec(4, 3);
  ec.set_value(0, 0);
  ec.set_value(0, 1);
  ec.set_value(1, 0);
  ec.set_value(2, 1);
  ec.set_value(3, 2);
  ec.setup();
  ec.search();
}
// vim: cc=60 ts=2 sts=2 sw=2:
