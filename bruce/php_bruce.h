//php_bruce.h
#ifndef BRUCE_H
#define BRUCE_H
#include <string.h>
//加载config.h，如果配置了的话
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

//加载php头文件
#include "php.h"
#define phpext_walu_ptr &bruce_module_entry
extern zend_module_entry bruce_module_entry;

#endif
