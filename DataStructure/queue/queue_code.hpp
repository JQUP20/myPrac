#ifndef __QUEUE_CODE__
#define __QUEUE_CODE__


/*
 * 面试题9：用两个栈实现队列
// 题目：用两个栈实现一个队列。队列的声明如下，请实现它的两个函数appendTail
// 和deleteHead，分别完成在队列尾部插入结点和在队列头部删除结点的功能
 */

#include <stack>
#include <exception>
#include <stdexcept>

using namespace std;

template <typename T> class CQueue
{
public:
    CQueue(void);
    ~CQueue(void);
    
    //
    void appendTail(const T& node);

    //
    T deleteHead();

private:
    stack<T> stack1;
    stack<T> stack2;
};

template <typename T> CQueue<T>::CQueue(void)
{

}

template <typename T> CQueue<T>::~CQueue(void)
{

}

template<typename T>
void CQueue<T>::appendTail(const T& element)
{
    stack1.push(element);
}

template<typename T>
T CQueue<T>::deleteHead()
{
    if(stack2.size() <= 0)
    {
        while(stack1.size() > 0)
        {
            T& data = stack1.top();
            stack1.pop();
            stack2.push(data);
        }
    }

    std::logic_error ex("queue is empty");
    if(stack2.size() == 0)
        throw std::exception(ex);

    T head = stack2.top();
    stack2.pop();

    return head;
}

#endif
