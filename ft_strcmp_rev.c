#include <libft.h>

/// @brief Compares s1 and s2 using ascii value of character in reverse order;
/// @param s1 Null terminated string
/// @param s2 Null terminated string
/// @return difference between s1 and s2 where the first character differs
/// (starting from the end) . ```0``` if s1 and s2 are equal.
/// ```< 0``` if ```s1 < s2```.
/// ```> 0``` if ```s1 > s2```.
int	ft_strcmp_rev(const char *s1, const char *s2)
{
	size_t			i;
	size_t			len_s1;
	size_t			len_s2;
	unsigned char	c1, c2;

	i = 0;
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (len_s1 && len_s2) {
		do {
			c1 = s1[len_s1 - i - 1];
			c2 = s2[len_s2 - i - 1];
		} while (++i && (len_s1 - i >= 1) && (len_s2 - i >= 1) && c1 == c2);
	}
	if (!(len_s1 && len_s2) || (c1 == c2)) {
		if (len_s1 - i == 0)
			c1 = 0;
		else
			c1 =  s1[len_s1 - i - 1];
		if (len_s2 - i == 0)
			c2 = 0;
		else
			c2 = s2[len_s2 - i - 1];
	}
	return ((unsigned char) c1 - (unsigned char) c2);
}