#include <stdio.h>

int	main(int argc, char *argv[])
{
	int	ret;

	ret = 0;
	while (*argv[1] != '\0')
		ret += *argv[1]++;
	printf("%d\n", ret);
	return (0);
}
