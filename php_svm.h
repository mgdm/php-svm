/*
  +----------------------------------------------------------------------+
  | PHP Version 5 / svm                                                  |
  +----------------------------------------------------------------------+
  | Copyright (c) 2010 Ian Barber                                        |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.0 of the PHP license,       |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_0.txt.                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Authors: Ian Barber <ian.barber@gmail.com>                           |
  +----------------------------------------------------------------------+
*/
#ifndef _PHP_SVM_H_
# define _PHP_SVM_H_

#define PHP_SVM_EXTNAME "svm"
#define PHP_SVM_EXTVER  "@PACKAGE_VERSION@"

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#ifdef ZTS
# include "TSRM.h"
#endif

#include "php.h"
#include <libsvm/svm.h>

ZEND_BEGIN_MODULE_GLOBALS(svm)
	zend_bool test;
ZEND_END_MODULE_GLOBALS(svm)
	
ZEND_EXTERN_MODULE_GLOBALS(svm)

#ifdef ZTS
# define SVM_G(v) TSRMG(svm_globals_id, zend_svm_globals *, v)
#else
# define SVM_G(v) (svm_globals.v)
#endif

typedef struct _php_svm_object  {
	zend_object zo;
	/* hold the SVM parameters */
	struct svm_parameter param; 
	
	/* Store the last error message here */
	char last_error[512];

} php_svm_object;

typedef struct _php_svm_model_object {
	zend_object zo;
	
	/* Hold the training data */
	struct svm_node *x_space;
	
	/* hold the model generated by training, or to be used for classifying*/
	struct svm_model *model;
	
} php_svm_model_object;

extern zend_module_entry svm_module_entry;
#define phpext_svm_ptr &svm_module_entry

#endif /* _PHP_SVM_H_ */


