// compare element at [i]
// with children
void heapify(int list[], int len, int i)
{
  // left child index
    auto l = i * 2;
    // right child index
    auto r = i * 2 + 1;

    auto largestIndex = i;

    // find largest index
    if (r <= len && list[r] > list[i])
    {
        largestIndex = r;
    }

    if (l <= len && list[l] > list[largestIndex])
    {
        largestIndex = l;
    }

    // bubble up using a recursive call
    if (largestIndex != i)
    {
        int temp = list[i];
        list[i] = list[largestIndex];
        list[largestIndex] = temp;
        heapify(list, len, largestIndex);
    }

}

// Create heap from array
void buildHeap(int list[], int len)
{
    len = len - 1;
    for(int i = len/2; i >= 0; i--)
    {
        heapify(list, len, i);
    }
}

void heapsort(int list[], int length)
{
    buildHeap(list, length);
    int heapSize = length - 1;
    for (int i = heapSize; i >= 0; i--)
    {
      // place the top of
      // the heap at the end
      // and bubble down
        int temp = list[0];
        list[0] = list[heapSize];
        list[heapSize] = temp;
        heapSize--;
        heapify(list, heapSize, 0);
    }
}

int main(int,char**)
{
  
  return 0;
}
