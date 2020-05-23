#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int x, y;
	int width, heigh;
} t_rectangle;

int get_rectangle_area(t_rectangle *rectangle);
