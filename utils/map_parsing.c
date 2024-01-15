#include "../so_long.h"

char	*ft_strjoin_without_newline(char *s1, char const *s2)
{
	char	*ret;
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;
	size_t	j;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ret = (char *)malloc(s1_len + s2_len + 1);
	ret = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!ret)
		return (NULL);
	i = -1;
	j = -1;
	while (++i < s1_len && s1[i] != '\n')
		ret[i] = s1[i];
	free(s1);
	while (++j < s2_len && s2[j] != '\n')
		ret[i++] = s2[j];
	ret[i] = '\0';
	return (ret);
}
char	*ft_strdup_without_newline(const char *s1)
{
	int length;
	int i;
	char *casted_str;

	length = 0;
	i = 0;
	if (!s1)
		return (NULL);
	while (s1[length] && s1[length] != '\n')
		length++;
	casted_str = (char *)malloc(sizeof(char) * length + 1);
	if (!casted_str)
		return (NULL);
	while (i < length)
	{
		casted_str[i] = s1[i];
		i++;
	}
	casted_str[i] = '\0';
	return (casted_str);
}