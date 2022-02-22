#include <stdlib.h>
#include <unistd.h>

#include "Vour.h"
#include "verilated.h"

int main(int argc, char** argv, char** env) {
   Verilated::commandArgs(argc, argv);
   int reps = 0;
   Vour* top = new Vour;
   for(; reps < 20; ++reps )
   {
      top -> _y = ( reps <  8 ) ? 0 : 1;
      top -> _a = ( reps < 12 ) ? 0 : 1;
      usleep( 100000 );
      top -> eval(); 
      printf( "%d\n", top -> _x );
      if( Verilated::gotFinish() )
         break;
   }
   delete top;
   return EXIT_SUCCESS;
}
