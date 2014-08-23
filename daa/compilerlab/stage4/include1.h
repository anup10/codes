
typedef enum { conType, idType, oprType} nodeEnum;

typedef struct{
	int value;						/* value of constant */
	}conNodeType;
	
typedef struct{
	int i;							/* subscript to sym array */
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
	
	extern int sym[26];


























