#ifndef LEPTJSON_H__
#define LEPTJSON_H__

#include <assert.h>

namespace myjson{

#define EXPECT(c, ch)       do { assert(*c->json == (ch)); c->json++; } while(0)

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
        lept_type type;
    }lept_value;

    enum{
        LEPT_PARSE_OK = 0,
        LEPT_PARSE_EXPECT_VALUE,
        LEPT_PARSE_INVALID_VALUE,
        LEPT_PARSE_ROOT_NOT_SINGULAR
    };

    static int lept_parse(lept_value* v, const char* json);

    static lept_type lept_get_type(const lept_value* v);

//private:

    static void lept_parse_whitespace(lept_context* c); 
    static int lept_parse_true(lept_context* c, lept_value* v);

    static int lept_parse_false(lept_context* c, lept_value* v);

    static int lept_parse_null(lept_context* c, lept_value* v);

    static int lept_parse_value(lept_context* c, lept_value* v);
};

} /*NAMESPACE MYJSON*/

#endif /*LEPTJSON_H*/
