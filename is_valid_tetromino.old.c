#include <stdio.h>
#include "libft.h"

static int n_char(char *t, char c)
{
  int n;

  n = 0;
  while (*t)
    n += c == *(t++);
  return (n);
}

/*
** Can only be used with a valid grid with a valid nbr of '#'s
*/
static int valid_shape(char *t)
{
  int i;
  int total;
  int n;

  n = 0;
  total = 0;
  i = 0;
  while (i < 20)
  {
    if (t[i] == '#')
    {
      n =  (i <= 14  ? t[i + 5] == '#' : 0) +\
            (i >= 5   ? t[i - 5] == '#' : 0) +\
            (i >= 1   ? t[i - 1] == '#' : 0) +\
            (i <= 18  ? t[i + 1] == '#' : 0);
      if (n == 0)
        return (0);
    }
    i++;
    total += n;
  }
  return (total);
}


int is_valid(char *t)
{
  return ( \
  ft_strlen(t) == 20    && \
  t[4] ==   '\n'        && \
  t[9] ==   '\n'        && \
  t[14] ==  '\n'        && \
  t[19] ==  '\n'        && \
  n_char(t, '\n') == 4  && \
  n_char(t, '#')  == 4  && \
  valid_shape(t)  >= 6       );
}

/*

0   1   2   3   4   5   6   7   8   9  10  11  12  13  14  15  16  17  18  19
.   .   .   .   \n  .   .   .   .   \n  .   .   .   .   \n  .   .   .   .   \n

0   1   2   3   4

5   6   7   8   9

10  11  12  13  14

15  16  17  18  19
*/

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
      ft_putstr("\e[32mOK\e[0m\n\n");
    else
      ft_putstr("\e[41mNOT OK\e[0m\n\n");
    i++;
  }
  return 0;
}
