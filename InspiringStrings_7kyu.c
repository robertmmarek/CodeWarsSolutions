#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char *longest_word(char *word_str) {
  // Give me back the longest word!
  int str_len = strlen(word_str);
  char local_str[str_len+1];
  memcpy((void*)local_str, (void*)word_str, str_len*sizeof(char));
  local_str[str_len] = '\0';
  char* token;
  
  char* current_longest = malloc((str_len+1)*sizeof(char));
  current_longest[str_len] = '\0';
  int longest_len = 0;
  
  token = strtok(local_str, " ");
  
  while( token != NULL )
  {
    printf("%s\n", token);
    if (strlen(token) >= longest_len)
    {
      int token_len = strlen(token);
      longest_len = token_len;
      memcpy((void*)current_longest, (void*)token, token_len*sizeof(char));
      current_longest[token_len] = '\0';
    }
  
    token = strtok(NULL, " ");
  }
  
  return current_longest;
}