// Caleb Catt
// This program handles very large integers through means of operator overloading
// 4/24/2019
// This is the incomplete version of the very_long_int class.
// It defines some functions (notably, operator+), but not others, which are stubbed out.
// Students are invited to implement only the stubbed-out functions described in the assignment.
// Note that there *may be* stubs below that students are not asked to implement (e.g., operator*).

#include<iostream>
#include<vector>

using namespace std;

class very_long_int
{
	// Precondition:  The input starts with a sequence of digits followed by an 'X',
	//                with blanks, end-of-line markers, and invalid  digit characters
	//                ignored.  There are no leading zeroes, except for 0 itself, which
	//                has a single 0.
	// Postcondition: very_long contains the very long integer whose digits came from
	//                instream, and a reference to instream has been returned.	The
	//                worstTime(n) is O(n), where n is the number of digit characters
	//                in the input.
	friend istream& operator>> (istream& instream, very_long_int& very_long)
	{
		const char LOWEST_DIGIT_CHAR = '0';

		const char HIGHEST_DIGIT_CHAR = '9';

		const char SENTINEL = 'X';

		char digit_char;

		very_long.digits.erase(very_long.digits.begin(), very_long.digits.end());
		do
		{
			// Loop invariant: Each digit read in so far has been appended to digits.
			instream >> digit_char;
			if ((LOWEST_DIGIT_CHAR <= digit_char) &&
				(digit_char <= HIGHEST_DIGIT_CHAR))
				very_long.digits.push_back(digit_char - LOWEST_DIGIT_CHAR);
		} // while
		while (digit_char != SENTINEL);

		return instream;
	} // overloading >>

	// Postcondition:  The value of very_long has been written to outstream.  The
	//                 worstTime(n) is O(n), where n is the size of very_long.
	friend ostream & operator<< (ostream & outstream, const very_long_int very_long)
	{
		for (unsigned i = 0; i < very_long.digits.size(); i++)
			outstream << (int)very_long.digits[i];
		return outstream;
	} // overloading <<


protected:
	vector<char>digits;

	// Postcondition:  If i >= digits.size(), 0 has been returned; else
	//                 the ith least significant digit in digits has
	//                 been returned.  The least significant digit is
	//                 the 0th least significant digit.
	char least(unsigned i) const
	{
		if (i >= digits.size())
			return 0;
		else
			return digits[digits.size() - i - 1];
	} // least


public:

	// Postcondition: The very_long_int has been initialized to an
	//                empty very_long_int.
	very_long_int()
	{
	} // default constructor


	// Postcondition: The value of the very_long_int is the
	//                unsigned int n.
	very_long_int(unsigned n)
	{
		initialize(n);
	} // constructor

	// Postcondition: The value of the very_long_int is the
	//                unsigned int n.
	void initialize(unsigned n) // called by non-default constructor
	{
		const short BASE = 10;
		digits.erase(digits.begin(), digits.end()); // start over with this VLI

		do
		{
			digits.push_back(n % BASE);
			n = n / BASE;
		} while (n > 0);

		//Flip the order of the digits, since they were entered in reverse order.
		reverse(digits.begin(), digits.end());
	}

	// Postcondition: The value returned is the sum of the calling object (the left-hand
//                 operand) and other_very_long (the right-hand operand). The
//                 worstTime(n) is O(n), where n is the maximum of the number of digits
//                 in the calling object and other_very_long.
	very_long_int operator+ (const very_long_int & other_very_long)
	{
		int carry = 0,
			larger_size,
			partial_sum;

		very_long_int sum;

		if (digits.size() > other_very_long.digits.size())
			larger_size = digits.size();
		else
			larger_size = other_very_long.digits.size();

		for (int i = 0; i < larger_size; i++)
		{
			// Loop invariant: The (i-1)st least significant digits in
			//                            the calling object and other_very_long
			//                            have been added.
			partial_sum = least(i) + other_very_long.least(i) + carry;
			carry = partial_sum / 10;
			sum.digits.push_back(partial_sum % 10);
		} // for

		if (carry == 1)
			sum.digits.push_back(carry);
		reverse(sum.digits.begin(), sum.digits.end());
		return sum;
	} // overloading +

	// Postcondition: true has been returned if the
	//                value of the calling object is less than the value
	//                of other_very_long.  Otherwise, false
	//                has been returned.
	bool operator< (const very_long_int & other_very_long) const
	{
		if (digits.size() == other_very_long.digits.size())
		{
			if (digits[0] > other_very_long.digits[0])
				return false;
			else
			{
				int i = 0;
				while (digits[i] == other_very_long.digits[i])
				{
					i++;
				}
				if (digits[i] > other_very_long.digits[i])
					return false;
			}
		}
		else if (digits.size() > other_very_long.digits.size())
			return false;
		else return true;
		return true;
	}

	// Postcondition: true has been returned if the value of the
	//                calling object is greater than the value
	//                of other_very_long.  Otherwise, false
	//                has been returned.
	bool operator> (const very_long_int & other_very_long) const
	{
		return other_very_long < *this;
	} // overloading  <


		// Postcondition: true has been returned if the value of the
		//                calling object is equal to the value
		//                of other_very_long.  Otherwise, false
		//                has been returned.
	bool operator== (const very_long_int & other_very_long) const
	{
		int larger_size;

		if (digits.size() > other_very_long.digits.size())
			larger_size = digits.size();
		else
			larger_size = other_very_long.digits.size();

		if (digits.size() == other_very_long.digits.size())
		{
			for (int i = 0; i <= larger_size; i++)
			{
				if (digits[i] != other_very_long.digits[i])
				{
					return false;
				}
			}
			return true;
		}
		else
			return true;
		 // stub
	}

	// Postcondition: The calling object contains the nth Fibonacci
	//                number.
	very_long_int fibonacci(unsigned n)
	{
		if (n <= 1)
			return n;
		very_long_int previous = 0,
					  current = 1;
		for (int i = 0; i < n - 1; i++)
		{
			very_long_int temp = previous + current;
			previous = current;
			current = temp;
		}
		return current;
	}


	// Precondition: The calling object is >= other_very_long.
	// Postcondition: A VLI representing calling_object minus other_very_long is returned.
	very_long_int operator- (const very_long_int & other_very_long)
	{
		int carry = 0,
			larger_size,
			partial_sum;

		very_long_int difference;

		if (digits.size() > other_very_long.digits.size())
			larger_size = digits.size();
		else
			larger_size = other_very_long.digits.size();

		for (int i = 0; i < larger_size; i++)
		{
			// Loop invariant: The (i-1)st least significant digits in
			//                            the calling object and other_very_long
			//                            have been added.
			partial_sum = least(i) - other_very_long.least(i) - carry;
			carry = partial_sum / 10;
			difference.digits.push_back(partial_sum % 10);
		} // for

		if (carry == 1)
			difference.digits.push_back(carry);
		reverse(difference.digits.begin(), difference.digits.end());
		return difference; 
	}

	// Postcondition: The value returned is the product of this very_long_int and
	// other_very_long. The worstTime(n) is O(n*n), where n is the maximum of the
	// number of digits in either input value.
	// Postcondition: A VLI representing calling_object times the other_very_long is returned.//
	very_long_int operator* (const very_long_int & other_very_long)
	{
		int carry = 0,
			larger_size,
			partial_sum;

		very_long_int product;

		if (digits.size() > other_very_long.digits.size())
			larger_size = digits.size();
		else
			larger_size = other_very_long.digits.size();

		for (int i = 0; i < larger_size; i++)
		{
			// Loop invariant: The (i-1)st least significant digits in
			//                            the calling object and other_very_long
			//                            have been added.
			partial_sum = least(i) * other_very_long.least(i) * carry;
			carry = partial_sum / 10;
			product.digits.push_back(partial_sum % 10);
		} // for

		if (carry == 1)
			product.digits.push_back(carry);
		reverse(product.digits.begin(), product.digits.end());
		return product;
	}


}; // very_long_int
