#include "Logger.hpp"

int main(void)
{
	Logger logger = Logger("log.log");

	logger.log("console", "Launching program");
	logger.log("console", "Program launched");
	logger.log("console", "Logging to file");
	logger.log("file", "Program opening file");
	logger.log("file", "Program logging into log");
	logger.log("file", "Program now stopping to log logs into log");
	logger.log("console", "Closed file");
	logger.log("console", "Program initializing failure phase to prove functionality");
	logger.log("console", "Failure tests being run...");
	logger.log("", "hey");
	logger.log("Good day", "hey");
	logger.log("Log", "hey");
	logger.log("Log log log log log log log log log log", "hey");
	logger.log("/a/z/dz/zdg/zd/dzg/d", "cool");
	logger.log("console", "Failure tests finished");
	logger.log("console", "Wasn't that cool?");
	logger.log("console", "Writing one more line to file");
	logger.log("file", "This should be at the end");
	logger.log("console", "Done");
	logger.log("console", "Exiting program");

	return (0);
}
