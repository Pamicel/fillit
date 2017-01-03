

////////////////////////////////////////////////////////////////////////////////
////////  DEBUG   //////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

static char *bigger_mother_fucker(char *str, int n_digits)
{
  char *new;
  int n = ft_strlen(str);
  if (n < n_digits)
  {
      new = ft_strnew(n_digits);
      ft_strcpy(&(new[n_digits - n]), str);
      for (int i = 0; i < n_digits - n; i++)
          new[i] = '0';
      return (new);
  }
  return (str);
}

static void print(unsigned short *us, int size)
{
  for(int i = 0; i < size; i++)
      printf("%s\n", bigger_mother_fucker(ft_itoa_base(us[i], 2), 16));
}

static void print_at(t_tro tetro, int shift, t_map map, int index)
{
  ft_print_tetro_on_map(tetro, shift, map, index);
  print(map, 16);
}

////////////////////////////////////////////////////////////////////////////////
////////  DEBUG   //////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
// int main(void)
// {
// 	int ind[5];
//
// 	t_tro tetro_0 = {0b1100000000000000, 0b1000000000000000, 0b1000000000000000, 0b0000000000000000, 0b0000000000000000, 0b0000000000000000};
// 	t_tro tetro_1 = {0b1100000000000000, 0b0100000000000000, 0b0100000000000000, 0b0000000000000000, 0b0000000000000000, 0b0000000000000000};
// 	t_tro tetro_2 = {0b1100000000000000, 0b0100000000000000, 0b0100000000000000, 0b0000000000000000, 0b0000000000000000, 0b0000000000000000};
// 	unsigned short map[] = {0b0000000000000000, 0b0000000000000000, 0b0000000000000000, 0b0000000000000000,\
// 		0b0000000000000000, 0b0000000000000000, 0b0000000000000000, 0b0000000000000000,\
// 			0b0000000000000000, 0b0000000000000000, 0b0000000000000000, 0b0000000000000000,\
// 			0b0000000000000000, 0b0000000000000000, 0b0000000000000000, 0b0000000000000000};
// 	t_tro tetros[3];
// 	ft_memcpy(tetros[0], tetro_0, sizeof(t_tro));
// 	ft_memcpy(tetros[1], tetro_1, sizeof(t_tro));
// 	ft_memcpy(tetros[2], tetro_2, sizeof(t_tro));
// 	// int shift = 0;
// 	// int index = 0;
// 	// int size = 5;
//
// 	int n = ft_fillit(tetros, 3);
// 	ft_print_result(tetros, 3, n);
//
// 	// ind[4] = 4;
// 	// ind[3] = 0;
// 	// ind[2] = 0;
// 	// ind[1] = 0;
// 	// ind[0] = 3;
// 	//
// 	// printf("\e[31m");
// 	// print(map, 16);
// 	// printf("\e[0m");
// 	// ft_solve(tetros, map, ind);
// 	// printf("\e[31m");
// 	// print(map, 16);
// 	// printf("\e[0m");
// 	//
// 	// for (int i = 0; i < 3; i++)
// 	// {
// 	// 	printf("tetros[%d]\n", i);
// 	// 	printf("x = %d, y = %d\n\n", (int)(tetros[i][4]), (int)(tetros[i][5]));
// 	// }
//
// 	// do {
// 	// 	printf("index = %d\n", index);
// 	// 	printf("shift = %d\n", shift);
// 	// 	printf("print_at(tetro, %d, map, %d);\n", shift, index);
// 	// 	print_at(tetro, shift, map, index);
// 	//   ft_erase_tetro_from_map(tetro, shift, map, index);
// 	// } while (ft_move_tetro(tetro, &shift, &index, size));
// }



///////////////////////////////////////////////////////////////////////////////
//      ft_get_tetro.c
//

/*
// // // // // // // // // // // // // // // // // // // // // // // // // // //

// // // // // // //
#include <stdio.h>
// // // // // // //

////////////////////////////////////////////////////////////////////////////////
////////  DEBUG   //////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

static char *bigger_mother_fucker(char *str, int n_digits)
{
  char *new;
  int n = ft_strlen(str);
  if (n < n_digits)
  {
	  new = ft_strnew(n_digits);
	  ft_strcpy(&(new[n_digits - n]), str);
	  for (int i = 0; i < n_digits - n; i++)
		  new[i] = '0';
	  return (new);
  }
  return (str);
}

static void print(unsigned short *us, int size)
{
  for(int i = 0; i < size; i++)
	  printf("%s\n", bigger_mother_fucker(ft_itoa_base(us[i], 2), 16));
}

////////////////////////////////////////////////////////////////////////////////
////////  /DEBUG   /////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
////////  IMPORTÉ DE FT_READ_FILE   ////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

static unsigned short *ft_create_pieces(void)
{
	unsigned short	*all_pieces;

	all_pieces = (unsigned short*)ft_memalloc(sizeof(unsigned short) * 19 * 4);
	if (!all_pieces)
		return (NULL);
	ft_memcpy(all_pieces,\
		(unsigned short[19 * 4]){16384, 57344, 0, 0, 16384, 49152, 16384, 0, \
		57344, 16384, 0, 0, 32768, 49152, 32768, 0, 32768, 49152, 16384, 0, \
		49152, 24576, 0, 0, 16384, 49152, 32768, 0, 24576, 49152, 0, 0, \
		32768, 32768, 32768, 32768, 61440, 0, 0, 0, 49152, 49152, 0, 0, \
		49152, 32768, 32768, 0, 16384, 16384, 49152, 0, 57344, 8192, 0, 0, \
		32768, 57344, 0, 0, 49152, 16384, 16384, 0, 32768, 32768, 49152, 0,\
		8192, 57344, 0, 0, 57344, 32768, 0, 0},\
		sizeof(unsigned short) * 19 * 4);
	return (all_pieces);
}

////////////////////////////////////////////////////////////////////////////////
////////  /IMPORTÉ DE FT_READ_FILE   ///////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

int main(void)
{
	char *tetro_str = "##..\n.##.\n....\n....\n";
	t_tro tetro;

	ft_memset(tetro, 0, sizeof(t_tro));

	ft_get_tetro(tetro_str, ft_create_pieces(), tetro);
	print(tetro, 6);
	return 0;
}
*/
