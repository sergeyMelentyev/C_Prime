gcc main.c -o new_name -lm -g -Wall -O3 -std=gnu11
// -o new_name 		set output name
// -lm 		ask linker to link math lib
// -g 		adds symbols for debugging
// -std=gnu11		compiler should allow code conforming to the C11
// -O3		optimization level three
// -Wall		adds compiler warnings

#include <stdio.h>
#define NAME replacement_text		// symbolic constant
enum boolean { NO, YES };		// enumeration constant
char name = '';		// character constant
char array[] = "";		// string constant

/* QUALIFIERS AND MODIFICATORS */
auto int x;		// in block auto memory manager, local scope, init with random value
const double e = 2.7182818;		//constant qualifier
void func_name(const char[]);		// constatnt qualifier as an array argument
int extern_var_name;		// external variable definition, global file scope, init with 0
extern int extern_var;		// the way to access external variable from func / file scope
static int static_var;		// in block memory manager, local block/file scope, init with 0
register int var_name;		// only in block cpu register memory, no pointers, init with random
volatile int a;		// value could be changed while program runs, do not optimize (compiler)
restrict int *b;		// pointer could be optimized (compiler), if the pointer is unique
int number = (int) e;		// explicit type conversion
int func_wrap(char s[]) { return (int) func_that_return_dbl(s); }		// explicit return type conversion

/* CONTROL FLOW */
int conditional_expr = (val_a > val_b) ? val_a : val_b;
for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
	c = s[i], s[i] = s[j], s[j] = c;		// several operations horthand notation
switch (expression) {
	case const_expr: statement;
		break;
	default: statement;
}
while (expression) {
	statements;
}
do {
	statements;
} while (expression);

/* ARRAY */
int arr[10];		// array declaration
int days[] = {1, 2, 3, 4};		// array initialization
char patter[] = "name";		// the same as char patter[]= {'n', 'a', 'm', 'e', '\0'};
int *ptr_name;		// pointer of type int declaration
ptr_name = &arr[0];		// ptr_name point to the first element of array
ptr_name == arr;		// the same as above
*(ptr_name + i);		// ptr_name point to the arr[i] element
ptr_name[i] == *(ptr_name + i);		// pointer to arr[i] element
void name(char s[], char *s);		// both formal parameters in a func prototype are equivalent
func_name(&arr[2], arr+2);		// passing a pointers to the beginning of the subarray

char days[2][13] = { {0, 1, 2, 3}, {0, 1, 3, 4} };		// two dimension array
void name(int days[2][13], int days[][13], int (*days)[13]) { }		// the same arguments

void arr_copy(char *to_here, char *from_here) {
	while (*to_here++ = *from_here++)
		;
}
int str_compare(char *s, char *t) {
	for ( ; *s == *t; s++, t++)
		if (*s == '\0')
			return 0;
	return *s - *t;
}

/* STRUCTURES */
struct point {	int x; int y; };		// shape of structure of type struct point, no storage reserved
struct point { ... } x, y, z;		// structure declaration defines a type, followed by a list of vars

struct point pt1;		// defines a var pt1 which is a structure of type struct point
struct point pt2 = { 320, 200 };		//structure initialization
int x = pt_max.x;		// structure member access

struct rect {
	struct point pt1;
	struct point pt2;
};
struct rect screen;
int x = screen.pt1.x;		// nested structure member access

struct point *pp;		// declaration of pointer to a struct of type struct point
pp = &pt1;
int x = (*pp).x;		// structure member access via pointer
int x = pp->x;		// structure member access via pointer

struct {
	int len; char *str;
} *p;
int x = ++p->len;		// increment value of structure member

struct key {		// struct of type key defines an array keytab of struct of this type
	char * word; int count;
} keytab[10];

struct key {		// struct initialization, braces are not necessary
	char * word; int count;
} keytab[] = {
	{ "auto", 0 },
	{ "break", 0}
}

struct point make_struct_func(int x, int y) {
	struct point temp; temp.x = x; temp.y = y; return temp;
}
struct point add_struct_func(struct point p1, struct point p2) {
	p1.x += p2.x; p1.y += p2.y; return p1;
}

/* BINARY TREE */
struct tree_node {
	char *word; int count; struct tree_node *left; struct tree_node *right;
};

/* UNION */
union u_tag {		// a single var can hold any one of several types
	int ival;
	float fval;
	char cval;
} u;

/* RECURSION */
void recursionCall(int n) {
    if (n < 5)
        recursionCall(n + 1);
}
void recursionTailCall(int n) {
    if (n < 5)
        recursionTailCall(n + 1);
    return;
}

/* POINTERS */
char *arr_ptr[10];		// declaration of array, each element of which is a pointer to a char
int (*arr_ptr)[10];		// pointer to array[10] of int

void *func_name();		// function returning pointer to void
void (*func_name)();		// pointer to function returning void

char *ptr_name = &var_name;		// pointer of type char points to the address of var_name
char new_var_name = *ptr_name;		// dereferencing operator, get access to the object`s value
++*ptr_name; (*ptr_name)++;		// increment what pointer points to

void swap(int *px, int *py) {		// function receive two pointers as an arguments
	int temp; temp = *px; *px = *py; *py = temp;
}
swap(&var_one, &var_two);		// function call, pass pointers
void name(int (*func_name)(void *, void *));		// func receive func that has two void* args and returns int

/* MEMORY MANAGEMENT */
double *ptr;
ptr = (double *)malloc(30 * sizeof(double));		// ask for memory size for 30 values
free(ptr);		// release memory

long *name;
name = (long *)calloc(100, sizeof(long));		// ask for mem for 100 values and init with zeros
free(name);

int row = 5;
int column = 6;
int ar[row][column];		// two dimension array of dynamic length
ar = (int (*)[column])malloc(row * column * sizeof(int));		// array row * column
free(ar);

/* INPUT OUTPUT */
while ((c = getchar()) != EOF)
	// read one character at a time
while (scanf("%d %s %d", &day, month, &year) != EOF)
	// read from input ignores blanks, tabs, white spaces


/* ALGORITHMS */
int binary_search(int value, int arr_body[], int arr_length) {
	int low, high, mid; low = 0; high = arr_length - 1;
	while (low <= high) {
		mid = (low + high) / 2;
		if (value < arr_body[mid])
			high = mid - 1;
		else if (value > arr_body[mid])
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}
void shell_sort(int arr_body[], int arr_length) {
	int gap, i, j, temp;
	for (gap = arr_length / 2; gap > 0; gap /= 2)
		for (i = gap; i < arr_length; i++)
			for (j = i - gap; j >= 0 && arr_body[j] > arr_body[j + gap]; j -= gap) {
				temp = arr_body[j]; arr_body[j] = arr_body[j + gap]; arr_body[j + gap] = temp;
			}
}
