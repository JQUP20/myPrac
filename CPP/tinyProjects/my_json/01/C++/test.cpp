#include <iostream>
#include <cstring>
#include <iomanip>
#include "leptjson.h"

static int main_ret = 0;
static int test_count = 0;
static int test_pass  =0;

#define EXPECT_EQ_BASE(equality, expect, actual, format) \
    do{\
        test_count++; \
        if(equality) \
            test_pass++;\
        else {\
            fprintf(stderr, "%s:%d: expect: " format " actual: " format "\n", __FILE__, __LINE__, expect, actual); \
            main_ret = 1; \
        }\
    }while(0)

#define EXPECT_EQ_INT(expect, actual) EXPECT_EQ_BASE((expect) == (actual), expect, actual, "%d")

static void test_parse_null() {
    myjson::LeptJson::lept_value v;
    v.type = myjson::LeptJson::LEPT_FALSE;
    EXPECT_EQ_INT(myjson::LeptJson::LEPT_PARSE_OK, myjson::LeptJson::lept_parse(&v, "null"));
    EXPECT_EQ_INT(myjson::LeptJson::LEPT_NULL, myjson::LeptJson::lept_get_type(&v));
}

static void test_parse_true() {
    myjson::LeptJson::lept_value v;
    v.type = myjson::LeptJson::LEPT_FALSE;
    EXPECT_EQ_INT(myjson::LeptJson::LEPT_PARSE_OK, myjson::LeptJson::lept_parse(&v, "true"));
    EXPECT_EQ_INT(myjson::LeptJson::LEPT_TRUE, myjson::LeptJson::lept_get_type(&v));
}

static void test_parse_false() {
    myjson::LeptJson::lept_value v;
    v.type = myjson::LeptJson::LEPT_TRUE;
    EXPECT_EQ_INT(myjson::LeptJson::LEPT_PARSE_OK, myjson::LeptJson::lept_parse(&v, "false"));
    EXPECT_EQ_INT(myjson::LeptJson::LEPT_FALSE, myjson::LeptJson::lept_get_type(&v));
}

static void test_parse_expect_value() {
    myjson::LeptJson::lept_value v;

    v.type = myjson::LeptJson::LEPT_FALSE;
    EXPECT_EQ_INT(myjson::LeptJson::LEPT_PARSE_EXPECT_VALUE, myjson::LeptJson::lept_parse(&v, ""));
    EXPECT_EQ_INT(myjson::LeptJson::LEPT_NULL, myjson::LeptJson::lept_get_type(&v));

    v.type = myjson::LeptJson::LEPT_FALSE;
    EXPECT_EQ_INT(myjson::LeptJson::LEPT_PARSE_EXPECT_VALUE, myjson::LeptJson::lept_parse(&v, " "));
    EXPECT_EQ_INT(myjson::LeptJson::LEPT_NULL, myjson::LeptJson::lept_get_type(&v));
}

static void test_parse_invalid_value() {
    myjson::LeptJson::lept_value v;
    v.type = myjson::LeptJson::LEPT_FALSE;
    EXPECT_EQ_INT(myjson::LeptJson::LEPT_PARSE_INVALID_VALUE, myjson::LeptJson::lept_parse(&v, "nul"));
    EXPECT_EQ_INT(myjson::LeptJson::LEPT_NULL, myjson::LeptJson::lept_get_type(&v));

    v.type = myjson::LeptJson::LEPT_FALSE;
    EXPECT_EQ_INT(myjson::LeptJson::LEPT_PARSE_INVALID_VALUE, myjson::LeptJson::lept_parse(&v, "?"));
    EXPECT_EQ_INT(myjson::LeptJson::LEPT_NULL, myjson::LeptJson::lept_get_type(&v));
}

static void test_parse_root_not_singular() {
    myjson::LeptJson::lept_value v;
    v.type = myjson::LeptJson::LEPT_FALSE;
    EXPECT_EQ_INT(myjson::LeptJson::LEPT_PARSE_ROOT_NOT_SINGULAR, myjson::LeptJson::lept_parse(&v, "null x"));
    EXPECT_EQ_INT(myjson::LeptJson::LEPT_NULL, myjson::LeptJson::lept_get_type(&v));
}

static void test_parse() {
    test_parse_null();
     test_parse_true();
    test_parse_false();
    test_parse_expect_value();
    test_parse_invalid_value();
    test_parse_root_not_singular();
}

int main() {
    test_parse();
    //std::cout << test_pass << "/" << test_count << "  " << std::setprecision(2) << test_pass * 100.0 / test_count << "% passed" << std::endl;
    std::cout << test_pass << "/" << test_count << "  " << test_pass * 100.0 / test_count << "% passed" << std::endl;
    return main_ret;
}
