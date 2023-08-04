# Pipex

Pipex is a project focuses on the pipe() UNIX mechanism, while introducing us to other important functions like fork(), dup2(), and the concept of parent and child processes. 

## Usage

Here are the instructions in order to compile the program.

| Command | Usage |
| --- | --- |
| `make` | Compiles program and creates executable ./pipex
| `make clean` | Removes all object files (.o) of project and from libft
| `make fclean` | Removes all objects files (.o), all .a along with executable ./pipex
| `make re` | Removes all objects (.o) files and executable and recompiles them

## Mandatory Part 

The program will be executed as follows and take 4 arguments.

```shell
./pipex file1 cmd1 cmd2 file2
```

However, the program should behave following this pattern. 

```shell
./pipex < infile cmd1 | cmd2 > outfile
```

