# Creating Static Libraries in C++
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

**6. Generate executable by linking "main.o" and "cal.o"**
```
g++ -Wall -fexceptions -g -std=c++11 -o main.out main.o cal.o
```

**7.This step is to generate the object file cal.o using the same command above in point 4.**

**8.Using ar (a Linux archive utility tool) to create the library file**
```
ar cr lib_static_cal.a cal.o
```
>The “cr” flag is to indicate creating a new static library file. It is followed by the output file name first as a request. Notice the name of output is “libmy_math.a”. It is a convention to name the file libXXX.a in Linux, please always do it. When the library is used, the command line tool actually relies on this convention for the linker to work properly.

**9.Now we want to use the static library file**
```
g++ main.o lib_static_cal.a -o a.out
```

**10.Another method to use the static library file**
```
g++ main.o -L. -l_static_cal -o a.out
```
>This tells the compiler to look for libraries in path (.) with name lib_static_cal.a. Notice here we use l_static_cal. The linker will treat this as specifying file name lib_static_cal.a (Remember the naming convention for creating library we just talked about).

**11.Verify this**
We can verify that the library has been copied to the executable by deleting the library and running:
```
rm lib_static_cal.a 
./a.out
0.5
```
**12.Change the main file then just compile the main.cpp**
```
g++ -c main.cpp

//then the linking step
g++ main.o Num.o
```
