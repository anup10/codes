integer main() 
{
	integer i,j,k;
	integer z;
	z=20;
	j=2;
	i=1;
	while(i<=z)do
				
		if(i%2==0) then
			print(i);
		endif;
		
		i=i+1;
		
	endwhile;
	
	k=Getppid();
	print(k);
	return 0;
}
		
