/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalazs <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:04:11 by rbalazs           #+#    #+#             */
/*   Updated: 2023/12/13 11:04:13 by rbalazs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (c < '0' || c > '9')
		return (0);
	return (1);
}

/*
#include <stdio.h>
#include <ctype.h>
int main()
{
	printf("%d\n", ft_isdigit('0'));
  printf("%d\n", isdigit('0'));
}
*/
