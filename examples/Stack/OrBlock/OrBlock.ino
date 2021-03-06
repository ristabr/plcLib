#include <plcLib.h>

/* Programmable Logic Controller Library for the Arduino and Compatibles

   Logical OR of two parallel switch branches using Block OR instruction

                           X0          X1
                      ----|  |--------|  |----
                      |                      |     Y0
                  -----                      -----(  )-----
                      |    X2          X3    |
                      ----|  |--------|  |----		

   Connections:
   Input - switch connected to input X0 (Arduino pin A0)
   Input - switch connected to input X1 (Arduino pin A1)
   Input - switch connected to input X2 (Arduino pin A2)
   Input - switch connected to input X3 (Arduino pin A3)
   Output - LED connected to output Y0 (Arduino pin 3)


   Software and Documentation:
   https://github.com/wditch/plcLib

*/

Stack stack1;        // Create a single-bit stack with 32 levels

void setup() {
  setupPLC();        // Setup inputs and outputs
}

void loop() {

                     // Calculate First Branch
  in(X0);            // Read switch connected to Input 0
  andBit(X1);        // Logical AND with Input 1
  stack1.push();     // Push temporary result onto the stack

                     // Calculate second branch
  in(X2);            // Read switch connected to Input 2
  andBit(X3);        // Logical AND with Input 3
  
  stack1.orBlock();  // Merge branches using Block OR
  out(Y0);           // Send result to Output 0

}