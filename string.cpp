#include "string.hpp"

// Constructors /////////////////////////////////////////////////////
String::String() {
  this->capacity_ = 0;
  this->size_ = 0;
  this->chars_ = new char[1];
  this->chars_[0] = '\0';
}

String::String(const char* chars) {
  this->size_ = strlen(chars);
  if (this->size_ != 0) {
    this->capacity_ = 1;
    while (this->capacity_ < this->size_) {
      this->capacity_ *= 2;
    }
  } else {
    this->capacity_ = 0;
  }
  this->chars_ = new char[this->capacity_ + 1];
  for (size_t i = 0; i < this->size_; i++) {
    this->chars_[i] = chars[i];
  }
  this->chars_[this->size_] = '\0';
}

String::String(const String& string) {
  this->capacity_ = string.size_;
  this->size_ = string.size_;
  this->chars_ = new char[this->size_ + 1];
  for (size_t i = 0; i < this->size_; i++) {
    this->chars_[i] = string.chars_[i];
  }
}

String::String(size_t size, char character) {
  this->size_ = size;
  this->capacity_ = this->size_;
  this->chars_ = new char[this->capacity_ + kTerminalZeroSpace];
  for (size_t i = 0; i < this->size_; i++) {
    this->chars_[i] = character;
  }
  this->chars_[this->size_] = '\0';
}

// Methods ///////////////////////////////////////////////////////////
void String::Clear() {
  this->chars_[this->size_] = kSymbolToReplaceTerminalZero;
  if (this->size_ != 0) {
    this->chars_[0] = '\0';
  }
  this->size_ = 0;
}

void String::Reserve(size_t upd_capacity) {
  if (upd_capacity > this->capacity_) {
    char* upd_chars = new char[upd_capacity + kTerminalZeroSpace];
    for (size_t i = 0; i < this->size_; i++) {
      upd_chars[i] = this->chars_[i];
    }
    upd_chars[this->size_] = '\0';
    delete[] this->chars_;
    this->capacity_ = upd_capacity;
    this->chars_ = upd_chars;
  }
}

void String::PushBack(char character) {
  const size_t kSpaceForPushedElement = 1;
  (this->capacity_ == 0) ? this->capacity_ = 1 : this->capacity_ *= 2;
  char* upd_chars = new char[this->capacity_ + kTerminalZeroSpace];
  for (size_t i = 0; i < this->size_; i++) {
    upd_chars[i] = this->chars_[i];
  }
  upd_chars[this->size_] = character;
  this->size_++;
  upd_chars[this->size_] = '\0';

  *this = upd_chars;
  delete[] upd_chars;
}

void String::PopBack() {
  if (this->size_ > 0) {
    this->chars_[this->size_] = kSymbolToReplaceTerminalZero;
    this->size_--;
    this->chars_[this->size_] = '\0';
  }
}

void String::Resize(size_t upd_size) {
  if (upd_size > this->capacity_) {
    if (this->capacity_ == 0) {
      this->capacity_ = 1;
    } else {
      this->capacity_ = upd_size;
    }
    char* upd_chars = new char[this->capacity_ + kTerminalZeroSpace];
    for (size_t i = 0; i < this->size_; i++) {
      upd_chars[i] = this->chars_[i];
    }
    upd_chars[this->size_] = '\0';
    delete[] this->chars_;
    this->chars_ = upd_chars;
  }
  this->chars_[this->size_] = kSymbolToReplaceTerminalZero;
  this->size_ = upd_size;
  this->chars_[this->size_] = '\0';
}

void String::Resize(size_t upd_size, char character) {
  size_t temp_current_size = this->size_;
  this->Resize(upd_size);
  for (size_t i = temp_current_size; i < upd_size; i++) {
    this->chars_[i] = character;
  }
  this->chars_[upd_size] = '\0';
}
void String::ShrinkToFit() {
  if (this->size_ < this->capacity_) {
    char* upd_chars = new char[this->size_ + kTerminalZeroSpace];
    for (size_t i = 0; i < this->size_ + kTerminalZeroSpace; i++) {
      upd_chars[i] = this->chars_[i];
    }
    delete[] this->chars_;
    this->chars_ = upd_chars;
    this->capacity_ = this->size_;
  }
}

char& String::Front() { return this->chars_[0]; }

char String::Front() const { return this->chars_[0]; }

char& String::Back() { return this->chars_[this->size_ - 1]; }

char String::Back() const { return this->chars_[this->size_ - 1]; }

void String::Swap(String& swap_string) {
  std::swap(this->chars_, swap_string.chars_);
  std::swap(this->size_, swap_string.size_);
  std::swap(this->capacity_, swap_string.capacity_);
}

bool String::Empty() const { return this->size_ == 0; }

size_t String::Size() const { return this->size_; }

size_t String::Capacity() const { return this->capacity_; }

char* String::Data() { return this->chars_; }

const char* String::Data() const { return this->chars_; }

// Destructor //////////////////////////////////////////
String::~String() { delete[] this->chars_; }

// Getters /////////////////////////////////////////////
char*& String::GetChars() { return this->chars_; }

size_t& String::GetSize() { return this->size_; }

size_t& String::GetCapacity() { return this->capacity_; }

// Operators ///////////////////////////////////////////
char& String::operator[](size_t index) { return this->chars_[index]; }

char String::operator[](size_t index) const { return this->chars_[index]; }

String& String::operator=(const String& str) {
  if (*this != str) {
    delete[] this->chars_;
    this->capacity_ = str.capacity_;
    this->size_ = str.size_;
    this->chars_ = new char[this->capacity_ + 1];
    for (size_t i = 0; i < this->size_; i++) {
      this->chars_[i] = str.chars_[i];
    }
    this->chars_[this->size_] = '\0';
  }
  return *this;
}

String& String::operator=(const char* chars) {
  String resulting_string(chars);
  *this = resulting_string;
  return *this;
}

bool String::operator==(const String& compare_string) const {
  if (this->size_ != compare_string.size_) {
    return false;
  }
  for (size_t i = 0; i < compare_string.size_; i++) {
    if (this->chars_[i] != compare_string.chars_[i]) {
      return false;
    }
  }
  return true;
}

bool String::operator<(String compare_string) const {
  if (this->size_ == compare_string.size_) {
    for (size_t i = 0; i < compare_string.size_; i++) {
      if (this->chars_[i] > compare_string.chars_[i]) {
        return false;
      }
      if (this->chars_[i] < compare_string.chars_[i]) {
        return true;
      }
    }
    return true;
  }
  return (this->size_ < compare_string.size_);
}

bool String::operator!=(String compare_string) const {  // ok
  return !(*this == compare_string);
}

bool String::operator>=(String compare_string) const {  // ok
  return !(*this < compare_string);
}

bool String::operator>(String compare_string) const {  // ok
  return !(compare_string >= *this);
}

bool String::operator<=(String compare_string) const {  // ok
  return !(compare_string < *this);
}

String operator+(const String& string1, const String& string2) {
  String resulting_string;
  delete[] resulting_string.GetChars();
  resulting_string.GetCapacity() = string1.Size() + string2.Size();
  resulting_string.GetSize() = string1.Size() + string2.Size();
  resulting_string.GetChars() = new char[resulting_string.Size() + 1];
  for (size_t i = 0; i <= resulting_string.Size(); i++) {
    resulting_string.GetChars()[i] = (i < string1.Size())
                                         ? string1.Data()[i]
                                         : string2.Data()[i - string1.Size()];
  }
  return resulting_string;
}

String& String::operator+=(const String& string) {
  *this = *this + string;
  return *this;
}

String& String::operator*=(size_t num) {
  this->capacity_ = num * this->size_;
  char* upd_chars = new char[this->capacity_ + 1];
  for (size_t i = 0; i < num; i++) {
    memcpy(&upd_chars[i * this->size_], this->chars_, this->size_);
  }
  upd_chars[num * this->size_] = '\0';
  *this = upd_chars;
  delete[] upd_chars;
  return *this;
}

String operator*(String string, size_t num) {
  String resulting_string;
  resulting_string.Reserve(num * (string.GetSize()));
  resulting_string.GetSize() = num * string.GetSize();
  for (size_t i = 0; i < num; i++) {
    memcpy(&resulting_string.GetChars()[i * string.GetSize()], string.Data(),
           string.Size());
  }
  return resulting_string;
}

std::vector<String> String::Split(const String& delim) {
  if (*this == delim) {
    return {"", ""};
  }
  std::vector<String> resulting_list;
  String substring;
  for (size_t i = 0; i < this->size_; i++) {
    bool equality_flag = true;
    for (size_t j = 0; j < delim.size_; j++) {
      if (i + j == this->size_ || this->chars_[i + j] != delim.chars_[j]) {
        equality_flag = false;
        break;
      }
    }
    if (equality_flag) {
      resulting_list.push_back(substring);
      i += delim.size_ - 1;
      substring = String();
    } else {
      substring.PushBack(this->chars_[i]);
    }
  }
  resulting_list.push_back(substring);
  return resulting_list;
}

String String::Join(const std::vector<String>& strings) const {
  String resulting_string;
  std::vector<String> list_of_strings = strings;
  std::vector<String>::iterator iter = list_of_strings.begin();
  for (; iter != list_of_strings.end(); iter++) {
    resulting_string += *iter;
    if (iter != list_of_strings.end() - 1) {
      resulting_string += *this;
    }
  }
  return resulting_string;
}

std::ostream& operator<<(std::ostream& ostream, String string) {
  for (size_t i = 0; i < string.GetSize(); ++i) {
    ostream << string.GetChars()[i];
  }
  return ostream;
}

std::istream& operator>>(std::istream& istream, String& string) {
  char character;
  while (istream.get(character)) {
    string.PushBack(character);
  }
  return istream;
}
