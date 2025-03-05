#include "Array.hpp"

template <typename T>
Array <T>::Array() : m_array(new T[0]), m_n(0) {}

template <typename T>
Array <T>::Array(const unsigned int n) : m_array(new T[n]), m_n(n) {}

template <typename T>
Array <T>::Array(const Array &obj) : m_array(new T[obj.m_n]), m_n(obj.m_n)
{
    for (unsigned int i = 0; i < m_n; i++) {
        m_array[i] = obj.m_array[i];
    }
}

template <typename T>
Array <T> &Array <T>::operator=(const Array &obj)
{
    if (this == &obj)
        return *this;
    delete[] m_array;
    m_array = new T[obj.m_n];
    m_n = obj.m_n;
    for (unsigned int i = 0; i < m_n; i++)
        m_array[i] = obj.m_array[i];
    return *this;
}

template <typename T>
Array <T>::~Array()
{
    delete[] m_array;
}

template <typename T>
T &Array <T>::operator[](const unsigned int i)
{
    if (i >= m_n)
        throw std::out_of_range("Index out of range");
    return m_array[i];
}

template <typename T>
const T &Array <T>::operator[](const unsigned int i) const
{
    if (i >= m_n)
        throw std::out_of_range("Index out of range");
    return m_array[i];
}

template <typename T>
unsigned int Array <T>::size() const
{
    return m_n;
}

template <typename T>
void Array <T>::printArray() const
{
    std::cout << "Values in array: " << std::endl;
    for (unsigned int i = 0; i < m_n; i++)
        std::cout << BLUE <<  "Value[" << i << "]: " << m_array[i] << RESET << std::endl;
}
