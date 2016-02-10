#include "Enroll.h"


//constructor definition
Enroll::Enroll(Student & s, Course & c, double g)
{
    if(g < 0 || g > 4.0)
        cerr < "Error in Enroll::Enroll()-- Not possible to have a grade below zero or above 4";
    else
    {
        sid = s.sid;
        cid = c.cid;
        grade = g;
    }
}

Enroll::Enroll() { } //default constructor