
typedef enum { conType, idType, oprType} nodeEnum;

typedef struct{
	int value;						/* value of constant */
	}conNodeType;
	

	
struct symbol_table
 {
  int type;
  int size;
  char *name;	//location of name
  int *binding;	//location of contents of varialbe
  struct symbol_table *next;
 };

typedef struct{
	int i;
	struct symbol_table *entry;
	}idNodeType;
	
typedef struct{
	int oper;						/* operator */
	int nops;						/* number of operands */
	struct nodeTypeEx **pr;					/* operands */
	}oprNodeType;
	
typedef struct nodeTypeEx{
	nodeEnum type;
	
	union{
		conNodeType con;
		idNodeType id;
		oprNodeType opr;
	     };
	}nodeType;
	



























