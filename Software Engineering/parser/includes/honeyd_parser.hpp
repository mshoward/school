#ifndef HONEYD_PARSER_HEADER
#define HONEYD_PARSER_HEADER
namespace hdparser
{
	class honeyd_parser
	{
		public:
			std::string currString;
			std::string timeStamp;
			std::string packetType;
			std::string sourceIP;
			std::string sourceSocket;
			std::string targetIP;
			std::string targetSocket;
			std::string osVersion;
			int index;
			bool isGood;
			enum WORDTYPE
			{
				TIMESTAMP,
				PACKETTYPE,
				SOURCEIP,
				SOURCESOCKET,
				TARGETIP,
				TARGETSOCKET,
				OSVERSION
			};
			//TODO:: implement a smarter parser

			honeyd_parser();//done
			honeyd_parser(std::string rawString);//done
			~honeyd_parser();//nothing to do, so done by default
			void setString(std::string rawString);//done
			std::string getTimeStamp();//done
			std::string getPacketType();//done
			std::string getSourceIP();//done
			std::string getTargetIP();//done
			std::string getTargetSocket();//done
			std::string getOsVersion();//done
	};
}
#endif