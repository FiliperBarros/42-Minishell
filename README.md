# minishell

execve(ENOENT,EACCESS)

frocha-b@c1r2s1:~/cc/minishell$     skip_tokens addd o \0
Command '' not found, but can be installed with:

frocha-b@c1r2s1:~/cc/minishell$ .
bash: .: filename argument required
.: usage: . filename [arguments]
frocha-b@c1r2s1:~/cc/minishell$ export a=1 b=$a a=$b
frocha-b@c1r2s1:~/cc/minishell$ export
declare -x a=""
declare -x b=""
frocha-b@c1r2s1:~/cc/minishell$ ./bash
bash: ./bash: No such file or directory
frocha-b@c1r2s1:~/cc/minishell$ ^C
frocha-b@c1r2s1:~/cc/minishell$ env -i ./bash
env: ‘./bash’: No such file or directory
frocha-b@c1r2s1:~/cc/minishell$ env -i bash
frocha-b@c1r2s1:/home/frocha-b/cc/minishell$ env
PWD=/home/frocha-b/cc/minishell
SHLVL=1
_=/usr/bin/env
frocha-b@c1r2s1:/home/frocha-b/cc/minishell$ cd | cd
bash: cd: HOME not set
bash: cd: HOME not set
frocha-b@c1r2s1:/home/frocha-b/cc/minishell$ exit
frocha-b@c1r2s1:~/cc/minishell$ cd | cd
frocha-b@c1r2s1:~/cc/minishell$ cd
frocha-b@c1r2s1:~$ cd -
/home/frocha-b/cc/minishell
frocha-b@c1r2s1:~/cc/minishell$ 

frocha-b@c1r2s1:~/cc/minishell$ test="a b"
frocha-b@c1r2s1:~/cc/minishell$ <$test echo
bash: $test: ambiguous redirect
frocha-b@c1r2s1:~/cc/minishell$ test="a"
frocha-b@c1r2s1:~/cc/minishell$ <$test echo hello
bash: a: No such file or directory
frocha-b@c1r2s1:~/cc/minishell$ test="a b"
frocha-b@c1r2s1:~/cc/minishell$ <$test cat
bash: $test: ambiguous redirect
frocha-b@c1r2s1:~/cc/minishell$ cat $test
cat: a: No such file or directory
cat: b: No such file or directory
frocha-b@c1r2s1:~/cc/minishell$ <<EOF cat
> hello
> $SHELL
> $SHLVL
> EOF
hello
/bin/zsh
4
frocha-b@c1r2s1:~/cc/minishell$ <<"EOF" cat
> hello
> $SHELL
> $SHLVL
> EOF
hello
$SHELL
$SHLVL
frocha-b@c1r2s1:~/cc/minishell$ <<EOF"" cat
> hello
> $SHELL
> $SHLVL
> EOF
hello
$SHELL
$SHLVL
frocha-b@c1r2s1:~/cc/minishell$ cat $a
^C
frocha-b@c1r2s1:~/cc/minishell$ cat $test
cat: a: No such file or directory
cat: b: No such file or directory
frocha-b@c1r2s1:~/cc/minishell$ cat asd$test
cat: asda: No such file or directory
cat: b: No such file or directory
frocha-b@c1r2s1:~/cc/minishell$ test="o hello"
frocha-b@c1r2s1:~/cc/minishell$ ech$test
hello
frocha-b@c1r2s1:~/cc/minishell$ test=echo
frocha-b@c1r2s1:~/cc/minishell$ $test hello
hello
frocha-b@c1r2s1:~/cc/minishell$ <<EOF cat | <<EOF1 cat | <<EOF2 cat
> EOF
> EOF1
> EOF2
frocha-b@c1r2s1:~/cc/minishell$ ^C
frocha-b@c1r2s1:~/cc/minishell$ cat | <<EOF cat
> asf
> EOF
asf
asd

to check:
	name=a    a  /home/frocha-b



SIGPIPE