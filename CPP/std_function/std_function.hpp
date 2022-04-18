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
   /* void *my_memcpy(void *dest, const void* src, size_t n)
    {
        if(dest == nullptr || src == nullptr || n <= 0)
            return nullptr;

        int *pDest = (int *)dest;
        int *pSrc = (int *)src;
        char *tmp1 = nullptr;
        char *tmp2 = nullptr;
        int c1 = n / 4;
        int c2 = n % 4;

        if(pDest > pSrc && pDest < pSrc + n)
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
   */ 
    
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

    void* memset(void* src, int c, size_t n) {
        assert(src != nullptr);
        char* pSrc = static_cast<char *>(src);
        while(n--){
            *pSrc++ = (char)c;
        }
        return src;
    }

    char* starcat(char* dest, const char* src)
    {
        assert(dest != nullptr && src != nullptr);
        char* pDest = dest;
        while(*pDest != '\0')
        {
            pDest++;
        }
        while((*pDest++ = *src++) != '\0');
        return dest;
    }

    int strcmp(const char* s1, const char* s2){
        assert(s1 != nullptr && s2 != nullptr);
        while(s1 && s2 && *s1 == *s2){
            s1++;
            s2++;
        }
        return *s1 - *s2;
    }

    size_t strlen(const char* src){
        assert(src != nullptr);
        size_t ret = 0;
        while(*src++ != '\0'){
            ret++;
        }
        return ret;
    }

    long long StrToIntCore(const char* str, bool minus);

    enum Status {kValid = 0, kInvalid};
    int g_nStatus = kValid;

    int StrToInt(const char* str)
    {
        g_nStatus = kInvalid;
        long long num = 0;

        if(str != nullptr && *str != '\0')
        {
            bool minus = false;
            if(*str == '+')
                str ++;
            else if(*str == '-')
            {
                str ++;
                minus = true;
            }

            if(*str != '\0')
                num = StrToIntCore(str, minus);
        }

        return (int)num;
    }

    long long StrToIntCore(const char* digit, bool minus)
    {
        long long num = 0;

        while(*digit != '\0')
        {
            if(*digit >= '0' && *digit <= '9')
            {
                int flag = minus ? -1 : 1;
                num = num * 10 + flag * (*digit - '0');

                if(!minus && num > 0x7FFFFFFF
                        || (minus && num < (signed int)0x80000000))
                {
                    num = 0;
                    break;
                }

                digit++;
            }
            else
            {
                num = 0;
                break;
            }
        }

        if(*digit == '\0')
            g_nStatus = kValid;

        return num;
    }






































};
