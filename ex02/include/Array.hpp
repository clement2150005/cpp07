#pragma once

#include <cstddef>

template <typename T>
class Array
{
private:
	T *_data;
	size_t _size;

public:
	Array();
	Array(unsigned int n);
	Array(const Array &other);
	Array &operator=(const Array &other);
	T &operator[](unsigned int index);
	const T &operator[](unsigned int index) const;
	~Array();

	size_t size() const;
};

#include "Array.tpp"