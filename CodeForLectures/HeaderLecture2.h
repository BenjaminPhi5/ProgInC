// The header file for lecture 2.
#define PI 3.141592654
#define MAX(A,B) ((A) > (B) ? (A):(B))
#define PERCENT(D) (100*D) /* Wrong?  well what do you want it to achieve*/
#define DPRINT(D) printf(#D " = %g\n",D)
#define JOIN(A,B) (A ## B)
#define SWAP(T, X, Y) (Y), (X)

static void intro();
extern void myExternFunction();
int add();
int checkAdd(int a, int b);
int min(int arg_count,...);
int average(int arg_count,...);
unsigned int fact(unsigned int n);
unsigned int check(unsigned int n);
void triTest();
void preprocessorTest();
/*exercises functions */
int countlower(char str[], int len);
void myMerge(int arr[], unsigned int len);
void mergeSort(int* arr, int* tempArr, unsigned int p, unsigned int r);
void merge(int * arr, int* tempArr, unsigned int p, unsigned int q, unsigned int r);
void printarr(int arr[], len);
void printref(int * arr, len);
void testSwap();
int f(int x);