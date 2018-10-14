#include <vector>

using std::vector;

/// return THE FIRST index of element
/// being searched
int searchSortedArray(const vector<int>& arr, int el)
{
  int index = -1;
  int curIndex = arr.size() / 2;
  int minIndex = 0;
  int maxIndex = arr.size() - 1;

  while (minIndex <= maxIndex)
  {
    printf("arr[curIndex]: %d curIndex: %d maxIndex: %d minIndex: %d index: %d\n",
           arr[curIndex], curIndex, maxIndex, minIndex, index);

    curIndex = minIndex + ((maxIndex - minIndex) / 2) ;
    
    if (arr[curIndex] < el)
    {      
       minIndex = curIndex + 1;              
    }
    else if (arr[curIndex] > el)
    {      
       maxIndex = curIndex - 1;
    }
    else
    {
      maxIndex = curIndex - 1;
      index = curIndex;
    }      
  }
  
  return index;
}


int searchElementIndex(const vector<int>& ar)
{
  int ret = -1;

  int minIndex = 0;
  int maxIndex = ar.size() - 1;
  int curIndex = ar.size() / 2;

  while (minIndex <= maxIndex)
  {
    curIndex = minIndex + (maxIndex - minIndex) / 2;
    if (ar[curIndex] > curIndex)
      maxIndex = curIndex - 1;
    else if (ar[curIndex] < curIndex)
      minIndex = curIndex + 1;
    else
      {
        ret = curIndex;
        break;
      }
      
  }
  
  
  return ret;
}


int main(int, char**)
{
  vector<int> ar { 1,4,6,7,14,14,14,14,40,50 };
  auto index = searchSortedArray(ar, 14);

  printf("14 is at index: %d\n", index);

  index = searchSortedArray(ar, 16);

  printf("16 is at index: %d\n", index);


  ar = { -5, 1, 4, 4, 8, 15 };
  index = searchElementIndex(ar);

  printf("index: %d\n", index);
  
  return 0;
}
