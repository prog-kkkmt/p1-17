int strstr(const char *text, const char *pattern)
{   
    int i = 0,j = 0;
    
    if (*pattern == '\0') 
        return 0;
        
    for(i = j; text[i] != '\0'; i++)
{
    while(text[i+j] != '\0' && pattern[j] == text[i+j]) 
        j++;
    if(pattern[j] == '\0') 
        return i;
    j = 0;
} 
    return -1; 
}
