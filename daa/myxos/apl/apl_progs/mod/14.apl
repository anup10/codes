integer main() {
	integer a,b,c,d;
	a=Create("14.dat");
	a=Open("14.dat");
	d=1;
	b=140;
	while(b<1500) do
		c=Write(a,b);
		d=d+1;
		b=140*d;
	endwhile;
	c=Close(a);	
	return 0;
}
