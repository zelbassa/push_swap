
#include "push_swap.h"

void free_tokens(char **tokens)
{
    int i;

    i = 0;
    while (tokens[i])
    {
        free(tokens[i]);
        i++;
    }
    free(tokens);
}
