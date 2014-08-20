
//sets empty strings and isGood to false
hdparser::honeyd_parser::honeyd_parser()
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

//nothing to free
hdparser::honeyd_parser::~honeyd_parser()
{
	
}

//sets fields
hdparser::honeyd_parser::honeyd_parser(std::string rawString)
{
	setString(rawString);
}

//sets fields
void hdparser::honeyd_parser::setString(std::string rawString)
{
	std::stringstream input(rawString, std::ios_base::in);
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

//returns the timestamp or a string saying 
//the parser's not been given a string
std::string hdparser::honeyd_parser::getTimeStamp()
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

//same as above
std::string hdparser::honeyd_parser::getPacketType()
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

std::string hdparser::honeyd_parser::getSourceIP()
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
std::string hdparser::honeyd_parser::getTargetIP()
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
std::string hdparser::honeyd_parser::getTargetSocket()
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
std::string hdparser::honeyd_parser::getOsVersion()
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
