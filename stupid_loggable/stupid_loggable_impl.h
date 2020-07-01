ifndef STUPID_LOGGABLE_IMPL_H_
#define STUPID_LOGGABLE_IMPL_H_

namespace stupid
{
	class stupid_loggable_impl
	{
	public:
		void stupid_log_fatal(const char*	branch_id, ...);
		void stupid_log_error(const char*	branch_id, ...);
		void stupid_log_warn(const char*	branch_id, ...);
		void stupid_log_notice(const char*	branch_id, ...);
		void stupid_log_info(const char*	branch_id, ...);
		void stupid_log_debug(const char*	branch_id, ...);

	public:
		stupid_loggable_impl()	= default;
		~stupid_loggable_impl() = default;
		stupid_loggable_impl(const stupid_loggable_impl&)	= delete;
		stupid_loggable_impl(const stupid_loggable_impl&&)	= delete;
		stupid_loggable_impl& operator=(const stupid_loggable_impl&)	= delete;
		stupid_loggable_impl& operator=(const stupid_loggable_impl&&)	= delete;
	};
}

#endif 
