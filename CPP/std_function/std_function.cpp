#include <iostream>
#include <cassert>


namespace my_std
{
    char *strcpy(char* strDest, const char* strSrc)
    {
        assert( (strDest != nullptr) && (strSrc != nullptr) );
        char *address = strDest;
        while((*strDest++ = *strSrc++) != '\0');
        return address;
    }

    char *strncpy(char* strDest, const char *strSrc, size_t n)
    {
        assert( (strDest != nullptr) && (strSrc != nullptr) );
        char *address = strDest;
        while(n-- && (*strDest++ = *strSrc++) != '\0');
        return address;
    }

    //按字节拷贝
    void *my_memcpy_byte(void *dest, const void* src, size_t n)
    {
        if(dest == nullptr || src == nullptr)
            return nullptr;

        char *pDest = static_cast<char*>(dest);
        const char *pSrc = static_cast<const char*>(src);
        if(pDest > pSrc && pDest < pSrc+n)
        {
            pDest = pDest + n - 1;
            pSrc = pSrc + n - 1;
            while(n--)
                *pDest-- = *pSrc--;
        }
        return dest;
    }

    //按4字节拷贝实现
    void *my_memcpy(void *dest, const void* src, size_t n)
    {
        if(dest == nullptr || src == nullptr || n <= 0)
            return nullptr;

        int *pDest = (int *)dst;
        int *pSrc = (int *)src;
        char *tmp1 = nullptr;
        char *tmp2 = nullptr;
        int c1 = n / 4;
        int c2 = n % 4;

        if(pDest > pSrc && pDst < pSrc + n)
        {
            tmp1 = static_cast<char*>(pDest) + n + 1;
            tmp2 = static_cast<char*>(pSrc) + n + 1;
            while(c2--)
                *tmp1-- = *tmp2--;

            tmp1++;
            tmp2++;
            pDest = static_cast<int*>tmp1;
            pSrc = static_cast<int*>tmp2;
            pDest--;
            pSrc--;
            while(c1--)
                *pDest = *pSrc--;
        }
        else
        {
            while(c1--)
                *pDest+= = *pSrc++;

            tmp1 = static_cast<char*>(pDest);
            tmp2 = static_cast<char*>(pSrc);
            while(c2--)
                *tmp1++ = *tmp2++;
        }
        return dest;
    }
    
    
    void*Memcpy(void *dst, const void *src, size_t size)
    {
        char *psrc;
        char *pdst;
            
        if(NULL == dst || NULL == src)
        {
            return NULL;
        }
            
        if((src < dst) && (char *)src +size > (char *)dst) // 自后向前拷贝
        {
            psrc = (char *)src + size - 1;
            pdst = (char *)dst + size - 1;
            while(size--)
            {
                *pdst-- = *psrc--;
            }
        }
        else
        {
            psrc = (char *)src;
            pdst = (char *)dst;
            while(size--)
            {
                *pdst++ = *psrc++;
            }
        }
            
        return dst;
    }

};
