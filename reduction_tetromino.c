#include <stdio.h>

static int    ft_is_line_empty(char *t, int i)
{
  return (t[i]     != '#' &&  \
          t[i + 1] != '#' &&  \
          t[i + 2] != '#' &&  \
          t[i + 3] != '#');
}

static int    ft_is_col_empty(char *t, int i)
{
  return (t[i]      != '#' && \
          t[i + 5]  != '#' && \
          t[i + 10] != '#' && \
          t[i + 15] != '#');
}

static void   x_stop(int *v, char *t)
{
  int i;

  i = 0;
  while (ft_is_col_empty(t, i))
    i++;
  v[0] = i;
  while (i < 4 && !ft_is_col_empty(t, i))
    v[1] = i++;
}

static void   y_stop(int *v, char *t)
{
  int i;

  i = 0;
  while (ft_is_line_empty(t, i))
    i += 5;
  v[2] = i / 5;
  while (i <= 15 && !ft_is_line_empty(t, i))
  {
    v[3] = i / 5;
    i += 5;
  }
}

int main(void)
{
  int v[4];
  // xstart, xstop, ystart, ystop
  int i;
  char *t0 = "..##\n...#\n...#\n....\n";
  char *t1 = "##..\n##..\n....\n....\n";
  char *t2 = "....\n##..\n#...\n#...\n";
  char *t3 = "....\n##..\n##..\n....\n";

  i = 0;
  while (i < 4)
    v[i++] = 0;
  x_stop(v, t0);
  y_stop(v, t0);
  printf("t0\nxstart = %d\nxstop = %d\nystart = %d\nystop = %d\n", v[0], v[1], v[2], v[3]);  i = 0;
  while (i < 4)
    v[i++] = 0;
  x_stop(v, t1);
  y_stop(v, t1);
  printf("t1\nxstart = %d\nxstop = %d\nystart = %d\nystop = %d\n", v[0], v[1], v[2], v[3]);
  while (i < 4)
    v[i++] = 0;
  x_stop(v, t2);
  y_stop(v, t2);
  printf("t2\nxstart = %d\nxstop = %d\nystart = %d\nystop = %d\n", v[0], v[1], v[2], v[3]);
  while (i < 4)
    v[i++] = 0;
  x_stop(v, t3);
  y_stop(v, t3);
  printf("t3\nxstart = %d\nxstop = %d\nystart = %d\nystop = %d\n", v[0], v[1], v[2], v[3]);


  return 0;
}
