#ifndef _V_MACHINE_H_
#define _V_MACHINE_H_
#define TOTAL_MEMORY_BLOCK_SIZE 0x1000
#define MEMORY_BLOCK_BASE      0x00000000
unsigned int gUnAllocated; 
unsigned int gAllocated;   
typedef struct _objHeader {
 union Un {
  unsigned short bflag:1;
  unsigned short size:15;
 } collstuff;
 unsigned short dummy;
 unsigned int * pAddr;
} sObjHeader; 

#define MAX_OBJECT_COUNT 0xffff
typedef struct _returned {
   unsigned int index;
   unsigned int size;
} sObjReturn;
 
typedef struct _objTable {
   unsigned int objCount;    
   unsigned int objUsed;    
   unsigned int objReturned; 
   unsigned int ReturnedSize; 
   unsigned int UsedSize;    
   sObjHeader  *objElement[MAX_OBJECT_COUNT];
   sObjReturn  *Returned[MAX_OBJECT_COUNT];
   unsigned int Allocated[MAX_OBJECT_COUNT];
} sObjTable;
 
typedef unsigned int Instance;
 
Instance Vmalloc ( unsigned int size );
Instance Vrealloc ( Instance a, unsigned int size );
Instance Vcalloc ( unsigned int size );
void Vfree ( Instance a );
int Vcollect ( void );
Instance CreateObject ( unsigned int size );
#endif