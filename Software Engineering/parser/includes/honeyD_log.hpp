#ifndef HD_LOG_STATEMENT_H
#define HD_LOG_STATEMENT_H
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
