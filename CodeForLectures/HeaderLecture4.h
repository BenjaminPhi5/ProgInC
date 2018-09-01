typedef struct llist * llptr;
typedef struct llist {
	int val;
	llptr next;
};

struct test {int i;};
typedef struct test test_t;

static void intro();
void constEx();
void structType();
void gotcha1();
void gotcha2();
void gotcha3();
void gotcha4();
void gotcha5();

