#define NAME replacement_text		// symbolic constant
enum boolean { NO, YES };		// enumeration constant
char name = '';		// character constant
char array[] = "";		// string constant


// QUALIFIERS AND MODIFICATORS
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


// CONTROL FLOW
int conditional_expr = (val_a > val_b) ? val_a : val_b;
for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
	c = s[i], s[i] = s[j], s[j] = c;
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


// ARRAY
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


// RECURSION
void recursionCall(int n) {
    if (n < 5)
        recursionCall(n + 1);
}
void recursionTailCall(int n) {
    if (n < 5)
        recursionTailCall(n + 1);
    return;
}


// POINTERS
// may be compared if points to the same array
char *ptr_name = &var_name;		// pointer of type char points to the address of var_name
char new_var_name = *ptr_name;		// dereferencing operator, get access to the object`s value
++*ptr_name; (*ptr_name)++;		// increment what pointer points to

void swap(int *px, int *py) {		// function receive two pointers as an arguments
	int temp; 
	temp = *px; *px = *py; *py = temp;
}
swap(&var_one, &var_two);		// function call, pass pointers


// MEMORY MANAGEMENT
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


// ALGORITHMS
int binary_search(int value, int arr_body[], int arr_length) {
	int low, high, mid;
	low = 0;
	high = arr_length - 1;
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
				temp = arr_body[j];
				arr_body[j] = arr_body[j + gap];
				arr_body[j + gap] = temp;
			}
}
