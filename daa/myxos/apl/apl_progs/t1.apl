integer main()
{
	integer childpid;
	integer i;
	i=0;
	while(i<7) do
		childpid=Fork();
		print(childpid);
		breakpoint;
	endwhile;
		
		
			
		
	
	return 0;
}
