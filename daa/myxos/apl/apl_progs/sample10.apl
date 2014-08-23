integer main()
{
	integer childpid;
	integer retval;
	
	childpid = Fork();
	
	
	if(childpid == -2) then
		
		retval = Exec("sample10.xsm");
	else
		
		while(childpid != -1) do
			print(childpid);
			breakpoint;
		endwhile;
	endif;
	return 0;
}
