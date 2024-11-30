#include <libft.h>

void	_ft_insertion_sort(void* range, size_t len, size_t el_size, int (*cmp)(void* a, void* b)) {
	size_t	sorted_len = 1;
	size_t	i;

	while (sorted_len < len) {
		i = sorted_len;
		while (1) {
			if ((*cmp)(range + el_size * i, range + el_size * (i - 1)) < 0)
				ft_memswap(range + el_size * i, range + el_size * (i - 1), el_size);
			else
				break;
			if (--i == 0)
				break;
		}
		sorted_len++; 
	}
}
