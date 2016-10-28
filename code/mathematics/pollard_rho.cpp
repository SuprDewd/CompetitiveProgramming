// public static int[] seeds = new int[] {2,3,5,7,11,13,1031};
// public static BigInteger rho(BigInteger n,
//                              BigInteger seed) {
//     int i = 0,
//         k = 2;
//     BigInteger x = seed,
//                y = seed;
//     while (i < 1000000) {
//         i++;
//         x = (x.multiply(x).add(n)
//               .subtract(BigInteger.ONE)).mod(n);
//         BigInteger d = y.subtract(x).abs().gcd(n);
//         if (!d.equals(BigInteger.ONE) && !d.equals(n)) {
//             return d; }
//         if (i == k) {
//             y = x;
//             k = k*2; } }
//     return BigInteger.ONE; }
// vim: cc=60 ts=2 sts=2 sw=2:
