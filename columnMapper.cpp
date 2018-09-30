#include <string>
#include <vector>
#include <cmath>

using std::vector;
using std::string;


int getNum(char c)
{
  return c - 0x40;
}


int calcColHeading(const string& s)
{
  int ret = 0;

  int index = 0;
  for(auto it = s.rbegin(); it != s.rend(); ++it)
  {
    int num = getNum(*it);
    ret += (num % 27) * pow(26, index);
    ++index;
  }

  return ret;
}

int main(int, char**)
{
  printf("%d\n", 'Z' - 0x40);
  printf("col num for AA: %d\n", calcColHeading("AA"));
  printf("col num for ZZ: %d\n", calcColHeading("ZZ"));
  printf("col num for Z: %d\n", calcColHeading("Z"));
  return 0;
}
