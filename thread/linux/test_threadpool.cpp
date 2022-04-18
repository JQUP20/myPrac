#include "threadpool.h"
#include <iostream>
using namespace std;

class TaskRun{
public:
    void process()
    {
        static int num = 0;
        num++;

        cout << "num --> " << num << endl;
    }




};




int main()
{
    threadpool<TaskRun>* pool = nullptr;
    try
    {
        pool = new threadpool< TaskRun >;
    }
    catch( ... )
    {
        return 1;
    }

    delete pool;

    return 0;
}
