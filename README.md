<p align="center">
<img src="https://i.ibb.co/H4VJ6Yf/linux-simple-shell.png">
</p>

## Description 

The simple_shell project is an attempt to replicate the behavior of the Linux sh shell.
I have invited my friend to collaborate on this project with me as a second pair of eyes, to help identify potential flaws and suggest improvements. This project is also designed with the purpose of assisting beginer Linux developers in understanding the underlying processes and workings of the Linux system, as well as getting them familiar with some concepts in the C programming language.

- **Emulating sh Shell:** Our shell aims to mimic the behavior of the sh shell, both in terms of output and error handling.
- **Learning Process:** During this project, we delved into:
  - Understanding the workflow of a command-line interpreter.
  - Learning about process IDs (pid) and parent process IDs (ppid).
  - Managing processes and manipulating the environment.
  - Distinguishing between functions and system calls.
  - Creating new processes and executing commands with execve.
  - Handling PATH variables.
- **Code Quality:** strong emphasis was placed on writing beautiful code following the Betty style guide and most importantly avoiding memory leaks.

## Usage 

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

## Built-ins 

* exit & exit(status)
	* env
	* setenv & unsetenv

## Examples

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


## Project files 

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

	`$ ./man_1_simple_shell.3`

## Authors 

- Rotimi Owolabi -[@rohteemie](https://github.com/rohteemie)
