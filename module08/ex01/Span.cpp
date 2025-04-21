#include "Span.hpp"

Span::Span() : _size(0), _pos(0) {}

Span::Span(const unsigned int n) : _size(n), _pos(0) {}

Span::Span(const Span &obj) :  _array(obj._array), _size(obj._size), _pos(obj._pos) {}

Span &Span::operator=(const Span &obj)
{
    if (this == &obj)
        return *this;
    _size = obj._size;
    _pos = obj._pos;
    _array = obj._array;
    return *this;
}

Span::~Span() {}

void Span::addNumber(const unsigned int n)
{
    if (_pos >= _size)
        throw std::out_of_range("Error: Array is full");
    _array.push_back(n);
    _pos++;
}

unsigned int Span::shortestSpan()
{
    if (_pos <= 1)
        throw std::out_of_range("Error: Not enough elements");
    std::vector<unsigned int> tmp = _array;
    std::sort(tmp.begin(), tmp.end());
    unsigned int min = UINT_MAX;
    for (unsigned int i = 1; i < _pos; i++)
    {
        if (tmp[i] - tmp[i - 1] < min)
            min = tmp[i] - tmp[i - 1];
    }
    return min;
}

unsigned int Span::longestSpan()
{
    if (_pos <= 1)
        throw std::out_of_range("Error: Not enough elements");
    std::vector<unsigned int> tmp = _array;
    std::sort(tmp.begin(), tmp.end());
    return tmp[_pos - 1] - tmp[0];
}

void Span::printArray() const
{
    for (unsigned int i = 0; i < _pos; i++)
        std::cout << _array[i] << " ";
    std::cout << std::endl;
}
