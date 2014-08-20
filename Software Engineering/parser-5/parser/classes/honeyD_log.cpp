
//sets strings that if examined will give instructions to call
//populateFields(string someString) at some point
HoneyDLogStatement::HoneyDLogStatement()
{
	hdparser::honeyd_parser hdp;
	timeStamp = hdp.getTimeStamp();
	packetType = hdp.getPacketType();
	sourceIP = hdp.getSourceIP();
	targetIP = hdp.getTargetIP();
	targetSocket = hdp.getTargetSocket();
	osVersion = hdp.getOsVersion();
}

//nothing to free
HoneyDLogStatement::~HoneyDLogStatement()
{
}


//sets fields
HoneyDLogStatement::HoneyDLogStatement(std::string rawLine)
{
	hdparser::honeyd_parser hdp(rawLine);
	timeStamp = hdp.getTimeStamp();
	packetType = hdp.getPacketType();
	sourceIP = hdp.getSourceIP();
	targetIP = hdp.getTargetIP();
	targetSocket = hdp.getTargetSocket();
	osVersion = hdp.getOsVersion();
}

//also sets fields
void HoneyDLogStatement::populateFields(std::string rawLine)
{
	hdparser::honeyd_parser hdp(rawLine);
	timeStamp = hdp.getTimeStamp();
	packetType = hdp.getPacketType();
	sourceIP = hdp.getSourceIP();
	targetIP = hdp.getTargetIP();
	targetSocket = hdp.getTargetSocket();
	osVersion = hdp.getOsVersion();
}

