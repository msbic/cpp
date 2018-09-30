#include <cstdio>
#include <cassert>
#include <string>
#include <vector>

using std::string;

auto countBits(int num)
{
  auto bitCount = 0;
  string s;
  std::vector<string> v;
  
  for(auto i = 0; i < sizeof(num) * 8; ++i)
  {
    if (((num >> i) & 1) == 1)
    {
      ++bitCount;
      s = "1" + s;
    }
    else
    {
      s = "0" + s;
    }
  }

  //printf("%s\n", s.c_str());
  
  return bitCount;
}

int findClosestWeightNum(int num)
{  
  auto bitCount = countBits(num);
  auto small = 0;
  auto large = num * 2;
  for(int i = num - 1; i > 0; --i)
  {
    if (countBits(i) == bitCount)
    {
      small = i;
      break;
    }
  }

  for(int i = num + 1; i < 100000; ++i)
  {
    if (countBits(i) == bitCount)
    {
      large = i;
      break;
    }
  }

  

  auto smallDif = num - small;
  auto largeDif = large - num;

  if (largeDif > smallDif)
  {
    return small;
  }

  return large;
}

int main(int, char**)
{
  printf("closest num %d\n", findClosestWeightNum(92));
  //assert(countBits(65) == 2);
}
