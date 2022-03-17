#include "link_list.hpp"

void test()
{
    LinkList<string> link_list;

    link_list.Insert(0, "Beijing");
    link_list.Insert(1, "Tianjin");
    link_list.Insert(2, "Shanghai");
    link_list.Insert(3, "Guangzhou");
    link_list.Insert(4, "Shenzhen");
    link_list.Insert(5, "hangzhou");
    link_list.Insert(6, "wuhan");
    link_list.Insert(7, "Shuzhou");
    link_list.Insert(8, "ningbo");
    link_list.Insert(9, "hefei");
    link_list.Insert(10, "nanjing");
    
    cout << "link_list..." << endl;
    link_list.Output();
    cout << endl;

    LinkList<string> link_list_2(link_list);

    cout << "link_list_2..." << endl;
    link_list_2.Output();

    string delete_ptr;
    cout << "删除后..." << endl;
    link_list_2.Remove(1, delete_ptr);
    link_list_2.Remove(5, delete_ptr);
    link_list_2.Output();
}

int main()
{
    test();

    return 0;

}
