#include "fstream"

bool eq(const intx &a, const intx &b) {
  return !(a < b) && !(b < a);
}

intx fib(int n) {
  intx a(0), b(1);
  for (int i = 0; i < n; i++) {
    intx c = a + b;
    a = b;
    b = c;
  }

  return a;
}

intx fac(int n) {
  intx res(1);
  for (int i = 1; i <= n; i++) {
    res = res * i;
  }

  return res;
}

intx gcd(intx a, intx b) {
  return eq(b, intx(0)) ? a : gcd(b, a % b);
}

// void multiplication_speed() {
//     // int len = 100,
//     //     cnt = 1000;
// 
//     int len = 20,
//         cnt = 100;
// 
//     for (int i = 0; i < cnt; i++)
//     {
//         printf("%d\n", i);
//         stringstream ss;
//         for (int j = 0; j < len; j++)
//             ss << (rand() % 10 + '0');
// 
//         intx a(ss.str());
//         ss.str("");
// 
//         for (int j = 0; j < len; j++)
//             ss << (rand() % 10 + '0');
// 
//         intx b(ss.str());
// 
//         intx c1 = a * b;
//         // intx c2 = karatsuba(a,b);
//         intx c2 = karatsuba2(a,b);
// 
//         cout << a << endl;
//         cout << b << endl;
//         cout << a * b << endl;
//         cout << c2 << endl;
// 
//         assert_true(eq(c1,c2), true);
//     }
// }

void test() {
  // for (int i = 0; i < 1000; i++)
  // {
  //     for (int j = 0; j < 1000; j++)
  //     {
  //         assert_true(eq(karatsuba(intx(i), intx(j)), intx(i) * intx(j)), true);
  //     }
  // }

  // multiplication_speed();
  // return;

  // cout << (intx(-10) < intx(-5)) << endl;
  // cout << intx(-5) << endl;
  // cout << intx(-10) << endl;
  // cout << intx(-5) - intx(-10) << endl;
  // cout << intx(-10) - intx(-5) << endl;
  // return;

  ifstream input("intx.test.in");

  set<string> enabled_ops;
  enabled_ops.insert("add");
  enabled_ops.insert("sub");
  enabled_ops.insert("neg");
  enabled_ops.insert("lt");
  enabled_ops.insert("mul");
  enabled_ops.insert("div");
  enabled_ops.insert("mod");
  enabled_ops.insert("fib");
  enabled_ops.insert("fac");
  enabled_ops.insert("gcd");

  // int line = 0, n;
  int n;
  string op, s, ans;
  intx a, b;
  while (input >> op) {

    // printf("%d %s\n", ++line, op.c_str());

    intx res;
    if (op == "add") {
      input >> s;
      a = intx(s);
      input >> s;
      b = intx(s);
    } else if (op == "sub") {
      input >> s;
      a = intx(s);
      input >> s;
      b = intx(s);
    } else if (op == "mul") {
      input >> s;
      a = intx(s);
      input >> s;
      b = intx(s);
    } else if (op == "div") {
      input >> s;
      a = intx(s);
      input >> s;
      b = intx(s);
    } else if (op == "mod") {
      input >> s;
      a = intx(s);
      input >> s;
      b = intx(s);
    } else if (op == "neg") {
      input >> s;
      a = intx(s);
      res = -a;
    } else if (op == "lt") {
      input >> s;
      a = intx(s);
      input >> s;
      b = intx(s);
      res = a < b;
    } else if (op == "gcd") {
      input >> s;
      a = intx(s);
      input >> s;
      b = intx(s);
    } else if (op == "fib") {
      input >> n;
    } else if (op == "fac") {
      input >> n;
    }

    input >> ans;

    if (enabled_ops.find(op) != enabled_ops.end()) {

      if (op == "add") {
        assert_true(eq(intx(ans), a + b), true);
      } else if (op == "sub") {
        assert_true(eq(intx(ans), a - b), true);
      } else if (op == "mul") {
        assert_true(eq(intx(ans), a * b), true);
        // assert_true(eq(intx(ans), karatsuba(a, b)), true);
      } else if (op == "div") {
        assert_true(eq(intx(ans), a / b), true);
      } else if (op == "mod") {
        assert_true(eq(intx(ans), a % b), true);
      } else if (op == "neg") {
        assert_true(eq(intx(ans), -a), true);
      } else if (op == "lt") {
        assert_equal(ans == "True", a < b, true);
      } else if (op == "gcd") {
        assert_true(eq(intx(ans), gcd(a,b)), true);
      } else if (op == "fib") {
        assert_true(eq(intx(ans), fib(n)), true);
      } else if (op == "fac") {
        assert_true(eq(intx(ans), fac(n)), true);
      }

    }
  }
}

// vim: cc=60 ts=2 sts=2 sw=2:
