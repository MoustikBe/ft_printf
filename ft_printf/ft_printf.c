/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaac-c <misaac-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:58:08 by misaac-c          #+#    #+#             */
/*   Updated: 2024/02/24 17:28:59 by misaac-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_putchar(int s, int *count_2)
{
	int tchek;
	
	tchek = write(1, &s, 1);
	if(tchek < 0)
	{
		(*count_2) = -1;
		return ;
	}
	(*count_2)++;
}

void ft_putstr(char * s, int *count_2)
{
	int i;

	i = 0;
	if (s == NULL)
	{
		ft_putstr("(null)", count_2);
		return ;
	}
	while(s[i])
		ft_putchar((int)s[i++], count_2);
}

void ft_putnbr(int nbr, int *count_2)
{
	unsigned int n; 
	
	if(nbr < 0)
	{
		ft_putchar('-', count_2);
		n = -nbr;
	}
	else 
		n = nbr; 
	if(n > 9)
	{
		ft_putnbr(n / 10, count_2);
		ft_putchar(n % 10 + '0', count_2); 
	}
	else 
		ft_putchar(n + '0', count_2);
}

void ft_unsgined(unsigned nbr, int *count_2)
{	 
	if(nbr > 9)
	{
		ft_putnbr(nbr / 10, count_2);
		ft_putchar(nbr % 10 + '0', count_2); 
	}
	else 
		ft_putchar(nbr + '0', count_2);
	
}

void ft_hexadecimal(unsigned int nbr, char *hexa, int *count_2) // -- hexa = "123456789ABCDE" -- //
{
	if(nbr >= 16)
		ft_hexadecimal(nbr / 16, hexa, count_2);
	ft_putchar(hexa[nbr % 16], count_2);
}

// -- Partie pointeur -- // 
void ft_ptr_hexa(size_t nbr, char *hexa, int *count_2) // -- hexa = "123456789ABCDE" -- //
{
	if(nbr >= 16)
		ft_ptr_hexa(nbr / 16, hexa, count_2);
	ft_putchar(hexa[nbr % 16], count_2);
}

void ft_ptr(size_t num, int *count_2)
{ 
	ft_putstr("0x", count_2);
	ft_ptr_hexa(num, "0123456789abcdef", count_2);
}
// -- Partie pointeur -- // 

void ft_menu_variable(char *str, va_list *argv, int count, int *count_2)
{
	if(str[count] == 'c') // -- Imprime que un seul caractere  -- // 
		ft_putchar(va_arg(*argv, int), count_2);
	else if(str[count] == 's') // -- Imprime toutes une string -- //
		ft_putstr(va_arg(*argv, char *), count_2);
	else if(str[count] == 'd' || str[count] == 'i') // -- Imprime un entier -- //
		ft_putnbr(va_arg(*argv, int), count_2);
	else if(str[count] == 'u') // -- Imprime un entier non signer en base décimale -- //
		ft_unsgined(va_arg(*argv, unsigned int), count_2);
	else if(str[count] == 'p') // -- Imrpime l'adresse du pointeur -- //
		ft_ptr(va_arg(*argv, size_t), count_2);
	else if(str[count] == 'x') // -- Imprime en minuscule, le resultat de la convertion du nombre passer en hexa, donc par exemple on passe un int sa renvois sa valeur en hexa -- //
		ft_hexadecimal(va_arg(*argv, unsigned int), "0123456789abcdef", count_2);
	else if(str[count] == 'X') // -- La meme que l'autre mais cette fois-ci en majscule -- //
		ft_hexadecimal(va_arg(*argv, unsigned int), "0123456789ABCDEF", count_2);
	else if(str[count] == '%') // -- Imprime un signe % -- //
		ft_putchar('%', count_2);
	else
	{	
		(*count_2) = -1;
		return;
	}
}

int	ft_printf(const char *str, ...)
{
	va_list argv;
	int count;
	int count_2;

	count = 0;
	count_2 = 0;
	va_start(argv, str);
	while(str[count])
	{
		if(str[count] == '%')
		{
			ft_menu_variable((char *)str, &argv, ++count, &count_2);
			count++;
		}
		else
			ft_putchar((int)str[count++], &count_2);	
	}
	va_end(argv);	
	return count_2;
}
/*
int main(void)
{
	int one = 'a';
	char *str = "";
	char *test = "Tranquille ";
	int nbr =  7585;
	int *n = &nbr;
	int result = ft_printf("\nLe mien    : %p ", str); 
	int result2 = printf("\nL'original : %p ", str);
	printf("%d\n", result); 
	printf("%d\n", result2);
}
*/







