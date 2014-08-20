#ifndef HD_LOG_STATEMENT_H
#define HD_LOG_STATEMENT_H
/* wrapper for the honeyd_parser so the parser can be improved at will
 * without messing up the interface */
	class HoneyDLogStatement
	{
		public:
		
			std::string timeStamp;
			std::string packetType;
			std::string sourceIP;
			std::string sourceSocket;
			std::string targetIP;
			std::string targetSocket;
			std::string osVersion;
			HoneyDLogStatement();
			~HoneyDLogStatement();
			HoneyDLogStatement(std::string rawLine);
			void populateFields(std::string rawLine);
	};
#endif
