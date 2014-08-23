integer main() {
	integer a,b,c,d;
	a=Create("6.dat");
	a=Open("6.dat");
	d=1;
	b=60;
	while(b<15000) do
		c=Write(a,b);
		d=d+1;
		b=60*d;
	endwhile;
	c=Close(a);	
	return 0;
}
