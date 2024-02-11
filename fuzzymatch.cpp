
// #define PREPRO
#ifndef PREPRO
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstdarg>
#endif
using namespace std;

#define FILE_INFO printf("\n+Compiled from\t-- " __FILE__ "\n"); \
printf("+Exe name\t-- %s\n", argv[var 0])
#define Nl "\n"
// #define NOVIS

void inline printArr(int *array, int size) {
  for(int i = 0; i < size; i++) {
    std::cout << array[i] << " ";
  }
}

#define TYPE char
void inline inputArray(TYPE *array, int size) {
    int i = 0;
    while(i < size) std::cin >> array[i++];
}


#undef TYPE
#define TYPE int

#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<unordered_map>
// #include<utility>
// using namespace std;

double fuzzymatch(const string& s1, const string& s2) {
  map<char, size_t> prev_s1_chars, prev_s2_chars;
  const size_t N = max(s2.size(), s1.size());
  const size_t MAX_SCORE = 3 * N;
  double ratio = 0.0;
  size_t score = 0;
  for (size_t i{}; i < N; ++i) {
    char c1, c2;
    c1 = c2 = '\0';
    if (i < s1.size())
      c1 = s1[i];
    if (i < s2.size())
      c2 = s2[i];

    if (c1 == c2)
      score += 1 + 2;
    else {
      if (prev_s2_chars.find(c1) != prev_s2_chars.end() and 
          prev_s2_chars.at(c1) > 0) {
        score += 1;
        prev_s2_chars[c1] -= 1;
      } else if (c1 != '\0') {
        prev_s1_chars[c1] += 1;
      }

      if (prev_s1_chars.find(c2) != prev_s1_chars.end() and
          prev_s1_chars.at(c2) > 0) {
        score += 1;
        prev_s1_chars[c2] -= 1;
      } else if (c2 != '\0') {
        prev_s2_chars[c2] += 1;
      }
    }
  }
  ratio = score*1.0 / MAX_SCORE;
  return ratio;
}

// int main() {

//   // std::freopen("output.txt", "w", stdout);
//   std::freopen("input.txt", "r", stdin);
//   // freopen("array-input.txt", "r", stdin);
//   // int is_ok = EXIT_SUCCESS;  
//   // {
//   //   using namespace std;
//   // }
//   #define DUMP(var) #var << " = " << var

//   // Input

//   std::cout 
//   << "hello debug test\n" 
//   << fuzzymatch("U70FYC64MSWFAE277VMWR56EPFAJB", "LT9Y75RQZQQS33N8GC0AFCSU6C8C4") << Nl
//   << fuzzymatch("aaa", "aaass") << Nl;
//   std::cout << Nl;
//   return 0;
// }
