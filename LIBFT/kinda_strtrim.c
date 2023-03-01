#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static	int		in_set(char const *set, char c)
{
	//int		i;

	//i = 0;
	while(*set)
	{
		if(*set == c)
			return(1);
		set++;
	}
	return(0);
}

static char		*result(char const *s1, char const *set)
{
	char	*res;
	int		i;
	int		j;
	int		count;

	i = 0;
	j = 0;
	count = 0;
	res = (char*)malloc(sizeof(char) * (strlen(s1) + 1 - count));
	if(!res)
		return(NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		if(in_set(set, s1[i]) == 0)
		{
			res[j] = s1[i];
			j++;
		}
		i++;
	}
	res[j] = '\0';
	return(res);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		count;
	
	i = 0;
	count = 0;
	if(!s1 || !set)
		return(NULL);
	while(in_set(set, s1[i]) && s1[i])
	{
		count++;
		i++;
	}
	return(result(s1, set));
}
// remember to remove includes, change to ft_..
// int	main (void)
// {
// 	printf("%s\n", ft_strtrim("ERG doERGggo ERGGGGGGG", "ERG"));
// 	return(0);
// }