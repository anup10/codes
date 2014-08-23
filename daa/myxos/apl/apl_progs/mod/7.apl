integer main() {
	integer a,b,c,d;
	a=Create("7.dat");
	a=Open("7.dat");
	d=1;
	b=70;
	while(b<15000) do
		c=Write(a,b);
		d=d+1;
		b=70*d;
	endwhile;
	c=Close(a);	
	return 0;
}
