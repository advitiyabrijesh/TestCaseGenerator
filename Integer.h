class num_gen
{
	public :
	int x;
	static void Integer()
	{
		printf("%d\n",rand());
	}
	static int Integer(int l , int r )
	{
		return (l +  rand()%(r-l+1));
	}
	static void Integer(int mod )
	{
		printf("%d\n",rand()%mod + 1);
	}
	static int returnInteger(int mod)
	{
		return rand()%mod+1;
	}

};
