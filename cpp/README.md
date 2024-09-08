# C++ version of Difference table

Since I don't know how to make a `Makefile` yet, compiling this organized, *I hope*, `C++` codebase is tedious. To compile, run:

```bash
g++ ./main.cpp ./arguments.cpp ./lexicon.cpp ./utils.cpp ./difference_table.cpp -o ./main.exe
```

## How to use

Make sure you compile it first

- `s`: A comma-separated string that is a sequence of numbers
- `c`: An integer indicating the amount of predictions the program will make.

```bash
./main.exe -s "2,6,22,56,114,202" -c 5
```
