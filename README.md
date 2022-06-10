<p align="center">
<img src="https://https://www.alxafrica.com/wp-content/uploads/2022/01/header-logo.png">
</p>

<h1 align="center"> simple_shell project </h1>

### Description
In simple_shell project we code from zero our own custom printf function. Our shell must have the same behavior than **sh** shell in output and error. We had to learn about the workflow of a command line interpreter, what's a pid and ppid, learn about manage processes, how to manipulate the environment of the current process, the difference between a function and system call, how to create processes, how to get PATH variables, execute commands with execve. And off course be carefull with memory leaks and write beautiful code with Betty style.

### Usage
First, you have to clone this repo ```$git clone https://github.com/rohteemie/simple_shell.git```

Compile

	gcc -Wall -Werror -Wextra -pedantic *.c -o executable_filename

Execute: see more in <a href="#examples">examples<a/>
``` bash
Interactive mode:
$ ./hsh
./hsh$ [put_commands and_arguments]

Non-interactive mode
$ echo "[put_commands and_arguments]" | ./hsh
```

### Built-ins
* exit & exit(status)
* env
* setenv & unsetenv

### Examples
<div id="examples"><div/>

1. Absolute path commands
- non interactive
```bash
$ echo "/bin/pwd" | ./hsh
$ /home/rohteemie/simple_shell
```
- interactive mode
``` bash
$ ./hsh
./hsh$ /bin/echo hello world
helo world
./hsh$ exit
$
```
2. short command
- non interactive
```bash
$ echo "pwd" | ./hsh
$ /home/rohteemie/simple_shell
```
- interactive mode
``` bash
$ ./hsh
./hsh$ echo hello world
helo world
./hsh$ exit
$
```
3. built-ins
- non interactive
```bash
$ echo "exit" | ./hsh
$ echo $?
0
```
- interactive mode
``` bash
$ ./hsh
./hsh$ exit 98
$ echo $?
98
```

**Some error output**
``` bash
$ ./hsh
./hsh$ ls /non_existing_folder
ls: cannot access '/non_existing_folder': No such file or directory
./hsh$ exit
$ echo $?
2
```
``` bash
$ echo "non_valid_command" | ./hsh
./hsh: 1: non_valid_command: not found
$ echo $?
127
```
	 

### Project files
| File        | Description |
| ----------- | ----------- |
| AUTHORS     | File with names of the owners and authors of this project |
| Readme.md   | Nutshell description of simple_shell project |
| aux_funs.c  | Auxiliar functions <br> **signal_exit:** handler for SIGINT signals <br> **_calloc:** allocate memory and fills it with zeros
| built-ins.c | Built-ins functions: <br> **check_word:** evalute alpha chars in string <br> **exit_built_in:** stop execution of shell <br> **env_built_in:** prints environment variables |
| core_funs.c | Heart of simple_shell <br> **check_builtin:** check if first argument is a built-int <br> **not_found_error:** handler for print error when command is not found <br> **simple_exec:** decision flow for command execution|
| path_funs.c | Function to check command in path <br> **_getenv:** search variable in environment vars <br> **cmd_path:** concat first argument with PATH dirs |
| shell.h     | Header file <br> **All includes** <br> **All prototypes** <br> **Definition of struct params** |
| simple_shell.c | Initialize the simple_shell execution: <br> **test:** <br> Remove \n last char readed with getline <br> Tokenize and save in argv all arguments readed <br> Calls simple_exec <br> **main:** <br> Initialize params struct vars <br> Set signal listenes <br> Print prompt (interactive mode) <br> Read arguments with getline <br> Handle CTRL + D to stop execution|
| string_funs.c  | First string functions file <br> **_strcat:** concat string (no malloc) <br> **_strlen:** get length of string <br> **rev_string:** reverse a string <br> **_itoa:** convert int to string <br> **_strcmp:** compare two strings |
| string_funs2.c  | Second string functions file <br> **_strchr:** search char in string <br> **_strcpy:** copy string in other one <br> **str_concat:** concat string (malloc) <br> **_atoi:** convert string num, to int|


### Full documentation
For more info about this project you can run the man page:

`$ ./man_1_simple`

### Flowchart
Go to this link to see the flowchart of our project: [flow chart](https://app.diagrams.net/?lightbox=1&highlight=0000ff&layers=1&nav=1&title=shell.drawio#R%3Cmxfile%20pages%3D%225%22%3E%3Cdiagram%20id%3D%22ZPFKSTzHN-5zQBHHbEto%22%20name%3D%22start%22%3E7Vxbc9o4FP41zLAPMJZ85RFIms02TTulnW32JSNAgFtjeW0RIL%2B%2Bki3jixwgxMRKprxgHUuydc75zk2Clj5cbq5CFCw%2BkSn2WlCbblr6RQtCALUe%2B%2BKUbUKxbJgQ5qE7FZ0ywsh9xIKoCerKneKo0JES4lE3KBInxPfxhBZoKAzJuthtRrziUwM0xxJhNEGeTP3XndJFQnWgndH%2Fxu58kT4ZWGLBS5R2FiuJFmhK1jmSftnShyEhNLlabobY48xL%2BXJ987gcOH3Anvxr%2BPHD4p%2F%2FUL%2BTTPbhOUN2SwixT0%2BeGn0En6Lrxy%2FBxffoOx197fz0%2FY6Q5QPyVoJfYq10mzIQTxk%2FRZOEdEHmxEfeZUYdhGTlTzF%2FjMZaWZ8bQgJGBIz4E1O6FcqBVpQw0oIuPXH3yPUJPkRkFU7wnkUJeVEUzjHd00%2FMxxeY0xXBvStMlpiGW9YhxB6i7kNRoZDQy%2FmuX8Z7diHY%2FwxRaJIoRt%2F6X7%2FJ8vA8hh3O9%2FXCpXgUoJgZawbfl3D1AYcUb%2FbyQdzVLdA1k0HrDFFAE7RFDk2mdSZmWe9Rb1PzeEhvTaX0FkiiuPZd6iKPc43Tw6gFLY8taDAO2dWcX6GHFhzyNTALz4haPFDTEqLH%2BZ%2FSgDzYw355CJMBWkb8Qu4edAsTJg25k4%2BWeNeJvZ850FrmRVVPvHHpfbLe3GvI%2FdgU8er5LKLf7febG0lTMz0EDaLaEJjapo5QkzGuWzLGQeof69csTWLVK4CaS%2FdH7vqOT8UMXtK62IiZ48Y2bfhsvT%2Fyjdwo3syGxa10XM0GxDzSgNhqGRCjSTFnor3L3Tkk5kyydwXBKiVmoFaAY8oBDnt9tl53zgTHLbMbUezjKn8xur66vmWxkNZhFLTkNjGmx8PZ6Hsup8ph30ZfKoexW%2FfXV7eKGmPTKBhj2KswxqndzRtj61y22JaEl4gtZnz7L4mNLFkK%2BGUQkgmOosOsHKPJr3nM%2FM8r6rk%2BPjOLTUdTjMXAatQOnuTunmcHZ8SnQ%2BKxiI%2BvTtfiDw%2Fo0Bh7g50CpF18wrWg9ij72DAbqBVnQxmCt58rNeaGs5MH2R6DKCNPGOMwY%2BiAo8OdIK8vbizd6TTRIhy5j2gcT8IFEhDXp%2FECzAEPX58WHacL3QLwkHHcq%2FYSdHc1IfFirXzZpQrSHaaOBtALsO6I5tEyErN%2F4RzIpgZm14G93McpPEUvzkdms4i7tpLEd298uhLocpWgCaOxH7BlnXhKd5oCNuwpBWxdzqDvLkd7kZ0TRd0gP01w%2B5X1xcjWusA2zSKwQT3ALk1qdS37tcAMZMGLekg5jk0pUYD8glZY%2F694%2BTmWVGeGlq7HXqjPyw1pvMvkphtcT0KXB9klatyTF1Ai5EedCIfuLK5V8BvxnFGsDnxGYASb3T0mT9oRqsdvenhGs7fZvfYlbDm9Vr%2BiOpJSGOOSRSXky88f2GztDpAjynBBluPVEZHk2YJyq1ghMWw5YuxVFUi0s0WMjhLeoG47fnR%2Bq1gdQ05wZyHG7aA7Xs1mFQqtQqYJ7GIaZBpNp0FQtorqhzh1Q8A%2BFgJqhTJQNkjvI5SBTwHrlCQFQKMUdrwwSTl%2FqAJl2%2FYePM2xMIOGUjADcinAjRBjXDuiU9dXMHYCvaKbsSrcjFPhZZyzhU49iYXrkLGmDZJ4OBfMmkM%2FH9ryu1XhaaPePGWr2bj3NiS%2BYn8q24qmDzEA2%2B4WE0rbquDdqx5q0HUljKySxZ20ZnPQVOtQKVMNZTszWpA1Z01IlkHFnlXxSARbLN8MadeQQpxHcqdvajVvrHSnCXydsuOiJCbrh1p1jU6HpRy1fOIkMQpiVKYT%2FTBE21w3kSUc%2FRzbcUoqlsxYb0VfNhAsvUG%2FKjXzbSVNKbxqSZq0ngYL0nlh%2Fff8OZMBJcm%2Bj2S4VrnaplXTFh3s6lVbdK8gaDnm%2FRO3lXzEwbjN0JWK23QZvOneTLKD4o%2Bj4A3vzMTBZeeJXRggqW%2FjBYTy5oudGqHGNl8MNc6gK4n6FMyHUa%2FWGRtDLqy9D5dt1HnIBprF0y8v3Yo%2Fv4c23%2BKekmpYTdN1VbAqV8velYfOzk5kv4Ep%2BWn13bTjNH1GwpDz6z%2FQL3nfw27aUQv68m5ksWpKcUTbwRuvl5qlclRPa7peasjb%2B5zTEptrO%2FyvmgiA1rgMzEbM1ym%2FllLS5NUfxFRXowxQ3OwwwHlq1uXnAKCX%2FgagNMDWtZcNSFdy1qp4Kqacpan4ES%2FrNEjCo7ds58v7YkA748YYa2b%2FWJFIK%2FvfD%2F3yNw%3D%3D%3C%2Fdiagram%3E%3Cdiagram%20id%3D%22wnPK8H0QMCBDu31KDfzO%22%20name%3D%22test%22%3E7Vxbc5s4FP4t%2B8A03Zl0QFz9GCdpdnayu%2Bmk6W72pSODbGgwYkEkdn79SiCuosFu7QCO82BLBwmsc%2FRJ5ztHRFLPl6urCIbuH9hBvgRkZyWpFxIACpAn9ItJ1pnEMEEmWESewxuVglvvGXGhzKWJ56C41pBg7BMvrAttHATIJjUZjCL8VG82x379qSFcIEFwa0NflP7tOcTNpBYwS%2FlvyFu4%2BZMVgw94CfPGfCSxCx38VBGpl5J6HmFMstJydY58prxcL8By1%2FKFLd%2F9%2FsU%2FsxY360%2Bzf0%2Bzm33cpksxhAgF5Idv%2FWUWXJF5OPn86fme2Kd362Vyc8pt%2BQj9hOuLj5WscwUih%2BqTV3FEXLzAAfQvS%2Bk0wkngIPYYmdbKNtcYh1SoUOE3RMiaTw6YEExFLln6%2FKoPZ8ifQvthkd7qHPs4opcCHLDbz3FAeFcF8HreRAKqnP5R%2BYZa4tqMcRLZ6AXVcKsTGC0QeaEdvx9TU2XGcRtcIbxEJFrTBhHyIfEe69MS8tm9KNqVFqQFbsQtDCoLBv2MYiIa1fcpAJl2n1yPoNsQprp4omtA3TTbKfURRQStXlQDv6oaygc967SuLxhPJUoVmTdxKwjVjT2pTjtioWOOd2JBHRQWFMGgHtUGHcZDIAHDpwOZziJaWrCS7UJaln%2BFyYp%2Bpc3lP%2B%2Bur4U5UFpY6YbPfuy1Bcx0rQ6yNpTlG1wVZYa8J6MYR5R1oKcTZfqgUKYKBq1CKCaR7UYns2Q%2BlwB9gPxO0s%2BDd%2B8PC1atm9erwso6wqoDLp2wMgcFq4lg0PvL21abXjOl1%2B0AfW8R0LJNNYioeqdsanuUFJ3xC0vPcTKTo9h7hrP0fkz3IaZ7ZDoWfSrpFz9ltRcnahNrBQPkP0aqkqw2DJ7KH4BmgDoOs9rGFuI3v8GZY5A3wfN5jIhgwuI3%2FIRLIvokR5xuidN8rR0IUPX2%2Fa%2B5vbl4OUviEWxtZn1rU1Vxa7NadjZrXzubavaBELTyyD%2BsO2WpWe2%2BcuVixe%2BcVtZ5JaDjrXRi1fvqtbJbWsv7vYxGFDhnLA5Wk3z0mBLT3j2h1RwnWk0BrTXGx7xT%2BjFq51TPHc8cwVrfzqkicoTjrtfARzeQwKCApIiRxjSuwoEkixGW8JSW4JKhJa3TAT8W7b9S59TH9okCrIwnWmOniMCooVBrQ6FpvCYKj6GXTnB1o3BYwRdF3M8OgyYWk3UnPNGSed8BM0OR8B%2FRuTU6rWGhEwg2%2FYXppXUjPBTCqGu

#### Authors
Rotimi Owolabi -[rohteemie](https://github.com/rohteemie)<br>
Solomon John - [@slomon](https://github.com/Slomon80)<br>
