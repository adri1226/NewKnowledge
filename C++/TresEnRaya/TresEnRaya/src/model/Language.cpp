#include "Language.hpp"

const char * Language::getMessage(Message message)
{
	return _allMessage[message].c_str();
}
