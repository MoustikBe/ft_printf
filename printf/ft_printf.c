/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaac-c <misaac-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:58:08 by misaac-c          #+#    #+#             */
/*   Updated: 2024/02/20 23:12:04 by misaac-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_putchar(char s)
{
	write(1, &s, 1);
}

void ft_menu_variable(char *str, int count)
{
	if(str[count] == 'c') //Imprime que un seul caractere 
		printf("c");
	else if(str[count] == 's') //Imprime toutes une string
		printf("s");
	else if(str[count] == 'd') //Imprime un entier  
		printf("\nd\n");
	else if(str[count] == 'i') //Imprime un entier, mais peut convertir egalement des nbr recu dans differentes bases 
		printf("i");
	else if(str[count] == 'u') //Imprime un entier non signer en base décimale  
		printf("u");
	else if(str[count] == 'p') //Imrpime l'adresse du pointeur 
		printf("p");
	else if(str[count] == 'x') //Imprime en minuscule, le resultat de la convertion du nombre passer en hexa, donc par exemple on passe un int sa renvois sa valeur en hexa
		printf("x");
	else if(str[count] == 'X') //La meme que l'autre mais cette fois-ci en majscule
		printf("X");
	else if(str[count] == '%') //Imprime un signe %
		printf("%%");
}

int	ft_printf(const char *str, ...)
{
	int count = 0;
	while(str[count])
	{
		if(str[count] == '%')
			ft_menu_variable((char *)str, ++count);
		else
			ft_putchar(str[count++]);	
	}	
	return count;
}
int main(void)
{
	int result = ft_printf("ici c'est le dernier printte%dst"); 
	int result2 = printf("\ntest\n");
	printf("%d\n", result); 
	printf("%d\n", result2);
}