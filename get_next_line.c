#include <unistd.h>
#include <stdlib.h>

int	strLen(char *s)
{
	int i = 0;
	if(!s)
		return(NULL);
	while(s[i])
		i++;
	return(i);
}

char	*strJoin(char *s1, char *s2)
{
	int	i = 0;
	int j = 0;
	char	*newS;
	newS = (char *)malloc(sizeof(char) * (strLen(s1) + strlen(s2) + 1));
	if(!newS)
		return(NULL);
	while(s1[i])
	{
		newS[i] = s1[i];
		i++;
	}
	while(s2[j])
	{
		newS[i + j] = s2[j];
		j++;
	}
	newS[i + j] = '\0';
	return(newS);
}

char	*strDup(char *s)
{
	int i = 0;
	char *duplicate;
	duplicate = (char *)malloc(sizeof(char) * strLen(s) + 1);
	if(!duplicate)
		return(NULL);
	while(s[i])
	{
		duplicate[i] = s[i];
		i++;
	}
	duplicate[i] = '\0';
	return(duplicate);
}

char	*subStr(char *s, int start, int len)
{
	int i = 0;
	int j = 0;
	char newS;
	newS = (char *)malloc(sizeof(char) * len + 1);
	if(!newS)
		return(NULL);
	while(s[i])
	{
		if(i <= start && j < len)
			newS[j++] = s[i];
		i++
	}
	newS[j] = '\0';
	return(newS);
}

char	*hasNL(char *s)
{
	while(s[i])
	{
		if(s[i] == '\n')
			return((char *)s);
		s++;
	}
	return(NULL);
}

static char readAppend(int fd, char *buffer, char leftovers)
{
	bytesRd = 1;
	char *temp;

	while(bytesRd != 0)
	{
		bytesRd = read(fd, buffer, BUFFER_SIZE)
		if(bytesRd == -1)
			return(NULL);
		if(bytesRd == 0)
			break ;
		if(!leftovers)
			leftovers = strDup(" ");
		temp = leftovers;
		leftovers = strJoin(temp, buffer);
		free(temp);
		temp = NULL;
		if(hasNL(buffer))
			break ;
	}
	return(leftovers);
}

static char updateFormat(*line)
{
	int i = 0;
	char *leftovers

	while(line[i] && line[i] != '\n')
		i++;
	if(line[i] == '\0' || line[1] == '\0')
		return(NULL);
	leftovers = subStr(line, i + 1, strlen(line) - i);
	if(*leftovers == '\0')
	{
		free(leftovers);
		leftovers = NULL;
	}
	line[i + 1] = '\0';
	return(leftovers);
}

char	*get_next_line(fd)
{
	char *line;
	char *buffer; 
	static char *leftovers;

	if(fd < 0 || BUFFER_SIZE <= 0)
		return(NULL);
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if(!buffer)
		return(NULL);
	line = readAppend(fd, buffer, leftovers);
	free(buffer);
	buffer = NULL;
	if(!line)
		return(NULL);
	leftovers = updateFormat(line);
	return(line);
}
