integer main()
{
	integer childpid;
	integer retval,wait;
	
	childpid = Fork();
	
	
	if(childpid == -2) then
		
		retval = Exec("exe.xsm");
	endif;
	
	
	if(childpid != -1) then 
		retval=Exec("a.xsm");
		
	endif;
	return 0;
}
