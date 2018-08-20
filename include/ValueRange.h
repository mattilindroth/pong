#ifndef VALUERANGE_H
#define VALUERANGE_H


class ValueRange
{
    public:
        ValueRange(int Max, int Min);
        bool IsInRange(int val);
        int GetMax(void);
        int GetMin(void);
        int Length(void);
        virtual ~ValueRange();

    protected:

    private:
        int mMax, mMin;
};

#endif // VALUERANGE_H
