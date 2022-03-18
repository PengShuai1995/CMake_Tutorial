#include <cmath>
#include <iostream>
#include <string>

#include "TutorialConfig.h"
//should we include the MathFunctions header?
#ifdef USE_MYMATH
#include "MathFunctions.h"
#endif

int main(int argc, char* argv[])
{
    if(argc < 2)
    {
        std::cout<<argv[0]<<" Version "<<Tutorial_VERSION_MAHOR<<"."
                <<Tutorial_BERSION_MINOR<<std::endl;
        std::cout<<"Usage: "<<argv[0]<<" number"<<std::endl;
        return 1;
    }
    const double inputValue = std::stod(argv[1]);
    
    #ifdef USEMATH
     const double outputValue = sqrt(intputValue);
    #else
     const double outputValue = sqrt(inputValue);
    #endif
     std::cout<<"The square root of "<<inputValue<<" is "<<outputValue
              <<std::endl;
   return 0;

}