#include <string>
#include <cstdio>
#include <cmath>

using std::string;

int charToDigit(char c)
{
  return c - 0x30;
}

char digitToChar(int i)
{
  return i + 0x30;
}

int stringToInt(const string& s)
{
  int ret = 0;
  int k = 0;
  for(int i = s.size() - 1; i >=  0; --i)
  {
    //printf("i = %d k = %d pow(10,k): %f\n", i, k, pow(10,k));
    ret += (int)pow(10, k) * charToDigit(s[i]);
    ++k;
  }

  return ret;
}


string intToString(int num, int len)
{
  string s;
  
  for(int i = 0; i < len; ++i)
  {
    
    int  digit = ((int)num / (int)pow(10, i)) % 10;
    //if (digit == 0) break;
    s = digitToChar(digit) + s; 
    
  }
  
  return s;
}

int main(int, char**)
{
  //printf("%d\n", charToDigit('8'));
  //printf("%d\n", pow(2,10));
  printf("%d\n", stringToInt("12345"));

  printf("%s\n", intToString(90235, 5).c_str());
  //stringToInt("12345");
}
