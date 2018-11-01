#include <string>
#include <string_view>
#include <vector>
#include <array>
#include <unordered_set>
#include <stdexcept>
using std::string;
using std::vector;
using std::string_view;
using std::array;
using std::unordered_set;
using std::invalid_argument;

using format_specifier_t = string;

// get the list of format specifier
// for now, just ignore the flags, width, .precision, length
auto parse_format_string(string format_string) {
  vector<format_specifier_t> result{};
  unordered_set<char> specifier_set{
    'd', 'i', 'u', 'o', 'x', 'X', 'f', 'F', 'e', 'E', 'g', 'G',
    'a', 'A', 'c', 's', 'p', 'n', '%'
  };
  for (int i = 0; i < format_string.length(); i++) {
    char curr = format_string[i];
    if (curr == '%') {
      if (i == format_string.length() - 1) {
        throw invalid_argument("% at last of format string!");
      } else {
        char next = format_string[i + 1];
        bool in_set = (specifier_set.find(next) != specifier_set.end());
        if (!in_set) {
          string err_message = string("invalid format specifier: ");
          err_message.push_back(next);
          throw invalid_argument(err_message);
        } else if (next == '%') {
          i++;
        } else {
          format_specifier_t format_specifier = string("%");
          format_specifier.push_back(next);
          result.push_back(format_specifier);
          i++;
        }
      }
    }
  }
}

template <class ... Ts>
string printf_s(string format_string, Ts... args) {
}