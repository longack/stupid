#include "stupid_loggable.h"
#include "stupid_loggable_impl.h"

void stupid::stupid_loggable::stupid_log_fatal(const char* branch_id, ...)
{
	impl->stupid_log_fatal(branch_id, ...);
}

void stupid::stupid_loggable::stupid_log_error(const char* branch_id, ...)
{
	impl->stupid_log_error(branch_id, ...);
}

void stupid::stupid_loggable::stupid_log_warn(const char* branch_id, ...)
{
	impl->stupid_log_warn(branch_id, ...);
}

void stupid::stupid_loggable::stupid_log_notice(const char* branch_id, ...)
{
	impl->stupid_log_notice(branch_id, ...);
}

void stupid::stupid_loggable::stupid_log_info(const char* branch_id, ...)
{
	impl->stupid_log_info(branch_id, ...);
}

void stupid::stupid_loggable::stupid_log_debug(const char* branch_id, ...)
{
	impl->stupid_log_debug(branch_id, ...);
}

stupid::stupid_loggable::stupid_loggable()
{
	impl = new stupid_loggable_impl;
}

stupid::stupid_loggable::~stupid_loggable()
{
	delete impl;
}
