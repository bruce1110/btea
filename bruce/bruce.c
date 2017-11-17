//walu.c
#include "php_bruce.h"
ZEND_FUNCTION(bruce_hello)
{
    php_printf("Hello World!\n");
}
ZEND_FUNCTION(bruce_return)
{
    char * buf = "qinchong";
    RETURN_STRINGL(buf, strlen(buf), 1);
}
ZEND_FUNCTION(bruce_name_hello)
{
    char * name;
    char * address;
    int name_len;
    int address_len;
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ss", &name, &name_len, &address, &address_len) == FAILURE) {
        RETURN_NULL();
    }
    php_printf("hello ");
    PHPWRITE(name, name_len);
    php_printf(",I am in ");
    PHPWRITE(address, address_len);
    php_printf("\n");
}
static zend_function_entry bruce_functions[] = {
    ZEND_FE(bruce_hello,        NULL)
    ZEND_FE(bruce_return, NULL)
    ZEND_FE(bruce_name_hello, NULL)
    { NULL, NULL, NULL }
};
//module entry
zend_module_entry bruce_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
     STANDARD_MODULE_HEADER,
#endif
    "bruce", //这个地方是扩展名称，往往我们会在这个地方使用一个宏。
    bruce_functions, /* Functions */
    NULL, /* MINIT */
    NULL, /* MSHUTDOWN */
    NULL, /* RINIT */
    NULL, /* RSHUTDOWN */
    NULL, /* MINFO */
#if ZEND_MODULE_API_NO >= 20010901
    "2.1", //这个地方是我们扩展的版本
#endif
    STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_BRUCE
ZEND_GET_MODULE(bruce)
#endif
