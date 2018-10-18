#include "btree.h"
#include <string>
#include <cstdlib>

using std::string;

template <class T>
void printMe(const T&)
{}

template<>
void printMe<string>(const string& s)
{
  printf("+ %s\n", s.c_str());
}

template <class T>
void BTree<T>::Print(const shared_ptr<BTNode<T>>& root, TraversalType ttype, int level)
{
  if (! root && 0 == level)
  {
    Print(m_root, ttype, 0);    
  }
  
  if (root)
  {
    if (TraversalType::PRE_ORDER == ttype)
    {
      for(int i = 0; i < level; ++i)
	printf(" ");
      printMe(root->val);
      Print(root->left, ttype, level + 1);
      Print(root->right, ttype, level + 1);
    }
    else if (TraversalType::IN_ORDER == ttype)
    {      
      Print(root->left, ttype, level + 1);
      for(int i = 0; i < level; ++i)
	printf(" ");
      printMe(root->val);
      Print(root->right, ttype, level + 1);
    }
    else
    {
      Print(root->left, ttype, level + 1);
      Print(root->right, ttype, level + 1);
      for(int i = 0; i < level; ++i)
	printf(" ");
      printMe(root->val);
    }
  }
}

template <class T>
shared_ptr<BTNode<T>> BTree<T>::Find(shared_ptr<BTNode<T>> node, T val)
{
  
  if (! node)
  {
    return nullptr;
  }
  
  if (node && node->val == val)
  {
    return node;
  }

  auto n = Find(node->left, val);
  if (n)
  {
    return n;
  }

  auto nn = Find(node->right, val);
  if (nn)
  {
    return nn;
  }

  return nullptr;
}

template <class T>
void BTree<T>::AddNode(const T& to, const T& val)
{
  auto node = Find(m_root, to);
  if (node)
  {
    if (! node->left)
    {
      node->left = shared_ptr<BTNode<T>>( new BTNode<T>()  );
      node->left->val = val;
    }
    else if (! node->right)
    {
      node->right = shared_ptr<BTNode<T>>( new BTNode<T>()  );
      node->right->val = val;
    }
  }
  else
  {
    printf("Node not found %d %s\n", __LINE__, __func__);
    printMe(val);
  }
}

template <class T>
int BTree<T>::Height(const shared_ptr<BTNode<T>>& node) const
{
  if (! node)
  {
    return 0;
  }

  return 1 + std::max(Height(node->left), Height(node->right));
}

template <class T>
bool BTree<T>::IsBalancedHeight(const shared_ptr< BTNode< T > >& node) const
{
  if (! node)
  {
    return true;
  }

  if (node)
  {
    if (! node->left && ! node->right)
    {
      return true;
    }

    if (! node->left && node->right)
    {
      if (Height(node->right) >= 2)
      {
        return false;
      }
    }

    if (! node->right && node->left)
    {
      if (Height(node->left) >= 2)
      {
        return false;
      }
    }
  
    return (IsBalancedHeight(node->left) && IsBalancedHeight(node->right));
  }
}

template <class T>
void BTree<T>::Collect(const shared_ptr<BTNode<T>>& node, vector<T>& data, TraversalType ttype) const
{
  if (! node)
  {
    return;
  }
  
  switch(ttype)
  {
    case TraversalType::IN_ORDER:
      Collect(node->left, data, ttype);
      data.push_back(node->val);
      Collect(node->right, data, ttype);
      break;
    
    case TraversalType::POST_ORDER:
      Collect(node->left, data, ttype);      
      Collect(node->right, data, ttype);
      data.push_back(node->val);
      break;
      
    case TraversalType::PRE_ORDER:
      data.push_back(node->val);
      Collect(node->left, data, ttype);      
      Collect(node->right, data, ttype);      
      break;
  }
}

template <class T>
bool BTree<T>::IsSymmetric() const
{
  vector<T> left;
  vector<T> right;
  
  Collect(m_root->left, left, TraversalType::PRE_ORDER);
  Collect(m_root->right, right, TraversalType::PRE_ORDER);
  
  return (left == right);
}

int main(int, char**)
{
  BTree<string> tree("Michael");
  
  tree.AddNode("Michael", "Luiza");
  tree.AddNode("Michael", "Benka");
  
  tree.AddNode( "Benka", "Genka");
  
  tree.AddNode ("Benka", "Kollka");
  
  //tree.AddNode ("Luiza", "Irina");
  
  //tree.AddNode ("Luiza", "Rustam");

  //tree.AddNode("Rustam", "Gulnora");
  //tree.AddNode("Gulnora", "Anna");
  
  tree.Print(nullptr, BTree<string>::TraversalType::PRE_ORDER);

  //tree.Print(nullptr, BTree<string>::TraversalType::POST_ORDER);

  printf("tree height: %d\n", tree.Height(tree.Root()));

  printf("tree height balanced: %d\n", tree.IsBalancedHeight( tree.Root() ));
  
  BTree<int> iTree(0);
  iTree.AddNode(0, 1);
  iTree.AddNode(0, 1);
  iTree.AddNode(1, 15);
  
  printf("tree IsSymmetric: %d\n", iTree.IsSymmetric());
  
  return 0;
}
