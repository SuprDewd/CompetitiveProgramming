//Euler's function in short-hand notation to find gcd of two numbers namely num1 and num2

#include<bits/stdc++.h>

using namespace std;

#define loi long long

int main(void)
{
loi num1, num2;

cin >> num1 >> num2;

loi gcd = __gcd(num1, num2);

cout << gcd << "\n";

return 0;
}
