#include "libft.h"

void        *ft_realloc(void *ptr, size_t cur_size size_t new_size)
{
    void       *new;
    size_t     i;

    if (new_size <= cur_size)
      return (ptr);
    if (!(new = ft_memalloc(new_size)))
      return (NULL);
    i = 0;
    while (i < cur_size)
    {
      ((char*)new)[i] = ((char*)ptr)[i];
      i++;
    }
    free(ptr);
    return (new);
}
