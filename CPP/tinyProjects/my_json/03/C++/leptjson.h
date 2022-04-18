#ifndef LEPTJSON_H__
#define LEPTJSON_H__

#include <assert.h>
#include <cstddef>
#include <cstring>
#include <vector>

namespace myjson{

#define EXPECT(c, ch)       do { assert(*c->json == (ch)); c->json++; } while(0)

/*
typedef struct {
    const char* json;
    char* stack;
    size_t size, top;
}lept_context;
*/


typedef struct {
    const char* json;
}lept_context;

class LeptJson{
public:
    typedef enum{
        LEPT_NULL,
        LEPT_FALSE,
        LEPT_TRUE,
        LEPT_NUMBER,
        LEPT_STRING,
        LEPT_ARRAY,
        LEPT_OBJECT
    } lept_type;

    typedef struct {
        //一个值不可能同时为数字和字符串，这里可使用union来节省内存：
        /*char* s;
        size_t len;
        double n;
        */
        union {
           struct { char* s; size_t len; }s; 
           double n;
        }u;
        lept_type type;
    }lept_value;

    enum{
        LEPT_PARSE_OK = 0,
        LEPT_PARSE_EXPECT_VALUE,
        LEPT_PARSE_INVALID_VALUE,
        LEPT_PARSE_ROOT_NOT_SINGULAR,
        LEPT_PARSE_NUMBER_TOO_BIG,
        LEPT_PARSE_MISS_QUOTATION_MARK,
        LEPT_PARSE_INVALID_STRING_ESCAPE,
        LEPT_PARSE_INVALID_STRING_CHAR
    };

    static inline void lept_init(lept_value* v){
        (v)->type = LEPT_NULL; 
    }
   static inline void  lept_set_null(lept_value* v){
        lept_free(v);
    }
    LeptJson() {}

    ~LeptJson() {}


    static int lept_parse(lept_value* v, const char* json);
    
    static void lept_free(lept_value* v);

    static lept_type lept_get_type(const lept_value* v);

    static int lept_get_boolean(const lept_value* v);
    static void lept_set_boolean(lept_value* v, int b);

    static double lept_get_number(const lept_value* v);
    static void lept_set_number(lept_value* v, double n);

    static const char* lept_get_string(const lept_value* v);
    static size_t lept_get_string_length(const lept_value* v);
    static void lept_set_string(lept_value* v, const char* s, size_t len);

private:


    static void lept_parse_whitespace(lept_context* c);

    static int lept_parse_literal(lept_context* c, lept_value* v, const char* literal, lept_type type);
/*
    static int lept_parse_true(lept_context* c, lept_value* v);

    static int lept_parse_false(lept_context* c, lept_value* v);

    static int lept_parse_null(lept_context* c, lept_value* v);
    */

    static int lept_parse_value(lept_context* c, lept_value* v);

    static int lept_parse_number(lept_context* c, lept_value* v);

    static int lept_parse_string(lept_context* c, lept_value* v);

private:
    lept_value m_v;     //

    vector<lept_context> m_lept_context;
};

} /*NAMESPACE MYJSON*/

#endif /*LEPTJSON_H*/
