#include "libft.h"

typedef struct {
	int	a;
	int b;
} t_foo;

int main(void) {

	t_vector*	vector = ft_vector_create(sizeof(t_foo), 10);
	ft_vector_free(&vector);

	int*	vector_int = ft_vector_create(sizeof(int), 10);
	for (int i = 0; i < 100; i++) {
		if (ft_vector_push((void**)&vector_int, &i) == false)
			break;
	}
	for (unsigned int i = 0; i < ft_vector_size(vector_int); i++) {
		ft_printf("%d, ", vector_int[i]);
	}

	ft_vector_free((void**)&vector_int);

	return (0);
}
