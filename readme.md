# Next num
J.A. Pearson, jon@jpoffline.com, Feb 2017
REQUIREMENTS TO COMPILE CODE:
- g++ compiler (to use the provided makefile; msvc should also be fine)
- c++11        (required; plenty of c++11-specific features are used)

## Installation
- Navigate into build; type "make clean", "make".
- An executable will appear in the root (i.e., this directory), called "main".
- Running "main" will display the required command-line arguments.

### Examples
- To run unit tests:
```
main -test
```
- Run an example with double data-type choices; sample statistics are analysed.
```
main -double    
```
- Run an example with string data-type choices; sample statistics are analysed.
```
main -string
```
- Run the sampler (with double data-type), yielding N samples to the screen.
```
main -sample N  
```

## Structure 
- All source code lives in the directory "src". 
- Only src/main.cpp needs compilation (but requires c++11).
- Templates are used liberally: hence, the data-types of the choices can be easily user-defined.

As an example, see the function "run_nextNum_doubles" in main.h (around line 43).
In this test case we hard-code the data-type of the choices (in this case, DOUBLE),
the values of the choices, and the PDF of each choice. The subsequent parts of the function
shows a useful workflow to the interface of the sampler.
To see the declaration of the sampler class, see "solution_decl.h".
