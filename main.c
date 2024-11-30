#include "libft.h"

typedef struct {
	int	a;
	int b;
} t_foo;

static int	int_comp(void* a, void* b) {
	return (*(int*)b - *(int*)a);
}

int main(void) {

	t_vector*	vector = ft_vector_create(sizeof(t_foo), 0);
	ft_vector_free(&vector);

	int*	vector_int = ft_vector_create(sizeof(int), 0);
	for (int i = 0; i < 100; i++) {
		if (ft_vector_push((void**)&vector_int, &i) == false)
			break;
	}

	for (int i = 0; i < 75; i++) {
		if (ft_vector_pop((void*)&vector_int) == false) {
			ft_printf("alloc error\n");
			break;
		}
	}

	for (int i = 0; i < 25; i++) {
		if (ft_vector_insert((void*)&vector_int, i, &i) == false) {
			ft_printf("alloc error\n");
			break;
		}
	}

	for (int i = 0; i < 75; i++) {
		if (ft_vector_pop((void*)&vector_int) == false) {
			ft_printf("alloc error\n");
			break;
		}
	}

	static const int	array[] = {400, 401, 402};

	if (ft_vector_insert_range((void*)&vector_int, 0, array, 3) == false)
		ft_printf("alloc error\n");

	if (ft_vector_push_range((void*)&vector_int, array, 3) == false)
		ft_printf("alloc error\n");
	
	ft_dump_vector(vector_int, false);

	if (ft_vector_insert_range((void*)&vector_int, 3, array, 3) == false)
		ft_printf("alloc error\n");

	for (int i = 0; i < 25; i++) {
		if (ft_vector_insert_range((void*)&vector_int, 5, array, 3) == false) {
			ft_printf("alloc error\n");
			break;
		}
	}


	for (int i = 0; i < 1; i++) {
		if (ft_vector_erase_range((void*)&vector_int, 5, 3) == false) {
			ft_printf("alloc error\n");
			break;
		}
	}

	// ft_dump_vector(vector_int, false);

	// if (ft_vector_resize((void*)&vector_int, 1) == false)
	// 	ft_printf("alloc error\n");

	ft_dump_vector(vector_int, false);

	ft_insertion_sort((int*)vector_int, ft_vector_size(vector_int), &int_comp);

	ft_dump_vector(vector_int, false);


	ft_vector_free((void**)&vector_int);

	return (0);
}
