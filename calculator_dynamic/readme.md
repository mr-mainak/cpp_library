# Dynamic Library

## By : Mainak Sen

**1.Create a header file (.h)**
```
#ifndef CAL_H
#define CAL_H

class cal{
    private:
        int a,b;
    public:
        cal(int num1,int num2);
        int add();
        int subtract();
        int multiply();
        int divide();
};

#endif
```
> Using #ifndef
Sometimes we can end up including a header file multiple times. C++ doesn’t like this if
it ends up redefining something again. In our previous example this didn’t happen
because main.cpp and Num.cpp are compiled separately so the inclusion of Num.h causes
no problem. This is called a directive as it is a message to the
compiler, but not really a feature of the language. It tells the compiler to ignore what
follows if it has already seen this stuff before.

**2.Create implementation file (.cpp)**
```
#include "cal.h"
#include <iostream>

cal::cal(int num1,int num2): a(num1),b(num2) {};
int cal::add() {return a+b;}
int cal::subtract() {return a-b;}
int cal::multiply() {return a*b;}
int cal::divide() {return a/b;}
```

**3.Create the main file(.cpp)**
```
#include <iostream>
#include "cal.h"
using namespace std;

int main(){
    cal c(5,6);
    cout << c.multiply() << endl;
    return 0;
}
```

**4.Compile the intermediate file**
```
g++ -Wall -fexceptions -g -std=c++11 -c cal.cpp -o cal.o
```

**5.Compile the main file**
```
g++ -Wall -fexceptions -g -std=c++11 -c main.cpp -o main.o
```

**6.Compile to .so file**
```
g++ -shared -o libmy_math.so my_math.o
```
>The “-shared” flag instructs to generate a shared library. Again, the output file naming convention libXXX.so is a must and will be utilized by the linker later.

**7.Get the .out file**
```
g++ main.o lib_dyn_cal.so -o a.out
```

### Use any one way either 8 or 9
**8.Use LD_LIBRARY_PATH.**
```
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/home/HDD_PC/C++/Objects/calculator_dymanic
```
>At runtime, OS searches through every path in LD_LIBRARY_PATH (separated by “:”) to find the dynamic library it needs. By appending the path to LD_LIBRARY_PATH, we fixed it.

**9.Use -rpath**
```
g++ main.o -L. -l_dyn_cal -o a.out -Wl,-rpath,/home/HDD_PC/C++/Objects/calculator_dymanic
```
>Here “-Wl flag” means what follows it (which is a comma-separated list of flags) will be are passed to the linker. In this case, “-rpath /home/cpp_tutorial/static_library” is passed to the linker. The linker inserts this path information to the executable’s (a.out) own search path. This also works.

**10.Run the a.out file**
```
./a.out
```
