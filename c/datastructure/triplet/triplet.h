#ifndef _TRIPLET_H_
#define _TRIPLET_H_

#define     TRUE        1
#define     FALSE       0
#define     OK          1
#define     ERROR       0
#define     INFEASIBLE  -1
#define     OVERFLOW    -2 

// Status 是函数的类型，其值是函数结果状态代码
typedef int Status;

/* Triplet类型是int类型的指针，存放int类型的地址 */
typedef int *Triplet; /* 由InitTriplet分配三个元素存储空间 */

 /* bo1-1.c 抽象数据类型Triplet和int(由c1-1.h定义)的基本操作(8个) */

Status InitTriplet(Triplet *T,int v1,int v2,int v3)

{ // 操作结果:构造三元组T,依次置T的三个元素的初值为v1,v2和v3 

   *T=(int *)malloc(3*sizeof(int));

   if(!*T)

     exit(OVERFLOW);

   (*T)[0]=v1,(*T)[1]=v2,(*T)[2]=v3;

   return OK;

}

 Status DestroyTriplet(Triplet *T)

 { /* 操作结果：三元组T被销毁 */

   free(*T);

   *T=NULL;

   return OK;

 }



 Status Get(Triplet T,int i, int *e)

 { /* 初始条件：三元组T已存在，1≤i≤3。操作结果：用e返回T的第i元的值 */

   if(i<1||i>3)

     return ERROR;

   *e=T[i-1];

   return OK;

 }



 Status Put(Triplet T,int i,int e)

 { /* 初始条件：三元组T已存在，1≤i≤3。操作结果：改变T的第i元的值为e */

   if(i<1||i>3)

     return ERROR;

   T[i-1]=e;

   return OK;

 }



 Status IsAscending(Triplet T)

 { /* 初始条件：三元组T已存在。操作结果：如果T的三个元素按升序排列，返回1，否则返回0 */

   return(T[0]<=T[1]&&T[1]<=T[2]);

 }



 Status IsDescending(Triplet T)

 { /* 初始条件：三元组T已存在。操作结果：如果T的三个元素按降序排列，返回1，否则返回0 */

   return(T[0]>=T[1]&&T[1]>=T[2]);

 }



 Status Max(Triplet T,int *e)

 { /* 初始条件：三元组T已存在。操作结果：用e返回T的三个元素中的最大值 */

   *e=T[0]>=T[1]?T[0]>=T[2]?T[0]:T[2]:T[1]>=T[2]?T[1]:T[2];

   return OK;

 }



 Status Min(Triplet T,int *e)

 { /* 初始条件：三元组T已存在。操作结果：用e返回T的三个元素中的最小值 */

   *e=T[0]<=T[1]?T[0]<=T[2]?T[0]:T[2]:T[1]<=T[2]?T[1]:T[2];

   return OK;

 }

#endif