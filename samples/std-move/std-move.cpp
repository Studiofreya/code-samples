#include <memory>

// Struct to hold our data
struct Data
{
	int id = 0;
};

// Typedef of our unique pointer
typedef std::unique_ptr<Data>	Data_ptr;

void doProcess(Data_ptr && data)
{
	// Some code
}

int main()
{
	//Data_ptr data(new Data());
	//doProcess(data);	// C2446

	Data_ptr otherdata(new Data());
	doProcess(std::move(otherdata));

	return 0;
}