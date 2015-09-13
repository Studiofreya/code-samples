#define _CRT_SECURE_NO_WARNINGS

//	System dependencies ...
#include <iostream>
#include <limits>
#include <float.h>
#include <exception>
#include <iomanip>
#include <complex>

//	Boost dependencies ...

//	Project dependencies ...


int main(int argc, char * argv[])
{
#define DO_INF 0
#define DO_NAN 0
#define DO_CAPTURE 1
#define DO_TABLE 0

#if DO_INF
	// Infinite
	auto positive_inf = std::numeric_limits<double>::infinity();
	auto negative_inf = positive_inf * -1;

	std::cout << "Positive infinity: " << positive_inf << std::endl;
	std::cout << "Negative infinity: " << negative_inf << std::endl;

	// Output:
	// Positive infinity: 1.#INF
	// Negative infinity: -1.#INF

	double zero = 0.0;
	double divbyzero = 1.0 / zero;
	std::cout << "Division by zero: " << divbyzero << std::endl;

	// Output
	// Division by zero: 1.#INF

	auto add = positive_inf + 10;
	auto sub = positive_inf - 10;
	auto mul = positive_inf * 10;
	auto div = positive_inf / 10;

	std::cout << "Add: " << add << " Sub: " << sub << " Mul: " << mul << " Div: " << div << std::endl;
	
	// Output:
	// Add: 1.#INF Sub: 1.#INF Mul: 1.#INF Div: 1.#INF


	// Formatting (scientific)
	for(size_t i=0; i<10; i++)
	{
		std::cout << "Precision: " << std::scientific << i << std::setprecision(i) << " inf: " << positive_inf << std::endl;
	}

	// Output
	// Precision: 0 inf: 1.#INF00e+000
	// Precision: 1 inf: 1.$e+000
	// Precision: 2 inf: 1.#Je+000
	// Precision: 3 inf: 1.#IOe+000
	// Precision: 4 inf: 1.#INFe+000
	// Precision: 5 inf: 1.#INF0e+000
	// Precision: 6 inf: 1.#INF00e+000
	// Precision: 7 inf: 1.#INF000e+000
	// Precision: 8 inf: 1.#INF0000e+000
	// Precision: 9 inf: 1.#INF00000e+000

	// Formatting (fixed)
	for (size_t i=0; i<10; i++)
	{
		std::cout << "Precision: " << std::fixed << i << std::setprecision(i) << " inf: " << positive_inf << std::endl;
	}

	// Output
	// Precision: 0 inf: 1
	// Precision: 1 inf: 1.$
	// Precision: 2 inf: 1.#J
	// Precision: 3 inf: 1.#IO
	// Precision: 4 inf: 1.#INF
	// Precision: 5 inf: 1.#INF0
	// Precision: 6 inf: 1.#INF00
	// Precision: 7 inf: 1.#INF000
	// Precision: 8 inf: 1.#INF0000
	// Precision: 9 inf: 1.#INF00000


#endif

#if DO_NAN
	// NaN

	double a = 0.0;
	double b = 0.0 / a;
	double negative_sqrt = sqrt(-1);

	std::cout << "0.0/0.0 = " << b << std::endl;
	std::cout << "sqrt(-1) = " << negative_sqrt << std::endl;



	// Output
	// 0.0/0.0 = -1.#IND
	// sqrt(-1) = -1.#IND



	double dblmax = std::numeric_limits<double>::max();
	double dblmaxplusone = dblmax + dblmax;


#endif

#if DO_CAPTURE

	// Method 1, Comparision

	double inf = std::numeric_limits<double>::infinity();
	double nan = std::numeric_limits<double>::quiet_NaN();
	double ind = sqrt(-1);

	if (nan != nan)
	    std::cout << "nan != nan" << std::endl;

	if (ind != ind)
	    std::cout << "ind != ind" << std::endl;

	if (inf != inf)
	    std::cout << "inf != inf" << std::endl;

	// Output
	// nan != nan
	// ind != ind
	// std::isnan(nan) is true
	// std::isnan(ind) is true

	// Method 2, std::isnan

	if (std::isnan(nan))
	    std::cout << "std::isnan(nan) is true" << std::endl;

	if (std::isnan(ind))
	    std::cout << "std::isnan(ind) is true" << std::endl;

	if (std::isnan(inf))
	    std::cout << "std::isnan(inf) is true" << std::endl;

	// Output
	// std::isnan(nan) is true
	// std::isnan(ind) is true


	// According to the docs, always clear fp control word
	auto state = _clearfp();
	state = _control87(0,0);

	//auto state = _control87(0, 0);
	//auto state = _controlfp(_controlfp(0, 0) & ~(_EM_INVALID | _EM_ZERODIVIDE | _EM_OVERFLOW), _MCW_EM);
	//auto state = _controlfp((_EM_INVALID | _EM_ZERODIVIDE | _EM_OVERFLOW), _MCW_EM);
	//auto state = _controlfp(_EM_INEXACT|_EM_UNDERFLOW|_EM_OVERFLOW|_EM_ZERODIVIDE|_EM_INVALID, _MCW_EM);
	//_controlfp(_EM_INEXACT, _MCW_EM);
	//_control87(~_EM_INVALID, _MCW_EM);

	//state = _control87(state & _EM_INVALID, _MCW_EM);


	// This will turn on FPE for zerodiv
	//state = _control87(state & ~_EM_ZERODIVIDE, _MCW_EM);

	// This will turn on FPE for #IND
	//state = _control87(state & ~_EM_INVALID, _MCW_EM);


	// This will turn on FPE for #IND and zerodiv
	state = _control87(state & ~(_EM_ZERODIVIDE|_EM_INVALID), _MCW_EM);

	// All FPEs
	//state = _control87(state & ~(_EM_INEXACT|_EM_UNDERFLOW|_EM_OVERFLOW|_EM_ZERODIVIDE|_EM_INVALID|_EM_DENORMAL), _MCW_EM);


	//auto state = _control87(~(_EM_INEXACT|_EM_UNDERFLOW|_EM_OVERFLOW|_EM_ZERODIVIDE|_EM_INVALID|EM_DENORMAL), _MCW_EM);

	//_controlfp(_EM_INVALID)

//#define _MCW_EM         0x0008001f              /* interrupt Exception Masks */
//#define _EM_INEXACT     0x00000001              /*   inexact (precision) */
//#define _EM_UNDERFLOW   0x00000002              /*   underflow */
//#define _EM_OVERFLOW    0x00000004              /*   overflow */
//#define _EM_ZERODIVIDE  0x00000008              /*   zero divide */
//#define _EM_INVALID     0x00000010              /*   invalid */
//#define _EM_DENORMAL    0x00080000              /* denormal exception mask (_control87 only) */

	bool inexact	= 0 == (state & _EM_INEXACT);
	bool underflow	= 0 == (state & _EM_UNDERFLOW);
	bool overflow	= 0 == (state & _EM_OVERFLOW);
	bool zerodiv	= 0 == (state & _EM_ZERODIVIDE);
	bool invalid	= 0 == (state & _EM_INVALID);
	bool denorm		= 0 == (state & _EM_DENORMAL);

	std::cout << std::boolalpha << "Will break on: \n"
	    << "Inexact: " << inexact << "\n"
	    << "Underflow: " << underflow << "\n"
	    << "Overflow: " << overflow << "\n"
	    << "Zerodiv: " << zerodiv << "\n"
	    << "Invalid: " << invalid << "\n"
	    << "Denormal: " << denorm << "\n";

	// Output
	// Will break on:
	// Inexact: false
	// Underflow: false
	// Overflow: false
	// Zerodiv: true
	// Invalid: true
	// Denormal: false

	bool has_snan = std::numeric_limits<double>::has_signaling_NaN;

	const double sqrtneg = sqrt(-1);

	const double zero = 0.0;
	const double zerodivresult = 1.0 / zero;

// 	double infnan = inf - inf;
// 	double d = 0.0;
// 	double nan = 0.0 / d;
// 	double complex = sqrt(-1);


	//std::cout << "snan" << std::numeric_limits<double>::signaling_NaN() << std::endl;

	double qnan = std::numeric_limits<double>::quiet_NaN();
	double asd = qnan + 1;
	double snan = std::numeric_limits<double>::signaling_NaN();
	double val = snan + 1;

	std::cout << "qnan: " << qnan << std::endl;
	//std::cout << "snan" << std::numeric_limits<double>::signaling_NaN() << std::endl;

#endif

#if DO_TABLE

	//double nan = std::numeric_limits<double>::is_iec559

#endif

	return 0;
}

