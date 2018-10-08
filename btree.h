#include <memory>

#ifndef _BTREE_
#define _BTREE_

using std::shared_ptr;

template<class T> 
struct BTNode
{
  T val;
  shared_ptr<BTNode<T>> left;
  shared_ptr<BTNode<T>> right;
};


template <class T>
class BTree
{
public:
 explicit BTree(const T& root) :
  m_root(std::move(new BTNode<T>()))
  {
    m_root->val = root; 
  }

  enum class TraversalType { IN_ORDER, PRE_ORDER, POST_ORDER };
  /*const shared_ptr<BTNode<T>>& Find(T val) const;*/
  shared_ptr<BTNode<T>> Find(shared_ptr<BTNode<T>> node, T val);
  void AddNode(const T& to, const T& val);
  int Height(const shared_ptr<BTNode<T>>&) const;
  void Print(const shared_ptr<BTNode<T>>&, TraversalType, int level=0);
  const shared_ptr<BTNode<T>>& Root() const
  {
    return m_root;
  }

  bool IsBalancedHeight(const shared_ptr<BTNode<T>>&) const;
  
private:
  shared_ptr<BTNode<T>> m_root;
};

#endif
