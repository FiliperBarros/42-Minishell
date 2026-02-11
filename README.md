_This project has been created as part of the 42 curriculum by benes-al and frocha-b._

# MINISHELL


## DESCRIPTION

Minishell is a simplified implementation of a Unix shell, developed as part of the 42 School curriculum.  
The goal of this project is to deepen our understanding of:

- Parsing and lexical analysis
- Environment variables
- Builtins for essential commands (`echo`, `cd`, `pwd`, `export`, `unset`, `env`, `exit`) implemented internally to modify the shell’s state
- Process creation and management
- Pipes
- File descriptors and redirections
- Signal handling
- Terminal interaction
- Careful memory management to avoid leaks
- First `large-scale` project, emphasizing modular organization and maintainable code

The shell reproduces essential behaviors of `bash`, allowing users to execute commands, chain them with pipes, redirect input/output, and manage environment variables, all within a custom interactive prompt.


## EXECUTION FLOW

Below is the visual logic of how the shell handles input, parsing, and execution:

<p align="center">
  <img src="https://github.com/user-attachments/assets/9da56557-5248-415e-98cc-e618f588ccdb" alt="Minishell Flowchart" width="800">
</p>

## INSTRUCTIONS

### Step 1: Compilation
After downloading the repository, navigate into the project folder.  
To compile the project, run the following command in the terminal:

```bash
make
```
This will generate the executable:

```bash
./minishell
```

### Step 2: Execution
Start the shell by running:

```bash
./minishell
```
You will see a custom prompt:

```
minishell> 
```

You can then type commands just like in a standard shell.
For example:

```bash
ls -la | grep minishell > files.txt
```
### Step 3: Exit

To exit the shell, you can either:

```bash
exit
```

or press Ctrl-D on an empty line, just like in Bash.

### Additional Commands

To clean object files:

```bash
make clean
```
To remove all compiled files:

```bash
make fclean
```
To recompile the project:

```bash
make re
```

## RESOURCES

### References

The following references were used to understand key concepts of Minishell:

- **Bash Reference Manual** – for understanding shell behavior and expected command execution.  
- **Linux man pages** – for system calls such as `fork`, `execve`, `pipe`, `dup2`, `wait`, and `signal`.  
- **YouTube tutorials** – for practical demonstrations and examples:  
  - Pipes tutorial: [https://www.youtube.com/watch?v=QD9YKSg3wCc&list=PLK4FY1IoDcHG-jUt93Cl7n7XLQDZ0q7Tv]
  - Code organization and practical examples: [https://www.youtube.com/watch?v=SToUyjAsaFk&t=653s]  

### Use of AI

Artificial intelligence tools were used as a learning assistant to:

- Clarify UNIX concepts such as signals, pipes, and process flow  
- Improving code readability and organization  
- Enhancing documentation and wording for clarity
