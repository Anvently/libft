#include <libft.h>

static int	default_cmp(const void* a, const void* b) {
	return (a - b);
}

// int	ft_sbtree_insert(t_sbtree** root, const void* data, int (*cmp)(const void* a, const void* b)) {
// 	t_sbtree*	new_node;
// 	t_sbtree	*current, **prev_addr, *parent = NULL;
// 	int			diff;

// 	if (cmp == NULL)
// 		cmp = &default_cmp;
// 	new_node = ft_calloc(1, sizeof(t_sbtree));
// 	if (new_node == NULL)
// 		return (ERROR_FATAL);
// 	new_node->data = data;
// 	prev_addr = root;
// 	current = *root;
// 	while (current) {
// 		diff = cmp(current->data, data);
// 		if (diff > 0 || (diff == 0 && ((current->right == NULL && current->left != NULL)
// 				|| (current->right == NULL && current->left == NULL)))) {
// 			prev_addr = &current->right;
// 			current = current->right;
// 		} else if (diff < 0 || (diff == 0 && current->right != NULL && current->left == NULL)) {
// 			prev_addr = &current->left;
// 			current = current->left;
// 		}
// 		parent = current;
// 	}
// 	*prev_addr = new_node;
// 	new_node->parent = parent;
// 	return (SUCCESS);
// }

/// @brief Recursively insert a node in a sbtree starting from given root ```parent```.
/// @param parent addr of pointer storing the link toward the parent root. If ```NULL```
/// the recursion will stopped here and a new node will be inserted at this address.
/// @param data Can be either a integral type or the adress of a structure. 
/// @param cmp If ```NULL``` data will be compared as integral type. If a function is given
/// they will be passed as adress toward a memory area.
/// @return ```0``` if the node was inserted. ```ERROR_FATAL(-1)``` if allocation error,
/// ```1``` if data to insert is a  doubloon.
int	ft_sbtree_insert(t_sbtree** parent, const void* data, int (*cmp)(const void*, const void*)) {
	t_sbtree*	new_node;
	int			diff;

	if (cmp == NULL)
		cmp = &default_cmp;
	if (*parent == NULL) {
		new_node = ft_calloc(1, sizeof(t_sbtree));
		if (new_node == NULL)
			return (ERROR_FATAL);
		new_node->data = (void*) data;
		*parent = new_node;
		return (0);
	}
	diff = (*cmp)((*parent)->data, data);
	if (diff < 0)
		return (ft_sbtree_insert(&(*parent)->right, data, cmp));
	else if (diff > 0)
		return (ft_sbtree_insert(&(*parent)->left, data, cmp));
	else
		return (1);
}


void	_ft_sbtree_print(const t_sbtree* tree, int level, void (*fun)(const void*)) {
	static char			padding[128];

	if (level == 0)
		ft_memset(&padding[0], 0, sizeof(padding));
	_ft_sbtree_print_call(fun, tree->data);
	// ft_sdprintf(1, "%p\n", tree->data);
	if (tree->right && tree->left) {
		ft_sdprintf(1, "%s├─ ", padding);
		ft_strlcat(&padding[0], "|  ", sizeof(padding));
		_ft_sbtree_print(tree->right, level + 1, fun);
		padding[ft_strlen(padding) - 3] = '\0';
		ft_sdprintf(1, "%s└─ ", padding);
		ft_strlcat(&padding[0], "   ", sizeof(padding));
		_ft_sbtree_print(tree->left, level + 1, fun);
		padding[ft_strlen(padding) - 3] = '\0';
	}
	else if (tree->right) {
		ft_sdprintf(1, "%s└─ ", padding);
		ft_strlcat(&padding[0], "   ", sizeof(padding));
		_ft_sbtree_print(tree->right, level + 1, fun);
		padding[ft_strlen(padding) - 3] = '\0';
	}
	else if (tree->left) {
		ft_sdprintf(1, "%s|\n", padding);
		ft_sdprintf(1, "%s└─ ", padding);
		ft_strlcat(&padding[0], "   ", sizeof(padding));
		_ft_sbtree_print(tree->left, level + 1, fun);
		padding[ft_strlen(padding) - 3] = '\0';
	}
}

/// @brief Identify the shortest branch in the tree (in height) starting from ```root```
/// @param root 
/// @return ```-1``` if left branch is shorter. ```1``` if right branch is shorter.
/// ```0``` if branch are equal in height
int			ft_sbtree_shortest(const t_sbtree* root) {
	size_t	len_r = ft_sbtree_height(root->right, 0);
	size_t	len_l = ft_sbtree_height(root->left, 0);
	if (len_l == len_r)
		return (0);
	if (len_l < len_r)
		return (-1);
	return (1);
}

size_t	ft_sbtree_height(const t_sbtree* root, int height) {
	size_t	r_height = 0;
	size_t	l_height = 0;

	if (root == NULL)
		return (height);
	r_height = ft_sbtree_height(root->right, height + 1);
	l_height = ft_sbtree_height(root->left, height + 1);
	return (l_height >= r_height ? l_height : r_height);
}

void	ft_sbtree_clear(t_sbtree* root, void (*free_func)(void*)) {
	if (root == NULL)
		return;
	ft_sbtree_clear(root->left, free_func);
	ft_sbtree_clear(root->right, free_func);
	if (free_func && root->data)
		(*free_func)(root->data);
	free(root);
}

/// @brief Return the number of element inside the tree
/// @param root 
/// @return 
size_t	ft_sbtree_size(const t_sbtree* root) {
	size_t	size;

	if (root == NULL)
		return (0);
	size = 1;
	size += ft_sbtree_size(root->right);
	size += ft_sbtree_size(root->left);
	return (size);
}
