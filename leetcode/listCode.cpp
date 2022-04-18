#include "list.hpp"

void list_test()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectionListNodes(pNode1, pNode2);
    ConnectionListNodes(pNode2, pNode3);
    ConnectionListNodes(pNode3, pNode4);
    ConnectionListNodes(pNode4, pNode5);

    PrintList(pNode1);
}

/*
 * BM1  反转链表
 * 将链表反转，即将每个表元的指针从向后变成向前，那我们可以遍历原始链表，将遇到的节点一一指针逆向即可。

step 1：优先处理空链表，空链表不需要反转。
step 2：我们可以设置两个指针，一个当前节点的指针，一个上一个节点的指针（初始为空）。
step 3：遍历整个链表，每到一个节点，断开当前节点与后面节点的指针，并用临时变量记录后一个节点，然后当前节点指向上一个节点，即可以将指针逆向。
step 4：再轮换当前指针与上一个指针，让它们进入下一个节点及下一个节点的前序节点。
 */
class Solution1 {
public:
    ListNode* ReverseList(ListNode* pHead)
    {
        ListNode* pPrev = nullptr;
        ListNode* pCurrent = pHead;

        while(pCurrent != nullptr)
        {
            ListNode* pNext = pCurrent->m_pNext;

            pCurrent->m_pNext = pPrev;

            pPrev = pCurrent;
            pCurrent = pNext;
        }

        return pPrev;
    }

    void test_reverseList()
    {
        ListNode* pNode1 = CreateListNode(1);
        ListNode* pNode2 = CreateListNode(2);
        ListNode* pNode3 = CreateListNode(3);
        ListNode* pNode4 = CreateListNode(4);
        ListNode* pNode5 = CreateListNode(5);

        ConnectionListNodes(pNode1, pNode2);
        ConnectionListNodes(pNode2, pNode3);
        ConnectionListNodes(pNode3, pNode4);
        ConnectionListNodes(pNode4, pNode5);
        ListNode* pReversedHead = ReverseList(pNode1);

        PrintList(pReversedHead);
    }


};

/*
 * 链表内指定区间反转
 * 将链表反转，即将每个表元的指针从向后变成向前，那我们可以遍历原始链表，将遇到的节点一一指针逆向即可。

step 1：优先处理空链表，空链表不需要反转。
step 2：我们可以设置两个指针，一个当前节点的指针，一个上一个节点的指针（初始为空）。
step 3：遍历整个链表，每到一个节点，断开当前节点与后面节点的指针，并用临时变量记录后一个节点，然后当前节点指向上一个节点，即可以将指针逆向。
step 4：再轮换当前指针与上一个指针，让它们进入下一个节点及下一个节点的前序节点。
 */
class Solution2 {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* pPre = new ListNode(-1);
        pPre->m_pNext = head;
        ListNode* result = pPre;
        ListNode* pCurNode = head;

        for(int i = 1; i < m; i++)
        {
            pPre = pCurNode;
            pCurNode = pCurNode->m_pNext;
        }

        for(int i = m; i < n; i++)
        {
            ListNode* temp = pCurNode->m_pNext;
            pCurNode->m_pNext = temp->m_pNext;
            temp->m_pNext = pPre->m_pNext;
            pPre->m_pNext = temp;
        }

        return result->m_pNext;
    }

    
    void test_reverseBetween()
    {
        ListNode* pNode1 = CreateListNode(1);
        ListNode* pNode2 = CreateListNode(2);
        ListNode* pNode3 = CreateListNode(3);
        ListNode* pNode4 = CreateListNode(4);
        ListNode* pNode5 = CreateListNode(5);

        ConnectionListNodes(pNode1, pNode2);
        ConnectionListNodes(pNode2, pNode3);
        ConnectionListNodes(pNode3, pNode4);
        ConnectionListNodes(pNode4, pNode5);
        ListNode* pReversedHead = reverseBetween(pNode1, 2, 4);

        PrintList(pReversedHead);
    }


};

/*
 * 链表中的节点每k个一组翻转
 *
 * 解题思路
 刷题模板
step 1：现在我们想一想，如果拿到一个链表，想要像上述一样分组翻转应该做些什么？首先肯定是分段吧，至少我们要先分成一组一组，才能够在组内翻转。分组很容易，只要每次遍历k个元素，就是一组。
step 2：然后是组内翻转，翻转完了再连接起来。翻转即指定区间内的翻转，也很容易，可以参考[链表指定区间内的翻转]。
step 3：最后是将反转后的分组连接，但是连接的时候遇到问题了：首先如果能够翻转，链表第一个元素一定是第一组，它翻转之后就跑到后面去了，而第一组的末尾元素才是新的链表首，我们要返回的也是这个元素，而原本的链表首要连接下一组翻转后的头部，即翻转前的尾部，如果不建立新的链表，看起来就会非常难。
step 4：如果我们从最后的一个组开始翻转，得到了最后一个组的链表首，是不是可以直接连在倒数第二个组翻转后的尾（即翻转前的头）后面，是不是看起来就容易多了。
 */
class Solution3{
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr || k <= 0)
            return nullptr;

        ListNode* tail = head;
        for(int i = 0; i < k; i ++)
        {
            if(tail == nullptr)
                return head;
            tail = tail->m_pNext;
        }

        ListNode* pPrev = nullptr;
        ListNode* pCur = head;

        while(pCur != tail)
        {
            ListNode* pNext = pCur->m_pNext;


            pCur->m_pNext = pPrev;
            pPrev = pCur;
            pCur = pNext;
        }

        head->m_pNext = reverseKGroup(tail, k);

        return pPrev;
    }
    

    void test_reverseKGroup()
    {
        ListNode* pNode1 = CreateListNode(1);
        ListNode* pNode2 = CreateListNode(2);
        ListNode* pNode3 = CreateListNode(3);
        ListNode* pNode4 = CreateListNode(4);
        ListNode* pNode5 = CreateListNode(5);

        ConnectionListNodes(pNode1, pNode2);
        ConnectionListNodes(pNode2, pNode3);
        ConnectionListNodes(pNode3, pNode4);
        ConnectionListNodes(pNode4, pNode5);
        ListNode* pReversedHead = reverseKGroup(pNode1, 2);

        PrintList(pReversedHead);
    }
};

/*
 *  合并两个排序的链表
 *
 *  step 1：判断空链表的情况，只要有一个链表为空，那答案必定就是另一个链表了，就算另一个链表也为空。
step 2：新建一个空的表头后面连接两个链表排序后的结点。
step 3：遍历两个链表都不为空的情况，取较小值添加在新的链表后面，每次只把被添加的链表的指针后移。
step 4：遍历到最后肯定有一个链表还有剩余的结点，它们的值将大于前面所有的，直接连在新的链表后面即可。
 */

class Solution4
{
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(pHead1 == nullptr)
            return pHead2;
        else if(pHead2 == nullptr)
            return pHead1;

        ListNode* pMerged = new ListNode(-1);
        ListNode* result = pMerged;

        while(pHead1 != nullptr && pHead2 != nullptr)
        {
            if(pHead1->m_nValue <= pHead2->m_nValue)
            {
                pMerged->m_pNext = pHead1;
                pHead1 = pHead1->m_pNext;
            }
            else if(pHead1->m_nValue > pHead2->m_nValue)
            {
                pMerged->m_pNext = pHead2;
                pHead2 = pHead2->m_pNext;
            }

            pMerged = pMerged->m_pNext;
        }

        if(pHead1 != nullptr)
            pMerged->m_pNext = pHead1;
        if(pHead2 != nullptr)
            pMerged->m_pNext = pHead2;

        return result->m_pNext;
    }

    void test_Merge()
    {
        ListNode* pNode1 = CreateListNode(1);
        ListNode* pNode2 = CreateListNode(2);
        ListNode* pNode3 = CreateListNode(3);
        ListNode* pNode4 = CreateListNode(4);
        ListNode* pNode5 = CreateListNode(5);

        ConnectionListNodes(pNode1, pNode3);
        ConnectionListNodes(pNode2, pNode4);
        ConnectionListNodes(pNode4, pNode5);

        ListNode* pMergeHead = Merge(pNode1, pNode2);

        PrintList(pMergeHead);
    }

};

/*
 *BM5 合并k个已排序的链表

 如果是两个有序链表合并，我们可能会利用归并排序合并阶段的思想：准备双指针分别放在两个链表头，每次取出较小的一个元素加入新的大链表，将其指针后移，继续比较，这样我们出去的都是最小的元素，自然就完成了排序。

其实这道题我们也可以两两比较啊，只要遍历链表数组，取出开头的两个链表，按照上述思路合并，然后新链表再与后一个继续合并，如此循环，知道全部合并完成。但是，这样太浪费时间了。

既然都是归并排序的思想了，那我们可不可以直接归并的分治来做，而不是顺序遍历合并链表呢？答案是可以的！

归并排序是什么？简单来说就是将一个数组每次划分成等长的两部分，对两部分进行排序即是子问题。对子问题继续划分，直到子问题只有1个元素。还原的时候呢，将每个子问题和它相邻的另一个子问题利用上述双指针的方式，1个与1个合并成2个，2个与2个合并成4个，因为这每个单独的子问题合并好的都是有序的，直到合并成原本长度的数组。

对于这k个链表，就相当于上述合并阶段的k个子问题，需要两个合并，不断往上，最终合并成完整的一个链表。

step 1：从链表数组的首和尾开始，每次划分从中间开始划分，划分成两半，得到左边n/2个链表和右边n/2个链表。
step 2：继续不断递归划分，直到每部分链表数为1.
step 3：将划分好的相邻两部分链表，按照两个有序链表合并的方式合并，合并好的两部分继续往上合并，直到最终合并成一个链表。
*/
#include <vector>
class Solution5
{
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //K个链表归并排序
        return divideMerge(lists, 0, lists.size() - 1);
    }

    ListNode* divideMerge(vector<ListNode*>& lists, int left, int right)
    {
        if(left > right)
            return nullptr;
        else if(left == right)
            return lists[left];
        int mid = (left + right) / 2;

        return Merge2(divideMerge(lists, left, mid), divideMerge(lists, mid + 1, right));
    }

    ListNode* Merge2(ListNode* pHead1, ListNode* pHead2) {
        if(pHead1 == nullptr)
            return pHead2;
        if(pHead2 == nullptr)
            return pHead1;

        ListNode* head = new ListNode(0);
        ListNode* cur = head;

        //
        while(pHead1 && pHead2) {
            //
            if(pHead1->m_nValue <= pHead2->m_nValue)
            {
                cur->m_pNext = pHead1;
                pHead1 = pHead1->m_pNext;
            } 
            else 
            {
                cur->m_pNext = pHead2;
                pHead2 = pHead2->m_pNext;
            }

            cur = cur->m_pNext;
        }
            
        if(pHead1)
            cur->m_pNext = pHead1;
        else
            cur->m_pNext = pHead2;

        return head->m_pNext;
    }

    void test_MergeKLists()
    {
        ListNode* pNode1 = CreateListNode(1);
        ListNode* pNode2 = CreateListNode(2);
        ListNode* pNode3 = CreateListNode(3);
        ListNode* pNode4 = CreateListNode(4);
        ListNode* pNode5 = CreateListNode(5);
        ListNode* pNode6 = CreateListNode(6);

        ConnectionListNodes(pNode1, pNode4);
        ConnectionListNodes(pNode2, pNode5);
        ConnectionListNodes(pNode3, pNode6);

        vector<ListNode*> lists;
        lists.push_back(pNode1);
        lists.push_back(pNode2);
        lists.push_back(pNode3);

        ListNode* mergeK = mergeKLists(lists);

        PrintList(mergeK);
    }

};

/*
 * BM6 判断链表中是否有环
 *  step 1：设置快慢两个指针，初始都指向链表头。
- step 2：遍历链表，快指针每次走两步，慢指针每次走一步。
- step 3：如果快指针到了链表末尾，说明没有环，因为它每次走两步，所以要验证连续两步是否为NULL。
- step 4：如果链表有环，那快慢双指针会在环内循环，因为快指针每次走两步，因此快指针会在环内追到慢指针，二者相遇就代表有环。
 */

class Solution6
{
public:
    bool hasCycle(ListNode *head)
    {
        //
        if(head == nullptr)
            return false;

        ListNode* pFast = head;
        ListNode* pSlow = head;
        //
        while(pFast != nullptr && pFast->m_pNext != nullptr)
        {
            //
            pFast = pFast->m_pNext->m_pNext;
            //
            pSlow = pSlow->m_pNext;

            if(pFast == pSlow)
                return true;
        }
        //
        return false;
    }
};


/*
 * BM7 链表中环的入口结点
 * step 1：使用[判断链表中是否有环]中的方法判断链表是否有环，并找到相遇的节点。
step 2：慢指针继续在相遇节点，快指针回到链表头，两个指针同步逐个元素逐个元素开始遍历链表。
step 3：再次相遇的地方就是环的入口。
 */

class Solution7
{
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead) 
    {
        ListNode* pSlow = hasCycle(pHead);
        PrintListNode(pSlow);
        //
        if(pSlow == nullptr)
            return nullptr;

        //
        ListNode* pFast = pHead;
        //
        while(pFast != pSlow)
        {
            pFast = pFast->m_pNext;
            pSlow = pSlow->m_pNext;
        }

        return pSlow;
    }


    ListNode* hasCycle(ListNode *head)
    {
        //
        if(head == nullptr)
            return nullptr;

        ListNode* pFast = head;
        ListNode* pSlow = head;
        //
        while(pFast != nullptr && pFast->m_pNext != nullptr)
        {
            //
            pFast = pFast->m_pNext->m_pNext;
            //
            pSlow = pSlow->m_pNext;

            if(pFast == pSlow)
                return pSlow;
        }
        //
        return nullptr;
    }


    void test_EntryNodeOfLoop()
    {
        ListNode* pNode1 = CreateListNode(1);
        ListNode* pNode2 = CreateListNode(2);
        ListNode* pNode3 = CreateListNode(3);
        ListNode* pNode4 = CreateListNode(4);
        ListNode* pNode5 = CreateListNode(5);
        ListNode* pNode6 = CreateListNode(6);

        ConnectionListNodes(pNode1, pNode2);
        ConnectionListNodes(pNode2, pNode3);
        ConnectionListNodes(pNode3, pNode4);
        ConnectionListNodes(pNode4, pNode5);
        ConnectionListNodes(pNode5, pNode6);

        
        ConnectionListNodes(pNode6, pNode3);
        
        ListNode* pEntry = EntryNodeOfLoop(pNode1);

        PrintListNode(pEntry);
    }

};

/*
 * BM8 链表中倒数最后k个结点
 *
 *
step 1：准备一个快指针，从链表头开始，在链表上先走k步。
step 2：准备慢指针指向原始链表头，代表当前元素，则慢指针与快指针之间的距离一直都是k。
step 3：快慢指针同步移动，当快指针到达链表尾部的时候，慢指针正好到了倒数k个元素的位置。
 */

class Solution8 {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param pHead ListNode类
     * @param k int整型
     * @return ListNode类
     */
    ListNode* FindKthToTail(ListNode* pHead, int k) {
        if(pHead == nullptr || k <= 0)
            return nullptr;

        ListNode* pFast = pHead;
        ListNode* pSlow = pHead;

        for(int i=  0; i < k; i++)
        {
            if(pFast != nullptr)
                pFast = pFast->m_pNext;

            else
                return nullptr;
        }

        while(pFast != nullptr)
        {
            pFast = pFast->m_pNext;
            pSlow = pSlow->m_pNext;
        }

        return pSlow;
    }
};

/*
 * BM9 删除链表的倒数第n个节点
 *
 * step 1：给链表添加一个表头，处理删掉第一个元素时比较方便。
step 2：准备一个快指针，在链表上先走n步。
step 3：准备慢指针指向原始链表头，代表当前元素，前序节点指向添加的表头，这样两个指针之间相距就是一直都是n。
step 4：快慢指针同步移动，当快指针到达链表尾部的时候，慢指针正好到了倒数n个元素的位置。
step 5：最后将该节点前序节点的指针指向该节点后一个节点，删掉这个节点。

*/
class Solution9 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        if(head == nullptr || n <= 0)
            return nullptr;
        //
        ListNode* res = new ListNode(-1);
        res->m_pNext = head;
        //
        ListNode* pCur = head;
        //
        ListNode* pPre = res;
        ListNode* pFast = head;
        //
        while(n--)
        {
            if(pFast != nullptr)
                pFast = pFast->m_pNext;
            else
                return nullptr;
        }

        //
        while(pFast != nullptr)
        {
            pFast = pFast->m_pNext;
            pPre = pCur;
            pCur = pCur->m_pNext;
        }

        pPre->m_pNext = pCur->m_pNext;

        return res->m_pNext;
    }

    void test_removeNthFromEnd()
    {
        ListNode* pNode1 = CreateListNode(1);
        ListNode* pNode2 = CreateListNode(2);
        ListNode* pNode3 = CreateListNode(3);
        ListNode* pNode4 = CreateListNode(4);
        ListNode* pNode5 = CreateListNode(5);
        ListNode* pNode6 = CreateListNode(6);

        ConnectionListNodes(pNode1, pNode2);
        ConnectionListNodes(pNode2, pNode3);
        ConnectionListNodes(pNode3, pNode4);
        ConnectionListNodes(pNode4, pNode5);
        ConnectionListNodes(pNode5, pNode6);

        
        
        ListNode* pNew = removeNthFromEnd(pNode1, 3);
        PrintList(pNew);
    }
};

/*
 * BM10 两个链表的第一个公共结点
 *
 * step 1：单独的遍历两个链表，得到各自的长度。
step 2：求得两链表的长度差n，其中较长的链表的指针从头先走n步。
step 3：两链表指针同步向后遍历，遇到第一个相同的节点就是第一个公共结点
 */

class Solution10
{

};




/*
 *BM11 链表相加(二)

 step 1：任意一个链表为空，返回另一个链表就行了，因为链表为空相当于0，0加任何数为0，包括另一个加数为0的情况。
step 2：相继反转两个待相加的链表。
step 3：设置返回链表的链表头，设置进位carry=0.
step 4：从头开始遍历两个链表，直到两个链表节点都为空且carry也不为1. 每次取出不为空的链表节点值，为空就设置为0，将两个数字与carry相加，然后查看是否进位，将进位后的结果（对10取模）加入新的链表节点，连接在返回链表后面，并继续往后遍历。
step 5：返回前将结果链表再反转回来。
*/

class Solution11 {
public:
    //
    ListNode* ReverseList(ListNode* pHead)
    {
        if(pHead == nullptr)
            return nullptr;

        ListNode* pCur = pHead;
        ListNode* pPre = nullptr;

        while(pCur != nullptr)
        {
            //
            ListNode* temp = pCur->m_pNext;

            pCur->m_pNext = pPre;

            pPre = pCur;
            pCur = temp;
        }

        return pPre;
    }

    ListNode* addInList(ListNode* head1, ListNode* head2)
    {
        //
        if(head1 == nullptr)
            return head2;
        if(head2 == nullptr)
            return head1;

        head1 = ReverseList(head1);
        head2 = ReverseList(head2);

        //
        ListNode* res = new ListNode(-1);
        ListNode* head = res;

        // 进位符号
        int carry = 0;

        while(head1 != nullptr || head2 != nullptr || carry != 0)
        {
            int val1 = (head1 == nullptr ? 0 : head1->m_nValue);
            int val2 = (head2 == nullptr ? 0 : head2->m_nValue);

            int temp = val1 + val2;

            carry = temp / 10;
            temp %= 10;

            //
            head->m_pNext = new ListNode(temp);
            head = head->m_pNext;

            //
            if(head1 != nullptr)
                head1 = head1->m_pNext;
            if(head2 != nullptr)
                head2 = head2->m_pNext;
        }

        return ReverseList(res->m_pNext);
    }

    
    void test_addInList()
    {
        ListNode* pNode1 = CreateListNode(1);
        ListNode* pNode2 = CreateListNode(2);
        ListNode* pNode3 = CreateListNode(3);
        ListNode* pNode4 = CreateListNode(4);
        ListNode* pNode5 = CreateListNode(5);
        ListNode* pNode6 = CreateListNode(6);

        ConnectionListNodes(pNode1, pNode2);
        ConnectionListNodes(pNode2, pNode3);
        ConnectionListNodes(pNode4, pNode5);
        ConnectionListNodes(pNode5, pNode6);

        
        
        ListNode* pNew = addInList(pNode1, pNode4);

        PrintList(pNew);
    }
};





int main()
{
    //list_test();
    
    //链表反转测试
//    Solution1 s1;
//    s1.test_reverseList();

//    Solution2 s2;
//    s2.test_reverseBetween();

//    Solution3 s3;
//    s3.test_reverseKGroup();

//    Solution4 s4;
//    s4.test_Merge();
    
///    Solution5 s5;
//    s5.test_MergeKLists();
    
//    Solution7 s7;
//    s7.test_EntryNodeOfLoop();

//    Solution9 s9;
//    s9.test_removeNthFromEnd();

    Solution11 s11;
    s11.test_addInList();
    return 0;
}
