#include <string>

using std::string;


bool isPalindrome(const string& str)
{
  int si = 0;
  int ei = str.length() - 1;

  while(si <= ei)
  {
    if (str[si] != str[ei])
    {
      return false;
    }

    ++si;
    --ei;
  }

  return true;
}


int main(int, char**)
{
  string s = "madam";
  printf("palindrome :%s %d\n", s.c_str(), isPalindrome(s));
  s = "Hallo";
  printf("palindrome :%s %d\n", s.c_str(), isPalindrome(s));
  s = "parammarap";
  printf("palindrome :%s %d\n", s.c_str(), isPalindrome(s));
  return 0;
}
