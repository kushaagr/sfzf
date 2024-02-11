#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <functional>
#include <iomanip>

#include "fuzzymatch.h"

#define Nl "\n";

using std::string;
using std::getline;

std::string get_first_parameter(int argc, char* argv[]) {
  // Check if any arguments are provided
  if (argc <= 1) {
    std::cerr << "Error: No command line parameter provided." << std::endl;
    return "";
  }

  // Check if more than one parameter is provided
  if (argc > 2) {
    std::cerr << "Error: More than one command line parameter provided." << std::endl;
    return "";
  }

  // Return the first parameter after the program name
  return std::string(argv[1]);
}


void printlist_tablular(const std::vector<std::pair<double, string>>& results) {
    if (results.empty()) {
        std::cout << "Empty list\n";
        return;
    }

    std::cout << "Value\tString\n";
    for (const auto& [value, str] : results) {
        std::cout << std::fixed << std::setprecision(2) << value << '\t' << str << '\n';
    }
}

void printlist(const std::vector<std::pair<double, string>>& results) {
    for (const auto& [value, str] : results) {
        std::cout << str << '\n';
    }    
}


int main(int argc, char* argv[]) {
    size_t is_ok = 0;

    string search_string = get_first_parameter(argc, argv);
    if (search_string.empty()) {
        is_ok = 1;
        return is_ok;
    }

    string s;
    std::vector<std::pair<double, string>> results;
    results.reserve(256);
    while(getline(std::cin, s)) {
        
        // std::cout << s << Nl;

        // double similarity = 1.0;
        double similarity = fuzzymatch(s, search_string);
        if (similarity > 0.01) {
            results.push_back(make_pair(similarity, s));
        }
    }
    std::sort(results.begin(), results.end(), std::greater<std::pair<double, string>>());
    printlist(results);
    // printlist_tablular(results); // For debugging
    return is_ok;
}