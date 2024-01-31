#include <stdio.h>
#include <stdlib.h>
#define MINDAY 1
#define MINMONTH 1
#define MINYEAR 1970
#define DAYS 31
#define MONTHS 12
#define YEARS 61

struct Date {
	int Day, Month, Year;
};

struct Date *distributionSort(int (*key)(struct Date c), int card, struct Date *base, int nel)
{
	int *count = (int*)calloc(card, sizeof(int));
	int j = 0, k, i;
	while (j < nel) {
		k = key(base[j]);
		count[k] = count[k] + 1;
		j = j + 1;
	}
	i = 1;
	while (i < card) {
		count[i] = count[i] + count[i - 1];
		i = i + 1;
	}
	struct Date *d = (struct Date*)malloc(nel * sizeof(struct Date));
	j = nel - 1;
	while (j >= 0) {
		k = key(base[j]);
		i = count[k] - 1;
		count[k] = i;
		d[i] = base[j];
		j = j - 1;
	}
	free(count);
	free(base);
	return d;
}

int dayKey(struct Date x)
{
	return x.Day - MINDAY;
}

int monthKey(struct Date x)
{
	return x.Month - MINMONTH;
}

int yearKey(struct Date x)
{
	return x.Year - MINYEAR;
}

int main(int argc, char **argv)
{
	int n, i;
	scanf("%d", &n);
	struct Date *dates = (struct Date*)malloc(n * sizeof(struct Date));
	for (i = 0; i < n; i++)
		scanf("%04d %02d %02d", &dates[i].Year, &dates[i].Month, &dates[i].Day);
	dates = distributionSort(dayKey, DAYS, dates, n);
	dates = distributionSort(monthKey, MONTHS, dates, n);
	dates = distributionSort(yearKey, YEARS, dates, n);
	for (i = 0; i < n; i++)
		printf("%04d %02d %02d\n", dates[i].Year, dates[i].Month, dates[i].Day);
	free(dates);
	return 0;
}
