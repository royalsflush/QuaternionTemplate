#ifndef QUATERNION_H
#define QUATERNION_H

#include <math.h>

template <typename T>

class Quaternion {
	T q[4];
	
	public:
		Quaternion();
		Quaternion(T a, T vx, T vy, T vz);
		Quaternion(T a, const T* v);
		Quaternion(Quaternion<T>& k);
		
		Quaternion<T>& operator=(const T* v);
		Quaternion<T>& operator=(const Quaternion<T>& k);
		void setFromAxisAngle(T angle, T vx, T vy, T vz);
		void setFromAxisAngle(T angle, const T* v);

		Quaternion<T>& dot(const Quaternion<T>& k);
		Quaternion<T>& cross(const Quaternion<T>& k);

		Quaternion<T>& operator*=(const Quaternion<T>& k);
		const Quaternion<T> operator*(const Quaternion<T>& k);
		
		operator T*();
		T* getRotMatrix();
		T operator[](int i);
};

/* Class constructors */
	template<typename T>
Quaternion<T>::Quaternion() {
	q[0]=1;
	q[1]=q[2]=q[3]=0;
}

	template<typename T>
Quaternion<T>::Quaternion(T a, T vx, T vy, T vz) {
	q[0]=a;
	q[1]=vx; q[2]=vy; q[3]=vz;
}

	template<typename T>
Quaternion<T>::Quaternion(T a, const T* v) {
	q[0]=a;
	for (int i=0; i<3; i++)
		q[i+1]=v[i];
}

	template<typename T>
Quaternion<T>::Quaternion(Quaternion<T>& k) {
	for (int i=0; i<4; i++)
		this->q[i]=k.q[i];
}

/* Setters */
	template<typename T>
Quaternion<T>& Quaternion<T>::operator=(const T* v) {
	for (int i=0; i<4; i++)
		q[i]=v[i];
}

	template<typename T>
Quaternion<T>& Quaternion<T>::operator=(const Quaternion<T>& k) {

}

	template<typename T>
void Quaternion<T>::setFromAxisAngle(T angle, T vx, T vy, T vz) {
	q[0]=cos(angle/2.0);
	double sinA = sin(angle/2.0);

	q[1]=vx*sinA; q[2]=vy*sinA; q[3]=vz*sinA;
}

	template<typename T>
void Quaternion<T>::setFromAxisAngle(T angle, const T* v) {
	q[0]=cos(angle/2.0);
	double sinA = sin(angle/2.0);

	for (int i=0; i<3; i++)
		q[i+1]=sinA*v[i];
}

/* Operations */
	template<typename T>
Quaternion<T>& Quaternion<T>::dot(const Quaternion<T>& k) {
	
}

	template<typename T>
Quaternion<T>& Quaternion<T>::cross(const Quaternion<T>& k) {

}

	template<typename T>
Quaternion<T>& Quaternion<T>::operator*=(const Quaternion<T>& k) {

}

	template<typename T>
const Quaternion<T> Quaternion<T>::operator*(const Quaternion<T>& k) {

}

/* Getters */
	template<typename T>
Quaternion<T>::operator T*() {
	return q;
}

	template<typename T>
T* Quaternion<T>::getRotMatrix() {

}

	template<typename T>
T Quaternion<T>::operator[](int i) {
	return q[i];
}

#endif //QUATERNION_H
