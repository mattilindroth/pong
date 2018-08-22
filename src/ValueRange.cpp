#include "ValueRange.h"

ValueRange::ValueRange(int Max, int Min) {
    mMin = Min;
    mMax = Max;
}

bool ValueRange::IsInRange(int val) {

    if(val <= mMax) {
        if(val >= mMin) {
//            printf("mMAx: %i, mMin: %i, val: %i\n", mMax, mMin, val);
            return true;
        }
    }
    return false;
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
