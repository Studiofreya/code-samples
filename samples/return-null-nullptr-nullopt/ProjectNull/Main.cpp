#include <memory>
#include <iostream>
#include <vector>
#include <optional>

using std::optional;
using std::string;
using std::nullopt;
using std::vector;
using std::cout;
using std::unique_ptr;

class SomeClass
{

};

int emptyInt() {
	return 0;
}

optional<int> optionalEmptyInt() {
	return nullopt;
}

string emptyString() {
	return "";
}

optional<string> optionalEmptyString() {
	return nullopt;
}

SomeClass* emptyClass() {
	return nullptr;
}


SomeClass* emptyClass2() {
	return NULL;
}

optional<SomeClass> optionalEmptyClass() {
	return nullopt;
}
vector<string> emptyVector() {
	return {};
}

unique_ptr<SomeClass> emptyUniquePtr()
{
	return nullptr;
}

int main()
{
	int myInt = emptyInt();
	optional<int> myInt2 = optionalEmptyInt();
	
	string myString = emptyString();
	optional<string> myString2 = optionalEmptyString();

	SomeClass* myClass = emptyClass();
	SomeClass* myClass2 = emptyClass2();
	optional<SomeClass> myClass3 = optionalEmptyClass();

	vector<string> myVector = emptyVector();

	if (myInt == 0) {
		cout << "Empty int \n";
	}

	if (!myInt2) {
		cout << "Empty int2 \n";
	}

	if (myString.empty()) {
		cout << "Empty string \n";
	}

	if (!myString2) {
		cout << "Empty optional string \n";
	}

	if (myClass == nullptr) {
		cout << "Empty SomeClass \n";
	}

	if (myClass2 == nullptr) {
		cout << "Empty SomeClass2 \n";
	}

	if (!myClass3) {
		cout << "Empty optional SomeClass \n";
	}

	if (myVector.empty()) {
		cout << "Empty vector \n";
	}

	system("pause");
}



