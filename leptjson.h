#ifndef LEPTJSON_H__
#define LEPTJSON_H__

typedef enum { LEPT_NULL, LEPT_FALSE, LEPT_TRUE, LEPT_NUMBER, LEPT_STRING, LEPT_ARRAY, LEPT_OBJECT } lept_type;

typedef struct {
    double n;
    lept_type type;
} lept_value;

int lept_parse(lept_value* v, const char* json);

/* return code of lept_parse */
enum {
    LEPT_PARSE_OK = 0,
    LEPT_PARSE_EXPECT_VALUE,       /* empty json */
    LEPT_PARSE_INVALID_VALUE,      /* unspported value */
    LEPT_PARSE_ROOT_NOT_SINGULAR,   /* mutiple values */
    LEPT_PARSE_NUMBER_TOO_BIG
};

lept_type lept_get_type(const lept_value* v);

double lept_get_number(const lept_value* v);


#endif /* LEPTJSON_H__ */