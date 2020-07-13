#include <iostream>
#include <bits/stdc++.h>

using namespace std;
long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}
//761457 614573

long long lcm_good(long long int a,long long int b) {
long long cal = (a*b)/__gcd(a, b);
return cal;
}

int main() {
  long long int a, b;
  cin >> a >> b;
  long long int lcm_cal = lcm_good(a, b);
  cout << lcm_cal<<endl;
  return 0;
}
