#include <libft.h>

static t_vector_header*	_get_vector_header(t_vector* vector) {
	if (vector == NULL)
		return (NULL);
	return (((t_vector_header*)vector) - 1);
}

/// @brief Realloc vector
/// @param vector_addr 
/// @param target_capacity 
/// @return ```false``` if allocation failed. Vector IS NOT freed
static bool	_vector_realloc(t_vector** vector_addr, t_vector_header* header, size_t target_capacity) {
	t_vector_struct*	new_vector;

	new_vector = realloc(header,
		sizeof(t_vector_header) + target_capacity * header->type_size);
	if (!new_vector)
		return (false);
	if (new_vector != header)
		*vector_addr = &new_vector->data;
	new_vector->header.capacity = target_capacity;
	return (true);
}

/// @brief Realloc vector by multiplying its capacity by 2
/// If reallocation fails, vector IS NOT freed.
/// @param vector_addr 
/// @return ```false``` if allocation failed
static bool	_vector_expand(t_vector** vector_addr) {
	t_vector_header*	header;

	if (!*vector_addr)
		return (false);
	header = _get_vector_header(*vector_addr);
	return (_vector_realloc(vector_addr, header, (header->capacity ? header->capacity * 2 : 2)));
}

/// @brief Realloc vector by dividing its capacity by 2
/// If reallocation fails, vector IS NOT freed.
/// @param vector_addr 
/// @return ```false``` if allocation failed
static bool	_vector_shrink(t_vector** vector_addr) {
	t_vector_header*	header;

	if (!*vector_addr)
		return (false);
	header = _get_vector_header(*vector_addr);
	return (_vector_realloc(vector_addr, header, (header->capacity ? header->capacity / 2 : 0)));
}

static inline bool	_has_capacity(t_vector_header* header) {
	return (header->capacity > header->len);
}

static inline bool	_has_over_capacity(t_vector_header* header) {
	return (header->len < header->capacity / 4);
}

/// @brief Allocate a vector.
/// @param type_size Size in byte of vector elements
/// @param initial_capacity Number of element to reserve the space for at initialization
/// @return A pointer toward the vector data that can be used to access elements
/// ```NULL``` if allocation fails
t_vector*	ft_vector_create(size_t type_size, size_t initial_capacity) {
	t_vector_struct*			vector;

	vector = malloc(sizeof(t_vector_header) + type_size * initial_capacity);
	if (!vector)
		return (NULL);
	vector->header.capacity = initial_capacity;
	vector->header.type_size = type_size;
	vector->header.len = 0;
	return (&vector->data);
}

void			ft_vector_free(t_vector** vector_addr) {
	if (!*vector_addr)
		return;
	free(_get_vector_header(*vector_addr));
	*vector_addr = NULL;
}

/// @brief Add a new element to the vector which is a copy of memory area pointed
/// by data
/// @param vector_addr 
/// @param data 
/// @return ```false``` if a reallocation faield. Vector IS NOT freed
bool			ft_vector_push(t_vector** vector_addr, void* data) {
	t_vector_header*	header;
	
	if (!*vector_addr)
		return (false);
	header = _get_vector_header(*vector_addr);
	if (_has_capacity(header) == false) {
		ft_printf("expanding\n");
		if (_vector_expand(vector_addr) == false)
			return (false);
	}
	ft_memcpy(*vector_addr + header->len * header->type_size, data, header->type_size);
	ft_hexdump(*vector_addr + header->len * header->type_size, 1, header->type_size, 0);
	header->len += 1;
	return (true);
}

/// @brief Remove the last element of the vector
/// @param vector_addr 
/// @return ```false``` if ```vector_addr``` was ```NULL``` or if a shrinking operation
/// failed. Vector IS NOT freed
bool		ft_vector_pop(t_vector** vector_addr) {
	t_vector_header*	header;

	if (!*vector_addr)
		return (false);
	header = _get_vector_header(*vector_addr);
	if (header->len == 0)
		return (true);
	header->len -= 1;
	if (_has_over_capacity(header)) {
		if (_vector_shrink(vector_addr) == false)
			return (false);
	}
	return (true);
}

size_t	ft_vector_size(const t_vector* vector) {
	if (!vector)
		return (0);
	return (_get_vector_header(vector)->len);
}

/// @brief Set a vector capacity. Nothing is done if the actual size or capacity of the vector is
/// bigger than desired.
/// @param vector_addr 
/// @param nbr_el 
/// @return ```false``` if ```vector_addr``` was ```NULL``` or if a realloc operation
/// failed. Vector IS NOT freed
bool	ft_vector_reserve(t_vector** vector_addr, size_t nbr_el) {
	t_vector_header*	header;

	if (!*vector_addr)
		return (false);
	header = _get_vector_header(*vector_addr);
	if (header->capacity > nbr_el)
		return (true);
	return (_vector_realloc(vector_addr, header, nbr_el));
}

bool			ft_vector_insert(t_vector** vector_addr, size_t pos, void* data);
