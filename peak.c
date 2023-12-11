unsigned long peak(unsigned long nel, int(*less)(unsigned long i, unsigned long j))
{
	if (nel == 1) return 0;
	else if (!(less(0, 1))) return 0;
	for (unsigned long i = 1; i <= nel - 2; i++)
		if (!(less(i, i - 1)) && !(less(i, i + 1))) return i;
	return nel - 1;
}
