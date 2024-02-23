/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaac-c <misaac-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:58:08 by misaac-c          #+#    #+#             */
/*   Updated: 2024/02/23 19:33:10 by misaac-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_putchar(int s)
{
	write(1, &s, 1);
}

void ft_putstr(char * s)
{
	int i;

	i = 0; 
	while(s[i])
		ft_putchar((int)s[i++]);
}

void ft_putnbr(int nbr)
{
	unsigned int n; 
	
	if(nbr < 0)
	{
		ft_putchar('-');
		n = -nbr;
	}
	else 
		n = nbr; 
	if(n > 9)
	{
		ft_putnbr(n / 10);
		ft_putchar(n % 10 + '0'); 
	}
	else 
		ft_putchar(n + '0');
}

void ft_unsgined(unsigned nbr)
{	 
	if(nbr > 9)
	{
		ft_putnbr(nbr / 10);
		ft_putchar(nbr % 10 + '0'); 
	}
	else 
		ft_putchar(nbr + '0');
	
}

void ft_hexadecimal(unsigned long int nbr, char *hexa) // -- hexa = "123456789ABCDE" -- //
{
	if(nbr > 16)
		ft_hexadecimal(nbr / 16, hexa);
	ft_putchar(hexa[nbr % 16]);
}

void ft_ptr(void *x)
{
	unsigned int num; 

	num = (unsigned int)x;
	ft_putchar('0');
	ft_putchar('x');
	ft_hexadecimal(num, "0123456789abcdef");
}


void ft_menu_variable(char *str, va_list *argv, int count)
{
	if(str[count] == 'c') // -- Imprime que un seul caractere  -- // 
		ft_putchar(va_arg(*argv, int));
	else if(str[count] == 's') // -- Imprime toutes une string -- //
		ft_putstr(va_arg(*argv, char *));
	else if(str[count] == 'd' || str[count] == 'i') // -- Imprime un entier -- //
		ft_putnbr(va_arg(*argv, int));
	else if(str[count] == 'u') // -- Imprime un entier non signer en base décimale -- //
		ft_unsgined(va_arg(*argv, unsigned int));
	else if(str[count] == 'p') // -- Imrpime l'adresse du pointeur -- //
		ft_ptr(va_arg(*argv, void *));
	else if(str[count] == 'x') // -- Imprime en minuscule, le resultat de la convertion du nombre passer en hexa, donc par exemple on passe un int sa renvois sa valeur en hexa -- //
		ft_hexadecimal(va_arg(*argv, unsigned long int), "0123456789abcdef");
	else if(str[count] == 'X') // -- La meme que l'autre mais cette fois-ci en majscule -- //
		ft_hexadecimal(va_arg(*argv, unsigned long int), "0123456789ABCDEF");
	else if(str[count] == '%') // -- Imprime un signe % -- //
		ft_putchar('%');
}

int	ft_printf(const char *str, ...)
{
	va_list argv;
	int count = 0;
	
	va_start(argv, str);
	while(str[count])
	{
		if(str[count] == '%')
		{
			ft_menu_variable((char *)str, &argv, ++count);
			count++;
		}
		else
			ft_putchar((int)str[count++]);	
	}
	va_end(argv);	
	return count;
}
int main(void)
{
	int one = 'a';
	char *str = "Bonjour comment ça va ?";
	char *test = "Tranquille ";
	int nbr =  -7585;
	int result = ft_printf("le porjet  : %s \n", str); 
	int result2 = printf("l'original : %s \n", str);
	printf("%d\n", result); 
	printf("%d\n", result2);
}
