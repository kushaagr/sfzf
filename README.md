# sfzf - A simple fzf algorithm written in C++
[![Windows](https://img.shields.io/static/v1?label=os&message=Windows&logo=microsoft&color=blue)]()

## Command format
```
sfzf SEARCH_STRING
```

It takes input from stdin and outputs only the results that have atleast
1% match with the provided search string.

## Demo

![Demo](static/output.gif)

## Build
+ Make sure you have gcc installed and it can compile to **C++17**.
+ Run `.\build.bat`
