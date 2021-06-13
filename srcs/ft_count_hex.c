int ft_count_hex(unsigned long hex)
{
	int i;

	i = 0;
	if (!hex)
		return (1);
	while (hex > 0)
	{
		hex /= 16;
		i++;
	}
	return (i);
}