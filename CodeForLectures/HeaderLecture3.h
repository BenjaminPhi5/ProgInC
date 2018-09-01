struct circle {
	int x;
	int y;
	unsigned int r;
};

union Data {
   int i;
   float f;
   char str[20];
};

struct age {
	unsigned int age : 3; // this has a size of 3
};

struct ex {
	int i[5];
	int j;
	struct ex * k;
};

static void intro();
void pointersEx();
void arrayEx();
void arrayEx2();
void copied(int s[]);
void swap2(int * x, int * y);
void multdim();
void sort(int a[], const int len, int (*compare)(int,int));
int inc(int a, int b);
void doSort();
int desc(int a, int b);
void changeC(struct circle * pc);
struct circle circle_init();
void unionExample();
void unionExample2();
void bitFieldTest();
static void ex1();
static void ex2();
char* strfind(const char* s, const char* f);
struct ex ex_init(int n);
static void ex3();
static void ex4();