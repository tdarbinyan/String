#pragma once
#include <stdlib.h>

#include <cstring>
#include <iostream>
#include <vector>

class String {
 private:
  size_t size_;
  size_t capacity_;
  char* chars_;
  const size_t kTerminalZeroSpace =
      1;  // One slot for terminal zero to not overuse memory
  const char kSymbolToReplaceTerminalZero =
      '!';  // Any symbol to use to guarantee the existance of only one terminal
            // zero at a time // useless comment
 public:
  String();

  String(const char* chars);

  String(const String& str);

  String(size_t size, char character);

  ~String();

  char*& GetChars();

  size_t& GetSize();

  size_t& GetCapacity();

  void Clear();

  void Reserve(size_t upd_capacity);

  void PushBack(char character);

  void PopBack();

  void Resize(size_t upd_size);

  void Resize(size_t upd_size, char character);

  void ShrinkToFit();

  char& Front();

  char Front() const;

  char& Back();

  char Back() const;

  void Swap(String& swap_string);

  bool Empty() const;

  size_t Size() const;

  size_t Capacity() const;

  char* Data();

  const char* Data() const;

  char& operator[](size_t index);

  char operator[](size_t index) const;

  String& operator=(const String& string);

  String& operator=(const char* chars);

  bool operator==(const String& compare_string) const;

  bool operator!=(String compare_string) const;

  bool operator<=(String compare_string) const;

  bool operator>=(String compare_string) const;

  bool operator>(String compare_string) const;

  bool operator<(String compare_string) const;

  String& operator+=(const String& string);

  String& operator*=(size_t num);

  std::vector<String> Split(const String& delim = " ");

  String Join(const std::vector<String>& strings) const;
};

String operator*(String string, size_t num);

String operator+(const String& string1, const String& string2);

std::ostream& operator<<(std::ostream& ostream, String string);

std::istream& operator>>(std::istream& istream, String& string);
