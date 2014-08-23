integer main()
{
	integer r1,r2,r3,r4,r5,mul,i;
	string str;
	r1=Open("readnum.dat");
	r2=Read(r1,mul);
	print("Enter op file");
	read(str);
	r3=Create(str);
	r4=Open(str);

	i=1;
	while(i<=1500) do
		if(i%mul==0) then
			r5=Write(r4,i);
		endif;
		i=i+1;
	endwhile;
	
	print("anup5...");
	return 0;
}






