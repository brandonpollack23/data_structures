#include "myException.h"
#include <string>

illegalParameterValue::illegalParameterValue(string theMessage){

	message = theMessage;
}


void illegalParameterValue::outputMessage() 
{
	cout << message << endl;

} 

illegalParameterValue::~illegalParameterValue() throw() {
//Error- declaration of `virtual APIEx::~APIEx()' throws different exceptions
}


illegalIndex::illegalIndex(string theMessage){

	message = theMessage;
}


void illegalIndex::outputMessage() 
{
	cout << message << endl;

} 

illegalIndex::~illegalIndex() throw() {
//Error- declaration of `virtual APIEx::~APIEx()' throws different exceptions
}
