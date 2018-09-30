#include <vector>
#include <stack>
#include <string>
#include <sstream>
#include <cassert>

using std::vector;
using std::string;
using std::stringstream;
using std::stack;


vector<string> split(const string& str, char delim)
{
  vector<string> ret;
  stringstream ss(str);
  string s;

  while(std::getline(ss, s, delim))
  {
    ret.emplace(ret.begin(), s);
  }

  return ret;
}

int eval(int left, int right, const string& op)
{
    printf("left %d right %d op %s\n", left, right, op.c_str());
    
  if ("+" == op)
    return left + right;
  if ("-" == op)
    return left - right;
  if ("X" == op)
    return left * right;
  if ("/" == op)
    return left/right;

  printf("left %d right %d op %s\n", left, right, op.c_str());
  assert(false);
  return 0;
}

int evalRPN(stack<string, vector<string>>& exprStack)
{
  while(! exprStack.empty())
  {
    if (exprStack.size() == 1)
    {
      auto s(exprStack.top());
      exprStack.pop();
      return std::stoi(s);
    }
    else
    {
      assert(exprStack.size() >= 3);
      //printf("num1: %s\n", exprStack.top().c_str());
      auto num1( stoi(exprStack.top() ));
      exprStack.pop();
      //printf("num2: %s\n", exprStack.top().c_str());
      auto num2( stoi(exprStack.top() ));
      exprStack.pop();
      //printf("op: %s\n", exprStack.top().c_str());
      auto op(exprStack.top());
      exprStack.pop();

      exprStack.push(std::to_string ( eval(num1, num2, op) ));
    }
  }
  return -1;
}

int main(int, char**)
{
  auto s = "3,4,+,2,X,1,+";
  auto lst = split(s, ',');
  stack<string, vector<string>> stk( lst );

  auto res = evalRPN(stk);
  printf("result of %s = %d\n", s, res);
  //for(const auto& st : lst)
  //  printf("%s ", st.c_str());
}
