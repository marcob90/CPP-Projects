#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account{
	
	public:
		Account( double );
		void setBalance( double );
		double getBalance();
		void credit( double );
		void debit( double );
		
	private:
		double balance;
};

#endif
