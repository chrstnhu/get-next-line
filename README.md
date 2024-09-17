# get-next-line

Project 42 school

Write a function that returns a line read from a file descriptor

### Prototype
```c
char *get_next_line(int fd);
```

### Functions autorized
* read
* malloc
* free

## Run
> Git clone and go to project directory :

```bash
git clone git@github.com:chrstnhu/get_next_line.git && cd get_next_line
```
> Compile
```bash
cc -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c 
```
> Run
```bash
./a.out
```
## Test
* Change the file descriptor in the file main
* Change the text of the file

## Rules
* Repated calls of get_next_line, read one line at a time
* Function should return the line that was read
* Returned line should include the terminating \n character
  (except the end of file)
* Need to compile with -D BUFFER_SIZE=n
> [!WARNING]
> lseek() and global variables are forbidden

### Bonus
* One static variable
* Manage multiples files descriptors

> [!Caution]
> * Check valgrind leak
> 
> * Don't forget to free stdin 
