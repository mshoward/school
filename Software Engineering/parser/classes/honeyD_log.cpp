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
HoneyDLogStatement::HoneyDLogStatement()
{
	hdparser::honeyd_parser hdp();
	timeStamp = hdp.getTimeStamp();
	packetType = hdp.getPacketType();
	sourceIP = hdp.getSourceIP();
	targetIP = hdp.getTargetIP();
	targetSocket = hdp.getTargetSocket();
	osVersion = hdp.getOsVersion();
}
