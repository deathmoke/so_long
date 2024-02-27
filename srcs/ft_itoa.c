/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccadoret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 10:02:09 by ccadoret          #+#    #+#             */
/*   Updated: 2023/09/10 11:04:15 by ccadoret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../includes/so_long.h"
#include "../includes/get_next_line.h"

int	size_nb(int n)
{
	if (n < 0)
		n = -n;
	if (n < 10)
		return (1);
	return (1 + size_nb(n / 10));
}

void	reverse_string(char *str)
{
	int		start;
	int		end;
	char	temp;

	start = 0;
	end = ft_strlen(str) - 1;
	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}

char	*int_to_str(char *str, int num)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	if (num == 0)
	{
		str[i++] = '0';
		str[i] = '\0';
		return (str);
	}
	if (num < 0)
	{
		sign = -1;
		num = -num;
	}
	while (num > 0)
	{
		str[i++] = '0' + (num % 10);
		num /= 10;
	}
	if (sign == -1)
		str[i++] = '-';
	str[i] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;

	if (n == -2147483648)
	{
		str = (char *)malloc(12 * sizeof(char));
		str = int_to_str(str, -214748364);
		reverse_string(str);
		str[10] = '8';
		str[11] = '\0';
		return (str);
	}
	if (n >= 0)
		str = (char *)malloc((size_nb(n) + 1) * sizeof(char));
	if (n < 0)
		str = (char *)malloc((size_nb(n) + 2) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str = int_to_str(str, n);
	reverse_string(str);
	return (str);
}
/*
int main() {
    int num = -2147483648LL;
    char *str = ft_itoa(num);
    if (str != NULL) {
        printf("Chiffre converti en chaîne de caractères : %s\n", str);
        free(str);
    } else {
        printf("Échec de l'allocation mémoire.\n");
    }

    return 0;
}
*/