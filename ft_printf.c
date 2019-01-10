/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaoliiny <kaoliiny@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 20:04:57 by kaoliiny          #+#    #+#             */
/*   Updated: 2019/01/10 17:23:54 by kaoliiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static void print_buff(t_format *f)
{
	ft_putstr(f->buff);
}

bool	manage_buff(int c, t_format *f)
{
	(c != 0) ? f->buff[f->sum++] = c : 0;
	if (!f->sum % BUFF_SIZE)
	{
		ft_bzero(&f->buff, 4096);
		print_buff(f);
	}
	return (true);
}

bool	manage_flags(const char **str, t_format *f)
{
	return ((**str == '0' && (f->fl.zero = true))
	|| (**str == '+' && (f->fl.plus = true))
	|| (**str == '-' && (f->fl.minus = true))
	|| (**str == ' ' && (f->fl.space = true))
	|| (**str == '#' && (f->fl.hash = true))
	|| (**str == 'j' && (f->fl.j = true))
	|| (**str == 'z' && (f->fl.z = true))
	|| (**str == 'L' && (f->fl.lll = true))
	|| (**str == 'l' && (f->fl.l = true))
	//	&& *str[1] == 'l' && ++(*str) && (f->fl.ll = true))
	|| (**str == 'h' && (f->fl.h = true)));
	//&& *str[1] == 'h' && ++(*str) && (f->fl.hh = true));
}

void	manage_field(const char *str, va_list ap, t_format *f)
{
	int tmp;

	while (*str)
	{
		if (*str == '%' && *(++str))
		{
			while (*str)
				if (manage_flags(&str, f))
					str++;
				else if ((tmp = ft_atoi(str)))
					str += int_size((f->fl.min_width = tmp));
				else if (*str == '.' && (tmp = ft_atoi(++str)))
					str += int_size((f->fl.precision = tmp));
				else
				{
					check_conv(str++, f);
					ft_bzero(&f->fl, sizeof(flags));
					break ;
				}
		}
		else
			manage_buff(*str++, f);
	}
}

int		ft_printf(const char *format, ...)
{
	t_format	f;

	ft_bzero(&f, sizeof(t_format));
	f.buff = (char *)malloc(sizeof(char) * BUFF_SIZE);
	va_start(f.ap, format);
	manage_field(format, f.ap, &f);
	va_end(f.ap);
	print_buff(&f);
	return (f.sum);
}



int main()
{
// 	ft_printf("%L.312f|\n", 127.3143L);
// 	   printf("%L.312f|\n", 127.3143L);
// 	ft_printf("%3.12f|\n", 127.31643);
// 	   printf("%3.12f|\n", 127.31643);

// 		ft_printf("%-48.5f|\n", 63.055);
// 	  printf("%-48.5f|\n", 63.055);
// 	  	ft_printf("%0100.20f|\n", 42.424242424242);
// 	  printf("%0100.20f|\n", 42.424242424242);
// 	  	ft_printf("%f|\n", 0);
// 		printf("%f|\n", 0);
// 	  	ft_printf("%#33.12f|\n", 0);
// 	   printf("%#33.12f|\n", 0);
// 	   	ft_printf("%-#.20f|\n", 11.6);
// 	   printf("%-#.20f|\n", 11.6);

// 		printf("%100.20f|\n", 142.512414);
// 		ft_printf("%100.20f|\n", 142.512414);
// 		printf("%-100.20f|\n", 142.512414);
// 		ft_printf("%-100.20f|\n", 142.512414);
// 		printf("% -10.200f|\n", 142.512414);
// 		ft_printf("% -10.200f|\n", 142.512414);
// 		printf("%+-100.20f|\n", 142.512414);
// 		ft_printf("%+-100.20f|\n", 142.512414);
// 		printf("%+100.20f|\n", -142.512414);
// 		ft_printf("%+100.20f|\n", -142.512414);
// 		printf("%100.20f|\n", -142.512414);
// 		ft_printf("%100.20f|\n", -142.512414);
// 		printf("%100.20f|\n", 142.512414);
// 		ft_printf("%100.20f|\n", 142.512414);
// 		printf("%+100.20f|\n", 142.512414);
// 		ft_printf("%+100.20f|\n", 142.512414);
// printf("\n");


	// printf("%31.2f|\n", 127.3143);
	// 	ft_printf("%L.312f|\n", 127.3143L);
	// printf("%L.312f|\n", 127.3143L);
	// 	ft_printf("%L.312f|\n", 127.3143L);
	// printf("%L.312f|\n", 127.3143L);
//	printf("%zu|\n", 184467.44073709551614);	
	// printf("%zu|\n", 18446744073709551614);
	// ft_printf("%zu|\n", 18446744073709551614);

// 		printf("%100.20d|\n", 124141);
// 		ft_printf("%100.20d|\n", 124141);
// 		printf("%-100.20d|\n", 124141);
// 		ft_printf("%-100.20d|\n", 124141);
// 		printf("% -10.200d|\n", 124141);
// 		ft_printf("% -10.200d|\n", 124141);
// 		printf("%+-100.20d|\n", 124141);
// 		ft_printf("%+-100.20d|\n", 124141);
// 		printf("%+100.20d|\n", -124141);
// 		ft_printf("%+100.20d|\n", -124141);
// 		printf("%100.20d|\n", -124141);
// 		ft_printf("%100.20d|\n", -124141);
// 		printf("%100.20d|\n", 124141);
// 		ft_printf("%100.20d|\n", 124141);
// 		printf("%+100.20d|\n", 124141);
// 		ft_printf("%+100.20d|\n", 124141);
// printf("\n");
// 		printf("%#33.20x|\n", 37732);
// 		ft_printf("%#33.20x|\n", 37732);
// 		printf("%#20x|\n", 37732);
// 		ft_printf("%#20x|\n", 37732);
// 		printf("%#100.20x|\n", 37732);
// 		ft_printf("%#100.20x|\n", 37732);
// 		printf("%#0100x|\n", 37732);
// 		ft_printf("%#0100x|\n", 37732);
// 		printf("%#-100.20X|\n", 124141);
// 		ft_printf("%#-100.20X|\n", 124141);
// 		printf("%#-100.20x|\n", 124141);
// 		ft_printf("%#-100.20x|\n", 124141);
// printf("\n");

// 		printf("%.20u|\n", 37732);
// 		ft_printf("%.20u|\n", 37732);
// 		printf("%20u|\n", 37732);
// 		ft_printf("%20u|\n", 37732);
// 		printf("%100.20u|\n", 37732);
// 		ft_printf("%100.20u|\n", 37732);
// 		printf("%0100u|\n", 37732);
// 		ft_printf("%0100u|\n", 37732);
// printf("\n");
// 		printf("%.20d|\n", 37732);
// 		ft_printf("%.20d|\n", 37732);
// 		printf("%20d|\n", 37732);
// 		ft_printf("%20d|\n", 37732);
// 		printf("%100.20d|\n", 37732);
// 		ft_printf("%100.20d|\n", 37732);
// 		printf("%0100d|\n", 37732);
// 		ft_printf("%0100d|\n", 37732);
// printf("\n");
// 		printf("%5d|\n", -42);
// 		ft_printf("%5d|\n", -42);
// 		printf("%-5d|\n", -42);
// 		ft_printf("%-5d|\n", -42);
// 		printf("%05d|\n", -42);
// 		ft_printf("%05d|\n", -42);

// 		printf("%25.5d|\n", -42);
// 		ft_printf("%25.5d|\n", -42);
// 		printf("%-25.5d|\n", -42);
// 		ft_printf("%-25.5d|\n", -42);
// printf("\n");
// 		printf("%.20d|\n", 0);
// 		ft_printf("%.20d|\n", 0);
// 		printf("%20d|\n", 0);
// 		ft_printf("%20d|\n", 0);
// 		printf("%100.20d|\n", 0);
// 		ft_printf("%100.20d|\n", 0);
// 		printf("%0100d|\n", 0);
// 		ft_printf("%0100d|\n", 0);
// printf("\n");
// 		printf("%#3.20x|\n", 0);
// 		ft_printf("%#.20x|\n", 0);
// 		printf("%#-20x|\n", 0);
// 		ft_printf("%#-20x|\n", 0);
// 		printf("%#100.20x|\n", 0);
// 		ft_printf("%#100.20x|\n", 0);
// 		printf("%#0100x|\n", 0);
// 		ft_printf("%#0100x|\n", 0);
// printf("\n");
// 													printf("%#.20o|\n", 37732);
// 													ft_printf("%#.20o|\n", 37732);
// 													printf("%#20o|\n", 37732);
// 													ft_printf("%#20o|\n", 37732);
// 													printf("%#100.20o|\n", 37732);
// 													ft_printf("%#100.20o|\n", 37732);
// 													printf("%#0100o|\n", 37732);
// 													ft_printf("%#0100o|\n", 37732);
// 												printf("\n");
// 													printf("%#.20o|\n", 0);
// 													ft_printf("%#.20o|\n", 0);
// 													printf("%#20o|\n", 0);
// 													ft_printf("%#20o|\n", 0);
// 													printf("%#100.20o|\n", 0);
// 													ft_printf("%#100.20o|\n", 0);
// 													printf("%#0100o|\n", 0);
// 													ft_printf("%#0100o|\n", 0);
// 												printf("\n");
// 												printf("@moulitest: %#.o|\n", 0);
// 												ft_printf("@moulitest: %#.o|\n", 0);
// 												printf("@moulitest: %#.o|\n", 1);
// 												ft_printf("@moulitest: %#.o|\n", 1);
// 		printf("%5d|\n", 0);
// 		ft_printf("%5d|\n", 0);
// 		printf("%-5d|\n", 0);
// 		ft_printf("%-5d|\n", 0);
// 		printf("%05d|\n", 0);
// 		ft_printf("%05d|\n", 0);
// 		printf("%25.5d|\n", 0);
// 		ft_printf("%25.5d|\n", 0);
// 		printf("%-25.5d|\n", 0);
// 		ft_printf("%-25.5d|\n", 0);
// 		printf("%5.5d|\n", 0);
// 		ft_printf("%5.5d|\n", 0);
// 		printf("%x|\n", 0);
// 		ft_printf("%x|\n", 0);
// 		printf("%o|\n", 0);
// 		ft_printf("%o|\n", 0);
// 		printf("%u|\n", 0);
// 		ft_printf("%u|\n", 0);
// 		printf("%d|\n", 0);
// 		ft_printf("%d|\n", 0);
// printf("\n");
// 		printf("%d\n", 42);
// 		ft_printf("%d\n", 42);
// 		printf("%d%d\n", 42, 41);
// 		ft_printf("%d%d\n", 42, 41);
// 		printf("%d%d%d\n", 42, 43, 44);
// 		ft_printf("%d%d%d\n", 42, 43, 44);
// 		printf("%ld\n", 2147483647);
// 		ft_printf("%ld\n", 2147483647);
// 		printf("%lld\n", 9223372036854775807);
// 		ft_printf("%lld\n", 9223372036854775807);
// 		printf("%x\n", 505);
// 		ft_printf("%x\n", 505);
// 		printf("%X\n", 505);
// 		ft_printf("%X\n", 505);
// 		printf("%20.15d\n", 54321);
// 		ft_printf("%20.15d\n", 54321);
// 		printf("%-10d\n", 3);
// 		ft_printf("%-10d\n", 3);
// 		printf("% d\n", 3);
// 		ft_printf("% d\n", 3);
// 		printf("%+d\n", 3);
// 		ft_printf("%+d\n", 3);
// 		printf("%010d\n", 1);
// 		ft_printf("%010d\n", 1);
// 		printf("%jd\n", 9223372036854775807);
// 		ft_printf("%jd\n", 9223372036854775807);
// 		printf("%zd\n", 4294967295);
// 		ft_printf("%zd\n", 4294967295);
// 		printf("%U\n", 4294967295);
// 		ft_printf("%U\n", 4294967295);
// 		printf("%u\n", 4294967295);
// 		ft_printf("%u\n", 4294967295);
// 		printf("%o\n", 40);
// 		ft_printf("%o\n", 40);
// 		printf("%x\n", 1000);
// 		ft_printf("%x\n", 1000);
// 		printf("%#X\n", 1000);
// 		ft_printf("%#X\n", 1000);
// printf("\n\n");

		// printf("%hhd\n", 0);
		// ft_printf("%hhd\n", 0);
// printf("\n");

// 		printf("%#.x|\n", 0);
// 		ft_printf("%#.x|\n", 0);
// 		printf("%#.o|\n", 0);
// 		ft_printf("%#.o|\n", 0);
// 		printf("%#.u|\n", 0);
// 		ft_printf("%#.u|\n", 0);
// 		printf("%#.d|\n", 0);
// 		ft_printf("%#.d|\n", 0);
// printf("\n");

		printf("%.x|\n", 0);
		ft_printf("%.x|\n", 0);
		printf("%.o|\n", 0);
		ft_printf("%.o|\n", 0);
		printf("%.u|\n", 0);
		ft_printf("%.u|\n", 0);
		printf("%.d|\n", 0);
		ft_printf("%.d|\n", 0);
printf("\n\n");

		printf("%p\n", &ft_printf);
		ft_printf("%p\n", &ft_printf);
		printf("%p\n", NULL);
		ft_printf("%p\n", NULL);
		printf("%.p\n", NULL);
		ft_printf("%.p\n", NULL);
		printf("%#.p\n", NULL);
		ft_printf("%#.p\n", NULL);
printf("\n");
	char	c[] = "sdfds";
		printf("%p\n", c);
		ft_printf("%p\n", c);
		printf("%p\n", "sddfgsd");
		ft_printf("%p\n", "sddfgsd");
printf("\n\n");

// 		printf("%\n");
// 		ft_printf("%\n");
// 		printf("%d%d%d%d%d\n", 1, -2, 3, -4, 5);
// 		ft_printf("%d%d%d%d%d\n", 1, -2, 3, -4, 5);
// 		printf("%hhd\n", 127 + 42);
// 		ft_printf("%hhd\n", 127 + 42);
// 		printf("{%03.2d}\n", 0);
// 		ft_printf("{%03.2d}\n", 0);
// 		printf("%o, %ho, %hho\n", -42, -42, -42);
// 		ft_printf("%o, %ho, %hho\n", -42, -42, -42);
// 		printf("%hhu, %hhu\n", 0, 127 + 42);
// 		ft_printf("%hhu, %hhu\n", 0, 127 + 42);
// 		printf("@moulitest: %5.o %5.0o|\n", 0, 0);
// 		ft_printf("@moulitest: %5.o %5.0o|\n", 0, 0);
// 		printf("%5.0o|\n", 0);
// 		ft_printf("%5.0o|\n", 0);
// 		printf("@moulitest: %5.d %5.0d|\n", 0, 0);
// 		ft_printf("@moulitest: %5.d %5.0d|\n", 0, 0);

}
