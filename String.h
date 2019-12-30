//
// Created by max on 23.10.2018.
//
#pragma once

#include <iostream>
#include <vector>
#include <cstring>

class String {
    char* str;
    size_t _size;
    size_t _capacity;

    String& resize();


public:
    String();

    char* data();

    String(char const*);

    String(String const&);

    String& operator=(String const&);

    bool operator==(String const&) const;


    String(String&&) noexcept;

    size_t size() const;

    char operator[](size_t nom) const;

    char& operator[](size_t nom);


    friend std::ostream& operator<<(std::ostream&, String const&);

    friend std::istream& operator>>(std::istream&, String&);

    friend void swap(String&, String&);


    String& append(char);

    String& append(String const&);

    ~String();

};

std::ostream& operator<<(std::ostream&, String const&);

void swap(String& s1, String& s2);

std::istream& operator>>(std::istream&, String&);
