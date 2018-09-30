#include <vector>
#include <stack>
#include <string>
#include <sstream>

using std::vector;
using std::string;
using std::stringstream;
using std::stack;

stack<string> splitAndStack(const string& str, char delim)
{
  stack<string> ret;
  stringstream ss(str);
  string s;

  while(std::getline(ss, s, delim))
  {
    ret.push(s);
  }

  return ret;
}

int main(int, char**)
{
  auto stk = splitAndStack("Bob likes Alice", ' ');
  while(! stk.empty())
  {
    auto str( stk.top() );
    stk.pop();
    printf("%s ", str.c_str());
  }
}
