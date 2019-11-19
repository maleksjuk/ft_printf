#include "../includes/ft_printf.h"

void	ft_right_part(char **str, int *i, double num, int precision)
{
	int		j;
	double	tmp;

	num *= 10;
	j = 0;
	(*str)[(*i)++] = '.';
	while (j++ < precision)
	{
		if (precision - j == 0)
		{
			tmp = (num - (int)num) * 10;
			if (tmp > 5)
				num += 1;
		}
		if ((int)num == 0)
		{
			(*str)[(*i)++] = '0';
			num *= 10;
			continue ;
		}
		(*str)[(*i)++] = (char)((int)num + 48);
		num = (num - (int)num) * 10;
	}
	(*str)[(*i)] = '\0';
}

void	ft_left_part(double *num, char **str, int *i, double modulo)
{
	while ((int)*num != 0)
	{
		(*str)[(*i)++] = (char)((*num / modulo) + 48);
		*num -= (int)(*num / modulo) * modulo;
		modulo /= 10;
	}
}

double	ft_modulo(double num)
{
	double modulo;

	modulo = 1;
	while ((int)(num /= 10) != 0)
		modulo *= 10;
	return (modulo);
}

int 	ft_f(t_printf **p)
{
//	int		len;
	int		i;
	char	*str;
	double	num;

	i = 0;
	num = (*p)->double_val; //va_arg((*p)->ap, double);
	str = (char *)malloc(sizeof(char) * (100));
	ft_left_part(&num, &str, &i, ft_modulo(num));
	ft_right_part(&str, &i, num, (*p)->precision);
	(*p)->final_str = str;
//	if (num == INFINITY)
//		(*p)->final_str = ft_strjoin((*p)->final_str, "inf");
//	else
//	{
//		len = len_nbr(num);
//		str = ft_strnew(len + (*p)->width + (*p)->precision + (*p)->space + 1);
//		if (!str)
//			return (1);
//		if ((*p)->plus && num > 0)                // FLAG +
//			str[i++] = '+'; //write(1, "+", 1);
//		if (num < 0)
//		{
//			str[i++] = '-'; //write(1, "-", 1);
//			num = num * (-1);
//		}
//		else if ((*p)->space && !(*p)->plus)    // FLAG space (_)
//			str[i++] = ' '; //write(1, " ", 1);
//		i += for_precision(p, len, &str[i]);
//		if ((*p)->zero)                            // FLAG 0
//			i += simvol_out(p, len, '0', &str[i]);
//		if ((*p)->width > len && !(*p)->minus)
//			i += simvol_out(p, len, ' ', &str[i]);
//		ft_strcpy(&str[i], ft_itoa(num));
//		if ((*p)->minus)                        // FLAG -
//			i += simvol_out(p, len, ' ', &str[i]);
//		(*p)->final_str = ft_strjoin((*p)->final_str, str);
//		free(str);
//	}
	return (0);
}