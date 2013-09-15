#ifndef PHP_MOSQUITTO_H
#define PHP_MOSQUITTO_H

extern zend_module_entry mosquitto_module_entry;
#define phpext_mosquitto_ptr &mosquitto_module_entry

#ifdef PHP_WIN32
#	define PHP_MOSQUITTO_API __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
#	define PHP_MOSQUITTO_API __attribute__ ((visibility("default")))
#else
#	define PHP_MOSQUITTO_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

#include <mosquitto.h>

#define PHP_MOSQUITTO_ERROR_HANDLING() \
	zend_replace_error_handling(EH_THROW, mosquitto_ce_exception, &mosquitto_original_error_handling TSRMLS_CC)

#define PHP_MOSQUITTO_RESTORE_ERRORS() \
	zend_restore_error_handling(&mosquitto_original_error_handling TSRMLS_CC)

typedef struct _mosquitto_client_object {
	zend_object std;
	struct mosquitto *client;
} mosquitto_client_object;

PHP_MINIT_FUNCTION(mosquitto);
PHP_MSHUTDOWN_FUNCTION(mosquitto);
PHP_MINFO_FUNCTION(mosquitto);

PHP_FUNCTION(mosquitto_version);

#endif	/* PHP_MOSQUITTO_H */

/* __footer_here__ */