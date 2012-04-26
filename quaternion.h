#ifndef QUATERNION_H
#define QUATERNION_H

#include <math.h>

template <typename T>

class Quaternion {
	T q[4];
	
	public:
		Quaternion(); //ok
		Quaternion(T a, T vx, T vy, T vz); //ok
		Quaternion(const T* v);
		Quaternion(T a, const T* v); //ok
		Quaternion(const Quaternion<T>& k); //ok
	
		Quaternion<T>& set(T a, T vx, T vy, T vz); //ok
		Quaternion<T>& operator=(const T* v); //ok
		Quaternion<T>& operator=(const Quaternion<T>& k); //ok
		Quaternion<T>& setFromAxisAngle(T angle, T vx, T vy, T vz); //ok
		Quaternion<T>& setFromAxisAngle(T angle, const T* v); //ok

		T dot(const Quaternion<T>& k) const; //ok
		Quaternion<T>& cross(const Quaternion<T>& k); //to do
		T norm() const; 
		Quaternion<T>& normalize();

		const Quaternion<T> operator*(const Quaternion<T>& k) const; //ok
		Quaternion<T>& operator*=(const Quaternion<T>& k); //ok
		
		T get(int i) const; //ok
		operator T*(); //ok
		T* getRotMatrix();
		T& operator[](int i); //ok
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
Quaternion<T>::Quaternion(const T* v) {
	for (int i=0; i<4; i++)
		q[i]=v[i];
}

	template<typename T>
Quaternion<T>::Quaternion(T a, const T* v) {
	q[0]=a;
	for (int i=0; i<3; i++)
		q[i+1]=v[i];
}

	template<typename T>
Quaternion<T>::Quaternion(const Quaternion<T>& k) {
	for (int i=0; i<4; i++)
		this->q[i]=k.get(i);
}

/* Setters */
	template<typename T>
Quaternion<T>& Quaternion<T>::set(T a, T vx, T vy, T vz) {
	q[0]=a;
	q[1]=vx; q[2]=vy; q[3]=vz;
	return *this;
}

	template<typename T>
Quaternion<T>& Quaternion<T>::operator=(const T* v) {
	for (int i=0; i<4; i++)
		q[i]=v[i];
	return *this;
}

	template<typename T>
Quaternion<T>& Quaternion<T>::operator=(const Quaternion<T>& k) {
	if (&k==this) return *this;

	for (int i=0; i<4; i++)
		q[i]=k.get(i);
	return *this;
}

	template<typename T>
Quaternion<T>& Quaternion<T>::setFromAxisAngle(T angle, T vx, T vy, T vz) {
	q[0]=cos(angle/2.0);
	double sinA = sin(angle/2.0);

	q[1]=vx*sinA; q[2]=vy*sinA; q[3]=vz*sinA;
	return *this;
}

	template<typename T>
Quaternion<T>& Quaternion<T>::setFromAxisAngle(T angle, const T* v) {
	q[0]=cos(angle/2.0);
	double sinA = sin(angle/2.0);

	for (int i=0; i<3; i++)
		q[i+1]=sinA*v[i];
	return *this;
}

/* Operations */
	template<typename T>
T Quaternion<T>::dot(const Quaternion<T>& k) const {
	T res=0;
	for (int i=0; i<4; i++)
		res+=k.get(i)*q[i];
	return res;	
}

	template<typename T>
Quaternion<T>& Quaternion<T>::cross(const Quaternion<T>& k) {
	//erm...
}

	template<typename T>
T Quaternion<T>::norm() const {
	T n = this->dot(*this);
	return sqrt(n);
}

	template<typename T>
Quaternion<T>& Quaternion<T>::normalize() {
	T n = this->norm();
	if (n==0) return *this;

	for (int i=0; i<4; i++)
		q[i]/=n;
	return *this;
}

	template<typename T>
const Quaternion<T> Quaternion<T>::operator*(const Quaternion<T>& k) const {
	Quaternion<T> res;

	res[0] = q[0]*k.get(0)-q[1]*k.get(1)-q[2]*k.get(2)
			-q[3]*k.get(3);
 	res[1] = q[0]*k.get(1)+q[1]*k.get(0)+q[2]*k.get(3)
			-q[3]*k.get(2);
	res[2] = q[0]*k.get(2)-q[1]*k.get(3)+q[2]*k.get(0)
			+q[3]*k.get(1);
	res[3] = q[0]*k.get(3)+q[1]*k.get(2)-q[2]*k.get(1)
			+q[3]*k.get(0);

	return res;
}

	template<typename T>
Quaternion<T>& Quaternion<T>::operator*=(const Quaternion<T>& k) {
	Quaternion<T> res((*this)*k);
	*this=res;

	return *this;
}

/* Getters */
	template<typename T>
T Quaternion<T>::get(int i) const {
	return q[i];
}

	template<typename T>
Quaternion<T>::operator T*() {
	return q;
}

	template<typename T>
T* Quaternion<T>::getRotMatrix() {
	T* v = new T[16];
	for (int i=0; i<16; i++)
		v[i]=0;	

	v[0*4+0]=1-2*q[2]*q[2]-2*q[3]*q[3];
	v[1*4+1]=1-2*q[1]*q[1]-2*q[3]*q[3];
	v[2*4+2]=1-2*q[1]*q[1]-2*q[2]*q[2];
	v[3*4+3]=1;

	v[0*4+1]=2*q[1]*q[2]-2*q[0]*q[3];
	v[1*4+0]=2*q[1]*q[2]+2*q[0]*q[3];
	
	v[0*4+2]=2*q[1]*q[3]+2*q[0]*q[2];
	v[2*4+0]=2*q[1]*q[3]-2*q[0]*q[2];
	
	v[1*4+2]=2*q[2]*q[3]-2*q[0]*q[1];
	v[2*4+1]=2*q[2]*q[3]+2*q[0]*q[1];

	return v;	
}

	template<typename T>
T& Quaternion<T>::operator[](int i) {
	return q[i];
}

#endif //QUATERNION_H
