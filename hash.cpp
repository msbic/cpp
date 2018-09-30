unsigned int hash( const string & key, int tableSize )
{
  unsigned int hashVal = 0;
  for( char ch : key )
    hashVal = 37 * hashVal + ch;
  return hashVal % tableSize;
}
