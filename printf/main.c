#include <stdio.h>
#include "ft_printf.h"

int main(int ac, char **av)
{
   int  i = 1942989;
   int *ptr = malloc(sizeof(int));
   void *s = "Norman";

   int res = printf("1 Char : %c %c\n", 'a', 19);
   int res2 = ft_printf("ft_1 Char : %c %c\n", 'a', 19);
   printf("res = %d et ft_res = %d\n", res, res2);
   int res3 = printf("1 string : %s\n", "l'ecole c'est cool");
   int res4 = ft_printf("ft_1 string : %s\n", "l'ecole c'est cool");
   printf("res = %d et ft_res = %d\n", res3, res4);
   int res5 = printf("___Pointer : %p\n", ptr);
   int res6 = ft_printf("ft_Pointer : %p\n", ptr);
   printf("res = %d et ft_res = %d\n", res5, res6);
   int res7 = printf("Int : %d %i\n", 19, 19);
   int res8 = ft_printf("ft_Int : %d %i\n", 19, 19);
   printf("res = %d et ft_res = %d\n", res7, res8);
   int res9 = printf("Unsigned Int : %u\n", 19);
   int res10 = ft_printf("ft_Unsigned Int : %u\n", 19);
   printf("res = %d et ft_res = %d\n", res9, res10);
   int res11 = printf("Hexa min MAJ : %x %X\n", i, i);
   int res12 = ft_printf("ft_Hexa min MAJ : %x %X\n", i, i);
   printf("res = %d et ft_res = %d\n", res11, res12);
   int res13 = printf("Pourcent : %%\n");
   int res14 = ft_printf("ft_Pourcent : %%\n");
   printf("res = %d et ft_res = %d\n", res13, res14);

}


    /*ft_printf("ft_%d et %s\n", -42, "ok cool");
    printf("%d et %s", -42, "ok cool");

   printf ("Characters: %c %c \n", 'a', 65);
   ft_printf ("ft_Characters: %c %c \n", 'a', 65);
   printf ("Decimals: %d %ld\n", 1977, 650000L);
   ft_printf ("ft_Decimals: %d %ld\n", 1977, 650000L);
   printf ("Preceding with blanks: %10d \n", 1977);
   ft_printf ("ft_Preceding with blanks: %10d \n", 1977);
   printf ("Preceding with zeros: %010d \n", 1977);
   ft_printf ("ft_Preceding with zeros: %010d \n", 1977);
   printf ("Some different radices: %d %x %o %#x %#o \n", 100, 100, 100, 100, 100);
   ft_printf ("ft_Some different radices: %d %x %o %#x %#o \n", 100, 100, 100, 100, 100);
   printf ("floats: %4.2f %+.0e %E \n", 3.1416, 3.1416, 3.1416);
   ft_printf ("ft_floats: %4.2f %+.0e %E \n", 3.1416, 3.1416, 3.1416);
   printf ("Width trick: %*d \n", 5, 10);
   ft_printf ("ft_Width trick: %*d \n", 5, 10);
   printf ("%s \n", "A string");
   ft_printf ("%s \n", "ft_A string");
*/