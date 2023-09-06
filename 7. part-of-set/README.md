# Часть множества

## Условие

Напишите шаблонную функцию `FindGreaterElement`, принимающую множество `elements` объектов типа `T` и еще один объект `threshold` типа `T` и возвращающую вектор из всех элементов множества, больших `threshold`, в возрастающем порядке.

```cpp
template <typename T>
vector<T> FindGreaterElement(const std::set<T>& elements, const T& threshold);
```

## Как тестировать локально

Собрать программу с помощью `cmake` и запустить `ctest`:

```bash
mkdir build; cd build
cmake ..; cmake --build .
ctest -V
```
