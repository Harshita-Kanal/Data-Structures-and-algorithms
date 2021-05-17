#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long MaxPairwiseProduct(vector<long int>& numbers) {
 long long max_product = 0;
    int n = numbers.size();

   // for (int first = 0; first < n; ++first) {
    //    for (int second = first + 1; second < n; ++second) {
     //       max_product = max(max_product,
        //        numbers[first] * numbers[second]);
       // }
  //  }

  sort(numbers.begin(), numbers.end());
  max_product = (long long int)(numbers.back()) * ((long long int)(numbers[n-2]));
  return max_product;
}

int main() {
    int n;
    cin >> n;
   vector<long int> numbers(n);
    for (int i = 0; i < n; ++i) {
       cin >> numbers[i];
    }
 long long int max_product = MaxPairwiseProduct(numbers);
    cout << max_product << "\n";
    return 0;
}
