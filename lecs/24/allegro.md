---
theme: default
class: 
    - lead
    - invert
size: 4:3
paginate: true
marp: true
---

# Now Some Drawing

---
# Allegro Library (simplified)
```c
#include <allegro5/allegro5.h>
#include <allegro5/allegro_primitives.h>

ALLEGRO_EVENT_QUEUE* queue = NULL;
ALLEGRO_DISPLAY* disp = NULL;

// Checks a condition `test`. 
// If false, prints out a `description` and exits
void must_init(bool test, const char *description)

// Initialization logic of allegro library
// creates queue or disp
void allegro_init()

// frees all the memory allocated by allegro
void allegro_close()
```
---
# Allegro Library (simplified)
```c
int main() {

    allegro_init();
    
    ALLEGRO_EVENT event;

    draw();

    // wait for some event to enter the queue.
    // In this case, it is only the event 
    // for closing the window
    al_wait_for_event(queue, &event);
    allegro_close();

    return 0;
}
```
---
# Multifile Code Organization
## Problem: 
- We want to write many program that use Allegro (1_learn_draw.c, 2_rec_drawing.c). 
- Then the functions defined in slide 3 has to be repeated in both the files.
## Solution:

Seperate the common code into ``allegro.h`` and ``allegro.c``

---

# Step 1: Declare in ``allegro.h``
Write a ``allegro.h`` that 
- includes the allegro, stdio, math header files
- declares variables ``disp``, ``queue`` (as extern; but do not initialize).
- declares the functions (also called prototypes)

```c
#include <allegro5/allegro5.h>
#include <allegro5/allegro_primitives.h>
#include <math.h>
#include <stdio.h>
// These are initialized in allegro.c
extern ALLEGRO_EVENT_QUEUE* queue;
extern ALLEGRO_DISPLAY* disp;
// Functions bellow are defined in allegro.c
void must_init(bool test, const char *description);
void allegro_init();
void allegro_close();
```
---
# Step 2: Define in ``allegro.c``
```c
#include "allegro.h"
ALLEGRO_EVENT_QUEUE* queue = NULL;
ALLEGRO_DISPLAY* disp = NULL;

void must_init(bool test, const char *description) {
    ...
}
void allegro_init() {
    ...
}

void allegro_close() {
    ...
}
```
---
# Step 3: Include ``allegro.h``
- Include ``allegro.h`` in both ``1_learn_draw.c`` and ``2_rec_drawing.c``.
```c
#include "allegro.h"
void draw() {
...
}

int main() {
...
}
```
---
# Step 4: Compile together

```bash
gcc 1_learn_draw.c allegro.c -o 1.out \\
     -lm -lallegro_primitives -lallegro 


gcc 2_rec_drawing.c allegro.c -o 2.out \\
     -lm -lallegro_primitives -lallegro 

```
---

# Recursive Tree Drawing
![](tree.jpg)

---
# Recursive Tree Drawing
- ``3_tree_drawing.c``
```c
#include "allegro.h"

// draws a line starting at (x, y), at an angle, with length len
// recursion goes to 11 level
// at the last two levels, line is drawn in green.
void drawTree(int x, int y, float angle, float len, int level) {
    // the other end point of the line, is obtained 
    // by moving len distance at an angle
    int x2  = x + len*cos(2*3.14*angle/360.0); 
    int y2  = y - len*sin(2*3.14*angle/360.0);

    // if level < 10 give brown color otherwise green
    ALLEGRO_COLOR c =  al_map_rgb_f(1,1,1) ; 
     
    // set line width to 5 if level <= 2
    al_draw_line(x,y,x2 , y2, c, 1);
    
    if (level <= 10) {
        drawTree(x2,y2, angle - 20, len, level+1);
        drawTree(x2,y2, angle + 20, len, level +1);    
    } 
}
```