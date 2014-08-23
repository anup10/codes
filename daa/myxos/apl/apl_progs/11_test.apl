integer main()
{
	integer childpid,ret;
	integer retval,r1;
	
	childpid = Fork();
	
	
	if(childpid == -2) then
		
		retval = Exec("evennum.xsm");
		
	else
		
		r1=Wait(childpid);
		retval=Exec("oddnum.xsm");
		
	endif;
	return 0;
}
