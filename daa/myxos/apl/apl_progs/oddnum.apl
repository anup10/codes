integer main() 
{
	integer i,j,p;
	integer z;
	z=20;
	j=2;
	i=1;
	while(i<=z)do
		if(i%2!=0) then
			print(i);
		endif;
		i=i+1;
		if(i>13) then
			p=Signal();
		endif;
	endwhile;
	print(Getppid());
	return 0;
}
		
