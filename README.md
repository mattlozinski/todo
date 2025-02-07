# todo

simple todo with saving to file

## installation

`g++ src/todo.cc -o todo`

optionally move `todo` to `/usr/bin` or `/bin`

## usage

Usage: `todo [command] [arguments]`

### available commands

- `list`, `l`
    - shows all tasks
    - default, when no command given
- `add`, `a`
    - adds tasks separated by space
- `done`, `d`
    - marks tasks with given indexes as done
- `undo`, `u`
    - unmarks tasks with given indexes as done
- `rm`, `r`
    - removes tasks with given indexes
- `sort`, `s`
    - sorts all task by status, uncompleted first
- `help`, `h`
    - show this help message

### examples
```
todo add "clean the house" milk oranges
todo done 2 3
todo rm 1
```

## about project

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

