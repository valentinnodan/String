//
// Created by ochkarikdan on 23.10.2018.
//

#include "String.h"

#include <iostream>
#include <cstring>

String& String::resize() {
    char* str1 = new char[_capacity];
    memcpy(str1, str, _size);
    std::swap(str, str1);
    delete[] str1;
    return *this;
}


String::String() : _size(0), _capacity(10) {
    str = new char[_capacity];
}

char* String::data() {
    return str;
}

String::String(char const* mas) {
    size_t i = 0;
    while (mas[i] != '\0') {
        i++;
    }
    _size = i;
    _capacity = _size + 5;
    str = new char[_size + 5];
    i = 0;

    while (mas[i] != '\0') {
        str[i] = mas[i];
        i++;
    }
}

String::String(String const& str1) : _size(str1._size), _capacity(str1._capacity) {
    str = new char[_capacity];
    std::memcpy(str, str1.str, _size);
}

String& String::operator=(String const& str1) {
    String st(str1);
    swap(st, *this);
    return *this;
}

bool String::operator==(String const& str1) const {
    if (_size != str1._size) {
        return false;
    }
    for (size_t i = 0; i < _size; i++) {
        if (str[i] != str1.str[i]) {
            return false;
        }
    }
    return true;
}


String::String(String&& str1) noexcept : str(nullptr), _size(0), _capacity(0) { //std::move
    swap(str1, *this);
}

size_t String::size() const {
    return _size;
}

char String::operator[](size_t nom) const {
    return str[nom];
}

char& String::operator[](size_t nom) {
    return str[nom];
}

String& String::append(char const ch) {
    if (_size == _capacity) {
        _capacity <<= 1;
        resize();
    }
    str[_size++] = ch;
    return *this;
}

String& String::append(String const& str1) {
    if (_size + str1.size() >= _capacity) {
        _capacity = _size + str1._size + 5;
        resize();
    }
    std::memcpy(str + _size, str1.str, str1._size);
    _size += str1._size;
    return *this;
}

String::~String() {
    delete[] str;
}


std::ostream& operator<<(std::ostream& out, String const& str) {
    for (size_t i = 0; i < str._size; i++) {
        out << str[i];
    }
    return out;
}

void swap(String& s1, String& s2) {
    std::swap(s1.str, s2.str);
    std::swap(s1._size, s2._size);
    std::swap(s1._capacity, s2._capacity);
}


std::istream& operator>>(std::istream& in, String& str) {
    char ch;
    String st;
    in.get(ch);
    while (!std::iswspace(static_cast<unsigned char>(ch))) {
        st.append(ch);
        in.get(ch);
    }
    swap(st, str);
    return in;
}