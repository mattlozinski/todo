# todo

Simple todo with saving to file

## installation

clone repo

`git clone git@github.com:mattlozinski/todo.git`

compile

`g++ main.cc -o todo`

optionally move `todo` to `/bin` or `/usr/bin`

## usage

```
Simple todo with saving to file
Usage: todo [command] [arguments]

Available commands:
- list, l
   shows all tasks
   default, when no command given
- add, a
   adds tasks separated by space
- done, d
   marks tasks with given indexes as done
- undo, u
   unmarks tasks with given indexes as done
- rm, r
   removes tasks with given indexes
- sort, s
   sorts all task by status, uncompleted first
- help, h
   show this help message

Examples:
   todo add "clean the house" milk oranges
   todo done 2 3
   todo rm 1
```

## note

If you encounter any bugs, feel free to open issues

### future features

- configuration file
- clever implementation of keeping list in memory for changes
- more sorting options
- marking done/removing all items
- terminal completion
- pseudo-API (no. of items, etc)
- maybe:
    - searching by task
    - backup to reverse removal of items
    - dates in general
    - markdown support

