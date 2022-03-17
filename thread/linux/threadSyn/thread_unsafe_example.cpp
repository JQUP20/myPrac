#include <iostream>
#include <pthread.h>

using namespace std;

int ticket_num = 10000000;

void *sell_ticket(void *arg){
    while(ticket_num > 0)
    {
        if(ticket_num > 0)
            ticket_num--;
    }
}

int main() {
    pthread_t t1,t2,t3;
    pthread_create(&t1, nullptr, &sell_ticket, nullptr);
    pthread_create(&t2, nullptr, &sell_ticket, nullptr);
    pthread_create(&t3, nullptr, &sell_ticket, nullptr);
    pthread_join(t1, nullptr);
    pthread_join(t2, nullptr);
    pthread_join(t3, nullptr);

    cout << "ticket_num --> " << ticket_num << endl;

    return 0;
}
