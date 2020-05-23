#include <stdio.h>
#include <stdlib.h>
#include "geometry.h"

int main(void) {

	t_rectangle rec;

	rec.width = 5;
	rec.heigh = 3;
	rec.x = 5;
	rec.y = 10;

	int area = get_rectangle_area(&rec);

	printf("Area: %d\n", area);

	return EXIT_SUCCESS;
}
