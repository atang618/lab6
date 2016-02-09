
#include "Catalog.h"

void Catalog::add_student(Student & s)
{
    pair<int, Student> s_p;
    s_p = make_pair(s.sid, s);

    students.insert(s_p);
}

void Catalog::add_course(Course & c)
{
    pair<int, Course> c_p;
    c_p = make_pair(c.cid, c);

    courses.insert(c_p);
}

Student Catalog::retrieve_student(int sid)
{
    map<int, Student>::iterator j = students.find(sid);
    pair<int, Student> p = (*j);
    Student s = p.second;
    return s;
}

Course Catalog::retrieve_course(int cid)
{
    map<int, Course>::iterator k = courses.find(cid);
    pair<int, Course> p2 = (*k);
    Course c = p2.second;
    return c;
}

void Catalog::add_enrollment(Enroll & e)
{
    int the_sid = e.sid;

    if(students.find(the_sid) == students.end()) //student id not a key value in students map
    {
        cerr << "Student: "<< the_sid << "- is not a valid student in Catalog" << endl;
    }
    else if (courses.find(e.cid) == courses.end())
    {
        cerr << "Course: " << e.cid << "- is not a valid course in Catalog" << endl;
    }
    else
    {
        enrollments.push_front(e);
    }
}
void Catalog::print_students()
{
    cout << "Students: \n";

    for (map<int, Student>::iterator i = students.begin(); i != students.end(); i++)
    {
        pair<int, Student> p = *i;
        Student s = p.second;
        cout << "  " << s << endl;
    }
}

void Catalog::print_courses()
{
    cout << "Courses: \n";

    for (map<int, Course>::iterator i = courses.begin(); i != courses.end(); i++)
    {
        pair<int, Course> p = *i;
        Course c = p.second;
        cout << "  " << c << endl;
    }
}

void Catalog::print_enrollments()
{
    cout << "Enrollments: \n";

    for (list<Enroll>::iterator i = enrollments.begin(); i != enrollments.end(); i++)
    {
        Enroll e = *i;

        Student s = retrieve_student(e.sid);
        Course c = retrieve_course(e.cid);

        cout << "  " << "name: " << s.name << "; course: (" << c << "); grade: " << e.grade << endl;
    }
}

void Catalog::print_catalog()
{
    print_students();
    print_courses();
    print_enrollments();
    cout << endl;
}

/* returns vector of all enrollments for student with student ID: sid */
vector<Enroll> Catalog::get_all_enrollments(int sid)
{
    vector<Enroll> output;

    for (list<Enroll>::iterator i = enrollments.begin(); i != enrollments.end(); i++)
    {
        Enroll e = *i;
        if(e.sid == sid)
        {
            output.push_back(e);
        }
    }

    return output;
}