## Definition
* A function that is defined interms of itself is called "recursion"
* C allows function to be recursive.

There are four basic rules for recursion,
  1. Base case ( which is solved withour recursion )
  2. Making progress towards base case
  3. Design rule ( all recursive calls work )
  4. Compound interest rule ( never duplicate work by solving same instance of a problem )

## Example

```text
5! = 5*4!
       4! = 4*3!
              3! = 3*2!
                     2! = 2*1!
                            1! = 1*0!
                                   0! = 1 ( base case )
 ```
 
 ```c
 int factorial(int n)
 {
    if ( n == 0 )
      return(1);
    else
      return( n * factorial(n-1));
  }
  ```
  
  ## Try it yourself
  * Towers of Hanoi
  * Binary Search
                                   
