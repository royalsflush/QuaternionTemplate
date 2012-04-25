#include <stdio.h>

#include "quaternion.h"

void print(Quaternion<float>& k) {
	for (int i=0; i<4; i++)
		printf("%f ", k[i]);
	printf("\n");
}

int main() {
	Quaternion<float> q;
	print(q);
	return 0;
}
