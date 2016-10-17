#define NAME replacement_text		// symbolic name or symbolic constant
''		// character constant
""		// character string or string constant

int extern_var_name;		// external variable definition
extern int extern_var_name;		// way to access it from function scope





auto int x;   // in block auto memory manager, local scope, init with random val
register int y;   // in block cpu register memory, no pointers allow, local scope, init with random val
static int z;   // in block memory manager, local scope, init with 0, save value while program runs
volatile int a;     // value could be changed while program runs, do not optimize (compiler)
restrict int *b;     // pointer could be optimized (compiler), if the pointer is unique

double *pointer;    // pointer to the single value of type double (first element of the block)
pointer = (double *)malloc(30 * sizeof(double));    // ask for memory size for 30 values of type double
free(pointer);  // release memory

long *name;
name = (long *)calloc(100, sizeof(long));   // ask for memory for 100 values of type long and init all with zero
free(name);

int row = 5;
int column = 6;
int ar[row][column];    // two dimension array of dynamic length
ar = (int (*)[column])malloc(row * column * sizeof(int));    // array row * column
free(ar);


void recursionCall(int n) {
    if (n < 5)
        recursionCall(n + 1);
}

void recursionTailCall(int n) {
    if (n < 5)
        recursionTailCall(n + 1);
    return;
}
