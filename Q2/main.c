#include <stdio.h>

int last_survivor_calc(int num_soliders, int first_solider, int spacing_soliders) {
	int last_survivor;
	if (num_soliders == 1) {
		return first_solider;
	}
	if (num_soliders % 2 == 0) {
		last_survivor = last_survivor_calc(num_soliders / 2, first_solider, spacing_soliders * 2);
	}
	else {
		last_survivor = last_survivor_calc((num_soliders - 1) / 2, first_solider + spacing_soliders * 2, spacing_soliders * 2);
	}
	return last_survivor;
}

int main() {
	int last_survivor = last_survivor_calc(43,1,1);
	printf("The survivor is: %d", last_survivor);
	return 0;
}
