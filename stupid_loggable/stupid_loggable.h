#ifndef STUPID_LOGGABLE_H_
#define STUPID_LOGGABLE_H_

namespace stupid
{
	class stupid_loggable_impl;
	class stupid_loggable
	{
	public:
		void stupid_log_fatal(const char*	branch_id, ...);
		void stupid_log_error(const char*	branch_id, ...);
		void stupid_log_warn(const char*	branch_id, ...);
		void stupid_log_notice(const char*	branch_id, ...);
		void stupid_log_info(const char*	branch_id, ...);
		void stupid_log_debug(const char*	branch_id, ...);

	public:
		stupid_loggable();
		~stupid_loggable();

		stupid_loggable(const stupid_loggable&) = delete;
		stupid_loggable(const stupid_loggable&&) = delete;
		stupid_loggable& operator=(const stupid_loggable&) = delete;
		stupid_loggable& operator=(const stupid_loggable&&) = delete;

	private:
		stupid_loggable_impl* impl;
	};
}

#endif 
