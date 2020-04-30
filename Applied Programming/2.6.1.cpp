char *resize(const char *str, unsigned size, unsigned new_size)
{
  char *rezult = new char[new_size];
    
  for (int i = 0; i < new_size; i++)
      rezult[i] = str[i];
      
  delete []str;
  return rezult;
}
