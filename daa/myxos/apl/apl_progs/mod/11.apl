integer main() {
	integer a,b,c,d;
	a=Create("11.dat");
	a=Open("11.dat");
	d=1;
	b=110;
	while(b<15000) do
		c=Write(a,b);
		d=d+1;
		b=110*d;
	endwhile;
	c=Close(a);	
	return 0;
}
