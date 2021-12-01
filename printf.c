#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int	myPrintf(char *str, ...);
int	isString(char *str);
int	isInt(int i);
int	putNbr(unsigned int i, int base);


int	putChar(char c)
{
	write(1, &c, 1);
	return(1);
}

int	main(void)
{
	int data = 1293;
	int min_int = -2147483648;
	printf("bytes printed %d\n", (myPrintf("%s\n", "Ave Cesare")));
	myPrintf("Bytes printed %d\n", (printf("%s\n", "Marco Aurelio")));
	myPrintf("here is a hex number %x\n", data);
	printf("bytes printed %d\n", (myPrintf("lowest int is %d\n", min_int)));
				
}

int	myPrintf(char *str, ...)
{
	int	i = 0;
	int	counter = 0;
	va_list	args;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == 's')
				counter += isString(va_arg(args, char *));
			if (str[i] == 'd')
				counter += isInt(va_arg(args, int));
			if (str[i] == 'x')
				counter += putNbr(va_arg(args, unsigned int), 16);
		}
		else
			counter += putChar(str[i]);
		i++;	
	}
	va_end(args);
	return (counter);
}

int	isString(char *str)
{
	int	i = 0;
	if (!str)
		str = "(null)";
	while (str[i])
	{
		putChar(str[i]);
		i++;
	}
	return (i);
}

int	isInt(int i)
{
	int	count = 0;
	if (i < 0)
	{
		i *= -1;
		count += putChar('-');
	}
	count += putNbr(i, 10);
	return (count);
}

int	putNbr(unsigned int i, int base)
{
	char	*arr = "0123456789abcdef";
	int		count = 0;
	int		n;
	if (i / base != 0)
		count += putNbr(i / base, base);
	n = i % base;
	if (base == 16)
		count += write(1, &arr[n], 1);
	else if (base == 10)
		count += write(1, &arr[n], 1);
	return (count);	
}
