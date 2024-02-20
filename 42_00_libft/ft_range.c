#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int min, int max)
{
	int	*ret_arr;
	int	i;
	int	x;

	x = max - min;
	if (x <= 0)
		return (NULL);
	ret_arr = (int *)malloc(sizeof(int) * x);
	if (ret_arr == NULL)
		return (NULL);
	i = 0;
	while (i < x)
	{
		ret_arr[i] = min + i;
		i++;
	}
	return (ret_arr);
}

int	main(void)
{
	int	i;

	i = 0;

	while (i < 5)
	{
		printf("%d ", ft_range(5, 10)[i]);
		i++;
	}
	return (0);
}
