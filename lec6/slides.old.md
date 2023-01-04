---

# Struct for a Person
```c
typedef struct Person {
    char name[100];
    int age;
    int gender;
} Person;
```


---
# Enums

```c
typedef enum Gender {
    Woman = 0,
    Man = 1,
    Transgender = 2,
    NonBinary = 3,
    PreferNoResponse = 4
} Gender;

typedef struct Person {
    char name[100];
    int age;
    Gender gender;
} Person;

```





---
# Header Files




---
# Problem: Compiling is complicated 

```bash
gcc 1_learn_draw.c allegro.c -o 1.out \
     -lm -lallegro_primitives -lallegro
```

---

# Problem with Compiling   
# large projects

- Even if small number of files are changed, will compile everything!


---
# Solution: Make files
Recompile only files that are needed.

Make files specify **dependencies** between files and recompiles only what is needed.

---
# Makefile
```make
LDLIBS = -lm -lallegro_primitives -lallegro 

1.out : 1_learn_draw.o allegro.o
    cc -o 1.out 1_learn_draw.o allegro.o $(LDLIBS)

2.out : 2_rec_drawing.o allegro.o
    cc -o 2.out 2_rec_drawing.o allegro.o $(LDLIBS)

1_learn_draw.o : 1_learn_draw.c allegro.h
    cc -o 1_learn_draw.o 1_learn_draw.c $(LDLIBS)

2_rec_drawing.o : 2_rec_drawing.c allegro.h
    cc -o 2_rec_drawing.o 2_rec_drawing.c $(LDLIBS)

allegro.o : allegro.c allegro.h
    cc -o allegro.o allegro.c $(LDLIBS)

clean:
	rm -f *.out *.o
```
---
# Makefile simplified

```make
LDLIBS = -lm -lallegro_primitives -lallegro 

1.out : 1_learn_draw.o allegro.o
    cc -o 1.out 1_learn_draw.o allegro.o $(LDLIBS)

2.out : 2_rec_drawing.o allegro.o
    cc -o 2.out 2_rec_drawing.o allegro.o $(LDLIBS)

prog_objs = 1_learn_draw.o 2_rec_drawing.o allegro.o

$(prog_objs) : allegro.h

clean:
	rm -f *.out *.o
```
