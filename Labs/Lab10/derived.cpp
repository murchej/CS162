#include <iostream>
#include <string>
#include "derived.h"
#include "base.h"

using namespace std;


string Pet::getLifespan(int weight){

if(weight>100){
    return "Approximately 7 years.";
}

else {
    return 0;
}
}
