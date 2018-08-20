#include "ValueRange.h"

ValueRange::ValueRange(int Max, int Min) {
    mMin = Min;
    mMax = Max;
}

bool ValueRange::IsInRange(int val) {
    return (mMin <= val && mMax >= val);
}

int ValueRange::GetMax( void ) {
    return mMax;
}

int ValueRange::GetMin(void){
    return mMin;
}

int ValueRange::Length( void ) {
    return mMax - mMin;
}

ValueRange::~ValueRange()
{
    //dtor
}
