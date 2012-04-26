#include <stdio.h>

#include "quaternion.h"

void print(Quaternion<float>& k) {
	for (int i=0; i<4; i++)
		printf("%f ", k[i]);
	printf("\n");
}

int main() {
	printf("\nConstructors test:\n");
	
	Quaternion<float> u;
	printf("Default constructor - should be 1.0, 0.0, 0.0, 0.0:\n");
	print(u);
	
	Quaternion<float> l(2.0, 3.0, 2323.32 , 9.921);
	printf("Four-argument constructor - should be 2.0, 3.0, 2323.32, 9.921:\n");
	print(l);
	
	printf("Vector constructor - should be 4.5, 5.6, 2.3, 7.8\n");
	float bigV[] = {4.5, 5.6, 2.3, 7.8};
	Quaternion<float> t(bigV);
	print(t);

	float v[] = {4., 5.5, 21};
	Quaternion<float> q(9.3, v);
	printf("The scalar-vector constructor - should be 9.3, 4.0, 5.5, 21.0\n");	
	print(q);
	
	Quaternion<float> k(l);
	printf("The copy constructor - should be equal to the second quaternion\n");
	print(k);
	printf("\n");

	printf("Assignment test:\n");
	float anotherV[] = {1., 2.323, 932.2, 5};
	u=t= anotherV;
	printf("Assignment operator from a vector - should be 1.0, 2.323, 9032.32, 5.0:\n");
	print(t);
	printf("Assignment operator from another quaternion (by passing the reference in the assignment) - should be equal to the one above\n");
	print(u);

	u=l=q;
	printf("Testing if the reference is passed corrected - if so, the three quaternions are equal\n");
	print(q);
	print(l);
	print(u); 	
	printf("\n");

	printf("Four parameter set and reference passing - both quaternions should be 1.0, 2.0, 3.0, 4.0\n");
	u=k.set(1.0,2.0,3.0,4.0);
	print(k);
	print(u);
	printf("\n");

	printf("Axis-angle four-parameters assignment - angle is pi, axis is (2.0,1.0,3.0)\n");
	printf("So quaternion should be (0.0, 2.0, 1.0, 3.0)\n");
	printf("The second quaternion is testing the reference passed, so it should be equal to the first\n");
	l=q.setFromAxisAngle(acos(-1.0), 2.0, 1.0, 3.0);
	print(q);
	print(l);
	printf("Axis-angle scalar-vector assignment, same example as above\n");
	float axis[] = {2.0, 1.0, 3.0};
	k=u.setFromAxisAngle(acos(-1.0), axis);
	print(u);
	print(k); 
	printf("\n");

	printf("Dot product test: first quaternion is 1.0, 4.0, 8.0, 2.0;\n");
	printf("Second quaternion is 5.0, 1.0, 3.0, 6.0\n");
	printf("So the dot product should be equal to 45.0\n");
	u.set(1.0, 4.0, 8.0, 2.0);
	k.set(5.0, 1.0, 3.0, 6.0);
	printf("%f\n", u.dot(k));

	printf("Multiplication test - (using the vectors from the example above)\n");
	t=u*k;
	print(t);	
	printf("*= operator test with the same quaternions\n");
	u*=k;
	print(u);
	printf("Norm operation, should be 77.6853\n");
	printf("%f\n", u.norm());
	printf("Normalize operation - should be -0.4505, 0.8109, 0.2703, 0.2574\n");
	print(u.normalize()); 

	printf("Getting the rotation matrix, should be:\n");
	printf(" 0.7212  0.6704  0.1739\n");
	printf(" 0.2064 -0.4478  0.8699\n");
	printf(" 0.6611 -0.5915 -0.4614\n\n");
	float* mat = u.getRotMatrix();

	for (int i=0; i<4; i++) {
		for (int j=0; j<4; j++)
			printf("%f ", mat[i*4+j]);
		printf("\n");
	}
	

	return 0;
}
