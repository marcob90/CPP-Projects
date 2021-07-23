#ifndef SAVE_H
#define SAVE_H

class SavingsAccount
{
	public:
		static const int monthsPerYear = 12;
		SavingsAccount( double );
		void setSavings( double );
		double getSavings() const;
		double calculateMonthlyInterest();
		static void modifyInterestRate( double );
		void print() const;
	
	private:
		double savingsBalance;
		static double annualInterestRate;
};

#endif
