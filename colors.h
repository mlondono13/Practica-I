#include <iostream>
using namespace std;
namespace Color{
  enum Code{
    //Foreground - Background
    FG_GREEN = 32,
    FG_YELLOW = 33,
    FG_WHITE = 37,
    FG_DEFAULT = 39,
    FG_CYAN = 36,
    FG_BLUE = 94,
    FG_RED = 91
  };
class Modifier{
  Code code;
public:
  Modifier(Code Code) : code(Code){}
  friend std::ostream&
  operator<<(std::ostream& os, const Modifier& mod) {
    return os << "\033[" << mod.code << "m";
        }
    };
}
