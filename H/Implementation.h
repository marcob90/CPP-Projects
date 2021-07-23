class Implementation
{
	public:
		Implementation( int v )
		: value( v )
		{
		}
		~Implementation()
		{
		}
		void setValue( int v )
		{
			value = v;
		}
		int getValue() const
		{
			return value;
		}
		
	private:
		int value;
};

