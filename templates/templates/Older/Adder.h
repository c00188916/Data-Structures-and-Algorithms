#pragma once

// Adder.h
template <typename T> class Adder {
private:
	T m_sum;

public:
	Adder() {
		m_sum = 0;
	}

	// add function defined elsewhere.
	void add(T number);

	// get sum function defined elsewhere.
	T sum();
};

