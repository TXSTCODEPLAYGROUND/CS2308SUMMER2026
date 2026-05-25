# Unit-05: UNIX Programming & Shell Scripting

Welcome to Unit-05! In this unit, we explore UNIX programming and shell scripting using Bash. Shell scripting is essential for automating repetitive tasks, processing text, managing system resources, and much more. This guide covers the basics of Bash scripting—from variable declarations and conditionals to loops and system commands—along with practical examples and tricky questions to deepen your understanding.

---

## 1. Introduction to UNIX Programming & Bash

### Overview & Concepts
UNIX programming and shell scripting allow you to:
- **Automate Tasks:** Write scripts to manage files, monitor systems, and perform batch processing.
- **Process Text:** Use powerful tools like `grep`, `awk`, and `sed` for data extraction and manipulation.
- **Enhance Portability:** Scripts written in Bash run on any UNIX-like system (Linux, macOS, BSD, etc.).
- **System Management:** Manage processes, network tasks, and system resources efficiently.

**Philosophy:**  
The UNIX philosophy is to build simple, modular programs that do one thing well and combine them to perform complex tasks.

---

## 2. Bash Scripting Basics: Variables & Special Variables

### Declaring and Using Variables
- **Declaring Variables:** In Bash, you declare variables without spaces around the equals sign.
  ```bash
  #!/bin/bash
  greeting="Hello, World!"
  echo "$greeting"
  ```

- **Special Variables:**  
  - `$0`: Name of the script.
  - `$1`, `$2`, …: Command-line arguments.
  - `$#`: Number of arguments.
  - `$?`: Exit status of the last command.
  - `$$`: Process ID of the script.

### Exporting Variables
- **Exporting:** Allows child processes to access variables.
  ```bash
  #!/bin/bash
  name="Alice"
  export name
  ./child_script.sh  # child_script.sh can now use $name
  ```

### Tricky Questions
1. **Q:** What happens if you reference an undeclared variable in Bash?  
   **A:** It expands to an empty string. This might lead to unexpected behavior if not handled properly.

2. **Q:** How do you display the number of arguments passed to a script?  
   **A:** Use the special variable `$#`.

3. **Q:** Why is it important to export a variable?  
   **A:** Exporting a variable makes it available to any subprocesses spawned by the script, ensuring that child scripts have access to the necessary environment variables.

---

## 3. Conditionals and Expressions

### Using Conditionals in Bash
Bash provides several ways to evaluate conditions:
- **Test Command:**  
  ```bash
  #!/bin/bash
  num=10
  if [ $num -gt 5 ]; then
      echo "Number is greater than 5"
  else
      echo "Number is not greater than 5"
  fi
  ```
  
- **Double Brackets:**  
  ```bash
  if [[ $num -gt 5 ]]; then
      echo "Number is greater than 5"
  fi
  ```

- **String Comparisons:**  
  ```bash
  str1="apple"
  str2="banana"
  if [ "$str1" \< "$str2" ]; then
      echo "$str1 comes before $str2"
  fi
  ```

### Test Commands and Comparison Operations
- **Comparison Operators:** `-eq`, `-ne`, `-lt`, `-le`, `-gt`, `-ge`
- **Logical Operators:** `&&` (and), `||` (or), `!` (not)

### Tricky Questions
4. **Q:** What is the difference between `[ ]` and `[[ ]]` in Bash?  
   **A:** `[ ]` is the POSIX test command and has more limitations, while `[[ ]]` is a Bash keyword that offers enhanced pattern matching and safer syntax.

5. **Q:** How do you compare two strings for equality in Bash?  
   **A:** Use `=` or `==` within double brackets: `[[ "$str1" == "$str2" ]]`.

6. **Q:** Why must you quote variables in test conditions?  
   **A:** To prevent word splitting and globbing, ensuring that empty or multi-word variables are handled correctly.

---

## 4. Loops: For and While

### For Loops
For loops iterate over a list of items or ranges:
```bash
#!/bin/bash
# Iterating over a list
for color in red green blue; do
    echo "Color: $color"
done

# Iterating over a range
for i in {1..5}; do
    echo "Number: $i"
done
```

### While Loops and Reading Files
While loops are often used for reading file content:
```bash
#!/bin/bash
# Using a while loop to read a file line by line
IFS=  # Set Internal Field Separator to default (or customize as needed)
while IFS= read -r line; do
    echo "Line: $line"
done < file.txt
```

**Shebang:**  
The line `#!/bin/bash` at the top of your script tells the OS to use the Bash interpreter.

### Tricky Questions
7. **Q:** What does the `IFS` variable do in a Bash script?  
   **A:** IFS (Internal Field Separator) defines how Bash splits strings into words; setting it appropriately is crucial when reading input.

8. **Q:** How can you ensure that backslashes in input are treated literally in a read command?  
   **A:** Use the `-r` flag with `read`, as in `read -r line`.

9. **Q:** What is the difference between a `for` loop and a `while` loop in Bash?  
   **A:** A `for` loop iterates over a predetermined list of items or a range, whereas a `while` loop continues until a condition fails (often used for file reading or waiting for an event).

---

## 5. System Monitoring & Process Management

### Overview & Concepts
Bash scripting allows you to interact with system processes and monitor resources using built-in commands.

### Examples
- **Viewing Running Processes:**
  ```bash
  #!/bin/bash
  echo "Current processes:"
  ps aux
  ```
  
- **Monitoring Disk Usage:**
  ```bash
  #!/bin/bash
  echo "Disk usage:"
  df -h
  ```

- **Killing a Process:**
  ```bash
  #!/bin/bash
  pid=1234  # replace with actual process ID
  kill $pid && echo "Process $pid terminated"
  ```

### Tricky Questions
10. **Q:** How can you display detailed information about all running processes?  
    **A:** Use `ps aux`.

11. **Q:** What command would you use to monitor real-time system performance?  
    **A:** The `top` or `htop` command.

12. **Q:** How would you safely terminate a process from a script?  
    **A:** Use the `kill` command with the process ID, optionally checking if the process exists before terminating it.

---

## 6. Networking & File Transfers

### Overview & Concepts
Shell scripts can automate network operations and file transfers.

### Examples
- **Using `wget` to Download a File:**
  ```bash
  #!/bin/bash
  url="http://example.com/file.txt"
  wget "$url" -O downloaded_file.txt
  ```
  
- **Using `curl` to Fetch Data:**
  ```bash
  #!/bin/bash
  url="http://api.example.com/data"
  response=$(curl -s "$url")
  echo "Response: $response"
  ```

### Tricky Questions
13. **Q:** What is the main difference between `wget` and `curl`?  
    **A:** `wget` is designed primarily for downloading files recursively and handling downloads robustly, while `curl` is a more versatile tool for transferring data with support for many protocols.

14. **Q:** How can you save the output of a `curl` command into a variable?  
    **A:** Use command substitution, e.g., `response=$(curl -s "http://example.com")`.

15. **Q:** Why might you prefer `wget` over `curl` when downloading large files?  
    **A:** `wget` supports recursive downloads, download resumption, and is optimized for robust file downloading.

---

## 7. Powerful Text Processing with GREP

### Overview & Concepts
`grep` is a command-line utility used for searching text using regular expressions. It is indispensable for log analysis and text processing.

### Basic Usage
```bash
#!/bin/bash
# Search for the term "error" in log.txt
grep "error" log.txt
```

### Extended Regular Expressions
```bash
#!/bin/bash
# Use extended regular expressions with grep -E
grep -E "error|failure" log.txt
```

### Tricky Questions
16. **Q:** What does the command `grep -i "warning" file.txt` do?  
    **A:** It searches for the term "warning" in file.txt, ignoring case differences.

17. **Q:** How do you use grep to display line numbers of matching lines?  
    **A:** Use the `-n` flag: `grep -n "pattern" file.txt`.

18. **Q:** What is the purpose of using extended regular expressions with grep?  
    **A:** They allow for more complex and flexible pattern matching, making it easier to search for multiple patterns simultaneously.

---

## 8. Additional Tips & Best Practices in Bash Scripting

### Overview & Concepts
- **Shebang:** Always start your scripts with `#!/bin/bash` to specify the interpreter.
- **Comments:** Use `#` to add comments for clarity.
- **Error Handling:** Use `set -e` to make your script exit on errors.
- **Script Permissions:** Ensure your script is executable with `chmod +x script.sh`.
- **Portability:** Write scripts that avoid bash-specific features if you require POSIX compatibility.

### Tricky Questions
19. **Q:** What does the `#!/bin/bash` line in a script indicate?  
    **A:** It specifies that the script should be executed using the Bash shell.

20. **Q:** How do you make a Bash script executable?  
    **A:** By running `chmod +x script.sh` in the terminal.

21. **Q:** Why is error handling important in shell scripts, and how can you enforce it?  
    **A:** To prevent the script from continuing in an unexpected state; you can enforce it with `set -e` which exits the script when a command fails.

22. **Q:** What is the benefit of using comments in your scripts?  
    **A:** They improve readability and maintainability by explaining the purpose and functionality of the code.

---

## 9. Conclusion

This Unit-05 guide has provided a comprehensive look at UNIX programming and shell scripting with Bash:
- **Introduction:** The importance and power of shell scripting.
- **Variables & Special Variables:** Declaring, exporting, and using built-in variables.
- **Conditionals & Expressions:** Evaluating conditions with `[ ]` and `[[ ]]`.
- **Loops:** For loops, while loops, and file reading techniques.
- **System Monitoring & Process Management:** Managing processes and resources.
- **Networking & File Transfers:** Automating downloads with `wget` and `curl`.
- **Text Processing with GREP:** Searching and analyzing text data.
- **Best Practices:** Tips for writing robust, portable, and maintainable Bash scripts.