#include <stdio.h>
#include <unistd.h>
#include <string.h>


int ft_atoi(char *string)
{
	int i = 0;
	int num = 0;

	while (string[i])
	{
		num = num * 10 + string[i] - '0';
		i++;
	}
	return (num);
}

void	putnbr(int n)
{
	if (n >= 10)
		putnbr(n / 10);
	char digit = n % 10 + '0';
	write(1, &digit, 1);
}
int main(int argc, char **argv)
{
	int sum;
	int num;
	int i = 2;

	sum = 0;

	if (argc == 2 && argv[1] && argv[1][0] != '-')
	{
		num = ft_atoi(argv[1]);
		if (num <= 1)
		{
			num = 0;
		}
		else
		{
			while (i * i <= num)
			{
				if (num % i == 0)
				{
					i = 0;
					break ;
				}
				i++;
			}
			sum = i;
		}
	}
	putnbr(sum);
	write(1, "\n", 1);
	return (0);
}
