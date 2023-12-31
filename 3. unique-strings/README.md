# Количество уникальных строк

## Условие

Дан набор строк. Найдите количество уникальных строк в этом наборе.

## Формат ввода

Сначала вводится количество строк `N`, затем - сами `N` строк, разделенные пробелом. Все строки состоят лишь из латинских букв, цифр и символов подчеркивания.

## Формат вывода

Выведите единственное целое число - количество уникальных строк в данном наборе.

## Пример

Ввод

```bash
6
first
second
first
third
second
second
```

Вывод

```bash
3
```

## Как тестировать локально

Установить необходимые пакеты `python`.

```bash
pip install -r requirements.txt
```

Скомпилировать программу и запустить тесты

```bash
g++ -std=c++17 main.cpp -o a.out
pytest -vs
```
