#include <stdio.h>
#include <stdlib.h>

#ifdef WIN32
#include <windows.h>
#elif __linux
#include <dlfcn.h>
#endif

typedef void (* funcMatrix) (int[5][7]); //указатель на функцию матрицы
typedef void (* funcArray) (int[57]); //указатель на функцию массива
void matrix_test(void * lib);
void array_test(void * lib);

int main()
{
  int array[64];
  void * lib;

  int choose = 0, breakpoint = 1;

  do
  {
    printf("\nChoose the struct for work:\n"
        "1. Work with matrix.\n"
        "2. Work with array.\n"
        "3. Exit.\n");

    scanf("%d", &choose);

    switch(choose){
    case 1:{
      #ifdef WIN32
      lib = LoadLibrary("libMatrix.dll");
      if(!lib)
      {
        printf("Cant open library libMatrix.dll\n");
      }
      matrix_test(lib);
      FreeLibrary(lib);
      #endif

      #ifdef __linux
      lib = dlopen("libMatrix.so", RTLD_LAZY);
      if(!lib)
      {
        printf("Cant open library libMatrix.so\n");
      }
      matrix_test(lib);
      dlclose(lib);
      #endif
    } break;

    case 2:
    {
      lib = LoadLibrary("libArray.dll");
      if(!lib)
      {
        printf("Cant open library libArray.dll\n");
      }
      array_test(lib);
      FreeLibrary(lib);
    } break;
    case 3: breakpoint = 0; break;
    }
  } while(breakpoint);

  return 0;
}

void matrix_test(void * lib)
{
  int matrix[5][7];

  funcMatrix funCreateM;
  funcMatrix funPrintM;
  funcMatrix funChangeM;

  #ifdef WIN32
  funCreateM = (funcMatrix)GetProcAddress((HINSTANCE)lib, "CreateMatrix");
  if(funCreateM == NULL)
  {
    printf("Cant load function CreateMatrix");
  }
  funCreateM(matrix);

  printf("\n\nCreated matrix:\n");

  funPrintM = (funcMatrix)GetProcAddress((HINSTANCE)lib, "PrintMatrix");
  if(funPrintM == NULL)
  {
    printf("Cant load function PrintMatrix");
  }
  funPrintM(matrix);

  funChangeM = (funcMatrix)GetProcAddress((HINSTANCE)lib, "ChangeMatrix");
  if(funChangeM == NULL)
  {
    printf("Cant load function ChangeMatrix");
  }
  funChangeM(matrix);
  #endif

  #ifdef __linux
  funCreateM = (funcMatrix)dlsym(lib, "CreateMatrix");
  if(funCreateM == NULL)
  {
    printf("Cant load function CreateMatrix");
  }
  funCreateM(matrix);

  printf("\n\nGenerated matrix:\n");

  funPrintM = (funcMatrix)dlsym(lib, "PrintMatrix");
  if(funPrintM == NULL)
  {
    printf("Cant load function PrintMatrix");
  }
  funPrintM(matrix);

  funChangeM = (MatrixFun)dlsym(lib, "ChangeMatrix");
  if(funChangeM == NULL)
  {
    printf("Cant load function ChangeMatrix");
  }
  funChangeM(matrix);
  #endif
}

void array_test(void * lib)
{
  int array[57];

  funcArray funCreateA;
  funcArray funPrintA;
  funcArray funChangeA;

  #ifdef WIN32
  funCreateA = (funcArray)GetProcAddress((HINSTANCE)lib, "CreateArray");
  if(funCreateA == NULL)
  {
    printf("Cant load function GenArray");
  }
  funCreateA(array);

  printf("\n\nCreated array:\n");

  funPrintA = (funcArray)GetProcAddress((HINSTANCE)lib, "PrintArray");
  if(funPrintA == NULL)
  {
    printf("Cant load function PrintArray");
  }
  funPrintA(array);

  funChangeA = (funcArray)GetProcAddress((HINSTANCE)lib, "ChangeArray");
  if(funChangeA == NULL)
  {
    printf("Cant load function ProcesArray");
  }
  funChangeA(array);
  #endif

  #ifdef __linux
  funCreateA = (funcArray)dlsym(lib, "CreateArray");
  if(funCreateA == NULL)
  {
    printf("Cant load function CreateArray");
  }
  funCreateA(array);

  printf("\n\nCreated array:\n");

  funPrintA = (funcArray)dlsym(lib, "PrintArray");
  if(funPrintA == NULL)
  {
    printf("Cant load function PrintArray");
  }
  funPrintA(matrix);

  funChangeA = (funcArray)dlsym(lib, "ChangeArray");
  if(funChangeA == NULL)
  {
    printf("Cant load function ChangeArray");
  }
  funChangeA(array);

  #endif
}
