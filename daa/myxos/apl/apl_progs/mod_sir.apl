integer main()
{
	integer childpid,n,r1,r2,r3,mul,r4;
	

	print("Enter n :");
	read(n);
	r1=Create("readnum.dat");
	if(r1==-1) then
		print("gbl fl nt ctd");
	endif;

	while(n>0) do
		r2=Open("readnum.dat");
		if(r2==-1) then
			print("glb fl nt opn");
		endif;
		childpid=Fork();
		if(childpid == -2) then
			print("multiples of:");
			read(mul);
			r1=Write(r2,mul);
			
			r1=Exec("yes.xsm");
			
			
		
		else
			
			
			
			n=n-1;
		endif;
		
		
	endwhile;
	r1=Close(r2);
	return 0;
}










