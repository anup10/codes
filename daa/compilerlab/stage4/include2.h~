
typedef enum { conType, idType, oprType} nodeEnum;

typedef struct{
	int value;
	int ret_t;						/* value of constant */
	}conNodeType;
	
typedef struct{
	int i;
	int ret_t;							/* subscript to sym array */
	}idNodeType;
	
typedef struct{
	int oper;						/* operator */
	int nops;						/* number of operands */
	struct nodeTypeEx **pr;					/* operands */
	int ret_t;
	}oprNodeType;
	
typedef struct nodeTypeEx{
	nodeEnum type;
	
	union{
		conNodeType con;
		idNodeType id;
		oprNodeType opr;
	     };
	}nodeType;
	
	extern int sym[26];


























