#include <Windows.h>
#include "Logger.h"
#include "Shared.h"

Logger g_Logger(Shared::getDLLPath() + "aaface\\aa2facelog.txt", Logger::Priority::WARN);

Logger::Logger(std::string file, Priority prio) : currPrio(Priority::ERR), filter(prio)
{
	outfile.open(file);
	if(!outfile.good()) {
		MessageBox(0,"Could not open Logfile","Error",0);
	}
}

Logger::~Logger()
{
	outfile.close();
}

void Logger::SetPriority(Priority prio) {
	filter = prio;
	*this << "------- applied priority " << prio << " -------\r\n";
}

/* Returns true if the given priority is covered by the current priority, or else false */
bool Logger::FilterPriority(Priority prio)
{
	return prio >= filter;
}
