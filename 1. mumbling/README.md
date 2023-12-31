# Бормотание

## Условие

Вам необходимо реализовать функцию

```cpp
std::string accum(std::string s);
```

принимающую строку и преобразующую ее согласно следующим примерам:

```cpp
accum("abcd") -> "A-Bb-Ccc-Dddd"
accum("RqaEzty") -> "R-Qq-Aaa-Eeee-Zzzzz-Tttttt-Yyyyyyy"
accum("cwAt") -> "C-Ww-Aaa-Tttt"
```

Гарантируется, что аргумент функции содержит только строчные и заглавные буквы латинского алфавита. Заготовка для Вашего кода находится в файле `accum.h`.

## Как тестировать локально

Собрать программу с помощью `cmake` и запустить `ctest`:

```bash
mkdir build; cd build
cmake ..; cmake --build .
ctest -V
```
