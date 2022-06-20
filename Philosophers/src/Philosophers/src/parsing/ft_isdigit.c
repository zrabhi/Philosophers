#include "../philosophers.h"

bool	ft_isdigit(char *str)
{
	int i;

	i = -1;
	while(str[++i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			return (true);
	}
	return (false);
}
