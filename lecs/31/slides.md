---
theme: default
class: 
    - lead
    - invert
size: 4:3
paginate: true
marp: true
---
# Comp. Prog.
## Multi File | Command Line Args | Macros

---

# Multifile programming

- all structure declarations, function declarations in `.h` file
- all function definitions in `.c` file
- main function in `_main.c` file

### Reference
https://beej.us/guide/bgc/html/split/multifile-projects.html#multifile-projects

---
# Command line Arguments

```c
int main(int argc, char const *argv[]) {

    printf("argc value is %d\n", argc);
    for (int i = 0; i < argc; i++) {
        printf("argv[%d] value is %s\n", i, argv[i]);
    }
    ...
```

### Reference

https://beej.us/guide/bgc/html/split/the-outside-environment.html#command-line-arguments

---
# Macros

- Open a file using `fopen()` function and store its reference in a `FILE` pointer say `fPtr`.
- You must open file in `r`(read) mode or atleast mode that support read access.

- Read content from file using any of these functions `fgetc()`, `fgets()`, `fscanf()` or `fread()`.
Finally, close the file using `fclose(fPtr)`.

### Reference

https://beej.us/guide/bgc/html/split/the-c-preprocessor.html#simple-macros

---
