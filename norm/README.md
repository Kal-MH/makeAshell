# Subject

## Goal

bash shell 기능을 모방한 minishell 만들기

## Basic Concepts

### Functions

- readline
- rl_on_new_line
- rl_replace_line
- rl_redisplay
- add_history
- printf, malloc, free, write, open, read, close
- fork, wait, waitpid, wait3, wait4
- signal, kill, exit
- getcwd, chdir
- stat, lstat, fstat
- unlink
- execve
- dup, dup2
- pipe
- opendir, readdir, closedir
- strerror, errno
- isatty, ttyname, ttyslot
- ioctl
- getenv
- tcsetattr, tcgetattr, tgetent, tgetflag, tgetnum, tgetstr, tgoto, tputs

### Need to know

# Implementation

1. 라이브러리 세팅 및 구조체 정의
2. 전체 동작과정 정의
    1. input
        1. prompt
        2. save history
    2. tokenizer : 의미있는 단위로 쪼개기
        1. 자료구조 선정
    3. parser
        1. command array?
    4. exec
    5. free
        1. token
        2. input
        3. (command array)
        4. (환경변수, 지역변수)
3. 고려사항
    1. 환경변수, 지역변수, command 라인 자료구조
    2. 각각의 명령어 실행 시 예외사항 및 에러 처리
    3. memory leaks

# Evaluation

- [ ]  Norminette

### Mandatory Part

1. 동작
    1. one global variable
    2. show **prompt**.
    3. **working history**
    4. based on PATH variable or by using relative or absolute path.
2. builtins
    - **echo** with option -n
    - **cd** with only a relative or absolute path
    - **pwd** with no options
    - **export** with no options
    - **unset** with no options
    - **env** with no options or arguments\
    - **exit** with no options
3. redirections
    - < should redirect input.
    - **>** should redirect output.
    - **“<<”** read input from the current source until a line containing only the delimiter is seen. it doesn’t need to update history!
    - **“>>”** should redirect output with append mode.
4. pipes
5. variables
    1. **env**
    2. **$?**
6. interrupt
    1. **ctrl-C** print a new prompt on a newline.
    2. **ctrl-D** exit the shell.
    3. **ctrl-\** do nothing.

---

### Bonus
