#include "Adder.h"

template <typename T> void Adder<T>::add(T number) {
	m_sum += number;
}

template <typename T> T Adder<T>::sum() {
	return m_sum;
}

template class Adder<int>;
template class Adder<float>;
