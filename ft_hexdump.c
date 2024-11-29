#include <libft.h>
#include <stdint.h>

static void	printHexa(const void* data, int size)
{
	uint8_t	byte;
	static const char* hexcode = "0123456789abcdef";

	for (int i = size - 1; i >= 0 ; i -= 1)
	{
		byte = *(uint8_t*)(data + i);
		write(1, hexcode + ((byte & 0xF0) >> 4), 1);
		write(1, hexcode + (byte & 0x0F), 1);
	}
}

static void	print_chars(const char* buffer, size_t len) {
	for (size_t i = 0; i < len; i++)
		write(1, (ft_isprint(*(buffer + i)) ? buffer + i : "."), 1);
}


/// @brief Print ```n``` element of size ```unit``` at ```addr``` in hexadecimal format
/// @warning Must be used with caution as invalid read could occurs when reading non-owned
/// memory areas
/// @param addr 
/// @param len 
/// @param unit
/// @return ```1```  if sys error. 
void	ft_hexdump(const void* addr, size_t n, size_t unit, size_t start_from) {
	int					n_entry_line, offset, i;
	char				spaces[64] = {' '};

	ft_memset(&spaces, ' ', 64);
	n_entry_line = 16 / unit;
	if (n_entry_line == 0)
		n_entry_line = 1;
	offset = n_entry_line * unit;
	for (void* data = (addr + start_from * unit); data && data < (addr + (start_from * unit) + (n * unit)); data += offset) {
		ft_printf("%08x", ((data - addr)));
		write(1, " ", 1);
		for (i = 0; i < n_entry_line && (data + (i * unit)) < (addr + (start_from * unit) + (n * unit)); i++) {
			if (i == (n_entry_line / 2))
				write(1, "  ", 2);
			else
				write(1, " ", 1);
			printHexa(data + (i * unit), unit);
		}
		if (i != n_entry_line)
			write(1, spaces, (n_entry_line - i) * ((unit * 2) + 1) + (i <= (n_entry_line / 2) ? 1 : 0));
		write(1, "  |", 3);
		print_chars(data, offset - ((n_entry_line - i) * unit));
		write(1, "|", 1);
		write(1, "\n", 1);
	}
}
