#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int	myPrintf(char *string, ...);
int putChar(char c);
int isString(char *str);
int isInt(int i);
int	putNbr(unsigned int i, int base); 

int	main(void)
{
	int data = 1293;
	int min_int = -2147483648;
	printf("bytes printed %d\n", (myPrintf("%s\n", "Ave Cesare")));
	myPrintf("Bytes printed %d\n", (printf("%s\n", "Marco Aurelio")));
	myPrintf("here is a hex number %x\n", data);
	printf("bytes printed %d\n", (myPrintf("lowest int is %d\n", min_int)));
				
}

int	myPrintf(char *string, ...)
{
	int counter = 0;
	int i = 0;
	va_list args;
	va_start(args, string);
	while (string[i])
	{
		if (string[i] == '%')
		{
			i++;
			if (string[i] == 's')
				counter += isString(va_arg(args, char *));
			if (string[i] == 'd')
				counter += isInt(va_arg(args, int));
			if (string[i] == 'x')
				counter += putNbr(va_arg(args, unsigned int), 16);
		}
		else
			counter += putChar(string[i]);
		i++;
	}
	va_end(args);
	return(counter);
}

int	putChar(char c)
{
	write(1, &c, 1);
	return (1);
}

int isString(char *str)
{
	int i = 0;
	if (!str)
		str = "(null)";
	while (str[i])
	{
		putChar(str[i]);
		i++;
	}
	return(i);
}

int isInt(int i)
{
	int count = 0;
	if (i < 0)
	{
		i *= -1;
	count += putChar('-');
	}
	count += putNbr(i, 10);
	return (count);
}

int putNbr(unsigned int i, int base)
{
	char *arr = "0123456789abcdef";
	int count = 0;
	int n;

	if (i / base != 0)
		count += putNbr(i / base, base);
	n = i % base;
	count += write(1, &arr[n], 1);
	return(count);
}
