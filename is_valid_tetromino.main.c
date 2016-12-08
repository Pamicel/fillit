#include <stdio.h>
#include "libft.h"

int				is_valid(char *t);

int main(void)
{
  int i;

  char *t[7];
  t[0] = "..##\n...#\n...#\n....\n";
  t[1] = "##..\n##..\n....\n....\n";
  t[2] = "....\n##..\n#...\n#...\n";
  t[3] = "....\n##..\n##..\n.#..\n";
  t[4] = "##..\n##..\n....\n....\n";
  t[5] = "##..\n....\n.##.\n....\n";
  t[6] = "#...\n##..\n.#..\n....\n";

  i = 0;
  while (i < 7)
  {
    printf("%s", t[i]);
    if (is_valid(t[i]))
      printf("\e[32mOK\e[0m\n\n");
    else
      printf("\e[41mNOT OK\e[0m\n\n");
    i++;
  }
  return 0;
}
