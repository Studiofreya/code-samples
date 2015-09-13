BOOST=../../../boost_1_55_0

build:
	g++ -I$(BOOST) signals.cpp -o signals
	g++ -I$(BOOST) signals-arguments.cpp -o signals-args
	g++-4.8.1 -std=c++11 -I$(BOOST) signals-class.cpp -o signals-class
	g++-4.8.1 -std=c++11 -I$(BOOST) signals-lambda.cpp -o signals-lambda
	g++-4.8.1 -std=c++11 -I$(BOOST) -ggdb3 signals-message.cpp -o signals-message
