#include <stdio.h>
#include "ft_printf.h"

int main(int ac, char **av)
{
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
   printf("1 Char : %c %c\n", 'a', 19);
   ft_printf("ft_1 Char : %c %c\n", 'a', 19);
   printf("1 string : %s\n", "l'ecole c'est cool");
   ft_printf("ft_1 string : %s\n", "l'ecole c'est cool");
   int  i = 19;
   void *s = "Norman";
   printf("Pointer : %p\n", (char *)s);
   ft_printf("ft_Pointer : %p\n", (char *)s);
   printf("Int : %d %i\n", 19, 19);
   ft_printf("ft_Int : %d %i\n", 19, 19);
   printf("Unsigned Int : %u\n", 19);
   ft_printf("ft_Unsigned Int : %u\n", 19);
   printf("Hexa min MAJ : %x %X\n", i, i);
   ft_printf("ft_Hexa min MAJ : %x %X\n", i, i);
   printf("Pourcent : %%\n");
   ft_printf("ft_Pourcent : %%\n");

   
}