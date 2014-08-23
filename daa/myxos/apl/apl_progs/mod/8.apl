integer main() {
	integer a,b,c,d;
	a=Create("8.dat");
	a=Open("8.dat");
	d=1;
	b=80;
	while(b<15000) do
		c=Write(a,b);
		d=d+1;
		b=80*d;
	endwhile;
	c=Close(a);	
	return 0;
}
