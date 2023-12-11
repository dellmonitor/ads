unsigned long binsearch(unsigned long nel, int (*compare)(unsigned long i))
{
	unsigned long left = 0, right = nel - 1, guess;
	while (left <= right) {
		guess = (left + right) / 2;
		switch (compare(guess)) {
			case -1:
				left = guess + 1;
				break;
			case 1:
				right = guess - 1;
				break;
			case 0:
				return guess;
		}
	}
	return nel;
}
