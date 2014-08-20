honeyd_parser::honeyd_parser()
{
	currString = "";
	timeStamp = "";
	packetType = "";
	sourceIP = "";
	sourceSocket = "";
	targetIP = "";
	targetSocket = "";
	osVersion = "";
	isGood = false;
	index = 0;
}
~honeyd_parser()
{
	
}
honeyd_parser::honeyd_parser(std::string rawString)
{
	setString(rawString);
}

void honeyd_parser::setString(std::string rawString)
{
	std::stringstream input(&rawString, std::ios_base::in)
	currString = rawString;
	std::getline(input, timeStamp, ' ');
	std::getline(input, packetType, ' ');
	std::getline(input, sourceIP, ' ');
	std::getline(input, sourceSocket, ' ');
	std::getline(input, targetIP, ' ');
	std::getline(input, targetSocket, ' ');
	std::getline(input, targetSocket, ' ');
	std::getline(input, osVersion); /*
	the end of the log after this gets messy
	and I don't really understand it, so I'll shove it on the
	beginning of osVersion*/
	isGood = true;
	index = 0;
}
std::string honeyd_parser::getTimeStamp()
{
	if(isGood)
		return timeStamp;
	else
	{
		std::string ret;
		ret = "I HAVE NOT BEEN GIVEN A STRING";
		return ret;
	}
}
std::string honeyd_parser::getPacketType()
{
	if(isGood)
		return packetType;
	else
	{
		std::string ret;
		ret = "I HAVE NOT BEEN GIVEN A STRING";
		return ret;
	}
}

std::string honeyd_parser::getSourceIP()
{
	if(isGood)
		return sourceIP;
	else
	{
		std::string ret;
		ret = "I HAVE NOT BEEN GIVEN A STRING";
		return ret;
	}
}
std::string honeyd_parser::getTargetIP()
{
	if(isGood)
		return targetIP;
	else
	{
		std::string ret;
		ret = "I HAVE NOT BEEN GIVEN A STRING";
		return ret;
	}
}
std::string honeyd_parser::getTargetSocket()
{
	if(isGood)
		return targetSocket;
	else
	{
		std::string ret;
		ret = "I HAVE NOT BEEN GIVEN A STRING";
		return ret;
	}
}
std::string honeyd_parser::getOsVersion()
{
	if(isGood)
		return osVersion;
	else
	{
		std::string ret;
		ret = "I HAVE NOT BEEN GIVEN A STRING";
		return ret;
	}
}
