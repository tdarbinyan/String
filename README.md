# String

## Описание класса

В данной задаче реализован класс `String`, представляющий собой динамически расширяющуюся строку. Класс обеспечивает управление памятью и предоставляет удобные методы для работы с строками.

### Конструкторы

1. **Конструктор по умолчанию:**
   - Создает пустую строку. Память не выделяется.

```cpp
String();
```

2. **Конструктор с заданным размером и символом:**
   - Создает строку заданного размера, заполненную указанным символом.

```cpp
String(size_t size, char character);
```

3. **Конструктор от C-style строки:**
   - Создает строку, копируя содержимое C-style строки.

```cpp
String(const char* cString);
```

### Правило "трех"

1. **Конструктор копирования:**
   - Создает копию строки.

```cpp
String(const String& other);
```

2. **Копирующий оператор присваивания:**
   - Присваивает значение другой строке.

```cpp
String& operator=(const String& other);
```

3. **Деструктор:**
   - Освобождает выделенную память.

```cpp
~String();
```

### Основные методы

1. **`Clear()`**
   - Устанавливает размер строки в 0, не происходит деаллокации выделенной памяти.

```cpp
void Clear();
```

2. **`PushBack(character)`**
   - Добавляет символ в конец строки.

```cpp
void PushBack(char character);
```

3. **`PopBack()`**
   - Удаляет последний символ строки. Ничего не делает для пустой строки.

```cpp
void PopBack();
```

4. **`Resize(new_size)`**
   - Изменяет размер строки на указанный. При нехватке вместимости выделяет новый буфер.

```cpp
void Resize(size_t new_size);
```

5. **`Resize(new_size, character)`**
   - Изменяет размер строки на указанный и заполняет недостающие элементы символом.

```cpp
void Resize(size_t new_size, char character);
```

6. **`Reserve(new_cap)`**
   - Изменяет вместимость строки на максимум из новой вместимости и текущей вместимости.

```cpp
void Reserve(size_t new_cap);
```

7. **`ShrinkToFit()`**
   - Уменьшает вместимость строки до размера, если вместимость больше размера.

```cpp
void ShrinkToFit();
```

8. **`Swap(other)`**
   - Обменивает содержимое с другой строкой.

```cpp
void Swap(String& other);
```

9. **Операторы доступа по индексу:**
   - Константный и неконстантный операторы доступа по индексу.

```cpp
char& operator[](size_t index);
const char& operator[](size_t index) const;
```

10. **Методы `Front()` и `Back()`:**
    - Возвращают первый и последний символ строки.

```cpp
char& Front();
const char& Front() const;
char& Back();
const char& Back() const;
```

11. **`Empty()`**
    - Возвращает `true`, если строка пустая (размер 0).

```cpp
bool Empty() const;
```

12. **`Size()`**
    - Возвращает размер строки.

```cpp
size_t Size() const;
```

13. **`Capacity()`**
    - Возвращает вместимость строки.

```cpp
size_t Capacity() const;
```

14. **`Data()`**
    - Возвращает указатель на начало массива.

```cpp
const char* Data() const;
```

15. **Операторы сравнения:**
    - Операторы `<`, `>`, `<=`, `>=`, `==`, `!=` для задания лексикографического порядка.

```cpp
bool operator<(const String& other) const;
bool operator>(const String& other) const;
bool operator<=(const String& other) const;
bool operator>=(const String& other) const;
bool operator==(const String& other) const;
bool operator!=(const String& other) const;
```

16. **Операторы конкатенации:**
    - Операторы `+` и `+=` для конкатенации строк.

```cpp
String operator+(const String& other) const;
String& operator+=(const String& other);
```

17. **Оператор умножения на число:**
    - Умножение строки на число.

```cpp
String operator*(size_t n) const;
```

18. **Операторы ввода из потока и вывода в поток:**
    - Для ввода и вывода строк из и в поток.

```cpp
friend std::istream& operator>>(std::istream& is, String& str);
friend std::ostream& operator<<(std::ostream& os, const String& str);
```

19. **Метод `Split(delim)`**
    - Аналог сплита в Python. Разбивает строку на вектор подстрок по указанному разделителю.

```cpp
std::vector<String> Split(const String& delim = " ") const;
```

20. **Метод `Join(strings)`**
    - Аналог джоина в Python. Объединяет вектор строк в одну строку с использованием текущей строки в качестве разделителя.

```cpp
String Join(const std::vector<String>& strings) const;
```

## Примеры использования

Примеры использования класса `String` представлены в тестах. Убедитесь в правильности ваших реализаций, следуя указанным сигнатурам и требованиям.
