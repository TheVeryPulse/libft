#include "libft.h"
#include <stdlib.h>

int	main(void)
{
	char	*f_str;

	f_str = ft_format_string(" %d %s\n", 100, " >>>string test<<< ");
	ft_printf("%s", f_str);
	free(f_str);
}
